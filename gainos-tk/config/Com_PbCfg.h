#if !(((COM_SW_MAJOR_VERSION == 1) && (COM_SW_MINOR_VERSION == 2)) )
#error Com: Configuration file expected BSW module version to be 1.2.*
#endif

#ifndef COM_PBCFG_H
#define COM_PBCFG_H

#include "Com_Types.h"

extern const Com_ConfigType ComConfiguration;

// PDU group id definitions
#define vCom_IPduGrp0 0

//  COM IPDU Id Defines.
#define vCom_IPdu1_TX 0
#define COM_TX_vEcuC_Pdu_1 0	/* for vCom_IPdu1_TX */
#define vCom_IPdu1_RX 1
#define COM_RX_vEcuC_Pdu_1 1	/* for vCom_IPdu1_RX */

//General Signal (Group) Id defines
#define vCom_IPdu1_TX_Signal0 0
#define vCom_IPdu1_Signal0 1

//Group Signal Id defines

// Notifications
extern void vCom_IPdu1_TX_Signal0_Notification(void);
extern void vCom_IPdu1_TX_Signal0_TimeoutNotification(void);
extern void vCom_IPdu1_Signal0_Notification(void);
extern void vCom_IPdu1_Signal0_TimeoutNotification(void);

// Callouts
extern boolean vCom_IPdu0_Callout(PduIdType PduId, const uint8 *IPduData);
extern boolean vCom_IPdu1_Callout(PduIdType PduId, const uint8 *IPduData);
#endif /* COM_PBCFG_H */

