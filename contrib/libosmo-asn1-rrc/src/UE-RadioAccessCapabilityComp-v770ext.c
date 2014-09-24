/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "InformationElements"
 * 	found in "../asn/InformationElements.asn"
 * 	`asn1c -fcompound-names -fnative-types`
 */

#include "UE-RadioAccessCapabilityComp-v770ext.h"

static int
securityCapabilityIndication_3_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	/* Replace with underlying type checker */
	td->check_constraints = asn_DEF_NativeEnumerated.check_constraints;
	return td->check_constraints(td, sptr, ctfailcb, app_key);
}

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
static void
securityCapabilityIndication_3_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {
	td->free_struct    = asn_DEF_NativeEnumerated.free_struct;
	td->print_struct   = asn_DEF_NativeEnumerated.print_struct;
	td->ber_decoder    = asn_DEF_NativeEnumerated.ber_decoder;
	td->der_encoder    = asn_DEF_NativeEnumerated.der_encoder;
	td->xer_decoder    = asn_DEF_NativeEnumerated.xer_decoder;
	td->xer_encoder    = asn_DEF_NativeEnumerated.xer_encoder;
	td->uper_decoder   = asn_DEF_NativeEnumerated.uper_decoder;
	td->uper_encoder   = asn_DEF_NativeEnumerated.uper_encoder;
	if(!td->per_constraints)
		td->per_constraints = asn_DEF_NativeEnumerated.per_constraints;
	td->elements       = asn_DEF_NativeEnumerated.elements;
	td->elements_count = asn_DEF_NativeEnumerated.elements_count;
     /* td->specifics      = asn_DEF_NativeEnumerated.specifics;	// Defined explicitly */
}

static void
securityCapabilityIndication_3_free(asn_TYPE_descriptor_t *td,
		void *struct_ptr, int contents_only) {
	securityCapabilityIndication_3_inherit_TYPE_descriptor(td);
	td->free_struct(td, struct_ptr, contents_only);
}

static int
securityCapabilityIndication_3_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
		int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	securityCapabilityIndication_3_inherit_TYPE_descriptor(td);
	return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

static asn_dec_rval_t
securityCapabilityIndication_3_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const void *bufptr, size_t size, int tag_mode) {
	securityCapabilityIndication_3_inherit_TYPE_descriptor(td);
	return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

static asn_enc_rval_t
securityCapabilityIndication_3_encode_der(asn_TYPE_descriptor_t *td,
		void *structure, int tag_mode, ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *cb, void *app_key) {
	securityCapabilityIndication_3_inherit_TYPE_descriptor(td);
	return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

static asn_dec_rval_t
securityCapabilityIndication_3_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const char *opt_mname, const void *bufptr, size_t size) {
	securityCapabilityIndication_3_inherit_TYPE_descriptor(td);
	return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

static asn_enc_rval_t
securityCapabilityIndication_3_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
		int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	securityCapabilityIndication_3_inherit_TYPE_descriptor(td);
	return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static asn_dec_rval_t
securityCapabilityIndication_3_decode_uper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints, void **structure, asn_per_data_t *per_data) {
	securityCapabilityIndication_3_inherit_TYPE_descriptor(td);
	return td->uper_decoder(opt_codec_ctx, td, constraints, structure, per_data);
}

static asn_enc_rval_t
securityCapabilityIndication_3_encode_uper(asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints,
		void *structure, asn_per_outp_t *per_out) {
	securityCapabilityIndication_3_inherit_TYPE_descriptor(td);
	return td->uper_encoder(td, constraints, structure, per_out);
}

static int
ganssSupportIndication_5_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	/* Replace with underlying type checker */
	td->check_constraints = asn_DEF_NativeEnumerated.check_constraints;
	return td->check_constraints(td, sptr, ctfailcb, app_key);
}

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
static void
ganssSupportIndication_5_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {
	td->free_struct    = asn_DEF_NativeEnumerated.free_struct;
	td->print_struct   = asn_DEF_NativeEnumerated.print_struct;
	td->ber_decoder    = asn_DEF_NativeEnumerated.ber_decoder;
	td->der_encoder    = asn_DEF_NativeEnumerated.der_encoder;
	td->xer_decoder    = asn_DEF_NativeEnumerated.xer_decoder;
	td->xer_encoder    = asn_DEF_NativeEnumerated.xer_encoder;
	td->uper_decoder   = asn_DEF_NativeEnumerated.uper_decoder;
	td->uper_encoder   = asn_DEF_NativeEnumerated.uper_encoder;
	if(!td->per_constraints)
		td->per_constraints = asn_DEF_NativeEnumerated.per_constraints;
	td->elements       = asn_DEF_NativeEnumerated.elements;
	td->elements_count = asn_DEF_NativeEnumerated.elements_count;
     /* td->specifics      = asn_DEF_NativeEnumerated.specifics;	// Defined explicitly */
}

static void
ganssSupportIndication_5_free(asn_TYPE_descriptor_t *td,
		void *struct_ptr, int contents_only) {
	ganssSupportIndication_5_inherit_TYPE_descriptor(td);
	td->free_struct(td, struct_ptr, contents_only);
}

static int
ganssSupportIndication_5_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
		int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	ganssSupportIndication_5_inherit_TYPE_descriptor(td);
	return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

static asn_dec_rval_t
ganssSupportIndication_5_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const void *bufptr, size_t size, int tag_mode) {
	ganssSupportIndication_5_inherit_TYPE_descriptor(td);
	return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

static asn_enc_rval_t
ganssSupportIndication_5_encode_der(asn_TYPE_descriptor_t *td,
		void *structure, int tag_mode, ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *cb, void *app_key) {
	ganssSupportIndication_5_inherit_TYPE_descriptor(td);
	return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

static asn_dec_rval_t
ganssSupportIndication_5_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const char *opt_mname, const void *bufptr, size_t size) {
	ganssSupportIndication_5_inherit_TYPE_descriptor(td);
	return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

static asn_enc_rval_t
ganssSupportIndication_5_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
		int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	ganssSupportIndication_5_inherit_TYPE_descriptor(td);
	return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static asn_dec_rval_t
ganssSupportIndication_5_decode_uper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints, void **structure, asn_per_data_t *per_data) {
	ganssSupportIndication_5_inherit_TYPE_descriptor(td);
	return td->uper_decoder(opt_codec_ctx, td, constraints, structure, per_data);
}

static asn_enc_rval_t
ganssSupportIndication_5_encode_uper(asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints,
		void *structure, asn_per_outp_t *per_out) {
	ganssSupportIndication_5_inherit_TYPE_descriptor(td);
	return td->uper_encoder(td, constraints, structure, per_out);
}

static int
mac_ehsSupport_7_constraint(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	/* Replace with underlying type checker */
	td->check_constraints = asn_DEF_NativeEnumerated.check_constraints;
	return td->check_constraints(td, sptr, ctfailcb, app_key);
}

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
static void
mac_ehsSupport_7_inherit_TYPE_descriptor(asn_TYPE_descriptor_t *td) {
	td->free_struct    = asn_DEF_NativeEnumerated.free_struct;
	td->print_struct   = asn_DEF_NativeEnumerated.print_struct;
	td->ber_decoder    = asn_DEF_NativeEnumerated.ber_decoder;
	td->der_encoder    = asn_DEF_NativeEnumerated.der_encoder;
	td->xer_decoder    = asn_DEF_NativeEnumerated.xer_decoder;
	td->xer_encoder    = asn_DEF_NativeEnumerated.xer_encoder;
	td->uper_decoder   = asn_DEF_NativeEnumerated.uper_decoder;
	td->uper_encoder   = asn_DEF_NativeEnumerated.uper_encoder;
	if(!td->per_constraints)
		td->per_constraints = asn_DEF_NativeEnumerated.per_constraints;
	td->elements       = asn_DEF_NativeEnumerated.elements;
	td->elements_count = asn_DEF_NativeEnumerated.elements_count;
     /* td->specifics      = asn_DEF_NativeEnumerated.specifics;	// Defined explicitly */
}

static void
mac_ehsSupport_7_free(asn_TYPE_descriptor_t *td,
		void *struct_ptr, int contents_only) {
	mac_ehsSupport_7_inherit_TYPE_descriptor(td);
	td->free_struct(td, struct_ptr, contents_only);
}

static int
mac_ehsSupport_7_print(asn_TYPE_descriptor_t *td, const void *struct_ptr,
		int ilevel, asn_app_consume_bytes_f *cb, void *app_key) {
	mac_ehsSupport_7_inherit_TYPE_descriptor(td);
	return td->print_struct(td, struct_ptr, ilevel, cb, app_key);
}

static asn_dec_rval_t
mac_ehsSupport_7_decode_ber(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const void *bufptr, size_t size, int tag_mode) {
	mac_ehsSupport_7_inherit_TYPE_descriptor(td);
	return td->ber_decoder(opt_codec_ctx, td, structure, bufptr, size, tag_mode);
}

static asn_enc_rval_t
mac_ehsSupport_7_encode_der(asn_TYPE_descriptor_t *td,
		void *structure, int tag_mode, ber_tlv_tag_t tag,
		asn_app_consume_bytes_f *cb, void *app_key) {
	mac_ehsSupport_7_inherit_TYPE_descriptor(td);
	return td->der_encoder(td, structure, tag_mode, tag, cb, app_key);
}

static asn_dec_rval_t
mac_ehsSupport_7_decode_xer(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		void **structure, const char *opt_mname, const void *bufptr, size_t size) {
	mac_ehsSupport_7_inherit_TYPE_descriptor(td);
	return td->xer_decoder(opt_codec_ctx, td, structure, opt_mname, bufptr, size);
}

static asn_enc_rval_t
mac_ehsSupport_7_encode_xer(asn_TYPE_descriptor_t *td, void *structure,
		int ilevel, enum xer_encoder_flags_e flags,
		asn_app_consume_bytes_f *cb, void *app_key) {
	mac_ehsSupport_7_inherit_TYPE_descriptor(td);
	return td->xer_encoder(td, structure, ilevel, flags, cb, app_key);
}

static asn_dec_rval_t
mac_ehsSupport_7_decode_uper(asn_codec_ctx_t *opt_codec_ctx, asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints, void **structure, asn_per_data_t *per_data) {
	mac_ehsSupport_7_inherit_TYPE_descriptor(td);
	return td->uper_decoder(opt_codec_ctx, td, constraints, structure, per_data);
}

static asn_enc_rval_t
mac_ehsSupport_7_encode_uper(asn_TYPE_descriptor_t *td,
		asn_per_constraints_t *constraints,
		void *structure, asn_per_outp_t *per_out) {
	mac_ehsSupport_7_inherit_TYPE_descriptor(td);
	return td->uper_encoder(td, constraints, structure, per_out);
}

static asn_per_constraints_t asn_PER_type_securityCapabilityIndication_constr_3 = {
	{ APC_CONSTRAINED,	 0,  0,  0,  0 }	/* (0..0) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_type_ganssSupportIndication_constr_5 = {
	{ APC_CONSTRAINED,	 0,  0,  0,  0 }	/* (0..0) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_type_mac_ehsSupport_constr_7 = {
	{ APC_CONSTRAINED,	 0,  0,  0,  0 }	/* (0..0) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_INTEGER_enum_map_t asn_MAP_securityCapabilityIndication_value2enum_3[] = {
	{ 0,	4,	"true" }
};
static unsigned int asn_MAP_securityCapabilityIndication_enum2value_3[] = {
	0	/* true(0) */
};
static asn_INTEGER_specifics_t asn_SPC_securityCapabilityIndication_specs_3 = {
	asn_MAP_securityCapabilityIndication_value2enum_3,	/* "tag" => N; sorted by tag */
	asn_MAP_securityCapabilityIndication_enum2value_3,	/* N => "tag"; sorted by N */
	1,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static ber_tlv_tag_t asn_DEF_securityCapabilityIndication_tags_3[] = {
	(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_securityCapabilityIndication_3 = {
	"securityCapabilityIndication",
	"securityCapabilityIndication",
	securityCapabilityIndication_3_free,
	securityCapabilityIndication_3_print,
	securityCapabilityIndication_3_constraint,
	securityCapabilityIndication_3_decode_ber,
	securityCapabilityIndication_3_encode_der,
	securityCapabilityIndication_3_decode_xer,
	securityCapabilityIndication_3_encode_xer,
	securityCapabilityIndication_3_decode_uper,
	securityCapabilityIndication_3_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_securityCapabilityIndication_tags_3,
	sizeof(asn_DEF_securityCapabilityIndication_tags_3)
		/sizeof(asn_DEF_securityCapabilityIndication_tags_3[0]) - 1, /* 1 */
	asn_DEF_securityCapabilityIndication_tags_3,	/* Same as above */
	sizeof(asn_DEF_securityCapabilityIndication_tags_3)
		/sizeof(asn_DEF_securityCapabilityIndication_tags_3[0]), /* 2 */
	&asn_PER_type_securityCapabilityIndication_constr_3,
	0, 0,	/* Defined elsewhere */
	&asn_SPC_securityCapabilityIndication_specs_3	/* Additional specs */
};

static asn_INTEGER_enum_map_t asn_MAP_ganssSupportIndication_value2enum_5[] = {
	{ 0,	4,	"true" }
};
static unsigned int asn_MAP_ganssSupportIndication_enum2value_5[] = {
	0	/* true(0) */
};
static asn_INTEGER_specifics_t asn_SPC_ganssSupportIndication_specs_5 = {
	asn_MAP_ganssSupportIndication_value2enum_5,	/* "tag" => N; sorted by tag */
	asn_MAP_ganssSupportIndication_enum2value_5,	/* N => "tag"; sorted by N */
	1,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static ber_tlv_tag_t asn_DEF_ganssSupportIndication_tags_5[] = {
	(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_ganssSupportIndication_5 = {
	"ganssSupportIndication",
	"ganssSupportIndication",
	ganssSupportIndication_5_free,
	ganssSupportIndication_5_print,
	ganssSupportIndication_5_constraint,
	ganssSupportIndication_5_decode_ber,
	ganssSupportIndication_5_encode_der,
	ganssSupportIndication_5_decode_xer,
	ganssSupportIndication_5_encode_xer,
	ganssSupportIndication_5_decode_uper,
	ganssSupportIndication_5_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_ganssSupportIndication_tags_5,
	sizeof(asn_DEF_ganssSupportIndication_tags_5)
		/sizeof(asn_DEF_ganssSupportIndication_tags_5[0]) - 1, /* 1 */
	asn_DEF_ganssSupportIndication_tags_5,	/* Same as above */
	sizeof(asn_DEF_ganssSupportIndication_tags_5)
		/sizeof(asn_DEF_ganssSupportIndication_tags_5[0]), /* 2 */
	&asn_PER_type_ganssSupportIndication_constr_5,
	0, 0,	/* Defined elsewhere */
	&asn_SPC_ganssSupportIndication_specs_5	/* Additional specs */
};

static asn_INTEGER_enum_map_t asn_MAP_mac_ehsSupport_value2enum_7[] = {
	{ 0,	4,	"true" }
};
static unsigned int asn_MAP_mac_ehsSupport_enum2value_7[] = {
	0	/* true(0) */
};
static asn_INTEGER_specifics_t asn_SPC_mac_ehsSupport_specs_7 = {
	asn_MAP_mac_ehsSupport_value2enum_7,	/* "tag" => N; sorted by tag */
	asn_MAP_mac_ehsSupport_enum2value_7,	/* N => "tag"; sorted by N */
	1,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static ber_tlv_tag_t asn_DEF_mac_ehsSupport_tags_7[] = {
	(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_mac_ehsSupport_7 = {
	"mac-ehsSupport",
	"mac-ehsSupport",
	mac_ehsSupport_7_free,
	mac_ehsSupport_7_print,
	mac_ehsSupport_7_constraint,
	mac_ehsSupport_7_decode_ber,
	mac_ehsSupport_7_encode_der,
	mac_ehsSupport_7_decode_xer,
	mac_ehsSupport_7_encode_xer,
	mac_ehsSupport_7_decode_uper,
	mac_ehsSupport_7_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_mac_ehsSupport_tags_7,
	sizeof(asn_DEF_mac_ehsSupport_tags_7)
		/sizeof(asn_DEF_mac_ehsSupport_tags_7[0]) - 1, /* 1 */
	asn_DEF_mac_ehsSupport_tags_7,	/* Same as above */
	sizeof(asn_DEF_mac_ehsSupport_tags_7)
		/sizeof(asn_DEF_mac_ehsSupport_tags_7[0]), /* 2 */
	&asn_PER_type_mac_ehsSupport_constr_7,
	0, 0,	/* Defined elsewhere */
	&asn_SPC_mac_ehsSupport_specs_7	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_UE_RadioAccessCapabilityComp_v770ext_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct UE_RadioAccessCapabilityComp_v770ext, rf_CapabilityComp),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RF_CapabilityComp_v770ext,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"rf-CapabilityComp"
		},
	{ ATF_POINTER, 3, offsetof(struct UE_RadioAccessCapabilityComp_v770ext, securityCapabilityIndication),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_securityCapabilityIndication_3,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"securityCapabilityIndication"
		},
	{ ATF_POINTER, 2, offsetof(struct UE_RadioAccessCapabilityComp_v770ext, ganssSupportIndication),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ganssSupportIndication_5,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"ganssSupportIndication"
		},
	{ ATF_POINTER, 1, offsetof(struct UE_RadioAccessCapabilityComp_v770ext, mac_ehsSupport),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_mac_ehsSupport_7,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"mac-ehsSupport"
		},
};
static int asn_MAP_UE_RadioAccessCapabilityComp_v770ext_oms_1[] = { 1, 2, 3 };
static ber_tlv_tag_t asn_DEF_UE_RadioAccessCapabilityComp_v770ext_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_UE_RadioAccessCapabilityComp_v770ext_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* rf-CapabilityComp at 3118 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* securityCapabilityIndication at 3119 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* ganssSupportIndication at 3120 */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 } /* mac-ehsSupport at 3121 */
};
static asn_SEQUENCE_specifics_t asn_SPC_UE_RadioAccessCapabilityComp_v770ext_specs_1 = {
	sizeof(struct UE_RadioAccessCapabilityComp_v770ext),
	offsetof(struct UE_RadioAccessCapabilityComp_v770ext, _asn_ctx),
	asn_MAP_UE_RadioAccessCapabilityComp_v770ext_tag2el_1,
	4,	/* Count of tags in the map */
	asn_MAP_UE_RadioAccessCapabilityComp_v770ext_oms_1,	/* Optional members */
	3, 0,	/* Root/Additions */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_UE_RadioAccessCapabilityComp_v770ext = {
	"UE-RadioAccessCapabilityComp-v770ext",
	"UE-RadioAccessCapabilityComp-v770ext",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	SEQUENCE_decode_uper,
	SEQUENCE_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_UE_RadioAccessCapabilityComp_v770ext_tags_1,
	sizeof(asn_DEF_UE_RadioAccessCapabilityComp_v770ext_tags_1)
		/sizeof(asn_DEF_UE_RadioAccessCapabilityComp_v770ext_tags_1[0]), /* 1 */
	asn_DEF_UE_RadioAccessCapabilityComp_v770ext_tags_1,	/* Same as above */
	sizeof(asn_DEF_UE_RadioAccessCapabilityComp_v770ext_tags_1)
		/sizeof(asn_DEF_UE_RadioAccessCapabilityComp_v770ext_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_UE_RadioAccessCapabilityComp_v770ext_1,
	4,	/* Elements count */
	&asn_SPC_UE_RadioAccessCapabilityComp_v770ext_specs_1	/* Additional specs */
};
