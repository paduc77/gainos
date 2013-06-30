
/** \brief Free OSEK Conformance Test for the Alarms, Test Sequence 2
 **
 ** \file FreeOSEK/tst/ctest/src/ctest_al_02.c
 **/

/** \addtogroup FreeOSEK
 ** @{ */
/** \addtogroup FreeOSEK_CT Conformance Test
 ** @{ */
/** \addtogroup FreeOSEK_CT_AL Alarms
 ** @{ */
/** \addtogroup FreeOSEK_CT_AL_01 Test Sequence 2
 ** @{ */


/*
 * Initials     Name
 * ---------------------------
 * MaCe         Mariano Cerdeiro
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * 20090420 v0.1.0 MaCe initial version based on old moduletest
 */

/*==================[inclusions]=============================================*/
#include "os.h"				/* include os header file */
#include "test.h"	/* include test header file */
#include "ctest.h"			/* include ctest header file */

/*==================[macros and definitions]=================================*/

/*==================[internal data declaration]==============================*/

/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/
const uint32 SequenceCounterOk = MAX_SEQUENCE;

/*==================[internal functions definition]==========================*/

TASK(Task1)
{
	StatusType ret;
	AlarmBaseType AlarmBase;
	TickType Tick;

	ASSERT(OTHER, 0);
	
	Sequence(0);
	/* \treq AL_02 nmf B1B2E1E2 se call GetAlarmBase()
	 *
	 * \result Return alarm characteristics. Service returns E_OK
	 */
	ret = GetAlarmBase(Alarm1, &AlarmBase);
	ASSERT(AL_02, ret != E_OK);

	Sequence(1);
	/* \treq AL_04 nmf B1B2E1E2 se call GetAlarm() for alarm which is currently
	 * not in use
	 *
	 * \result Service returns E_OS_NOFUNC
	 */
	ret = GetAlarm(Alarm1, &Tick);
	ASSERT(AL_04, ret != E_OS_NOFUNC);

	Sequence(2);
	/* \treq AL_26 nmf B1B2E1E2 se call CancelAlarm() for alarm which is currently
	 * not in use
	 *
	 * \result Service returns E_OS_NOFUNC
	 */
	ret = CancelAlarm(Alarm1);
	ASSERT(AL_26, ret != E_OS_NOFUNC);

	Sequence(3);
	InitAlarmCounter();

	Sequence(4);
	/* \treq AL_23 nmf B1B2E1E2 se call SetAbsAlarm() for alarm which will
	 * activate a task on expiration
	 *
	 * \result Alarms is activated. Service returns E_OK
	 */
	ret = SetAbsAlarm(Alarm1, 1, 1);
	ASSERT(AL_23, ret != E_OK);

	Sequence(5);
	/* \treq AL_17 nmf B1B2E1E2 se call SetAbsAlarm() for already activated
	 * alarm which will activate a task on expiration
	 *
	 * \result Service returns E_OS_STATE
	 */
	ret = SetAbsAlarm(Alarm1, 3, 0);
	ASSERT(AL_17, ret != E_OS_STATE);

	Sequence(6);
	IncAlarmCounter();

//#if (CT_SCHEDULING_Task1 == CT_NON_PREEMPTIVE)
	/* force scheduling */
	Schedule();
//#endif /* #if (CT_SCHEDULING_TASK1 == CT_NON_PREEMPTIVE) */

	Sequence(8);
	IncAlarmCounter();

//#if (CT_SCHEDULING_Task1 == CT_NON_PREEMPTIVE)
	/* force scheduling */
	Schedule();
//#endif /* #if (CT_SCHEDULING_TASK1 == CT_NON_PREEMPTIVE) */

	Sequence(10);
	/* \treq AL_27 nmf B1B2E1E2 se call CancelAlarm() for already activated
	 * alarm which will activate a task on expiration	 
	 *
	 * \result Alarm is cancelled. Service returns E_OK
	 */
	ret = CancelAlarm(Alarm1);
	ASSERT(AL_27, ret != E_OK);

	Sequence(11);
	/* \treq AL_14 nmf B1B2E1E2 se call SetRelAlarm() for alarm which will
	 * activate a task on expiration
	 *
	 * \result Alarms is activated. Service returns E_OK
	 */
	ret = SetRelAlarm(Alarm1, 1, 0);
	ASSERT(AL_14, ret != E_OK);

	Sequence(12);
	/* \treq AL_08 nmf B1B2E1E2 se call SetRelAlarm() for already activated
	 * alarm which will activate a task on expiration
	 *
	 * \result Service returns E_OS_STATE
	 */
	ret = SetRelAlarm(Alarm1, 2, 0);
	ASSERT(AL_08, ret != E_OS_STATE);

	Sequence(13);
	/* \treq AL_05 nmf B1B2E1E2 se call GetAlarm() for alarm which will activate
	 * a task on expiration
	 *
	 * \result Return number of ticks until expiration. Service returns E_OK
	 */
	ret = GetAlarm(Alarm1, &Tick);
	ASSERT(AL_05, ret != E_OK);
	ASSERT(AL_05, Tick != 1);

	Sequence(14);
	IncAlarmCounter();

//#if (CT_SCHEDULING_Task1 == CT_NON_PREEMPTIVE)
	/* force scheduling */
	Schedule();
//#endif /* #if (CT_SCHEDULING_TASK1 == CT_NON_PREEMPTIVE) */

	Sequence(16);

	/* evaluate conformance tests */
	ConfTestEvaluation();

	/* finish the conformance test */
	ConfTestFinish();
}

TASK(Task2)
{
	static uint8 count = 0;

	switch (count)
	{
		case 0:
			/* increment call counter */
			count++;

			Sequence(7);
			TerminateTask();
			break;
		case 1:
			/* increment call counter */
			count++;

			Sequence(9);
			TerminateTask();
			break;
		case 2:
			/* increment call counter */
			count++;

			Sequence(15);
			TerminateTask();
			break;
		default:
			while(1);
			break;
	}
}


/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

