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

/*
 * NB! This file is for COM internal use only and may only be included from COM C-files!
 */



#ifndef COM_INTERNAL_H_
#define COM_INTERNAL_H_

#include "Com_Arc_Types.h"

typedef struct {
	PduLengthType currentPosition;
	boolean locked;
} Com_BufferPduStateType;
extern Com_BufferPduStateType Com_BufferPduState[];

extern const Com_ConfigType *ComConfig;
extern const Com_Arc_Config_type Com_Arc_Config;



#if COM_DEV_ERROR_DETECT == STD_ON
#include "Det.h"

#define DET_REPORTERROR(_x,_y,_z,_q) Det_ReportError(_x,_y,_z,_q)

// Define macro for parameter check.
#define PDU_ID_CHECK(PduId,ApiId,_rv) \
	if (PduId >= COM_N_IPDUS) { \
		DET_REPORTERROR(COM_MODULE_ID, COM_INSTANCE_ID, ApiId, COM_INVALID_PDU_ID); \
		return _rv; \
	} 
	
#define PDU_ID_CHECK_NO_RV(PduId,ApiId) \
	if (PduId >= COM_N_IPDUS) { \
		DET_REPORTERROR(COM_MODULE_ID, COM_INSTANCE_ID, ApiId, COM_INVALID_PDU_ID); \
		return; \
	}	

#define VALIDATE_SIGNAL(SignalId, ApiId,_rv) \
	if (SignalId >= COM_N_SIGNALS) { \
		DET_REPORTERROR(COM_MODULE_ID, COM_INSTANCE_ID, ApiId, COM_INVALID_SIGNAL_ID); \
		return _rv; \
	}
#else

#define DET_REPORTERROR(_x,_y,_z,_q)

#define PDU_ID_CHECK(PduId,ApiId,_rv)

#define PDU_ID_CHECK_NO_RV(PduId,ApiId)

#define VALIDATE_SIGNAL(PduId, ApiId,_rv)
#endif

#if 0
#define TESTBIT(source,bit)	( *( (uint8 *)source  + (bit / 8) ) &  (uint8)(1u << (bit % 8)) )
#define SETBIT(dest,bit)	( *( (uint8 *)dest    + (bit / 8) ) |= (uint8)(1u << (bit % 8)) )
#define CLEARBIT(dest,bit)	( *( (uint8 *)dest    + (bit / 8) ) &= (uint8)~(uint8)(1u << (bit % 8)) )
#else  /* I hate "/" and "%"  operation which can be replaced by ">>" and  "&", @parai*/
#define TESTBIT(source,bit)	( *( (uint8 *)source  + (bit >> 3U) ) &  (uint8)(1u << (bit & 7U)) )
#define SETBIT(dest,bit)	( *( (uint8 *)dest    + (bit >> 3U) ) |= (uint8)(1u << (bit & 7U)) )
#define CLEARBIT(dest,bit)	( *( (uint8 *)dest    + (bit >> 3U) ) &= (uint8)~(uint8)(1u << (bit & 7U)) )
#endif


#define GET_Signal(SignalId) \
	(&ComConfig->ComSignal[SignalId])

#define GET_ArcSignal(SignalId) \
	(&Com_Arc_Config.ComSignal[SignalId])

#define GET_IPdu(IPduId) \
	(&ComConfig->ComIPdu[IPduId])

#define GET_ArcIPdu(IPduId) \
	(&Com_Arc_Config.ComIPdu[IPduId])

#define GET_GroupSignal(GroupSignalId) \
	(&ComConfig->ComGroupSignal[GroupSignalId])

#define GET_ArcGroupSignal(GroupSignalId) \
	(&Com_Arc_Config.ComGroupSignal[GroupSignalId])

Std_ReturnType Com_Internal_TriggerIPduSend(PduIdType ComTxPduId);

#endif /* COM_INTERNAL_H_ */
