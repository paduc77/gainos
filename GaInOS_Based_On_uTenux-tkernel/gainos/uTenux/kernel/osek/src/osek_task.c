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
#include "kernel.h"
#include "task.h"
#include "wait.h"
#include "check.h"
#include "cpu_task.h"
/* |------------------+------------------------------------------------------------| */
/* | Syntax:          | StatusType ActivateTask ( TaskType <TaskID> )              | */
/* |------------------+------------------------------------------------------------| */
/* | Parameter (In):  | TaskID: Task reference                                     | */
/* |------------------+------------------------------------------------------------| */
/* | Parameter (Out): | none                                                       | */
/* |------------------+------------------------------------------------------------| */
/* | Description:     | The task <TaskID> is transferred from the suspended state  | */
/* |                  | into the ready state. The operating system ensures that    | */
/* |                  | the task code is being executed from the first statement.  | */
/* |------------------+------------------------------------------------------------| */
/* | Particularities: | 1) The service may be called from interrupt level and from | */
/* |                  | task level (see Figure 12-1(os223.doc)).                   | */
/* |                  | 2) Rescheduling after the call to ActivateTask depends on  | */
/* |                  | the place it is called from (ISR, non preemptable task,    | */
/* |                  | preemptable task).                                         | */
/* |                  | 3)If E_OS_LIMIT is returned the activation is ignored.     | */
/* |                  | 4)When an extended task is transferred from suspended      | */
/* |                  | state into ready state all its events are cleared.         | */
/* |------------------+------------------------------------------------------------| */
/* | Status:          | Standard:                                                  | */
/* |                  | 1) No error, E_OK                                          | */
/* |                  | 2) Too many task activations of <TaskID>, E_OS_LIMIT       | */
/* |                  | Extended:                                                  | */
/* |                  | 1) Task <TaskID> is invalid, E_OS_ID                       | */
/* |------------------+------------------------------------------------------------| */
/* | Conformance:     | BCC1, BCC2, ECC1, ECC2                                     | */
/* |------------------+------------------------------------------------------------| */
StatusType ActivateTask ( TaskType xTaskID )
{
	StatusType ercd = E_OK;
	ercd=tk_sta_tsk(xTaskID,/*stacd*/xTaskID);
	return ercd;
}

/* |------------------+--------------------------------------------------------------| */
/* | Syntax:          | StatusType TerminateTask ( void )                            | */
/* |------------------+--------------------------------------------------------------| */
/* | Parameter (In):  | none                                                         | */
/* |------------------+--------------------------------------------------------------| */
/* | Parameter (Out): | none                                                         | */
/* |------------------+--------------------------------------------------------------| */
/* | Description:     | This service causes the termination of the calling task. The | */
/* |                  | calling task is transferred from the running state into the  | */
/* |                  | suspended state.                                             | */
/* |------------------+--------------------------------------------------------------| */
/* | Particularities: | 1) An internal resource assigned to the calling task is      | */
/* |                  | automatically released. Other resources occupied by the task | */
/* |                  | shall have been released before the call to TerminateTask.   | */
/* |                  | If a resource is still occupied in standard status the       | */
/* |                  | behaviour is undefined.                                      | */
/* |                  | 2) If the call was successful, TerminateTask does not return | */
/* |                  | to the call level and the status can not be evaluated.       | */
/* |                  | 3) If the version with extended status is used, the service  | */
/* |                  | returns in case of error, and provides a status which can be | */
/* |                  | evaluated in the application.                                | */
/* |                  | 4) If the service TerminateTask is called successfully, it   | */
/* |                  | enforces a rescheduling.                                     | */
/* |                  | 5) Ending a task function without call to TerminateTask or   | */
/* |                  | ChainTask is strictly forbidden and may leave the system in  | */
/* |                  | an undefined state.                                          | */
/* |------------------+--------------------------------------------------------------| */
/* | Status:          | Standard:                                                    | */
/* |                  | 1)No return to call level                                    | */
/* |                  | Extended:                                                    | */
/* |                  | 1) Task still occupies resources, E_OS_RESOURCE              | */
/* |                  | 2) Call at interrupt level, E_OS_CALLEVEL                    | */
/* |------------------+--------------------------------------------------------------| */
/* | Conformance:     | BCC1, BCC2, ECC1, ECC2                                       | */
/* |------------------+--------------------------------------------------------------| */
StatusType TerminateTask ( void )
{
	StatusType ercd = E_NOT_OK;
	tk_ext_tsk();
	return ercd;
}

/* |------------------+-------------------------------------------------------------| */
/* | Syntax:          | StatusType ChainTask ( TaskType <TaskID> )                  | */
/* |------------------+-------------------------------------------------------------| */
/* | Parameter (In):  | TaskID Reference to the sequential succeeding task to       | */
/* |                  | be activated.                                               | */
/* |------------------+-------------------------------------------------------------| */
/* | Parameter (Out): | none                                                        | */
/* |------------------+-------------------------------------------------------------| */
/* | Description:     | This service causes the termination of the calling task.    | */
/* |                  | After termination of the calling task a succeeding task     | */
/* |                  | <TaskID> is activated. Using this service, it ensures       | */
/* |                  | that the succeeding task starts to run at the earliest      | */
/* |                  | after the calling task has been terminated.                 | */
/* |------------------+-------------------------------------------------------------| */
/* | Particularities: | 1. If the succeeding task is identical with the current     | */
/* |                  | task, this does not result in multiple requests. The task   | */
/* |                  | is not transferred to the suspended state, but will         | */
/* |                  | immediately become ready again.                             | */
/* |                  | 2. An internal resource assigned to the calling task is     | */
/* |                  | automatically released, even if the succeeding task is      | */
/* |                  | identical with the current task. Other resources occupied   | */
/* |                  | by the calling shall have been released before ChainTask    | */
/* |                  | is called. If a resource is still occupied in standard      | */
/* |                  | status the behaviour is undefined.                          | */
/* |                  | 3. If called successfully, ChainTask does not return to     | */
/* |                  | the call level and the status can not be evaluated.         | */
/* |                  | 4. In case of error the service returns to the calling      | */
/* |                  | task and provides a status which can then be evaluated      | */
/* |                  | in the application.                                         | */
/* |                  | 5.If the service ChainTask is called successfully, this     | */
/* |                  | enforces a rescheduling.                                    | */
/* |                  | 6. Ending a task function without call to TerminateTask     | */
/* |                  | or ChainTask is strictly forbidden and may leave the system | */
/* |                  | in an undefined state.                                      | */
/* |                  | 7. If E_OS_LIMIT is returned the activation is ignored.     | */
/* |                  | 8. When an extended task is transferred from suspended      | */
/* |                  | state into ready state all its events are cleared.          | */
/* |------------------+-------------------------------------------------------------| */
/* | Status:          | Standard:                                                   | */
/* |                  | 1. No return to call level                                  | */
/* |                  | 2. Too many task activations of <TaskID>, E_OS_LIMIT        | */
/* |                  | Extended:                                                   | */
/* |                  | 1. Task <TaskID> is invalid, E_OS_ID                        | */
/* |                  | 2. Calling task still occupies resources, E_OS_RESOURCE     | */
/* |                  | 3. Call at interrupt level, E_OS_CALLEVEL                   | */
/* |------------------+-------------------------------------------------------------| */
/* | Conformance:     | BCC1, BCC2, ECC1, ECC2                                      | */
/* |------------------+-------------------------------------------------------------| */
StatusType ChainTask ( TaskType xTaskID )
{
	StatusType ercd;
#ifdef DORMANT_STACK_SIZE
	/* To avoid destroying stack used in 'knl_make_dormant',
	   allocate the dummy area on the stack. */
	volatile VB _dummy[DORMANT_STACK_SIZE];
#endif

	/* Check context error */
#if CHK_CTX2
	if ( in_indp() ) {
#if USE_KERNEL_MESSAGE
		tm_putstring((UB*)"ChainTask was called in the task independent\n");
#endif
		tm_monitor(); /* To monitor */
	}
#endif
#if CHK_CTX1
	if ( in_ddsp() ) {
#if USE_KERNEL_MESSAGE
		tm_putstring((UB*)"ChainTask was called in the dispatch disabled\n");
#endif
	}
#endif

	DISABLE_INTERRUPT;
	ercd = tk_sta_tsk(xTaskID,xTaskID);
	if(ercd < E_OK)
	{
		ENABLE_INTERRUPT;
		return ercd;
	}
	knl_ter_tsk(knl_ctxtsk);
	knl_make_dormant(knl_ctxtsk);

	knl_force_dispatch();
	/* No return */

#ifdef DORMANT_STACK_SIZE
	/* for WARNING */
	_dummy[0] = 0;
#endif
}

/* |------------------+-------------------------------------------------------------| */
/* | Syntax:          | StatusType Schedule ( void )                                | */
/* |------------------+-------------------------------------------------------------| */
/* | Parameter (In):  | none                                                        | */
/* |------------------+-------------------------------------------------------------| */
/* | Parameter (Out): | none                                                        | */
/* |------------------+-------------------------------------------------------------| */
/* | Description:     | If a higher-priority task is ready, the internal resource   | */
/* |                  | of the task is released, the current task is put into the   | */
/* |                  | ready state, its context is saved and the higher-priority   | */
/* |                  | task is executed. Otherwise the calling task is continued.  | */
/* |------------------+-------------------------------------------------------------| */
/* | Particularities: | Rescheduling only takes place if the task an internal       | */
/* |                  | resource is assigned to the calling task during             | */
/* |                  | system generation. For these tasks, Schedule enables a      | */
/* |                  | processor assignment to other tasks with lower or equal     | */
/* |                  | priority than the ceiling priority of the internal resource | */
/* |                  | and higher priority than the priority of the calling task   | */
/* |                  | in application-specific locations. When returning from      | */
/* |                  | Schedule, the internal resource has been taken again.       | */
/* |                  | This service has no influence on tasks with no internal     | */
/* |                  | resource assigned (preemptable tasks).                      | */
/* |------------------+-------------------------------------------------------------| */
/* | Status:          | Standard:                                                   | */
/* |                  | 1. No error, E_OK                                           | */
/* |                  | Extended:                                                   | */
/* |                  | 1. Call at interrupt level, E_OS_CALLEVEL                   | */
/* |                  | 2. Calling task occupies resources, E_OS_RESOURCE           | */
/* |------------------+-------------------------------------------------------------| */
/* | Conformance:     | BCC1, BCC2, ECC1, ECC2                                      | */
/* |------------------+-------------------------------------------------------------| */
StatusType Schedule ( void )
{
	return E_OK;
}

/* |------------------+---------------------------------------------------------| */
/* | Syntax:          | StatusType GetTaskID ( TaskRefType <TaskID> )           | */
/* |------------------+---------------------------------------------------------| */
/* | Parameter (In):  | none                                                    | */
/* |------------------+---------------------------------------------------------| */
/* | Parameter (Out): | TaskID Reference to the task which is currently running | */
/* |------------------+---------------------------------------------------------| */
/* | Description:     | GetTaskID returns the information about the TaskID of   | */
/* |                  | the task which is currently running.                    | */
/* |------------------+---------------------------------------------------------| */
/* | Particularities: | 1. Allowed on task level, ISR level and in several hook | */
/* |                  | routines (see Figure 12-1(os223)).                      | */
/* |                  | 2. This service is intended to be used by library       | */
/* |                  | functions and hook routines.                            | */
/* |                  | 3. If <TaskID> can't be evaluated (no task currently    | */
/* |                  | running), the service returns INVALID_TASK as TaskType. | */
/* |------------------+---------------------------------------------------------| */
/* | Status:          | Standard:  No error, E_OK                               | */
/* |                  | Extended:  No error, E_OK                               | */
/* |------------------+---------------------------------------------------------| */
/* | Conformance:     | BCC1, BCC2, ECC1, ECC2                                  | */
/* |------------------+---------------------------------------------------------| */
StatusType GetTaskID ( TaskRefType pxTask )
{
	*pxTask = tk_get_tid();
	return E_OK;
}

/* |------------------+-------------------------------------------------------| */
/* | Syntax:          | StatusType GetTaskState ( TaskType <TaskID>,          | */
/* |                  | TaskStateRefType <State> )                            | */
/* |------------------+-------------------------------------------------------| */
/* | Parameter (In):  | TaskID: Task reference                                | */
/* |------------------+-------------------------------------------------------| */
/* | Parameter (Out): | State: Reference to the state of the task <TaskID>    | */
/* |------------------+-------------------------------------------------------| */
/* | Description:     | Returns the state of a task (running, ready, waiting, | */
/* |                  | suspended) at the time of calling GetTaskState.       | */
/* |------------------+-------------------------------------------------------| */
/* | Particularities: | The service may be called from interrupt service      | */
/* |                  | routines, task level, and some hook routines (see     | */
/* |                  | Figure 12-1(os223.doc)). When a call is made from a   | */
/* |                  | task in a full preemptive system, the result may      | */
/* |                  | already be incorrect at the time of evaluation.       | */
/* |                  | When the service is called for a task, which is       | */
/* |                  | activated more than once, the state is set to         | */
/* |                  | running if any instance of the task is running.       | */
/* |------------------+-------------------------------------------------------| */
/* | Status:          | Standard: No error, E_OK                              | */
/* |                  | Extended: Task <TaskID> is invalid, E_OS_ID           | */
/* |------------------+-------------------------------------------------------| */
/* | Conformance:     | BCC1, BCC2, ECC1, ECC2                                | */
/* |------------------+-------------------------------------------------------| */
StatusType GetTaskState ( TaskType xTaskID,TaskStateRefType pxState )
{
	TCB	*tcb;
	TSTAT	state;
	StatusType	ercd = E_OK;
	tcb = get_tcb_self(xTaskID);
	BEGIN_CRITICAL_SECTION;
	state = (TSTAT)tcb->state;
	if ( state == TS_NONEXIST ) {
		ercd = E_OS_ID;
	} else {
		if ( ( state == TS_READY ) && ( tcb == knl_ctxtsk ) ) {
			*pxState = RUNNING;
		} else {
			*pxState = (UB)state << 1;
		}
	}
	END_CRITICAL_SECTION;
	return ercd;
}
StatusType DelayTask(RELTIM dlytim)
{
	StatusType ercd;
	ercd = tk_dly_tsk(dlytim);
	return ercd;
}
StatusType SleepTask(TMO tmout)
{
	StatusType ercd;
	ercd = tk_slp_tsk(tmout);
	return ercd;
}
StatusType WakeUpTask(ID xTask)
{
	StatusType ercd;
	ercd = tk_wup_tsk(xTask);
	return ercd;
}
