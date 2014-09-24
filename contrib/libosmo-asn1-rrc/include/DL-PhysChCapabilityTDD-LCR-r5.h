/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "Internode-definitions"
 * 	found in "../asn/Internode-definitions.asn"
 * 	`asn1c -fcompound-names -fnative-types`
 */

#ifndef	_DL_PhysChCapabilityTDD_LCR_r5_H_
#define	_DL_PhysChCapabilityTDD_LCR_r5_H_


#include <asn_application.h>

/* Including external dependencies */
#include "MaxTS-PerSubFrame-r4.h"
#include "MaxPhysChPerSubFrame-r4.h"
#include "MinimumSF-DL.h"
#include <BOOLEAN.h>
#include "MaxPhysChPerTS.h"
#include "HSDSCH-physical-layer-category.h"
#include <NULL.h>
#include <constr_CHOICE.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum DL_PhysChCapabilityTDD_LCR_r5__tdd128_hspdsch_PR {
	DL_PhysChCapabilityTDD_LCR_r5__tdd128_hspdsch_PR_NOTHING,	/* No components present */
	DL_PhysChCapabilityTDD_LCR_r5__tdd128_hspdsch_PR_supported,
	DL_PhysChCapabilityTDD_LCR_r5__tdd128_hspdsch_PR_unsupported
} DL_PhysChCapabilityTDD_LCR_r5__tdd128_hspdsch_PR;

/* DL-PhysChCapabilityTDD-LCR-r5 */
typedef struct DL_PhysChCapabilityTDD_LCR_r5 {
	MaxTS_PerSubFrame_r4_t	 maxTS_PerSubFrame;
	MaxPhysChPerSubFrame_r4_t	 maxPhysChPerFrame;
	MinimumSF_DL_t	 minimumSF;
	BOOLEAN_t	 supportOfPDSCH;
	MaxPhysChPerTS_t	 maxPhysChPerTS;
	BOOLEAN_t	 supportOf8PSK;
	struct DL_PhysChCapabilityTDD_LCR_r5__tdd128_hspdsch {
		DL_PhysChCapabilityTDD_LCR_r5__tdd128_hspdsch_PR present;
		union DL_PhysChCapabilityTDD_LCR_r5__tdd128_hspdsch_u {
			HSDSCH_physical_layer_category_t	 supported;
			NULL_t	 unsupported;
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} tdd128_hspdsch;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} DL_PhysChCapabilityTDD_LCR_r5_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_DL_PhysChCapabilityTDD_LCR_r5;

#ifdef __cplusplus
}
#endif

#endif	/* _DL_PhysChCapabilityTDD_LCR_r5_H_ */
#include <asn_internal.h>