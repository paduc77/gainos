/* -------------------------------- Arctic Core ------------------------------
 * Arctic Core - the open source AUTOSAR platform http://arccore.com
 *
 * Copyright (C) 2009  ArcCore AB <contact@arccore.com>
 *
 * This source code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published by the
 * Free Software Foundation; See <http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt>.                                           
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 * -------------------------------- Arctic Core ------------------------------*/

/* Modified && Ported by parai to integrated with GaInOS,which is an open source 
 * AUTOSAR OS based on uTenux(tkernel). 
 * And re-construct a GUI tool named gainos-studio,which is based on python and Qt4.8,
 * for the whole Com Architecture of ArCore.
 * URL:      https://github.com/parai
 * Email:    parai@foxmail.com
 * Name:     parai(Wang Fan)
 * from Date:2013-04-08 to $Date: 2013-04-13 13:51:22 $
 * $Revision: 1.1 $
 */
#ifndef DEM_H_
#define DEM_H_

#define DEM_MODULE_ID			MODULE_ID_DEM
#define DEM_VENDOR_ID			1

#define DEM_SW_MAJOR_VERSION    1
#define DEM_SW_MINOR_VERSION   	0
#define DEM_SW_PATCH_VERSION    0
#define DEM_AR_MAJOR_VERSION    3
#define DEM_AR_MINOR_VERSION    0
#define DEM_AR_PATCH_VERSION    1

/** @req DCM067.Cfg-files */
#include "Dem_Types.h"
#include "Dem_Cfg.h"
#include "Dem_Lcfg.h"
#include "Dem_IntErrId.h" /** @req DEM115 */
#include "Dem_IntEvtId.h"
/** @req DEM153 */ /** @req DEM154 */ /* Realized in Dem_IntErrId.h and Dem_IntEvtId.h */
// #include "Rte_Dem.h"


#if (DEM_DEV_ERROR_DETECT == STD_ON)
// Error codes reported by this module defined by AUTOSAR /** @req DEM116 */ /** @req DEM173 */
#define DEM_E_PARAM_CONFIG					0x10
#define DEM_E_PARAM_ADDRESS					0x11
#define DEM_E_PARAM_DATA					0x12
#define DEM_E_PARAM_LENGTH					0x13
#define DEM_E_UNINIT						0x20
#define DEM_E_NODATAAVAILABLE				0x30

// Other error codes reported by this module
#define DEM_E_CONFIG_PTR_INVALID			0x40
#define DEM_E_EVENT_STATUS_BUFF_FULL		0x41
#define DEM_E_EXT_DATA_TOO_BIG				0x42
#define DEM_E_PRE_INIT_EXT_DATA_BUFF_FULL	0x43
#define DEM_E_PRI_MEM_EVENT_BUFF_FULL		0x44
#define DEM_E_PRI_MEM_EXT_DATA_BUFF_FULL	0x45

#define DEM_E_UNEXPECTED_EXECUTION			0xfe
#define DEM_E_NOT_IMPLEMENTED_YET			0xff

// Service ID in this module
#define DEM_PREINIT_ID							0x01
#define DEM_INIT_ID								0x02
#define DEM_SHUTDOWN_ID							0x03
#define DEM_SETEVENTSTATUS_ID					0x04
#define DEM_RESETEVENTSTATUS_ID					0x05
#define DEM_SETOPERATIONCYCLESTATE_ID			0x08
#define DEM_GETEVENTSTATUS_ID					0x0A
#define DEM_GETEVENTFAILED_ID					0x0B
#define DEM_GETEVENTTESTED_ID					0x0C
#define DEM_GETDTCOFEVENT_ID					0x0D
#define DEM_REPORTERRORSTATUS_ID 				0x0F
#define DEM_SETDTCFILTER_ID						0x13
#define DEM_GETSTATUSOFDTC_ID					0x15
#define DEM_GETDTCSTATUSAVAILABILITYMASK_ID		0x16
#define DEM_GETNUMBEROFFILTEREDDTC_ID			0x17
#define DEM_GETNEXTFILTEREDDTC_ID				0x18
#define DEM_GETEXTENDEDDATARECORDBYDTC_ID		0x20
#define DEM_GETSIZEOFEXTENDEDDATARECORDBYDTC_ID	0x21
#define DEM_CLEARDTC_ID							0x22
#define DEM_DISABLEDTCSTORAGE_ID				0x24
#define DEM_ENABLEDTCSTORAGE_ID					0x25
#define DEM_GETTRANSLATIONTYPE_ID				0x3c
#define DEM_GETFAULTDETECTIONCOUNTER_ID 		0x3E
#define DEM_MAINFUNCTION_ID						0x55

#define DEM_UPDATE_EVENT_STATUS_ID				0x80
#define DEM_MERGE_EVENT_STATUS_ID				0x81
#define DEM_GET_EXTENDED_DATA_ID				0x82
#define DEM_STORE_EXT_DATA_PRE_INIT_ID			0x83
#define DEM_STORE_EVENT_PRI_MEM_ID				0x84
#define DEM_STORE_EXT_DATA_PRI_MEM_ID			0x85
#define DEM_PREDEBOUNCE_NONE_ID					0x86
#define DEM_PREDEBOUNCE_COUNTER_BASED_ID		0x87
#define DEM_GLOBAL_ID							0xff

#endif


/*
 * Interface for upper layer modules (8.3.1)
 */
#if ( DEM_VERSION_INFO_API == STD_ON ) /** @req DEM111 */
#define Dem_GetVersionInfo(_vi) STD_GET_VERSION_INFO(_vi,DEM) /** @req DEM177 */ /** @req DEM110 */ /** @req DEM178 */
#endif /* DEM_VERSION_INFO_API */

/*
 * Interface ECU State Manager <-> DEM (8.3.2)
 */
void Dem_PreInit( void ); /** @req DEM179 */
void Dem_Init( void ); /** @req DEM181 */
void Dem_Shutdown( void ); /** @req DEM182 */


/*
 * Interface for basic software scheduler
 */
void Dem_MainFunction( void ); /** @req DEM266 */


/*
 * Interface SW-Components via RTE <-> DEM (8.3.3)
 */
Std_ReturnType Dem_SetEventStatus(Dem_EventIdType eventId, uint8 eventStatus); /** @req DEM183 */
Std_ReturnType Dem_ResetEventStatus(Dem_EventIdType eventId); /** @req DEM185 */
Std_ReturnType Dem_GetEventStatus(Dem_EventIdType eventId, Dem_EventStatusExtendedType *eventStatusExtended); /** @req DEM195 */
Std_ReturnType Dem_GetEventFailed(Dem_EventIdType eventId, boolean *eventFailed); /** @req DEM196 */
Std_ReturnType Dem_GetEventTested(Dem_EventIdType eventId, boolean *eventTested); /** @req DEM197 */
Std_ReturnType Dem_GetFaultDetectionCounter(Dem_EventIdType eventId, sint8 *counter); /** @req DEM203 */
Std_ReturnType Dem_SetOperationCycleState(Dem_OperationCycleIdType operationCycleId, Dem_OperationCycleStateType cycleState); /** @req DEM194 */
Std_ReturnType Dem_GetDTCOfEvent(Dem_EventIdType eventId, Dem_DTCKindType dtcKind, uint32* dtcOfEvent); /** @req DEM198 */


/*
 * Interface BSW-Components <-> DEM (8.3.4)
 */
void Dem_ReportErrorStatus(Dem_EventIdType eventId ,uint8 eventStatus); /** @req DEM206 */


/*
 * Interface DCM <-> DEM (8.3.5)
 */
Dem_ReturnClearDTCType Dem_ClearDTC(uint32 dtc, Dem_DTCKindType dtcKind, Dem_DTCOriginType dtcOrigin); /** @req DEM241 */
Dem_ReturnSetDTCFilterType Dem_SetDTCFilter(uint8 dtcStatusMask, Dem_DTCKindType dtcKind, Dem_DTCOriginType dtcOrigin, Dem_FilterWithSeverityType filterWithSeverity, Dem_DTCSeverityType dtcSeverityMask, Dem_FilterForFDCType filterForFaultDetectionCounter);  /** @req DEM208 */
Dem_ReturnGetStatusOfDTCType Dem_GetStatusOfDTC(uint32 dtc, Dem_DTCKindType dtcKind, Dem_DTCOriginType dtcOrigin, Dem_EventStatusExtendedType* status); /** @req DEM212 */
Std_ReturnType Dem_GetDTCStatusAvailabilityMask(uint8 *dtcStatusMask); /** @req DEM213 */
Dem_ReturnGetNumberOfFilteredDTCType Dem_GetNumberOfFilteredDtc(uint16* numberOfFilteredDTC); /** @req DEM214 */
Dem_ReturnGetNextFilteredDTCType Dem_GetNextFilteredDTC(uint32* dtc, Dem_EventStatusExtendedType* dtcStatus); /** @req DEM215 */
Dem_ReturnTypeOfDtcSupportedType Dem_GetTranslationType(void); /** @req DEM230 */
Dem_ReturnControlDTCStorageType Dem_DisableDTCStorage(Dem_DTCGroupType dtcGroup, Dem_DTCKindType dtcKind); /** @req DEM242 */
Dem_ReturnControlDTCStorageType Dem_EnableDTCStorage(Dem_DTCGroupType dtcGroup, Dem_DTCKindType dtcKind); /** @req DEM243 */
Dem_ReturnGetExtendedDataRecordByDTCType Dem_GetExtendedDataRecordByDTC(uint32 dtc, Dem_DTCKindType dtcKind, Dem_DTCOriginType dtcOrigin, uint8 extendedDataNumber, uint8 *destBuffer, uint16 *bufSize); /** @req DEM239 */
Dem_ReturnGetSizeOfExtendedDataRecordByDTCType Dem_GetSizeOfExtendedDataRecordByDTC(uint32 dtc, Dem_DTCKindType dtcKind, Dem_DTCOriginType dtcOrigin, uint8 extendedDataNumber, uint16 *sizeOfExtendedDataRecord); /** @req DEM240 */



/*
 * OBD-specific Interfaces (8.3.6)
 */

#endif /*DEM_H_*/
