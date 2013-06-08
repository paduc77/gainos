/* Copyright(C) 2013, GaInOS-TK by Fan Wang. All rights reserved.
 *
 * This program is open source software; developer can redistribute it and/or
 * modify it under the terms of the U-License as published by the T-Engine China
 * Open Source Society; either version 1 of the License, or (at developer option)
 * any later Version.
 *
 * This program is distributed in the hope that it will be useful,but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE. See the U-License for more details.
 * Developer should have received a copy of the U-Licensealong with this program;
 * if not, download from www.tecoss.org(the web page of the T-Engine China Open
 * Source Society).
 *
 * GaInOS-TK is a static configured RTOS, which conformed to OSEK OS 2.2.3 Specification
 * and it is based on uTenux(http://www.uloong.cc).
 *
 * Email: parai@foxmail.com
 * Sourrce Open At: https://github.com/parai/gainos-tk/
 */
#ifndef VPORT_MACRO_H_H
#define VPORT_MACRO_H_H
/*
 * CPU interrupt control
 *	'intsts' is the value of PRIMASK in CPU
 *	disint()  Set PRIMASK = 1 and return the original PRIMASK
 *		  to the return value.
 *	enaint()  Set PRIMASK = intsts, Do not change except
 *		  for PRIMASK
 *		  Return the original PRIMASK to the return value.
 */
#define DI(intsts)	    ( (intsts) = disint() )
#define EI(intsts)	    ( (void)enaint(intsts) )
#define isDI(intsts)	( ((intsts) & 0x10) != 0 )

/*
 * Start/End critical section
 */
#define BEGIN_CRITICAL_SECTION	{ imask_t _primask_ = disint()
#define END_CRITICAL_SECTION	if ( !isDI(_primask_)			\
				  && knl_ctxtsk != knl_schedtsk		        	\
				  && !knl_isTaskIndependent()	            	\
				  && !knl_dispatch_disabled ) {		            \
					knl_dispatch();		                    	\
				}				                            	\
				enaint(_primask_); }

/*
 * Start/End interrupt disable section
 */
#define BEGIN_DISABLE_INTERRUPT	{ imask_t _primask_ = disint()
#define END_DISABLE_INTERRUPT	enaint(_primask_); }


/*
 * Interrupt enable/disable
 */
#define ENABLE_INTERRUPT	{ asm cli; }
#define DISABLE_INTERRUPT	{ asm sei; }

/*
 * Enable interrupt nesting
 *	Enable the interrupt that has a higher priority than 'level.'
 */
#define ENABLE_INTERRUPT_UPTO(level)	/* do nothing */

#define  knl_EnterTaskIndependent()	knl_taskindp++
#define  knl_LeaveTaskIndependent() knl_taskindp--
/*
 * Move to/Restore task independent part
 */
#define ENTER_TASK_INDEPENDENT	{ knl_EnterTaskIndependent(); }
#define LEAVE_TASK_INDEPENDENT	{ knl_LeaveTaskIndependent(); }

/* ----------------------------------------------------------------------- */
/*
 *	Check system state
 */
#define knl_isTaskIndependent() (( knl_taskindp > 0 ))
/*
 * When a system call is called from the task independent part, TRUE
 */
#define in_indp()	( knl_isTaskIndependent() || knl_ctxtsk == NULL )

/*
 * When a system call is called during dispatch disable, TRUE
 * Also include the task independent part as during dispatch disable.
 */
#define in_ddsp()	( knl_dispatch_disabled	\
			|| in_indp()		\
			|| isDI(knl_getPRIMASK()) )

/*
 * When a system call is called during CPU lock (interrupt disable), TRUE
 * Also include the task independent part as during CPU lock.
 */
#define in_loc()	( isDI(knl_getPRIMASK())		\
			|| in_indp() )

/*
 * When a system call is called during executing the quasi task part, TRUE
 * Valid only when in_indp() == FALSE because it is not discriminated from
 * the task independent part.
 */
#define in_qtsk()	( knl_ctxtsk->sysmode > knl_ctxtsk->isysmode )

/* ----------------------------------------------------------------------- */
/*
 *	Task dispatcher startup routine
 */

/*
 * Request for task dispatcher startup
 *	Do nothing at this point because there is no delayed
 *	interrupt function.
 *	Perform dispatcher startup with END_CRITICAL_SECTION.
 */
#define knl_dispatch_request()	/* */

#endif