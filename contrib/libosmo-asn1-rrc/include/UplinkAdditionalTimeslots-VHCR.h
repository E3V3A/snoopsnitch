/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "InformationElements"
 * 	found in "../asn/InformationElements.asn"
 * 	`asn1c -fcompound-names -fnative-types`
 */

#ifndef	_UplinkAdditionalTimeslots_VHCR_H_
#define	_UplinkAdditionalTimeslots_VHCR_H_


#include <asn_application.h>

/* Including external dependencies */
#include "TimeslotNumber.h"
#include <constr_SEQUENCE.h>
#include "IndividualTimeslotInfo-VHCR.h"
#include "UL-TS-ChannelisationCodeList.h"
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum UplinkAdditionalTimeslots_VHCR__parameters_PR {
	UplinkAdditionalTimeslots_VHCR__parameters_PR_NOTHING,	/* No components present */
	UplinkAdditionalTimeslots_VHCR__parameters_PR_sameAsLast,
	UplinkAdditionalTimeslots_VHCR__parameters_PR_newParameters
} UplinkAdditionalTimeslots_VHCR__parameters_PR;

/* UplinkAdditionalTimeslots-VHCR */
typedef struct UplinkAdditionalTimeslots_VHCR {
	struct UplinkAdditionalTimeslots_VHCR__parameters {
		UplinkAdditionalTimeslots_VHCR__parameters_PR present;
		union UplinkAdditionalTimeslots_VHCR__parameters_u {
			struct UplinkAdditionalTimeslots_VHCR__parameters__sameAsLast {
				TimeslotNumber_t	 timeslotNumber;
				
				/* Context for parsing across buffer boundaries */
				asn_struct_ctx_t _asn_ctx;
			} sameAsLast;
			struct UplinkAdditionalTimeslots_VHCR__parameters__newParameters {
				IndividualTimeslotInfo_VHCR_t	 individualTimeslotInfo;
				UL_TS_ChannelisationCodeList_t	 ul_TS_ChannelisationCodeList;
				
				/* Context for parsing across buffer boundaries */
				asn_struct_ctx_t _asn_ctx;
			} newParameters;
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} parameters;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} UplinkAdditionalTimeslots_VHCR_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_UplinkAdditionalTimeslots_VHCR;

#ifdef __cplusplus
}
#endif

#endif	/* _UplinkAdditionalTimeslots_VHCR_H_ */
#include <asn_internal.h>