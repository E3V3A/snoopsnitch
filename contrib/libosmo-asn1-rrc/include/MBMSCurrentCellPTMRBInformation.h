/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "PDU-definitions"
 * 	found in "../asn/PDU-definitions.asn"
 * 	`asn1c -fcompound-names -fnative-types`
 */

#ifndef	_MBMSCurrentCellPTMRBInformation_H_
#define	_MBMSCurrentCellPTMRBInformation_H_


#include <asn_application.h>

/* Including external dependencies */
#include "MBMSCurrentCellPTMRBInfo-v770ext-IEs.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct MBMS_CurrentCell_SCCPCHList_r6;
struct MBMS_SIBType5_SCCPCHList_r6;

/* MBMSCurrentCellPTMRBInformation */
typedef struct MBMSCurrentCellPTMRBInformation {
	struct MBMS_CurrentCell_SCCPCHList_r6	*mbms_CurrentCell_SCCPCHList	/* OPTIONAL */;
	struct MBMS_SIBType5_SCCPCHList_r6	*mbms_SIBType5_SCCPCHList	/* OPTIONAL */;
	struct MBMSCurrentCellPTMRBInformation__v770NonCriticalExtensions {
		MBMSCurrentCellPTMRBInfo_v770ext_IEs_t	 mbmsCurrentCellPTMRBInfo_v770ext;
		struct MBMSCurrentCellPTMRBInformation__v770NonCriticalExtensions__nonCriticalExtensions {
			
			/* Context for parsing across buffer boundaries */
			asn_struct_ctx_t _asn_ctx;
		} *nonCriticalExtensions;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *v770NonCriticalExtensions;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} MBMSCurrentCellPTMRBInformation_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MBMSCurrentCellPTMRBInformation;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "MBMS-CurrentCell-SCCPCHList-r6.h"
#include "MBMS-SIBType5-SCCPCHList-r6.h"

#endif	/* _MBMSCurrentCellPTMRBInformation_H_ */
#include <asn_internal.h>
