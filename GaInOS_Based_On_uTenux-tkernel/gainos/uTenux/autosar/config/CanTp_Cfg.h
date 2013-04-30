#ifndef CANTP_CFG_H_
#define CANTP_CFG_H_

#include "CanTp_Types.h"

#define CANTP_MAIN_FUNCTION_PERIOD_TIME_MS	10  /* ms */
#define CANTP_CONVERT_MS_TO_MAIN_CYCLES(x) 	(x)/CANTP_MAIN_FUNCTION_PERIOD_TIME_MS

#define CANTP_NSDU_CONFIG_LIST_SIZE 4
#define CANTP_NSDU_RUNTIME_LIST_SIZE 4
#define CANTP_RXID_LIST_SIZE 4

#define FRTP_CANCEL_TRANSMIT_REQUEST 	STD_OFF
#define CANTP_VERSION_INFO_API STD_OFF   /**< Build version info API */
#define CANTP_DEV_ERROR_DETECT STD_ON

/* CanTp Rx NSdu Id */
#define CANTP_RX_vEcuC_Pdu0 0
#define CANTP_RX_vEcuC_Pdu1 1

/* CanTp Tx NSdu Id */
#define CANTP_TX_vEcuC_Pdu0 2
#define CANTP_TX_vEcuC_Pdu1 3

#define USE_CANIF

extern const CanTp_ConfigType CanTpConfig;
extern const CanTp_NSduType CanTpNSduConfigList[];
extern const CanTp_RxIdType CanTp_RxIdList[];

#endif

