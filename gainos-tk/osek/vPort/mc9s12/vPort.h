#ifndef  VPORT_H_H
#define  VPORT_H_H
/* ============================ INCLUDEs ========================================== */
#include "osek_os.h"
#include "vPortMacro.h"
#include "knl_task.h"
/* ============================ MACROs ============================================= */
/*
 * Size of system stack area destroyed by 'make_dormant()'
 * In other words, the size of area required to write by 'setup_context().'
 */
#define DORMANT_STACK_SIZE	( sizeof(VW) * 3 )	/* To 'PC' position */

#define SP_OFFSET 4 /* sizeof(QUEUE) */
/* ============================ TYPEs ============================================= */
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

/* ============================ FUNCTIONs ========================================= */
/*
 * Throw away the current task context.
 * and forcibly dispatch to the task that should be performed next.
 *	Use at system startup and 'tk_ext_tsk, tk_exd_tsk.'
 */
#pragma CODE_SEG __NEAR_SEG NON_BANKED
IMPORT void knl_force_dispatch(void); 
#pragma CODE_SEG DEFAULT
/*
 * Start task dispatcher
 */
#define knl_dispatch() {asm swi;}

IMPORT imask_t disint( void );
IMPORT void enaint( imask_t intsts );
IMPORT void knl_start_hw_timer( void );
/*
 * Create stack frame for task startup
 *	Call from 'make_dormant()'
 */
IMPORT void knl_setup_context( TCB *tcb );
IMPORT void knl_enter_isr(void);

IMPORT void knl_exit_isr(void);

#endif/* VPORT_H_H */