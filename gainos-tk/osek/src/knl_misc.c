/* Copyright(C) 2013, GaInOS-TK by Fan Wang. All rights reserved.
 *
 * This program is open source software; developer can redistribute it and/or
 * modify it under the terms of the U-License as published by the T-Engine Chin a
 * Open Source Society; either version 1 of the License, or (at developer opti on)
 * any later Version.
 *
 * This program is distributed in the hope that it will be useful,but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNES S FOR
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
#include "knl_queue.h"
#include "knl_task.h"
#include "knl_bitop.h"
#include <string.h>
//initialize the ready queue and also the ready queue map
EXPORT void knl_ready_queue_initialize( RDYQUE *rq )
{
	INT	i;

	rq->top_priority = NUM_PRI;
	for ( i = 0; i < NUM_PRI; i++ ) {
		QueInit(&rq->tskque[i]);
	}
	rq->null = NULL;
//	rq->klocktsk = NULL;
	(void)memset(rq->bitmap, 0, sizeof(rq->bitmap));
}
/*
 * Insert task in ready queue
 *	Insert it at the end of the same priority tasks with task priority 
 *	indicated with 'tcb'. Set the applicable bit in the bitmap area and 
 *	update 'top_priority' if necessary. 
 */
EXPORT void knl_ready_queue_insert( RDYQUE *rq, TCB *tcb )
{
	INT	priority = tcb->priority;

	QueInsert(&tcb->tskque, &rq->tskque[priority]);
	knl_tstdlib_bitset(rq->bitmap, priority);

//	if ( tcb->klocked ) {
//		rq->klocktsk = tcb;
//	}

	if ( priority < rq->top_priority ) {
		rq->top_priority = priority;
	}
}

/*
 * Insert task at head in ready queue 
 */
EXPORT void knl_ready_queue_insert_top( RDYQUE *rq, TCB *tcb )
{
	INT	priority = tcb->priority;
	QueInsert(&tcb->tskque, rq->tskque[priority].next);
	knl_tstdlib_bitset(rq->bitmap, priority);

//	if ( tcb->klocked ) {
//		rq->klocktsk = tcb;
//	}

	if ( priority < rq->top_priority ) {
		rq->top_priority = priority;
	}
}
/*
 * Delete task from ready queue
 *	Take out TCB from the applicable priority task queue, and if the task 
 *	queue becomes empty, clear the applicable bit from the bitmap area.
 *	In addition, update 'top_priority' if the deleted task had the highest 
 *	priority. In such case, use the bitmap area to search the second
 *	highest priority task.
 */
EXPORT void knl_ready_queue_delete( RDYQUE *rq, TCB *tcb )
{
	INT	priority = tcb->priority;
	INT	i;

//	if ( rq->klocktsk == tcb ) {
//		rq->klocktsk = NULL;
//	}

	QueRemove(&tcb->tskque);
//	if ( tcb->klockwait ) {
//		/* Delete from kernel lock wait queue */
//		tcb->klockwait = FALSE;
//		return;
//	}
	if ( !isQueEmpty(&rq->tskque[priority]) ) {
		return;
	}

	knl_tstdlib_bitclr(rq->bitmap, priority);
	if ( priority != rq->top_priority ) {
		return;
	}

	i = knl_tstdlib_bitsearch1(rq->bitmap, priority, NUM_PRI - priority);
	if ( i >= 0 ) {
		rq->top_priority = priority + i;
	} else {
		rq->top_priority = NUM_PRI;
	}
}

