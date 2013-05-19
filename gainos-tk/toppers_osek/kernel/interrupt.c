/*
 *  TOPPERS/OSEK Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      OSEK Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2004 by Witz Corporation, JAPAN
 * 
 *  Copyright (C) 2013 by Fan Wang(parai), China
 * 
 * The above copyright holders grant permission gratis to use,
 * duplicate, modify, or redistribute (hereafter called use) this
 * software (including the one made by modifying this software),
 * provided that the following four conditions (1) through (4) are
 * satisfied.
 * 
 * (1) When this software is used in the form of source code, the above
 *    copyright notice, this use conditions, and the disclaimer shown
 *    below must be retained in the source code without modification.
 *
 * (2) When this software is redistributed in the forms usable for the
 *    development of other software, such as in library form, the above
 *    copyright notice, this use conditions, and the disclaimer shown
 *    below must be shown without modification in the document provided
 *    with the redistributed software, such as the user manual.
 *
 * (3) When this software is redistributed in the forms unusable for the
 *    development of other software, such as the case when the software
 *    is embedded in a piece of equipment, either of the following two
 *    conditions must be satisfied:
 *
 *  (a) The above copyright notice, this use conditions, and the
 *      disclaimer shown below must be shown without modification in
 *      the document provided with the redistributed software, such as
 *      the user manual.
 *
 *  (b) How the software is to be redistributed must be reported to the
 *      TOPPERS Project according to the procedure described
 *      separately.
 *
 * (4) The above copyright holders and the TOPPERS Project are exempt
 *    from responsibility for any type of damage directly or indirectly
 *    caused from the use of this software and are indemnified by any
 *    users or end users of this software from any and all causes of
 *    action whatsoever.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS." THE ABOVE COPYRIGHT HOLDERS AND
 * THE TOPPERS PROJECT DISCLAIM ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, ITS APPLICABILITY TO A PARTICULAR
 * PURPOSE. IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS AND THE
 * TOPPERS PROJECT BE LIABLE FOR ANY TYPE OF DAMAGE DIRECTLY OR
 * INDIRECTLY CAUSED FROM THE USE OF THIS SOFTWARE.
 */

/*
 *	Includes
 */

#include "osek_kernel.h"
#include "interrupt.h"

/*
 *  help the kernel to remember current ISR ID
 */
IsrType		runisr;

/*
 *  �����݊Ǘ��@�\�����Ŏg�p����ϐ��̒�`
 */

/*
 *  SuspendAllInterrupts �̃l�X�g��
 *
 *  ���̕ϐ��́Cdisable_int() ������Ԃł̂ݕύX���Ă悢�D
 */
UINT8		sus_all_cnt;

/*
 *  SuspendOSInterrupts �̃l�X�g��
 *
 *  ���̕ϐ��́Cset_ipl(ipl_maxisr2) ������Ԃł̂ݕύX���Ă悢�D
 *  set_ipl(ipl_maxisr2) ���Ă��C�J�e�S��1 �� ISR �͓����Ă��邪�C����
 *  �l�ɖ߂��Ă��烊�^�[������Ζ��͂Ȃ��D
 */
static UINT8	sus_os_cnt;

/*
 *  SuspendOSInterrupts ����O�̊����ݗD�惌�x��
 *
 *  ���̕ϐ��́Cset_ipl(ipl_maxisr2) ������Ԃł̂ݕύX���Ă悢�D�܂��C
 *  ���̕ϐ����g�p���Ă���Ԃ́Csus_os_cnt ���[���ɂ��Ă����D
 *  set_ipl(ipl_maxisr2) ���Ă��J�e�S��1 �� ISR �͓����Ă��邪�C
 *  sus_os_cnt ���[���ɂ��Ă������ƂŁC�J�e�S��1 �� ISR �ł��̕ϐ���
 *  �ύX����邱�Ƃ͂Ȃ��D
 */
static IPL	saved_ipl;

/*
 *  SuspendAllInterrupts/SuspendOSInterrupts ����O�̎��s�R���e�L�X�g
 *
 *  ���̕ϐ��́Cdisable_int �܂��� set_ipl(ipl_maxisr2) ������Ԃł̂�
 *  �ύX���Ă悢�D�܂��C���̕ϐ����g�p���Ă���Ԃ́Csus_all_cnt �� 
 *  sus_os_cnt ���[���ɂ��Ă����Dset_ipl(ipl_maxisr2) ���Ă��J�e�S��1
 *  �� ISR �͓����Ă��邪�Csus_os_cnt ���[���ɂ��Ă������ƂŁC�J�e�S
 *  ��1 �� ISR �ł��̕ϐ����ύX����邱�Ƃ͂Ȃ��D
 */
static UINT8	saved_callevel;

/*
 *  �����݊Ǘ��@�\�̏�����
 */
void
interrupt_initialize(void)
{
	IsrType		isrid;

	isrid = ISRID_NULL;
	sus_all_cnt = 0u;
	sus_os_cnt = 0u;
	for (isrid = 0; isrid < tnum_isr2; isrid++) {
		isrcb_lastres[isrid] = 0u;
	}
}

/*
 *  ���ׂĂ̊����݂̋֎~�i�����ȈՔŁj
 */
void
DisableAllInterrupts(void)
{
	LOG_DISINT_ENTER();
	disable_int();
	LOG_DISINT_LEAVE();
}

/*
 *  ���ׂĂ̊����݂̋��i�����ȈՔŁj
 */
void
EnableAllInterrupts(void)
{
	LOG_ENAINT_ENTER();
	enable_int();
	LOG_ENAINT_LEAVE();
}

/*
 *  ���ׂĂ̊����݂̋֎~
 */
void
SuspendAllInterrupts(void)
{
	LOG_SUSALL_ENTER();
	if (sus_all_cnt == UINT8_INVALID) {
		/*
		 *  SuspendAllInterrupts ���J��Ԃ��Ă񂾏ꍇ�̑΍�
		 *  �i���������ɔ�����j
		 */
	}
	else if (sus_all_cnt == 0) {
		disable_int();
		sus_all_cnt++;
		if (sus_os_cnt == 0) {
			saved_callevel = callevel;
			callevel = TCL_NULL;
		}
	}
	else {
		sus_all_cnt++;
	}
	LOG_SUSALL_LEAVE();
}

/*
 *  ���ׂĂ̊����݂̋���
 */
void
ResumeAllInterrupts(void)
{
	LOG_RSMALL_ENTER();
	if (sus_all_cnt == 0) {
		/*
		 *  SuspendAllInterrupts ���Ă΂��ɁCResumeAllInterrupts
		 *  ���Ă񂾏ꍇ�̑΍�i���������ɔ�����j
		 */
	}
	else if (sus_all_cnt == 1) {
		if (sus_os_cnt == 0) {
			callevel = saved_callevel;
		}
		sus_all_cnt--;
		enable_int();
	}
	else {
		sus_all_cnt--;
	}
	LOG_RSMALL_LEAVE();
}

/*
 *  �J�e�S��2�̊����݂̋֎~
 */
void
SuspendOSInterrupts(void)
{
	IPL	ipl;

	LOG_SUSOSI_ENTER();
	if (sus_os_cnt == UINT8_INVALID) {
		/*
		 *  SuspendOSInterrupts ���J��Ԃ��Ă񂾏ꍇ�̑΍�
		 *  �i���������ɔ�����j
		 */
	}
	else if (sus_os_cnt == 0) {
		ipl = current_ipl();

		/*
		 *  ���ł� ISR2 ���֎~����Ă��鎞�͉������Ȃ��D
		 */
		if (ipl < ipl_maxisr2) {
			set_ipl(ipl_maxisr2);
		}
		sus_os_cnt++;
		saved_ipl = ipl;
		if (sus_all_cnt == 0) {
			saved_callevel = callevel;
			callevel = TCL_NULL;
		}
	}
	else {
		sus_os_cnt++;
	}
	LOG_SUSOSI_LEAVE();
}

/*
 *  �J�e�S��2�̊����݂̋���
 */
void
ResumeOSInterrupts(void)
{
	LOG_RSMOSI_ENTER();
	if (sus_os_cnt == 0) {
		/*
		 *  SuspendOSInterrupts ���Ă΂��ɁCResumeOSInterrupts
		 *  ���Ă񂾏ꍇ�̑΍�i���������ɔ�����j
		 */
	}
	else if (sus_os_cnt == 1) {
		if (sus_all_cnt == 0) {
			callevel = saved_callevel;
		}
		sus_os_cnt--;

		/*
		 *  ���Ƃ��� ISR2 ���֎~����Ă������͉������Ȃ��D
		 */
		if (saved_ipl < ipl_maxisr2) {
			set_ipl(saved_ipl);
		}
	}
	else {
		sus_os_cnt--;
	}
	LOG_RSMOSI_LEAVE();
}
