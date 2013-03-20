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
 *	@(#)syslib_common.h (tk)
 *
 *	System Library
 */

#ifndef __TK_SYSLIB_COMMON_H__
#define __TK_SYSLIB_COMMON_H__

/*
 * CPU-dependent
 */
#ifdef _APP_AT91SAM3_
#  include <tk/sysdepend/app_at91sam3/syslib_depend.h>
#endif

#ifdef _APP_AT91SAM4_
#  include <tk/sysdepend/app_at91sam4/syslib_depend.h>
#endif

#ifdef _APP_AT91SAM7_
#  include <tk/sysdepend/app_at91sam7/syslib_depend.h>
#endif

#ifdef _APP_STM32F1_
#  include <tk/sysdepend/app_stm32f1/syslib_depend.h>
#endif

#ifdef _APP_STM32F4_
#  include <tk/sysdepend/app_stm32f4/syslib_depend.h>
#endif

#ifdef _APP_LPC17_
#  include <tk/sysdepend/app_lpc17/syslib_depend.h>
#endif

#ifdef _APP_LPC18_
#  include <tk/sysdepend/app_lpc18/syslib_depend.h>
#endif

#ifdef _APP_MK60_
#  include <tk/sysdepend/app_mk60/syslib_depend.h>
#endif

#ifdef _APP_LM3S_
#  include <tk/sysdepend/app_lm3s/syslib_depend.h>
#endif

#ifdef _APP_LM4F_
#  include <tk/sysdepend/app_lm4f/syslib_depend.h>
#endif

#ifdef _APP_EFM32G_
#  include <tk/sysdepend/app_efm32g/syslib_depend.h>
#endif

#ifdef _APP_MB9BF5_
#  include <tk/sysdepend/app_mb9bf5/syslib_depend.h>
#endif

#ifdef _APP_XMC4000_
#  include <tk/sysdepend/app_xmc4000/syslib_depend.h>
#endif

#ifdef _APP_SIM3_
#  include <tk/sysdepend/app_sim3/syslib_depend.h>
#endif

#ifdef _APP_MC9S12_
#  include <tk/sysdepend/app_mc9s12/syslib_depend.h>
#endif

#ifdef _APP_MPC56XX_
#  include <tk/sysdepend/app_mpc56xx/syslib_depend.h>
#endif

#endif /* __TK_SYSLIB_COMMON_H__ */
