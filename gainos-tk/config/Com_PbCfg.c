#include "Com.h"
#include "Com_Internal.h"
//#include <stdlib.h>
#if defined(USE_PDUR)
#include "PduR.h"
#endif

//Signal init values.
const uint8 vCom_IPdu1_TX_Signal0_InitValue[3] ={0x00, 0x00,0x00,};
const uint8 vCom_IPdu1_Signal0_InitValue[3] ={0x00, 0x00,0x00,};

//Group signal definitions
#if(COM_N_GROUP_SIGNALS > 0)
const ComGroupSignal_type ComGroupSignal[] = {
};

/* SignalGroup GroupSignals lists. */
#endif	/* COM_N_GROUP_SIGNALS */

/* IPdu buffers and signal group buffers */
uint8 vCom_IPdu1_TX_IPduBuffer[8];
uint8 vCom_IPdu1_RX_IPduBuffer[8];
uint8 vCom_IPdu1_RX_IPduDeferredRxBuffer[8];

//Signal definitions
const ComSignal_type ComSignal[] = {
	{
		/* .ComBitPosition = */ 0,
		/* .ComBitSize = */ 24,
		/* .ComErrorNotification = */ NULL,
		/* .ComFirstTimeoutFactor = */ 10,
		/* .ComHandleId = */ vCom_IPdu1_TX_Signal0,
		/* .ComNotification = */ NULL,
		/* .ComRxDataTimeoutAction = */ COM_TIMEOUT_DATA_ACTION_NONE,
		/* .ComSignalEndianess = */ COM_BIG_ENDIAN,
		/* .ComSignalInitValue = */ &vCom_IPdu1_TX_Signal0_InitValue,
		/* .ComSignalType = */ UINT8_N,
		/* .ComTimeoutFactor = */ 10,
		/* .ComTimeoutNotification = */ NULL,
		/* .ComTransferProperty = */ TRIGGERED,
		/* .ComUpdateBitPosition = */ 0,
		/* .ComSignalArcUseUpdateBit = */ FALSE,
		/* .Com_Arc_IsSignalGroup = */ FALSE,
		/* .ComGroupSignal = */ NULL,
		/* .Com_Arc_ShadowBuffer = */ NULL,
		/* .ComIPduHandleId = */ vCom_IPdu1_TX,
		/* .Com_Arc_EOL = */ FALSE
	},
	{
		/* .ComBitPosition = */ 0,
		/* .ComBitSize = */ 24,
		/* .ComErrorNotification = */ NULL,
		/* .ComFirstTimeoutFactor = */ 10,
		/* .ComHandleId = */ vCom_IPdu1_Signal0,
		/* .ComNotification = */ NULL,
		/* .ComRxDataTimeoutAction = */ COM_TIMEOUT_DATA_ACTION_NONE,
		/* .ComSignalEndianess = */ COM_BIG_ENDIAN,
		/* .ComSignalInitValue = */ &vCom_IPdu1_Signal0_InitValue,
		/* .ComSignalType = */ UINT8_N,
		/* .ComTimeoutFactor = */ 10,
		/* .ComTimeoutNotification = */ NULL,
		/* .ComTransferProperty = */ TRIGGERED,
		/* .ComUpdateBitPosition = */ 0,
		/* .ComSignalArcUseUpdateBit = */ FALSE,
		/* .Com_Arc_IsSignalGroup = */ FALSE,
		/* .ComGroupSignal = */ NULL,
		/* .Com_Arc_ShadowBuffer = */ NULL,
		/* .ComIPduHandleId = */ vCom_IPdu1_RX,
		/* .Com_Arc_EOL = */ TRUE
	},
};

//I-PDU group definitions
const ComIPduGroup_type ComIPduGroup[] = {
	{
		/* .ComIPduGroupHandleId = */ vCom_IPduGrp0,
		/* .Com_Arc_EOL = */ TRUE
	},
};

/* IPdu signal lists. */
const ComSignal_type * const vCom_IPdu1_TX_SignalRefs[] = {
	&ComSignal[ vCom_IPdu1_TX_Signal0 ],
	NULL
};
const ComSignal_type * const vCom_IPdu1_RX_SignalRefs[] = {
	&ComSignal[ vCom_IPdu1_Signal0 ],
	NULL
};
//I-PDU definitions
const ComIPdu_type ComIPdu[] = {
	{// vCom_IPdu1_TX
		/* .ComIPduCallout = */ NULL,
		/* .ArcIPduOutgoingId = */ PDUR_TX_vEcuC_Pdu_1,
		/* .ComIPduSignalProcessing = */ DEFERRED,
		/* .ComIPduSize = */ 8,
		/* .ComIPduDirection = */ SEND,
		/* .ComIPduGroupRef = */ vCom_IPduGrp0,
		{/* .ComTxIPdu = */
			/* .ComTxIPduMinimumDelayFactor = */ 1,
			/* .ComTxIPduUnusedAreasDefault = */ 0,
			{/* .ComTxModeTrue = */
				/* .ComTxModeMode =  */ PERIODIC,
				/* .ComTxModeNumberOfRepetitions =  */ 0,
				/* .ComTxModeRepetitionPeriodFactor =  */ 10,
				/* .ComTxModeTimeOffsetFactor =  */ 20,
				/* .ComTxModeTimePeriodFactor =  */ 10,
			},
		},
		/* .ComIPduDataPtr = */ vCom_IPdu1_TX_IPduBuffer,
		/* .ComIPduDeferredDataPtr = */ NULL,
		/* .ComIPduGroupRef = */ vCom_IPdu1_TX_SignalRefs,
		/* .ComIPduDynSignalRef = */ NULL,
		/* .Com_Arc_EOL = */ FALSE,
	},
	{// vCom_IPdu1_RX
		/* .ComIPduCallout = */ NULL,
		/* .ArcIPduOutgoingId = */ PDUR_RX_vEcuC_Pdu_1,
		/* .ComIPduSignalProcessing = */ DEFERRED,
		/* .ComIPduSize = */ 8,
		/* .ComIPduDirection = */ RECEIVE,
		/* .ComIPduGroupRef = */ vCom_IPduGrp0,
		{/* .ComTxIPdu = */
			/* .ComTxIPduMinimumDelayFactor = */ 1,
			/* .ComTxIPduUnusedAreasDefault = */ 0,
			{/* .ComTxModeTrue = */
				/* .ComTxModeMode =  */ PERIODIC,
				/* .ComTxModeNumberOfRepetitions =  */ 0,
				/* .ComTxModeRepetitionPeriodFactor =  */ 10,
				/* .ComTxModeTimeOffsetFactor =  */ 20,
				/* .ComTxModeTimePeriodFactor =  */ 10,
			},
		},
		/* .ComIPduDataPtr = */ vCom_IPdu1_RX_IPduBuffer,
		/* .ComIPduDeferredDataPtr = */ vCom_IPdu1_RX_IPduDeferredRxBuffer,
		/* .ComIPduGroupRef = */ vCom_IPdu1_RX_SignalRefs,
		/* .ComIPduDynSignalRef = */ NULL,
		/* .Com_Arc_EOL = */ FALSE,
	},
};

const Com_ConfigType ComConfiguration = {
	/* .ComConfigurationId = */ 1,
	/* .ComIPdu = */ ComIPdu,
	/* .ComIPduGroup = */ ComIPduGroup,
	/* .ComSignal = */ ComSignal,
#if(COM_N_GROUP_SIGNALS > 0)
	/* .ComGroupSignal = */ ComGroupSignal
#else
	/* .ComGroupSignal = */ NULL
#endif
};

Com_Arc_IPdu_type Com_Arc_IPdu[] = {
	{ // vCom_IPdu1_TX
		{/* .Com_Arc_TxIPduTimers = */
			/* .ComTxIPduNumberOfRepetitionsLeft = */ 0,
			/* .ComTxModeRepetitionPeriodTimer = */ 0,
			/* .ComTxIPduMinimumDelayTimer = */ 0,
			/* .ComTxModeTimePeriodTimer = */ 0
		},
		/* .Com_Arc_IpduStarted = */ 0
	},
	{ // vCom_IPdu1_RX
		{/* .Com_Arc_TxIPduTimers = */
			/* .ComTxIPduNumberOfRepetitionsLeft = */ 0,
			/* .ComTxModeRepetitionPeriodTimer = */ 0,
			/* .ComTxIPduMinimumDelayTimer = */ 0,
			/* .ComTxModeTimePeriodTimer = */ 0
		},
		/* .Com_Arc_IpduStarted = */ 0
	},
};

Com_Arc_Signal_type Com_Arc_Signal[] = {
	{ // vCom_IPdu1_TX_Signal0
		/* .Com_Arc_DeadlineCounter = */ 0,
		/* .ComSignalUpdated = */ 0,
	},
	{ // vCom_IPdu1_Signal0
		/* .Com_Arc_DeadlineCounter = */ 0,
		/* .ComSignalUpdated = */ 0,
	},
};

#if(COM_N_GROUP_SIGNALS > 0)
Com_Arc_GroupSignal_type Com_Arc_GroupSignal[COM_N_GROUP_SIGNALS];
#endif

const Com_Arc_Config_type Com_Arc_Config = {
	/* .ComIPdu = */ Com_Arc_IPdu,
	/* .ComSignal = */ Com_Arc_Signal,
#if(COM_N_GROUP_SIGNALS > 0)
	/* .ComGroupSignal = */ Com_Arc_GroupSignal
#else
    /* .ComGroupSignal = */ NULL
#endif
};

