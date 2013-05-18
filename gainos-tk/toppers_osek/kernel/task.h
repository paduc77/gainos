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
 *	�^�X�N�Ǘ����W���[��
 */

#ifndef _TASK_H_
#define _TASK_H_

/*
 *  �^�X�NID�̓���Ȓl�̒�`
 */
#define TSKID_NULL		((TaskType) UINT8_INVALID)	/* ����ID */

/*
 *  �^�X�N��ԁitcb_stat�j�l�̒�`
 */
#define TS_RUNNABLE		READY				/* ���s��ԁC���s�\��� */
#define TS_DORMANT		SUSPENDED			/* �x�~��� */
#define TS_WAITING		WAITING				/* �҂���� */

/*
 *  os_cfg.c, static configured information for tasks
 */
extern const UINT8	tnum_task;		/* number of the (basic & extend) task has been configured */
extern const UINT8	tnum_exttask;		/* number of the extend task has been configured */
extern const Priority	tinib_inipri[];		/* task init priority */
extern const Priority	tinib_exepri[];		/* task priority when start to execute */
extern const UINT8		tinib_maxact[];		/* task max activate count */
extern const AppModeType tinib_autoact[];	/* task autostart mode */
extern const FP			tinib_task[];		/* task entery */
extern const VP			tinib_stk[];		/* task stack buffer entry */
extern const UINT16		tinib_stksz[];		/* task stack buffer size */

/*
 *  os_cfg.c
 *
 *  used to manage tasks < tasks queue, state, proority, activate count >
 */
extern TaskType			tcb_next[];			/* task linker,indicate the next task in the queue */
extern UINT8			tcb_tstat[];		/* task state */
extern Priority			tcb_curpri[];		/* task current priority */
extern UINT8			tcb_actcnt[];		/* task current activate count */
extern EventMaskType	tcb_curevt[];		/* task current event has been set */
extern EventMaskType	tcb_waievt[];		/* task wait event */
extern ResourceType		tcb_lastres[];		/* task acquired resource recently */

/*
 *  help the scheduler to remember the current task in running state
 *
 *  when it is TKSID_NULL, no task is in ready state
 */
extern TaskType			runtsk;

/*
 *  help the scheduler to remember the next highest ready task  
 */
extern TaskType			schedtsk;

/*
 *  help the scheduler to remember the next high priority
 */
extern Priority			nextpri;

/*
 *  �^�X�N�Ǘ����W���[���̏�����
 */
extern void	task_initialize(void);

/*
 *  �^�X�N�̋N��
 *
 *  �Ώۃ^�X�N�itskid �Ŏw�肵���^�X�N�j���N������i�x�~��Ԃ�����s��
 *  �����ԂɑJ�ڂ�����D�^�X�N�̋N�����ɕK�v�ȏ��������s���D
 */
extern BOOL	make_active(TaskType tskid);

/*
 *  ���s�ł����Ԃւ̈ڍs
 *
 *  �Ώۃ^�X�N�itskid �Ŏw�肵���^�X�N�j�����s�ł����ԂɑJ�ڂ�����D
 *  �Ώۃ^�X�N�̗D��x���C�ō��D��x�^�X�N�ischedtsk�j�̗D��x������
 *  ���ꍇ�ɂ́C�Ώۃ^�X�N��V�����ō��D��x�^�X�N�Ƃ��C����܂ł̍ō�
 *  �D��x�^�X�N�����f�B�L���[�̐擪�ɓ����D�����łȂ��ꍇ�ɂ́C�Ώ�
 *  �^�X�N�����f�B�L���[�̖����ɓ����D�Ώۃ^�X�N���ō��D��x�^�X�N��
 *  �����ꍇ�ɁCTRUE ��Ԃ��D
 */
extern BOOL	make_runnable(TaskType tskid);

/*
 *  �ō��D�揇�ʃ^�X�N�̃T�[�`
 *
 *  ���f�B�L���[���ōł��D�揇�ʂ̍����^�X�N���T�[�`���C��������f�B
 *  �L���[����O���āC�ō��D�揇�ʃ^�X�N�ischedtsk�j�Ƃ���D���ۂɂ́C
 *  ���f�B�L���[���̍ō��D��x�� nextpri �ɐݒ肳��Ă��邽�߂ɃT�[�`
 *  �͕K�v�Ȃ��C�D��x nextpri �̃��f�B�L���[�̐擪�̃^�X�N���ō��D��
 *  ���ʃ^�X�N�Ƃ���D���f�B�L���[�̃T�[�`�́C���̃^�X�N�����f�B�L���[
 *  ����O������� nextpri ���X�V���邽�߂ɕK�v�ƂȂ�D���̃T�[�`�ɁC
 *  ready_primap ��p����D
 *  ���̊֐��́C����܂Ŏ��s��Ԃł������^�X�N���҂���Ԃ��x�~��ԂɈ�
 *  �s�������ɁC���Ɏ��s���ׂ��^�X�N��I�Ԃ��߂ɌĂяo���D����Ă��̊�
 *  ���ł́C����܂ł̍ō��D��x�^�X�N�͖�������D
 */
extern void	search_schedtsk(void);

/*
 *  �^�X�N�̃v���G���v�g
 *
 *  ���^�X�N�����s�\��ԂɈڍs�����C�ō��D��x�^�X�N�����s��Ԃɂ���D
 *  ���̊֐�����߂�����ɁCdispatch ���Ăяo���đ��̃^�X�N�֐؂�ւ���
 *  ���Ƃ�z�肵�Ă���D
 */
extern void	preempt(void);

#endif /* _TASK_H_ */
