/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "InformationElements"
 * 	found in "../asn/InformationElements.asn"
 * 	`asn1c -fcompound-names -fnative-types`
 */

#ifndef	_RL_AdditionInformationList_H_
#define	_RL_AdditionInformationList_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct RL_AdditionInformation;

/* RL-AdditionInformationList */
typedef struct RL_AdditionInformationList {
	A_SEQUENCE_OF(struct RL_AdditionInformation) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RL_AdditionInformationList_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RL_AdditionInformationList;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "RL-AdditionInformation.h"

#endif	/* _RL_AdditionInformationList_H_ */
#include <asn_internal.h>