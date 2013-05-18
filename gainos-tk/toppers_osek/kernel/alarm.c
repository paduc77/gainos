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
 *	�A���[���@�\
 */

#include "osek_kernel.h"
#include "check.h"
#include "alarm.h"

/*
 *  �X�^�e�B�b�N�֐��̃v���g�^�C�v�錾
 */
Inline TickType	add_tick(TickType almval, TickType incr, TickType maxval2);
Inline TickType	diff_tick(TickType val1, TickType val2, TickType maxval2);
static void	enqueue_alarm(AlarmType almid, CounterType cntid);
static void	dequeue_alarm(AlarmType almid, CounterType cntid);

/*
 *  �e�B�b�N�l�̉��Z
 *
 *  almval �� incr �����Z�����e�B�b�N�l��Ԃ��D���Z�����e�B�b�N�l���C
 *  maxval2 �𒴂���ꍇ�ɂ́C(maxval2 + 1) ���������l��Ԃ��D
 */
Inline TickType
add_tick(TickType almval, TickType incr, TickType maxval2)
{
	/*
	 *  �f���ȏ������� almval + incr <= maxval2 �ł��邪�C���̏�������
	 *  �́Calmval + incr �� TickType �ŕ\����͈͂𒴂���ꍇ�ɐ�����
	 *  ����ł��Ȃ��Ȃ邽�߁C���̏������Ƃ��Ă���D
	 */
	if (incr <= (maxval2 - almval)) {
		return(almval + incr);
	}
	else {
		/*
		 *  ���̌v�Z���ŁCalmval + incr �� maxval2 + 1 �� TickType �ŕ\
		 *  ����͈͂𒴂���ꍇ�����邪�C�I�[�o�t���[���Ă����܂�l��
		 *  ���������ߍ����x���Ȃ��D
		 */
		return(almval + incr - (maxval2 + 1));
	}
}

/*
 *  �e�B�b�N�l�̍�
 *
 *  val1 �� val2 �̍��ival1 ���� val2 ���������l�j��Ԃ��D�������̒l��
 *  �Ȃ�ꍇ�ɂ́C(maxval2 + 1) ���������l��Ԃ��D
 */
Inline TickType
diff_tick(TickType val1, TickType val2, TickType maxval2)
{
	if (val1 >= val2) {
		return(val1 - val2);
	}
	else {
		/*
		 *  ���̌v�Z���ŁCval1 - val2 �� maxval2 + 1 �� TickType �ŕ\��
		 *  ��͈͂𒴂���ꍇ�����邪�C�I�[�o�t���[���Ă����܂�l�͐�
		 *  �������ߍ����x���Ȃ��D
		 */
		return(val1 - val2 + (maxval2 + 1));
	}
}

/*
 *  �A���[���L���[�ւ̑}��
 *
 *  almid �Ŏw�肳���A���[�����Ccntid �Ŏw�肳���J�E���^�̃A���[��
 *  �L���[�ɑ}������D�܂��C�A���[���L���[�ɓ��������̃A���[���������
 *  ���ɂ́C���̖����ɑ}������i�擪�ł������x���Ȃ��Ǝv����j�D
 */
static void
enqueue_alarm(AlarmType almid, CounterType cntid)
{
	TickType	enqval, curval;
	AlarmType	next, prev;

	enqval = almcb_almval[almid];
	curval = cntcb_curval[cntid];

	/*
	 *  �}���ꏊ�̃T�[�`
	 */
	next = cntcb_almque[cntid];
	prev = ALMID_NULL;
	if (curval < enqval) {
		/*
		 *  enqval �� curval �����傫�����D����������ƁC����
		 *  �e�B�b�N����A���[���̎w��e�B�b�N�܂ł̊ԂɁC�J�E
		 *  ���^�̃I�[�o�t���[�i�ő�l�𒴂��āC0 �ɖ߂邱�Ɓj
		 *  ���N����Ȃ��ꍇ�D
		 */
		while ((next != ALMID_NULL) && ((curval <= almcb_almval[next])
					&& (almcb_almval[next] <= enqval))) {
			prev = next;
			next = almcb_next[prev];
		}
	}
	else {
		/*
		 *  ����ȊO�̎��D����������ƁC���݃e�B�b�N����A���[
		 *  ���̎w��e�B�b�N�܂ł̊ԂɁC�J�E���^�̃I�[�o�t���[
		 *  ���N����ꍇ�D
		 */
		while ((next != ALMID_NULL) && ((curval <= almcb_almval[next])
					|| (almcb_almval[next] <= enqval))) {
			prev = next;
			next = almcb_next[prev];
		}
	}

	/*
	 *  �L���[�̂Ȃ���������
	 */
	almcb_next[almid] = next;
	almcb_prev[almid] = prev;
	if (prev != ALMID_NULL) {
		almcb_next[prev] = almid;
	}
	else {
		cntcb_almque[cntid] = almid;
	}
	if (next != ALMID_NULL) {
		almcb_prev[next] = almid;
	}
}

/*
 *  �A���[���L���[����̍폜
 *
 *  almid �Ŏw�肳���A���[�����Ccntid �Ŏw�肳���J�E���^�̃A���[
 *  ���L���[����폜����D
 */
static void
dequeue_alarm(AlarmType almid, CounterType cntid)
{
	AlarmType	next, prev;

	next = almcb_next[almid];
	prev = almcb_prev[almid];
	if (prev != ALMID_NULL) {
		almcb_next[prev] = next;
	}
	else {
		cntcb_almque[cntid] = next;
	}
	if (next != ALMID_NULL) {
		almcb_prev[next] = prev;
	}
	almcb_next[almid] = almid;
}

/*
 *  �A���[���@�\�̏�����
 */
void
alarm_initialize(void)
{
	CounterType	cntid;
	AlarmType	almid;

	for (cntid = 0; cntid < tnum_counter; cntid++) {
		cntcb_curval[cntid] = 0u;
		cntcb_almque[cntid] = ALMID_NULL;
	}
	for (almid = 0; almid < tnum_alarm; almid++) {
		almcb_next[almid] = almid;
		if ((alminib_autosta[almid] & appmode) != APPMODE_NONE) {
			almcb_almval[almid] = alminib_almval[almid];
			almcb_cycle[almid] = alminib_cycle[almid];
			enqueue_alarm(almid, alminib_cntid[almid]);
		}
	}
}

/*
 *  �A���[���x�[�X�̎Q��
 */
StatusType
GetAlarmBase(AlarmType almid, AlarmBaseRefType p_info)
{
	StatusType	ercd = E_OK;
	CounterType	cntid;

	LOG_GETALB_ENTER(almid, p_info);
	CHECK_CALLEVEL(TCL_TASK | TCL_ISR2 | TCL_ERROR | TCL_PREPOST);
	CHECK_ALMID(almid);

	cntid = alminib_cntid[almid];
	p_info->maxallowedvalue = cntinib_maxval[cntid];
	p_info->ticksperbase = cntinib_tickbase[cntid];
	p_info->mincycle = cntinib_mincyc[cntid];
  exit:
	LOG_GETALB_LEAVE(ercd);
	return(ercd);

  error_exit:
	lock_cpu();
	_errorhook_par1.almid = almid;
	_errorhook_par2.p_info = p_info;
	call_errorhook(ercd, OSServiceId_GetAlarmBase);
	unlock_cpu();
	goto exit;
}

/*
 *  �A���[���̏�ԎQ��
 */
StatusType
GetAlarm(AlarmType almid, TickRefType p_tick)
{
	StatusType	ercd = E_OK;
	CounterType	cntid;
	TickType	curval;

	LOG_GETALM_ENTER(almid, p_tick);
	CHECK_CALLEVEL(TCL_TASK | TCL_ISR2 | TCL_ERROR | TCL_PREPOST);
	CHECK_ALMID(almid);

	lock_cpu();
	if (almcb_next[almid] == almid) {
		ercd = E_OS_NOFUNC;
		goto d_error_exit;
	}
	cntid = alminib_cntid[almid];
	curval = cntcb_curval[cntid];
	if (curval < almcb_almval[almid]) {
		*p_tick = almcb_almval[almid] - curval;
	}
	else {
		*p_tick = (cntinib_maxval2[cntid] - curval) + 1
					+ almcb_almval[almid];
	}
  exit:
	unlock_cpu();
	LOG_GETALM_LEAVE(ercd);
	return(ercd);

  error_exit:
	lock_cpu();
  d_error_exit:
	_errorhook_par1.almid = almid;
	_errorhook_par2.p_tick = p_tick;
	call_errorhook(ercd, OSServiceId_GetAlarm);
	goto exit;
}

/*
 *  �A���[���̐ݒ�i���Βl�j
 */
StatusType
SetRelAlarm(AlarmType almid, TickType incr, TickType cycle)
{
	StatusType	ercd = E_OK;
	CounterType	cntid;
	TickType	maxval;

	LOG_SETREL_ENTER(almid, incr, cycle);
	CHECK_CALLEVEL(TCL_TASK | TCL_ISR2);
	CHECK_ALMID(almid);

	cntid = alminib_cntid[almid];
	maxval = cntinib_maxval[cntid];
	CHECK_VALUE((0u < incr) && (incr <= maxval));
	CHECK_VALUE((cycle == 0u)
		|| ((cntinib_mincyc[cntid] <= cycle) && (cycle <= maxval)));

	lock_cpu();
	if (almcb_next[almid] != almid) {
		ercd = E_OS_STATE;
		goto d_error_exit;
	}
	almcb_almval[almid] = add_tick(cntcb_curval[cntid], incr,
										cntinib_maxval2[cntid]);
	almcb_cycle[almid] = cycle;
	enqueue_alarm(almid, cntid);
  exit:
	unlock_cpu();
	LOG_SETREL_LEAVE(ercd);
	return(ercd);

  error_exit:
	lock_cpu();
  d_error_exit:
	_errorhook_par1.almid = almid;
	_errorhook_par2.incr = incr;
	_errorhook_par3.cycle = cycle;
	call_errorhook(ercd, OSServiceId_SetRelAlarm);
	goto exit;
}

/*
 *  �A���[���̐ݒ�i��Βl�j
 */
StatusType
SetAbsAlarm(AlarmType almid, TickType start, TickType cycle)
{
	StatusType	ercd = E_OK;
	CounterType	cntid;
	TickType	maxval, start2;

	LOG_SETABS_ENTER(almid, start, cycle);
	CHECK_CALLEVEL(TCL_TASK | TCL_ISR2);
	CHECK_ALMID(almid);

	cntid = alminib_cntid[almid];
	maxval = cntinib_maxval[cntid];
	CHECK_VALUE(start <= maxval);
	CHECK_VALUE((cycle == 0u)
		|| ((cntinib_mincyc[cntid] <= cycle) && (cycle <= maxval)));

	lock_cpu();
	if (almcb_next[almid] != almid) {
		ercd = E_OS_STATE;
		goto d_error_exit;
	}

	start2 = start + maxval + 1;
	if (cntcb_curval[cntid] <= maxval) {
		if (start <= cntcb_curval[cntid]) {
			almcb_almval[almid] = start2;
		}
		else {
			almcb_almval[almid] = start;
		}
	}
	else {
		if (start2 <= cntcb_curval[cntid]) {
			almcb_almval[almid] = start;
		}
		else {
			almcb_almval[almid] = start2;
		}
	}
	almcb_cycle[almid] = cycle;
	enqueue_alarm(almid, cntid);
  exit:
	unlock_cpu();
	LOG_SETABS_LEAVE(ercd);
	return(ercd);

  error_exit:
	lock_cpu();
  d_error_exit:
	_errorhook_par1.almid = almid;
	_errorhook_par2.start = start;
	_errorhook_par3.cycle = cycle;
	call_errorhook(ercd, OSServiceId_SetAbsAlarm);
	goto exit;
}

/*
 *  �A���[���̃L�����Z��
 *
 */
StatusType
CancelAlarm(AlarmType almid)
{
	StatusType	ercd = E_OK;

	LOG_CANALM_ENTER(almid);
	CHECK_CALLEVEL(TCL_TASK | TCL_ISR2);
	CHECK_ALMID(almid);

	lock_cpu();
	if (almcb_next[almid] == almid) {
		ercd = E_OS_NOFUNC;
		goto d_error_exit;
	}
	dequeue_alarm(almid, alminib_cntid[almid]);

	/*
	 *  �A���[���R�[���o�b�N�̒�����C���A���[���� SetRelAlarm/
	 *  SetAbsAlarm ������� CancelAlarm �����󋵁iOSEK�d�l�ł͋�
	 *  ����Ă��Ȃ����CTOPPERS/OSEK�J�[�l���ł͋����Ă���j�ŁC��
	 *  �A���[�����A���[���L���[�ɍđ}�������̂�h�����߂ɁC
	 *  almcb_cycle[almid] �� 0 �ɂ��Ă����D
	 */
	almcb_cycle[almid] = 0u;
  exit:
	unlock_cpu();
	LOG_CANALM_LEAVE(ercd);
	return(ercd);

  error_exit:
	lock_cpu();
  d_error_exit:
	_errorhook_par1.almid = almid;
	call_errorhook(ercd, OSServiceId_CancelAlarm);
	goto exit;
}

/*
 *  �J�E���^��i�߂�
 */
StatusType
SignalCounter(CounterType cntid)
{
	StatusType	ercd = E_OK;
	TickType	newval;
	AlarmType	almid, next;

	LOG_SIGCNT_ENTER(cntid);
	CHECK_CALLEVEL(TCL_ISR2);
	CHECK_CNTID(cntid);

	lock_cpu();

	/*
	 *  �X�V��̃J�E���^�l�����߂�
	 */
	newval = add_tick(cntcb_curval[cntid], cntinib_tickbase[cntid],
												cntinib_maxval2[cntid]);

	/*
	 *  �J�E���^�̌��ݒl�̍X�V
	 */
	cntcb_curval[cntid] = newval;

	/*
	 *  �A���[���� expire ����
	 */
	while (((almid = cntcb_almque[cntid]) != ALMID_NULL)
			&& diff_tick(newval, almcb_almval[almid], cntinib_maxval2[cntid])
												<= cntinib_maxval[cntid]) {
		/*
		 *  �A���[���L���[�̐擪�̃A���[�����C�L���[����O���D
		 */
		next = almcb_next[almid];
		cntcb_almque[cntid] = next;
		if (next != ALMID_NULL) {
			almcb_prev[next] = ALMID_NULL;
		}
		almcb_next[almid] = almid;

		/*
		 *  �A���[���R�[���o�b�N�̌Ăяo��
		 */
		unlock_cpu();
		(*alminib_cback[almid])();
		lock_cpu();

		/*
		 *  �A���[���L���[�ւ̍đ}���i�����A���[���̏ꍇ�j
		 *
		 *  �A���[���R�[���o�b�N�̒��Ŏ��A���[���� SetRelAlarm/
		 *  SetAbsAlarm �����󋵁iOSEK�d�l�ł͋�����Ă��Ȃ����C
		 *  TOPPERS/OSEK�J�[�l���ł͋����Ă���j�ŁC�A���[���L���[
		 *  �ւ̍đ}����h�����߂ɁCalmcb_next[almid] == almid
		 *  �̏ꍇ�̂ݍđ}������D
		 */
		if ((almcb_next[almid] == almid) && (almcb_cycle[almid] > 0u)) {
			almcb_almval[almid] = add_tick(almcb_almval[almid], 
								almcb_cycle[almid], cntinib_maxval2[cntid]);
			enqueue_alarm(almid, cntid);
		}
	}
  exit:
	unlock_cpu();
	LOG_SIGCNT_LEAVE(ercd);
	return(ercd);

  error_exit:
	lock_cpu();
	_errorhook_par1.cntid = cntid;
	call_errorhook(ercd, OSServiceId_SignalCounter);
	goto exit;
}
