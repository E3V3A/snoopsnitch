/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "InformationElements"
 * 	found in "../asn/InformationElements.asn"
 * 	`asn1c -fcompound-names -fnative-types`
 */

#ifndef	_UL_MulticarrierEDCH_Infolist_TDD128_H_
#define	_UL_MulticarrierEDCH_Infolist_TDD128_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct UL_MulticarrierEDCH_InfolistItem_TDD128;

/* UL-MulticarrierEDCH-Infolist-TDD128 */
typedef struct UL_MulticarrierEDCH_Infolist_TDD128 {
	A_SEQUENCE_OF(struct UL_MulticarrierEDCH_InfolistItem_TDD128) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} UL_MulticarrierEDCH_Infolist_TDD128_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_UL_MulticarrierEDCH_Infolist_TDD128;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "UL-MulticarrierEDCH-InfolistItem-TDD128.h"

#endif	/* _UL_MulticarrierEDCH_Infolist_TDD128_H_ */
#include <asn_internal.h>
