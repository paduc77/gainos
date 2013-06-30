
/** \brief Free OSEK Conformance Test for the Event Mechanism, Test Sequence 1
 **
 ** \file FreeOSEK/tst/ctest/src/ctest_em_01.c
 **/

/** \addtogroup FreeOSEK
 ** @{ */
/** \addtogroup FreeOSEK_CT Conformance Test
 ** @{ */
/** \addtogroup FreeOSEK_CT_EM Event Mechanism
 ** @{ */
/** \addtogroup FreeOSEK_CT_EM_01 Test Sequence 1
 ** @{ */


/*
 * Initials     Name
 * ---------------------------
 * MaCe         Mariano Cerdeiro
 */

/*
 * modification history (new versions first)
 * -----------------------------------------------------------
 * 20090417 v0.1.0 MaCe initial version based on old moduletest
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

/*==================[external functions definition]==========================*/

TASK(Task1)
{
	StatusType ret;
	EventMaskType EventMask;

	Sequence(0);
	/* enable interrupts ISR2 and ISR3 */
	/* nothing to do */

	Sequence(1);
	/* \treq EM_01 nmf E1E2 e Call SetEvent() with an invalid Task ID
	 *
	 * \result Service returns E_OS_ID
	 */
	ret = SetEvent(INVALID_TASK, Event1);
	ASSERT(EM_01, ret != E_OS_ID);

	Sequence(2);
	/* \treq EM_02 nmf E1E2 e Call SetEvent() for basic task
	 *
	 * \result Service returns E_OS_ACCESS
	 */
	ret = SetEvent(Task1, Event1);
	ASSERT(EM_02, ret != E_OS_ACCESS);

	Sequence(3);
	/* \treq EM_03 nmf E1E2 e Call SetEvent() for suspended extended task
	 *
	 * \result Service returns E_OS_STATE
	 */
	ret = SetEvent(Task2, Event1);
	ASSERT(EM_03, ret != E_OS_STATE);

	Sequence(4);
	/* \treq EM_11 nmf E1E2 e Call ClearEvent() from basic task
	 *
	 * \result Service returns E_OS_ACCESS
	 */
	ret = ClearEvent(Event1);
	ASSERT(EM_11, ret != E_OS_ACCESS);

	Sequence(5);
	/*  trigger ISR 2 */
	TriggerISR2();

#if ( ISR_CATEGORY_3 == ENABLE )
	/* trigger ISR 3 */
	TriggerISR3();
#endif /* #if ( ISR_CATEGORY_3 == ENABLE ) */

	Sequence(8);
	/* \treq EM_15 nmf E1E2 e Call GetEvent() with invalid Task ID
	 *
	 * \result Service returns E_OS_ID
	 */
	ret = GetEvent(INVALID_TASK, &EventMask);
	ASSERT(EM_15, ret != E_OS_ID);

	Sequence(9);
	/* \treq EM_16 nmf E1E2 e Call GetEvent() from basic task
	 *
	 * \result Service returns E_OS_ACCESS
	 */
	ret = GetEvent(Task1, &EventMask);
	ASSERT(EM_16, ret != E_OS_ACCESS);

	Sequence(10);
	/* \treq EM_17 nmf E1E2 e Call GetEvent() from suspended extended task
	 *
	 * \result Service returns E_OS_STATE
	 */
	ret = GetEvent(Task2, &EventMask);
	ASSERT(EM_17, ret != E_OS_STATE);

	Sequence(11);
	/* \treq EM_21 nmf E1E2 e Call WaitEvent() from basic task
	 *
	 * \result Service returns E_OS_ACCESS
	 */
	ret = WaitEvent(Event1);
	ASSERT(EM_21, ret != E_OS_ACCESS);

	Sequence(12);
	ChainTask(Task2);
}

TASK(Task2)
{
	StatusType ret;

	Sequence(13);
	ret = GetResource(Resource1);
	ASSERT(OTHER, ret != E_OK);

	Sequence(14);
	/* \treq EM_22 nmf E1E2 e Call WaitEvent() from extended task with occupies
	 * resource
	 *
	 * \result Service returns E_OS_RESOURCE
	 */
	ret = WaitEvent(Event1);
	ASSERT(EM_22, ret != E_OS_RESOURCE);
	
	Sequence(15);
	ret = ReleaseResource(Resource1);
	ASSERT(OTHER, ret != E_OK);

	Sequence(16);

	/* evaluate conformance tests */
	ConfTestEvaluation();

	/* finish the conformance test */
	ConfTestFinish();
}

ISR(ISR2)
{
	StatusType ret;
	EnterISR();	//only ISR category: 2 was supported by gainos-tk
	Sequence(6);
	/* \treq EM_12 nmf E1E2 e Call ClearEvent() from ISR category 2
	 *
	 * \result Service returns E_OS_CALLEVEL
	 */
	ret = ClearEvent(Event1);
	ASSERT(EM_12, ret != E_OS_CALLEVEL);

	Sequence(7);
	/* \treq EM_23 nmf E1E2 e Call WaitEvent() from ISR category 2
	 *
	 * \result Service returns E_OS_CALLEVEL
	 */
	ret = WaitEvent(Event1);
	ASSERT(EM_23, ret != E_OS_CALLEVEL);
	LeaveISR();
}

#if ( ISR_CATEGORY_3 == ENABLE )
ISR(ISR3)
{
	StatusType ret;

	EnterISR();

	/* ISR3 are not supported by FreeOSEK OS*/

	LeaveISR();
}
#endif /* #if ( ISR_CATEGORY_3 == ENABLE ) */

/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/** @} doxygen end group definition */
/*==================[end of file]============================================*/

