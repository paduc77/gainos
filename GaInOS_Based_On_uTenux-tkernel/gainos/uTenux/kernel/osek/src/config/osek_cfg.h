#ifndef _OSEK_CFG_H_
#define _OSEK_CFG_H_
#include "osek_os.h"

/* #####################  TASK  ########################## */
#define cfgOSEK_TASK_NUM 4
extern const T_CTSK OsekTaskTable[cfgOSEK_TASK_NUM];
extern const BOOL   OsekTaskAuotStartable[cfgOSEK_TASK_NUM];
#define ID_vTask0		 (MIN_TSKID+0)
#define ID_vTask1		 (MIN_TSKID+1)
#define ID_vTask2		 (MIN_TSKID+2)
#define ID_vTask3		 (MIN_TSKID+3)
extern TASK(vTask0);
extern TASK(vTask1);
extern TASK(vTask2);
extern TASK(vTask3);
/* #####################  EVENT ########################## */
#define cfgOSEK_EVENTFLAG_NUM 2
#define ID_vTask1Event		(MIN_FLGID+0)
#define vTask1Event0		 0x1
#define vTask1Event1		 0x2
#define ID_vTask2Event		(MIN_FLGID+1)
#define vTask2Event0		 0x1
#define vTask2Event1		 0x2
/* #####################  ALARM ########################## */
#define cfgOSEK_ALARM_NUM 3
extern ID OsekAlarmIdTable[cfgOSEK_ALARM_NUM];
extern UB OsekAlarmTypeTable[cfgOSEK_ALARM_NUM];
extern const FP OsekAlarmHandlerTable[cfgOSEK_ALARM_NUM];
#define ID_vAlarm0		(0)
#define ID_vAlarm1		(1)
#define ID_vAlarm2		(2)
extern ALARMCALLBACK(vAlarm0);
extern ALARMCALLBACK(vAlarm1);
extern ALARMCALLBACK(vAlarm2);
/*  ####################  RESOURCE ####################### */
#define cfgOSEK_RESOURCE_NUM 3
extern const T_CMTX OsekResourceTable[cfgOSEK_RESOURCE_NUM];
#define ID_vRes0		 (MIN_MTXID+0)
#define ID_vRes1		 (MIN_MTXID+1)
#define ID_vResSerial		 (MIN_MTXID+2)

#define cfgOS_START_UP_HOOK 0
#define cfgOS_SHUT_DOWN_HOOK 0
#endif /* _OSEK_CFG_H_ */

