/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "InformationElements"
 * 	found in "../asn/InformationElements.asn"
 * 	`asn1c -fcompound-names -fnative-types`
 */

#ifndef	_ASCSetting_FDD_H_
#define	_ASCSetting_FDD_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct AccessServiceClass_FDD;

/* ASCSetting-FDD */
typedef struct ASCSetting_FDD {
	struct AccessServiceClass_FDD	*accessServiceClass_FDD	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ASCSetting_FDD_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ASCSetting_FDD;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "AccessServiceClass-FDD.h"

#endif	/* _ASCSetting_FDD_H_ */
#include <asn_internal.h>
