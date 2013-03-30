/*
 *------------------------------------------------------------------------------
 *    Cpu
 *
 *    Copyright (C) 2008-2013 by Dalian uLoong Co.,Ltd. All rights reserved.
 *
 *    This program is open source software; developer can redistribute it and/or
 *    modify it under the terms of the U-License as published by the T-Engine China
 *    Open Source Society; either version 1 of the License, or (at developer option)
 *    any later Version.
 *
 *    This program is distributed in the hope that it will be useful,but WITHOUT ANY
 *    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 *    A PARTICULAR PURPOSE.  See the U-License for more details.
 *
 *    Developer should have received a copy of the U-License along with this program;
 *    if not, download from www.tecoss.org(the web page of the T-Engine China Open
 *    Source Society).
 *
 *    CPU:        MC9S12
 *    RTOS:       uT-Kernel
 *    Version:    1.4.00
 *
 *	 File Name      : cpu_task.h
 *	 Create Date    : 2013/3/15-2013/3/17
 *	 Author	        : Fan Wang(parai)
 *	 Description    : CPU-Dependent Task Start Processing.
 *-------------------------------------------------------------------------------
 */

#ifndef _CPU_TASK_
#define _CPU_TASK_

#include "cpu_insn.h"

/*
 * System stack configuration at task startup
 */
typedef struct {
    VB ppage;
    VH taskmode;
    VB ccr;
    VB b;   /* exinfL */
    VB a;   /* exinfH */
    VH x;
    VH y;
    VH pc;
    VB rtn[3];  /* dummy return address with ppage */
    VH stacd;
} SStackFrame;

/*
 * Size of system stack area destroyed by 'make_dormant()'
 * In other words, the size of area required to write by 'setup_context().'
 */
#define DORMANT_STACK_SIZE	( sizeof(VW) * 3 )	/* To 'PC' position */


/*
 * Create stack frame for task startup
 *	Call from 'make_dormant()'
 */
IMPORT void knl_setup_context( TCB *tcb );

/*
 * Set task startup code
 *	Called by 'tk_sta_tsk()' processing.
 */
IMPORT void knl_setup_stacd( TCB *tcb, INT stacd );

/*
 * Delete task contexts
 */
IMPORT void knl_cleanup_context( TCB *tcb );

#endif /* _CPU_TASK_ */
