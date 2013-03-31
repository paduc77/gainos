/*
 *------------------------------------------------------------------------------
 *    Cpu
 *
 *    Copyright (C) 2008-2013 by Fan Wang(parai). All rights reserved.
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
 *	 File Name      : cpu_init.c
 *	 Create Date    : 2013/3/15-2013/3/17
 *	 Author	        : Fan Wang(parai)
 *	 Description    : CPU-Dependent Initialization/Finalization.
 *-------------------------------------------------------------------------------
 */

#include "kernel.h"
#include "task.h"
#include "cpu_insn.h"
#include "tkdev_conf.h"
#include "INTCInterrupts.h"

/* Temporal stack used when 'dispatch_to_schedtsk' is called */
Noinit(EXPORT	UINT	knl_tmp_stack[TMP_STACK_SZ]);

/*
 * CPU-dependent initialization
 */
IMPORT void knl_dispatch_entry(void);
LOCAL __asm void knl_install_sc_handler()
{
nofralloc	
    lis     r0, knl_dispatch_entry@h
    ori     r0, r0, knl_dispatch_entry@l
    /* IVOR8 System call interrupt (SPR 408) */
    mtivor8 r0	
    blr
}
EXPORT ER knl_cpu_initialize( void )
{
	knl_install_sc_handler();
	return E_OK;
}

#if USE_CLEANUP
/*
 * CPU-dependent finalization
 */
EXPORT void knl_cpu_shutdown( void )
{
}
#endif /* USE_CLEANUP */
