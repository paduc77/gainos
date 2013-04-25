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
#include "Cpu.h"
static ER OsekCreateTasks(void)
{
	int i;
	ER ercd=E_OK;
	for(i=0;i<cfgOSEK_TASK_NUM;i++)
	{
		ercd = tk_cre_tsk((T_CTSK*)&OsekTaskTable[i]);
		if(ercd<E_OK)
		{
			/* tm_putstring((UB*)"At Cre."); */
			break;
		}
		if(OsekTaskAuotStartable[i])
		{
			ercd =tk_sta_tsk(ercd,ercd);
			if(ercd<E_OK)
			{
				/* tm_putstring((UB*)"At Sta."); */
				break;
			}
		}
	}
	/* if(ercd < E_OK) */
	/* { */
	/* 	tm_putstring((UB*)"Error while OsekCreateTasks().\r\n"); */
	/* } */
	return ercd;
}
static ER OsekCreateEntFlgs(void)
{
	int i;
	ER ercd = E_OK;
	static const T_CFLG cflg={NULL,TA_WSGL,0u,{'F','L','A','G','\0'}};
	for(i=0;i<cfgOSEK_EVENTFLAG_NUM;i++)
	{
		ercd = tk_cre_flg((T_CFLG*)&cflg);
		if(ercd<E_OK)
		{
			break;
		}
	}
	/* if(ercd < E_OK) */
	/* { */
	/* 	tm_putstring((UB*)"Error while OsekCreateEntFlgs().\r\n"); */
	/* } */
	return ercd;
}
static void OsekInitAlarms(void)
{
	int i;
	for(i=0;i<cfgOSEK_ALARM_NUM;i++)
	{
		OsekAlarmIdTable[i] = ALARM_NOT_IN_USE;
	}
}
static ER OsekCreateResources(void)
{
	int i;
	ER ercd=E_OK;
	for(i=0;i<cfgOSEK_RESOURCE_NUM;i++)
	{
		ercd = tk_cre_mtx((T_CMTX*)&OsekResourceTable[i]);
		if(ercd<E_OK)
		{
			break;
		}
	}
	/* if(ercd < E_OK) */
	/* { */
	/* 	tm_putstring((UB*)"Error while OsekCreateResources().\r\n"); */
	/* } */
	return ercd;
}
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
void StartOS ( AppModeType xAppMode )
{
	ER ercd;
	DISABLE_INTERRUPT;
	/* tm_putstring((UB*)"StartOS().\r\n"); */
	ercd=OsekCreateTasks();
	if(ercd < E_OK)
	{
		(void)ShutdownOS(ercd);
	}
	ercd = OsekCreateEntFlgs();
	if(ercd < E_OK)
	{
		(void)ShutdownOS(ercd);
	}
	OsekInitAlarms();
	ercd = OsekCreateResources();
	if(ercd < E_OK)
	{
		(void)ShutdownOS(ercd);
	}
#if(cfgOS_START_UP_HOOK == 1)
	StartupHook();			/* Call Start up hook */
#endif
    /* OS424: The first call to StartOS() (for starting the Operating System) shall not
       return. */
    OsekStartHighReadyTask();
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
/* |                  | Allowed at task level, ISR level, in ErrorHook and StartupHook,  | */
/* |                  | and also called internally by the operating system.              | */
/* |                  | If the operating system calls ShutdownOS it never uses E_OK      | */
/* |                  | as the passed parameter value.                                   | */
/* |------------------+------------------------------------------------------------------| */
/* | Conformance:     | BCC1, BCC2, ECC1, ECC2                                           | */
/* |------------------+------------------------------------------------------------------| */
void ShutdownOS( StatusType xError )
{
#if (cfgOS_SHUT_DOWN_HOOK == 1)
	ShutdownHook(xError);
#endif
/* OS425: If ShutdownOS() is called and ShutdownHook() returns then the operating
   system shall disable all interrupts and enter an endless loop. */
	/* tm_printf("Shut down OS because of error %d.\r\n",xError); */
	for ( ; ; )
    {
        /* Dead lopp here */
    }

}
