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

#ifndef _OSEK_KERNEL_H_
#define _OSEK_KERNEL_H_

/*
 *  �J�[�l���������ʂ̃C���N���[�h�t�@�C��
 */
#include "kernel.h"

/*
 *  �J�[�l�����Ŏg�p����f�[�^�^�̒�`
 */
#ifndef _MACRO_ONLY
typedef void		*VP;			/* �^����܂�Ȃ����̂ւ̃|�C���^ */
typedef void		(*FP)(void);	/* �v���O�����̋N���Ԓn�i�|�C���^�j */
typedef UINT8		Priority;		/* �D��x�i�^�X�N�CISR�j */
typedef	UINT8		IPL;			/* �����ݗD�惌�x�� */
#endif /* _MACRO_ONLY */

#include "portable.h"
/*
 *  �D��x�̒i�K���̒�`
 */
#define TNUM_PRIORITY	((Priority) 16)

/*
 *  ��ʓI�Ȓ萔�̒�`
 */
#define	NULL			((void *) 0)		/* �����|�C���^ */

/*
 *  �D��x�l�̒�`
 */
#define TPRI_MINTASK	((Priority) 0)		/* �Œ�^�X�N�D��x */
#define TPRI_MAXTASK	((Priority)(TNUM_PRIORITY - 1))
											/* �ō��^�X�N�D��x */
#define TPRI_SCHEDULER	((Priority) 127)	/* �X�P�W���[���̗D��x */
#define TPRI_MINISR		((Priority) 128)	/* �Œኄ���ݗD��x */
#define TPRI_NULL		((Priority) UINT8_INVALID)
											/* �����D��x */

/*
 *  �C�x���g�}�X�N�l�̒�`
 */
#define EVTMASK_NONE	((EventMaskType) 0)	/* �C�x���g�Ȃ� */

/*
 *  �A�v���P�[�V�������[�h�l�̒�`
 */
#define APPMODE_NONE	((AppModeType) 0)	/* ���[�h�Ȃ� */

/*
 *  IPL�l�̒�`
 */
#define IPL_ENA_ALL	((IPL) 0)		/* ���ׂĂ̊����݂����� */

/*
 *  ���s���̃R���e�L�X�g�icallevel�j�̒l�̒�`
 */
#define TCL_NULL		((UINT8) 0x00)	/* �T�[�r�X�R�[�����Ăяo���Ȃ� */
#define TCL_TASK		((UINT8) 0x01)	/* �^�X�N */
#define TCL_ISR2		((UINT8) 0x02)	/* �J�e�S��2 ISR */
#define TCL_ERROR		((UINT8) 0x04)	/* ErrorHook */
#define TCL_PREPOST		((UINT8) 0x08)	/* PreTaskHook�CPostTaskHook */
#define TCL_STARTUP		((UINT8) 0x10)	/* StartupHook */
#define TCL_SHUTDOWN	((UINT8) 0x20)	/* ShutdownHook */


#ifndef _MACRO_ONLY
/*
 *  OS���s����̂��߂̕ϐ��iosctl.c�j
 */
extern UINT8		callevel;	/* ���s���̃R���e�L�X�g */
extern AppModeType	appmode;	/* �A�v���P�[�V�������[�h */

/*
 *  OS���̃N���e�B�J���Z�N�V��������֐�
 */
Inline void	lock_cpu(void);		/* �N���e�B�J���Z�N�V�����J�n */
Inline void	unlock_cpu(void);	/* �N���e�B�J���Z�N�V�����I�� */

Inline void
lock_cpu(void)
{
	disable_int();
}

Inline void
unlock_cpu(void)
{
	enable_int();
}

/*
 *  �G���[�t�b�N�Ăяo���̂��߂̐錾�iosctl.c�j
 *
 *  �T�[�r�X�R�[�����ŃG���[�����������ꍇ�ɂ́C�T�[�r�X�R�[���ւ̃p��
 *  ���[�^�� _errorhook_par1�`3 �ɐݒ肵����Ccall_errorhook ���Ăяo���D
 *  call_errorhook �ւ́C�G���[�R�[�h�ƃT�[�r�X�R�[����ID��n���D
 */
extern void	call_errorhook(StatusType ercd, OSServiceIdType svcid);

/*
 *  �|�X�g�^�X�N�t�b�N/�v���^�X�N�t�b�N�Ăяo���̂��߂̐錾�iosctl.c�j
 */
extern void	call_posttaskhook(void);
extern void	call_pretaskhook(void);

/*
 *  os_cfg.c
 */
extern void	object_initialize(void);

#endif /* _MACRO_ONLY */

/*
 *  �g���X�e�[�^�X��W����
 */
#ifndef BASIC_STATUS
#define EXTENDED_STATUS
#endif /* BASIC_STATUS */

#endif /* _OSEK_KERNEL_H_ */
