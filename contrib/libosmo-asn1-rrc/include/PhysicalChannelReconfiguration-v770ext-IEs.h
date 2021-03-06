/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "PDU-definitions"
 * 	found in "../asn/PDU-definitions.asn"
 * 	`asn1c -fcompound-names -fnative-types`
 */

#ifndef	_PhysicalChannelReconfiguration_v770ext_IEs_H_
#define	_PhysicalChannelReconfiguration_v770ext_IEs_H_


#include <asn_application.h>

/* Including external dependencies */
#include "High-MobilityDetected.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* PhysicalChannelReconfiguration-v770ext-IEs */
typedef struct PhysicalChannelReconfiguration_v770ext_IEs {
	High_MobilityDetected_t	*ueMobilityStateIndicator	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} PhysicalChannelReconfiguration_v770ext_IEs_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_PhysicalChannelReconfiguration_v770ext_IEs;

#ifdef __cplusplus
}
#endif

#endif	/* _PhysicalChannelReconfiguration_v770ext_IEs_H_ */
#include <asn_internal.h>
