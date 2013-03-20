/*
 *----------------------------------------------------------------------
 *    micro T-Kernel
 *
 *    Copyright (C) 2006-2008 by Ken Sakamura. All rights reserved.
 *    micro T-Kernel is distributed under the micro T-License.
 *----------------------------------------------------------------------
 *
 *    Version:   1.01.00
 *    Released by T-Engine Forum(http://www.t-engine.org) at 2008/02/25.
 *
 *----------------------------------------------------------------------
 */

/*
 *	inittask_def.h
 *	Initial task definition
 */

#ifndef _INITTASK_DEF_
#define _INITTASK_DEF_

#include <basic.h>
#include <tk/tkernel.h>
#include "utk_config.h"

/*
 * Initial task parameter
 */
#define INITTASK_EXINF		(0x0)
#define INITTASK_TSKATR		(TA_HLNG | TA_RNG0)
#define INITTASK_ITSKPRI	(INIT_TASK_PRI)
#define INITTASK_STKSZ		(512)
#define INITTASK_DSNAME		"inittsk"
#define INITTASK_STACK		(NULL)

#endif /* _INITTASK_DEF_ */
