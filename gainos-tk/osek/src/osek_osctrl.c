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
#include "osek_os.h"
#include "knl_task.h"
#include "knl_alarm.h"
#include "knl_event.h"
#include "knl_resource.h"
#include "knl_timer.h"
#include "portable.h"

#if(cfgOS_ERROR_HOOK == STD_ON)
EXPORT OSServiceIdType	_errorhook_svcid;
EXPORT _ErrorHook_Par	_errorhook_par1, _errorhook_par2, _errorhook_par3;
#endif
/* |------------------+------------------------------------------------------| */
/* | Syntax:          | void StartOS ( AppModeType <Mode> )                  | */
/* |------------------+------------------------------------------------------| */
/* | Parameter (In):  | Mode:application mode                                | */
/* |------------------+------------------------------------------------------| */
/* | Parameter (Out): | none                                                 | */
/* |------------------+------------------------------------------------------| */
/* | Description:     | The user can call this system service to start the   | */
/* |                  | operating system in a specific mode, see chapter 5   | */
/* |                  | (os223.doc), Application modes.                      | */
/* |------------------+------------------------------------------------------| */
/* | Particularities: | Only allowed outside of the operating system,        | */
/* |                  | therefore implementation specific restrictions may   | */
/* |                  | apply. See also chapter 11.3, System start-up,       | */
/* |                  | especially with respect to systems where OSEK and    | */
/* |                  | OSEKtime coexist. This call does not need to return. | */
/* |------------------+------------------------------------------------------| */
/* | Conformance:     | BCC1, BCC2, ECC1, ECC2                               | */
/* |------------------+------------------------------------------------------| */
void StartOS ( AppModeType AppMode )
{
    DISABLE_INTERRUPT;
    knl_app_mode =  AppMode;
    #if(cfgOSEK_ALARM_NUM > 0)
    knl_cntalm_init();
    #endif
    knl_resource_init();
	knl_task_init();

#if(cfgOS_START_UP_HOOK == STD_ON)
	StartupHook();			/* Call Start up hook */
#endif
#if(cfgOS_TK_EXTEND == STD_ON)
    knl_timer_init();
#else
    knl_start_hw_timer();     
#endif
    /* OS424: The first call to StartOS() (for starting the Operating System) shall not
       return. */ 
    #if(cfgOS_SHARE_SYSTEM_STACK == STD_ON)
    knl_start_dispatch();
    #else 
    knl_force_dispatch();
    #endif
}

/* |------------------+------------------------------------------------------------------| */
/* | Syntax:          | void ShutdownOS ( StatusType <Error> )                           | */
/* |------------------+------------------------------------------------------------------| */
/* | Parameter (In):  | Error:error occurred                                             | */
/* |------------------+------------------------------------------------------------------| */
/* | Parameter (Out): | none                                                             | */
/* |------------------+------------------------------------------------------------------| */
/* | Description:     | 1.The user can call this system service to abort                 | */
/* |                  | the overall system (e.g. emergency off). The                     | */
/* |                  | operating system also calls this function internally,            | */
/* |                  | if it has reached an undefined internal state and is             | */
/* |                  | no longer ready to run.                                          | */
/* |                  | 2.If a ShutdownHook is configured the hook routine               | */
/* |                  | ShutdownHook is always called (with <Error> as argument)         | */
/* |                  | before shutting down the operating system.                       | */
/* |                  | 3.If ShutdownHook returns, further behaviour of ShutdownOS       | */
/* |                  | is implementation specific.                                      | */
/* |                  | 4.In case of a system where OSEK OS and OSEKtime OS coexist,     | */
/* |                  | ShutdownHook has to return. <Error> needs to be a valid          | */
/* |                  | error code supported by OSEK OS.                                 | */
/* |                  | 5.In case of a system where OSEK OS and OSEKtime OS coexist,     | */
/* |                  | <Error> might also be a value accepted by OSEKtime OS.           | */
/* |                  | In this case, if enabled by an OSEKtime configuration parameter, | */
/* |                  | OSEKtime OS will be shut down after OSEK OS shutdown.            | */
/* |------------------+------------------------------------------------------------------| */
/* | Particularities: | After this service the operating system is shut down.            | */
/* |                  | Allowed at task level, ISR level, in CallErrorHook and StartupHook,  | */
/* |                  | and also called internally by the operating system.              | */
/* |                  | If the operating system calls ShutdownOS it never uses E_OK      | */
/* |                  | as the passed parameter value.                                   | */
/* |------------------+------------------------------------------------------------------| */
/* | Conformance:     | BCC1, BCC2, ECC1, ECC2                                           | */
/* |------------------+------------------------------------------------------------------| */
void ShutdownOS( StatusType Error )
{
    DISABLE_INTERRUPT;
#if (cfgOS_SHUT_DOWN_HOOK == STD_ON)
	ShutdownHook(Error);
#endif
/* OS425: If ShutdownOS() is called and ShutdownHook() returns then the operating
   system shall disable all interrupts and enter an endless loop. */
	for ( ; ; )
    {
        /* Dead lopp here */
    }

}

//get the os active application mode
AppModeType GetActiveApplicationMode(void)
{
    return knl_app_mode;
}

#if defined(cfgOSEK_STD_ISR_PROCESS)
/* For Arm Cortex M3, terrible. So I move them to portableS.S */
/* For others, define cfgOSEK_STD_ISR_PROCESS in your compiler pre-processor */
void EnterISR(void)
{
    knl_taskindp++;/* Enter Task Independedt Part */
    ENABLE_INTERRUPT;
}

void ExitISR(void)
{
    DISABLE_INTERRUPT;
    if(knl_taskindp > 0)
    {
        knl_taskindp--;
    }
    if((!in_indp()) && (!knl_dispatch_disabled))
    {
        if(knl_ctxtsk != knl_schedtsk)
        {
            knl_isr_dispatch();
        }
    }
    ENABLE_INTERRUPT;
}
#endif

#if(cfgOS_ERROR_HOOK == STD_ON)
void CallErrorHook(StatusType ercd)
{
    static call_count = 0;
    call_count++;
    if(1 == call_count)
    {
        ErrorHook(ercd);
    }
    call_count--;    
}
#endif
