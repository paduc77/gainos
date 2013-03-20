/*
 *------------------------------------------------------------------------------
 *    Include/tk
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
 *    CPU:        CORTEX M4
 *    RTOS:       uT-Kernel
 *    Version:    1.4.00
 *    Released by T-Engine China Open Source Society
 *                  (http://www.tecoss.org).
 *
 *	 File Name      : dbgspt_depend.h
 *	 Create Date    : 2012/9/6-2012/11/30
 *	 Author	        : Zhangzl-Zhangzl
 *	 Description    : micro T-Kernel Debugger Support System-Dependent Definition(tk/XMC4000) .
 *-------------------------------------------------------------------------------
 */

#ifndef __TK_DBGSPT_DEPEND_H__
#define __TK_DBGSPT_DEPEND_H__

#ifdef __cplusplus
extern "C" {
#endif

/*
 * System call/extension SVC caller information
 */
typedef struct td_calinf {
	VP	ssp;		/* Main stack pointer */
	VP	r11;		/* Frame pointer when calling */
} TD_CALINF;

#ifdef __cplusplus
}
#endif
#endif /* __TK_DBGSPT_DEPEND_H__ */
