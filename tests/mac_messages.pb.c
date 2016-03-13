/* Automatically generated nanopb constant definitions */
/* Generated by nanopb-0.3.6-dev at Sun Mar 13 14:08:56 2016. */

#include "mac_messages.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

const EncryptionScheme Layer2Message_encryption_scheme_default = EncryptionScheme_no_encryption;


const pb_field_t Layer2Message_fields[6] = {
    PB_FIELD(  1, INT32   , REQUIRED, STATIC  , FIRST, Layer2Message, message_type, message_type, 0),
    PB_FIELD(  2, UENUM   , OPTIONAL, STATIC  , OTHER, Layer2Message, encryption_scheme, message_type, &Layer2Message_encryption_scheme_default),
    PB_FIELD(  3, BYTES   , REQUIRED, STATIC  , OTHER, Layer2Message, data, encryption_scheme, 0),
    PB_FIELD(  4, BYTES   , OPTIONAL, STATIC  , OTHER, Layer2Message, nonce, data, 0),
    PB_FIELD(  5, BYTES   , OPTIONAL, STATIC  , OTHER, Layer2Message, mac, nonce, 0),
    PB_LAST_FIELD
};

const pb_field_t Layer3Message_fields[2] = {
    PB_ONEOF_FIELD(content,   1, MESSAGE , ONEOF, STATIC  , FIRST, Layer3Message, node_advertisement, node_advertisement, &NodeAdvertisement_fields),
    PB_LAST_FIELD
};

const pb_field_t NodeAdvertisement_fields[1] = {
    PB_LAST_FIELD
};


/* Check that field information fits in pb_field_t */
#if !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_32BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in 8 or 16 bit
 * field descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(Layer3Message, content.node_advertisement) < 65536 && pb_membersize(Layer3Message, content.node_advertisement) < 65536), YOU_MUST_DEFINE_PB_FIELD_32BIT_FOR_MESSAGES_Layer2Message_Layer3Message_NodeAdvertisement)
#endif

#if !defined(PB_FIELD_16BIT) && !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_16BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in the default
 * 8 bit descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(Layer3Message, content.node_advertisement) < 256 && pb_membersize(Layer3Message, content.node_advertisement) < 256), YOU_MUST_DEFINE_PB_FIELD_16BIT_FOR_MESSAGES_Layer2Message_Layer3Message_NodeAdvertisement)
#endif


/* @@protoc_insertion_point(eof) */
