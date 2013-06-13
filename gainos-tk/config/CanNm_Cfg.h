#ifndef CANNM_CFG_H_H
#define CANNM_CFG_H_H

#define CANNM_VERSION_INFO_API STD_ON
#define CANNM_DEV_ERROR_DETECT STD_ON
#define CANNM_NODE_ID_ENABLED  STD_ON
#define CANNM_USER_DATA_ENABLED STD_ON
#define CANNM_NODE_DETECTION_ENABLED STD_ON
#define CANNM_PDU_RX_INDICATION_ENABLED STD_ON //not implemented
#define CANNM_PASSIVE_MODE_ENABLED STD_ON

#define CANNM_CHANNEL_COUNT 1

extern const CanNm_ConfigType CanNm_Config;
#endif

