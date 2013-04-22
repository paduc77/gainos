#ifndef CAN_CFG_H_
#define CAN_CFG_H_

/* ################ Can General ################ */
#define CAN_DEV_ERROR_DETECT STD_ON
#define CAN_VERSION_INFO_API STD_OFF
#define CAN_TIMEOUT_DURATION 10 /* ms */

/* Number of controller configs */
#define CAN_CTRL_CONFIG_CNT 3

/* Info used by CanIF,index of configure in Can_ControllerCfgData[] */
#define INDEX_OF_CAN_CTRL_0 0
#define INDEX_OF_CAN_CTRL_1 1
#define INDEX_OF_CAN_CTRL_4 2

typedef enum {
	CAN_CTRL_0_vCanHth,
	CAN_CTRL_1_vCanHth,
	CAN_CTRL_4_vCanHth,
	NUM_OF_HTHS
} Can_Arc_HTHType;

typedef enum {
	CAN_CTRL_0_vCanHrh,
	CAN_CTRL_1_vCanHrh,
	CAN_CTRL_4_vCanHrh,
	NUM_OF_HRHS
} Can_Arc_HRHType;

IMPORT const Can_ConfigType Can_ConfigData;
#endif /* CAN_CFG_H_ */

