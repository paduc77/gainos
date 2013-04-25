/* Copyright 2012, Fan Wang(Parai)
 *
 * This file is part of GaInOS.
 *
 * GaInOS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *             
 * Linking GaInOS statically or dynamically with other modules is making a
 * combined work based on GaInOS. Thus, the terms and conditions of the GNU
 * General Public License cover the whole combination.
 *
 * In addition, as a special exception, the copyright holders of GaInOS give
 * you permission to combine GaInOS program with free software programs or
 * libraries that are released under the GNU LGPL and with independent modules
 * that communicate with GaInOS solely through the GaInOS defined interface. 
 * You may copy and distribute such a system following the terms of the GNU GPL
 * for GaInOS and the licenses of the other code concerned, provided that you
 * include the source code of that other code when and as the GNU GPL requires
 * distribution of source code.
 *
 * Note that people who make modified versions of GaInOS are not obligated to
 * grant this special exception for their modified versions; it is their choice
 * whether to do so. The GNU General Public License gives permission to release
 * a modified version without this exception; this exception also makes it
 * possible to release a modified version which carries forward this exception.
 * 
 * GaInOS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GaInOS. If not, see <http://www.gnu.org/licenses/>.
 *
 */
/* |---------+-------------------| */
/* | Author: | Wang Fan(parai)   | */
/* |---------+-------------------| */
/* | Email:  | parai@foxmail.com | */
/* |---------+-------------------| */
#include "osek_os.h"
#if(MICRO_TENUX_VERSION == 140)
#  include "kernel.h"
#  include "task.h"
#  include "eventflag.h"
#else if(MICRO_TENUX_VERSION == 150)
#  include "knl_kernel.h"
#  include "knl_task.h"
#  include "tk_flgimpl.h"
#endif
/* |------------------+----------------------------------------------------------| */
/* | Syntax:          | StatusType SetEvent ( TaskType <TaskID>                  | */
/* |                  | EventMaskType <Mask> )                                   | */
/* |------------------+----------------------------------------------------------| */
/* | Parameter (In):  | TaskID:Reference to the task for which one or several    | */
/* |                  | events are to be set.                                    | */
/* |                  | Mask:Mask of the events to be set                        | */
/* |------------------+----------------------------------------------------------| */
/* | Parameter (Out): | none                                                     | */
/* |------------------+----------------------------------------------------------| */
/* | Description:     | 1.The service may be called from an interrupt service    | */
/* |                  | routine and from the task level, but not from hook       | */
/* |                  | routines.                                                | */
/* |                  | 2.The events of task <TaskID> are set according to the   | */
/* |                  | event mask <Mask>. Calling SetEvent causes the task      | */
/* |                  | <TaskID> to be transferred to the ready state, if it     | */
/* |                  | was waiting for at least one of the events specified     | */
/* |                  | in <Mask>.                                               | */
/* |------------------+----------------------------------------------------------| */
/* | Particularities: | Any events not set in the event mask remain unchanged.   | */
/* |------------------+----------------------------------------------------------| */
/* | Status:          | Standard: 1.No error, E_OK                               | */
/* |                  | Extended: 2.Task <TaskID> is invalid, E_OS_ID            | */
/* |                  | 3.Referenced task is no extended task, E_OS_ACCESS       | */
/* |                  | 4.Events can not be set as the referenced task is in the | */
/* |                  | suspended state, E_OS_STATE                              | */
/* |------------------+----------------------------------------------------------| */
/* | Conformance:     | ECC1, ECC2                                               | */
/* |------------------+----------------------------------------------------------| */
StatusType SetEvent ( TaskType xTaskID , EventMaskType xMask )
{
	StatusType ercd = E_OK;
	TCB* tcb=get_tcb(xTaskID);
	ID flgid=(ID)(tcb->exinf);
	if((xTaskID >= cfgOSEK_TASK_NUM+MIN_TSKID) ||
	   (xTaskID < MIN_TSKID))
	{
		ercd = E_OS_ID;
		goto Error_Exit;
	}
	if(flgid == (ID)NULL)
	{
		ercd = E_OS_ACCESS;
		goto Error_Exit;
	}
	ercd = tk_set_flg(flgid,xMask);
  Error_Exit:
	return ercd;
}

/* |------------------+---------------------------------------------------------| */
/* | Syntax:          | StatusType ClearEvent ( EventMaskType <Mask> )          | */
/* |------------------+---------------------------------------------------------| */
/* | Parameter (In)   | Mask:Mask of the events to be cleared                   | */
/* |------------------+---------------------------------------------------------| */
/* | Parameter (Out)  | none                                                    | */
/* |------------------+---------------------------------------------------------| */
/* | Description:     | The events of the extended task calling ClearEvent are  | */
/* |                  | cleared according to the event mask <Mask>.             | */
/* |------------------+---------------------------------------------------------| */
/* | Particularities: | The system service ClearEvent is restricted to extended | */
/* |                  | tasks which own the event.                              | */
/* |------------------+---------------------------------------------------------| */
/* | Status:          | Standard: 1.No error, E_OK                              | */
/* |                  | Extended: 1.Call not from extended task, E_OS_ACCESS    | */
/* |                  | 2.Call at interrupt level, E_OS_CALLEVEL                | */
/* |------------------+---------------------------------------------------------| */
/* | Conformance:     | ECC1, ECC2                                              | */
/* |------------------+---------------------------------------------------------| */
StatusType ClearEvent ( EventMaskType xMask )
{
	StatusType ercd = E_OK;
	ID flgid=(ID)(knl_ctxtsk->exinf);
	if(flgid == (ID)NULL)
	{
		ercd = E_OS_ACCESS;
		goto Error_Exit;
	}
	ercd = tk_clr_flg(flgid,~xMask);
  Error_Exit:
	return ercd;
}

/* |------------------+--------------------------------------------------------------| */
/* | Syntax:          | StatusType GetEvent ( TaskType <TaskID>                      | */
/* |                  | EventMaskRefType <Event> )                                   | */
/* |------------------+--------------------------------------------------------------| */
/* | Parameter (In):  | TaskID:Task whose event mask is to be returned.              | */
/* |------------------+--------------------------------------------------------------| */
/* | Parameter (Out): | Event:Reference to the memory of the return data.            | */
/* |------------------+--------------------------------------------------------------| */
/* | Description:     | 1.This service returns the current state of all event bits   | */
/* |                  | of the task <TaskID>, not the events that the task is        | */
/* |                  | waiting for.                                                 | */
/* |                  | 2.The service may be called from interrupt service routines, | */
/* |                  | task level and some hook routines (see Figure 12-1).         | */
/* |                  | 3.The current status of the event mask of task <TaskID> is   | */
/* |                  | copied to <Event>.                                           | */
/* |------------------+--------------------------------------------------------------| */
/* | Particularities: | The referenced task shall be an extended task.               | */
/* |------------------+--------------------------------------------------------------| */
/* | Status:          | Standard: No error, E_OK                                     | */
/* |                  | Extended: Task <TaskID> is invalid, E_OS_ID                  | */
/* |                  | Referenced task <TaskID> is not an extended task,            | */
/* |                  | E_OS_ACCESS                                                  | */
/* |                  | Referenced task <TaskID> is in the suspended state,          | */
/* |                  | E_OS_STATE                                                   | */
/* |------------------+--------------------------------------------------------------| */
/* | Conformance:     | ECC1, ECC2                                                   | */
/* |------------------+--------------------------------------------------------------| */
StatusType GetEvent ( TaskType xTaskID , EventMaskRefType pxEvent )
{
	StatusType ercd = E_OK;
	TCB* tcb=get_tcb(xTaskID);
	ID flgid=(ID)(tcb->exinf);
	FLGCB	*flgcb;
	if((xTaskID >= cfgOSEK_TASK_NUM+MIN_TSKID) ||
	   (xTaskID < MIN_TSKID))
	{
		ercd = E_OS_ID;
		goto Error_Exit;
	}
	if(flgid == (ID)NULL)
	{
		ercd = E_OS_ACCESS;
		goto Error_Exit;
	}
	flgcb = get_flgcb(flgid);
	*pxEvent = flgcb->flgptn;
  Error_Exit:
	return ercd;
}


/* |------------------+------------------------------------------------------------| */
/* | Syntax:          | StatusType WaitEvent ( EventMaskType <Mask> )              | */
/* |------------------+------------------------------------------------------------| */
/* | Parameter (In):  | Mask:Mask of the events waited for.                        | */
/* |------------------+------------------------------------------------------------| */
/* | Parameter (Out): | none                                                       | */
/* |------------------+------------------------------------------------------------| */
/* | Description:     | The state of the calling task is set to waiting, unless    | */
/* |                  | at least one of the events specified in <Mask> has         | */
/* |                  | already been set.                                          | */
/* |------------------+------------------------------------------------------------| */
/* | Particularities: | 1.This call enforces rescheduling, if the wait condition   | */
/* |                  | occurs. If rescheduling takes place, the internal resource | */
/* |                  | of the task is released while the task is in the waiting   | */
/* |                  | state.                                                     | */
/* |                  | 2.This service shall only be called from the extended task | */
/* |                  | owning the event.                                          | */
/* |------------------+------------------------------------------------------------| */
/* | Status:          | Standard:No error, E_OK                                    | */
/* |                  | Extended:Calling task is not an extended task, E_OS_ACCESS | */
/* |                  | Calling task occupies resources, E_OS_RESOURCE             | */
/* |                  | Call at interrupt level, E_OS_CALLEVEL                     | */
/* |------------------+------------------------------------------------------------| */
/* | Conformance:     | ECC1, ECC2                                                 | */
/* |------------------+------------------------------------------------------------| */
StatusType WaitEvent( EventMaskType xMask )
{
	UINT flgptn;
	StatusType ercd = E_OK;
	ID flgid=(ID)(knl_ctxtsk->exinf);
	if(flgid == (ID)NULL)
	{
		ercd = E_OS_ACCESS;
		goto Error_Exit;
	}
	ercd = tk_wai_flg(flgid,xMask,TWF_ORW,&flgptn,TMO_FEVR);
  Error_Exit:
	return ercd;
}

