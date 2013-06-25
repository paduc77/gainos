/* Copyright(C) 2013, GaInOS-TK by Fan Wang. All rights reserved.
 * Generated by GaInOS-TK Studio at 2013-06-01:15-55-19.
 * Don't Modify it by hand.
 * Email: parai@foxmail.com
 * URL: https://github.com/parai/gainos-tk  && http://hi.baidu.com/parai
 */
#include "Os.h"
#include <stdio.h>
#include "Can.h"
#include "CanIf.h"
#include "PduR.h"
#include "CanNm.h"
#include "Nm.h"
#include "ComM.h"
#include "CanSM.h"

TASK(vTaskSender)
{
    (void)TerminateTask();
}

TASK(vTaskReceiver)
{
    /* Add your task special code here, but Don't delete this Task declaration.*/
    (void)TerminateTask();
}

TASK(vTaskMainFunction)
{
    /* Add your task special code here, but Don't delete this Task declaration.*/
    CanNm_MainFunction(vCanNm_Channel_0);
    ComM_MainFunction(vComM_Channel_0);
    CanSM_MainFunction();
    (void)TerminateTask();
}
ALARM(vAlarmSender)
{
    /* Alarm Type: Task, you still can add your special code here.*/
    (void)ActivateTask(ID_vTaskSender);
}
ALARM(vAlarmReceiver)
{
    /* Alarm Type: Task, you still can add your special code here.*/
    (void)ActivateTask(ID_vTaskReceiver);
}
ALARM(vAlarmMainFunction)
{
    /* Alarm Type: Task, you still can add your special code here.*/
    (void)ActivateTask(ID_vTaskMainFunction);
}

void StartupHook(void)
{
    /* Add Code Here */
    (void)SetRelAlarm(ID_vAlarmReceiver,50,10);
	(void)SetRelAlarm(ID_vAlarmSender,100,200);
	(void)SetRelAlarm(ID_vAlarmMainFunction,200,1); //so cyclic 1 Ticks = 4ms
	Can_Init(&Can_ConfigData); 
    CanIf_Init(&CanIf_Config);
    CanNm_Init(&CanNm_Config);
    CanSM_Init(&CanSM_Cfg);
    Nm_Init(&Nm_Config);
    ComM_Init(&ComM_Cfg);
    CanIf_SetControllerMode(vCanIf_Channel_0,CANIF_CS_STARTED);
    CanIf_SetControllerMode(vCanIf_Channel_1,CANIF_CS_STARTED);
    Nm_PassiveStartUp(vNm_Channel_0);
    ComM_RequestComMode(vComM_User_0,COMM_FULL_COMMUNICATION);
    CanNm_NetworkRequest(vCanNm_Channel_0);
}

void CanIf_UserRxIndication(uint8 channel, PduIdType pduId, const uint8 *sduPtr,
                           uint8 dlc, Can_IdType canId)
{
    int len = dlc;
    char* ptr= sduPtr;
    static int fcnt = 0;
    printf("channel=%d,pduId=%d,canId=%d.\r\r\n",(int)channel,(int)pduId,(int)canId);
    printf("[");      
    while(len > 0)
    {
        printf("0x%x,",(uint8)(*ptr));
        ptr++;
        len--;
    }
    printf("]\r\n");
} 

void ErrorHook(StatusType Error)
{
    /* Add Code Here */
}   
