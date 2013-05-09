#ifndef _OSEK_CFG_H_
#define _OSEK_CFG_H_
/* =====================  MISC  ========================== */
#define cfgOS_STATUS_LEVEL OS_STATUS_EXTEND

#define CHIP_MC9S12
//#define CHIP_STM32F1
//#define CHIP_AT91SAM3S
//#define CHIP_MPC54XX

#if defined(CHIP_MC9S12) //9s12
#define CPU_FREQUENCY        32000000 /* HZ */
#define OSC_FREQUENCY         8000000 /* HZ */
#elif defined(CHIP_STM32F1)//stm32
#define CPU_FREQUENCY        72000000 /* HZ */
#elif defined(CHIP_AT91SAM3S)
#define CPU_FREQUENCY        64000000 /* HZ */
#elif defined(CHIP_MPC54XX)
#define CPU_FREQUENCY  64000000   /* HZ */
#define OSC_FREQUENCY  8000000    /* Oscillator Clock 8MHZ */
#endif


/* =====================  TASK  ========================== */
#define cfgOSEK_MAX_PRIO  32
#define cfgOSEK_TASK_NUM  3
#define ID_vTask1  0
#define ID_vTask2  1
#define ID_vTaskIdle 2
IMPORT TASK(vTask1);
IMPORT TASK(vTask2);
IMPORT TASK(vTaskIdle);

/* =====================  EVENT ========================== */
#define cfgOSEK_EVENTFLAG_NUM 1
#define ID_vTask1Event   0

/* =====================  ALARM ========================== */
#define cfgOSEK_COUNTER_NUM 1
#define ID_vCounter1  0
#define cfgOSEK_ALARM_NUM 2
#define ID_vAlarm1 0
#define ID_vAlarm2 1
IMPORT ALARM(vAlarm1);
IMPORT ALARM(vAlarm2);

/*  ====================  RESOURCE ======================= */
#define cfgOSEK_RESOURCE_NUM 1
#define ID_vResource1 0

/*  ====================  HOOKs    ======================= */
#define cfgOS_SHUT_DOWN_HOOK 0
#define cfgOS_START_UP_HOOK  0
#endif /* _OSEK_CFG_H_ */

