/* Copyright(C) 2013, GaInOS-TK by Fan Wang. All rights reserved.
 * Generated by GaInOS-TK Studio at 2013-06-24:09-38-31.
 * Don't Modify it by hand.
 * Email: parai@foxmail.com
 * URL: https://github.com/parai/gainos-tk  && http://hi.baidu.com/parai
 */

#ifndef CANNM_CFG_H_H
#define CANNM_CFG_H_H

#define CANNM_DEV_ERROR_DETECT				STD_ON
#define CANNM_VERSION_INFO_API				STD_ON
#define CANNM_PASSIVE_MODE_ENABLED			STD_ON
#define CANNM_USER_DATA_ENABLED				STD_ON
#define CANNM_REMOTE_SLEEP_IND_ENABLED		STD_OFF	// Not supported
#define CANNM_BUS_SYNCHRONIZATION_ENABLED	STD_OFF	// Not supported
#define CANNM_BUS_LOAD_REDUCTION_ENABLED	STD_OFF	// Not supported
#define CANNM_NODE_ID_ENABLED				STD_ON
#define CANNM_NODE_DETECTION_ENABLED		STD_ON
#define CANNM_IMMEDIATE_RESTART_ENABLED		STD_OFF	// Not supported
#define CANNM_PDU_RX_INDICATION_ENABLED		STD_ON
#define CANNM_STATE_CHANGE_IND_ENABLED		STD_OFF	// Not supported
#define CANNM_COM_CONTROL_ENABLED			STD_OFF	// Not supported
#define CANNM_IMMEDIATE_TXCONF_ENABLED		STD_OFF	// Not supported
#define CANNM_REPEAT_MSG_IND_ENABLED		STD_OFF	// Not supported

#define CANNM_CHANNEL_COUNT 1
#define vCanNm_Channel_0 0
#define CANNM_TX_vEcuC_Pdu_1 0
#define CANNM_RX_vEcuC_Pdu_1 0

extern const CanNm_ConfigType CanNm_Config;

#endif /* CANNM_CFG_H_H */ 

