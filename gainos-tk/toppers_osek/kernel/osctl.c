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
 *	���s����@�\
 */

#include "osek_kernel.h"
#include "check.h"
#include "interrupt.h"

/*
 *  OS���s����̂��߂̕ϐ�
 */
UINT8		callevel;		/* ���s���̃R���e�L�X�g */
AppModeType	appmode;		/* �A�v���P�[�V�������[�h */

/*
 *  �G���[�t�b�N�ɓn�������i�[����ϐ�
 */
OSServiceIdType	_errorhook_svcid;
_ErrorHook_Par	_errorhook_par1, _errorhook_par2, _errorhook_par3;

/*
 *  �G���[�t�b�N�̌Ăяo��
 */
void
call_errorhook(StatusType ercd, OSServiceIdType svcid)
{
	UINT8	saved_callevel;
	IPL	saved_ipl;
	volatile FP	errorhook_adr;
	
	/*
	 *  C����̋K�i�ł͊֐��̃A�h���X��0�ɂȂ�Ȃ��Ƃ����O�񂩂�,
	 *  �R���p�C���̍œK���ɂ��ErrorHook�̃A�h���X���蕪��
	 *  �폜����Ă��܂��ꍇ�����邽��, volatile�w�肵�����[�J���ϐ���
	 *  �A�h���X�������Ă��画�肵�Ă���D
	*/
	errorhook_adr = (FP)ErrorHook;
	
	if (sus_all_cnt > 0) {
		if ((errorhook_adr != NULL) && (callevel != TCL_ERROR)) {
			_errorhook_svcid = svcid;
			ErrorHook(ercd);
		}
		ShutdownOS(E_OS_CALLEVEL);	/* �񕜕s�\ */
	}
	else {
		if (( errorhook_adr != NULL) && (callevel != TCL_ERROR)) {
			_errorhook_svcid = svcid;
			saved_callevel = callevel;
			callevel = TCL_ERROR;
			saved_ipl = current_ipl();
			if (saved_ipl < ipl_maxisr2) {
				set_ipl(ipl_maxisr2);
			}
			unlock_cpu();
			ErrorHook(ercd);
			lock_cpu();
			if (saved_ipl < ipl_maxisr2) {
				set_ipl(saved_ipl);
			}
			callevel = saved_callevel;	
		}
	}
}

/*
 *  �|�X�g�^�X�N�t�b�N�̌Ăяo��
 */
void
call_posttaskhook(void)
{
	callevel = TCL_PREPOST;
	set_ipl(ipl_maxisr2);
	unlock_cpu();
	PostTaskHook();
	lock_cpu();
	set_ipl(IPL_ENA_ALL);
	callevel = TCL_TASK;	
}

/*
 *  �v���^�X�N�t�b�N�̌Ăяo��
 */
void
call_pretaskhook(void)
{
	callevel = TCL_PREPOST;
	set_ipl(ipl_maxisr2);
	unlock_cpu();
	PreTaskHook();
	lock_cpu();
	set_ipl(IPL_ENA_ALL);
	callevel = TCL_TASK;	
}

/*
 *  ���݂̃A�v���P�[�V�������[�h�̎擾
 */
AppModeType
GetActiveApplicationMode(void)
{
	AppModeType	mode;

	LOG_GETAAM_ENTER();
	mode = appmode;
	LOG_GETAAM_LEAVE(mode);
	return(mode);
}

/* Import Functions */
extern void cpu_initialize(void);
extern void sys_initialize(void);
extern void tool_initialize(void);

/*
 *  OS�̋N��
 */
void
StartOS(AppModeType mode)
{
	volatile FP startuphook_adr;

	LOG_STAOS_ENTER(mode);

	/*
	 *  Store 
	 */
	appmode = mode;

	/*
	 *  Do the needed initialize
	 */
	cpu_initialize();  /* implemented in cpu_context.c */
	sys_initialize();  /* user defined interface */
	tool_initialize(); /* user defined interface */

	/*
	 *  Initialize OSEK OS objects.
	 */
	object_initialize();

	/*
	 *  StartupHook �̌Ăяo��
	 *  
	 *  C����̋K�i�ł͊֐��̃A�h���X��0�ɂȂ�Ȃ��Ƃ����O�񂩂�,
	 *  �R���p�C���̍œK���ɂ��StartupHook�̃A�h���X���蕪��
	 *  �폜����Ă��܂��ꍇ�����邽��, volatile�w�肵�����[�J���ϐ���
	 *  �A�h���X�������Ă��画�肵�Ă���D
	 *
	 */
	startuphook_adr = (FP)StartupHook;
	
	if (startuphook_adr != NULL) {
		/*
		 *  StartupHook �̒��ŁCSuspendAllInterrupts ���Ă΂�
		 *  �Ă����v�Ȃ悤�ɁCsus_all_cnt ���[���ɂ��Ă����D
		 */
		callevel = TCL_STARTUP;
		sus_all_cnt++;
		StartupHook();
		sus_all_cnt--;
	}
	callevel = TCL_TASK;

	LOG_STAOS_LEAVE();
	start_dispatch();
}

/*
 *  OS�̏I��
 */
void
ShutdownOS(StatusType ercd)
{
	volatile FP shutdownhook_adr;

	LOG_STUTOS_ENTER(ercd);

	/*
	 *  ���ׂĂ̊����݂��֎~����
	 */
	disable_int();

	/*
	 *  ShutdownHook �̌Ăяo��
	 *  
	 *  C����̋K�i�ł͊֐��̃A�h���X��0�ɂȂ�Ȃ��Ƃ����O�񂩂�,
	 *  �R���p�C���̍œK���ɂ��ShutdownHook�̃A�h���X���蕪��
	 *  �폜����Ă��܂��ꍇ�����邽��, volatile�w�肵�����[�J���ϐ���
	 *  �A�h���X�������Ă��画�肵�Ă���D
	 */
	 
	 shutdownhook_adr = (FP)ShutdownHook;
	 
	if (shutdownhook_adr != NULL) {
		/*
		 *  ShutdownHook �̒��ŁCSuspendAllInterrupts ���Ă΂�
		 *  �Ă����v�Ȃ悤�ɁCsus_all_cnt ���[���ɂ��Ă����D
		 */
		callevel = TCL_SHUTDOWN;
		sus_all_cnt++;
		ShutdownHook(ercd);
		sus_all_cnt--;
	}

	LOG_STUTOS_LEAVE();

	/*
	 *  �^�[�Q�b�g�ˑ��̏I������
	 */
	cpu_terminate();
	sys_exit();
}


