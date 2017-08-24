/*
 * Copyright (C) 2015 Swift Navigation Inc.
 * Contact: Fergus Noble <fergus@swift-nav.com>
 *
 * This source is subject to the license found in the file 'LICENSE' which must
 * be be distributed together with this source. All other rights reserved.
 *
 * THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 * EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
 */
#include <stdio.h>
#include <ctype.h>
#include "../include/libsbp/common.h"
#include "../include/libsbp/acquisition.h"
#include "../include/libsbp/bootload.h"
#include "../include/libsbp/ext_events.h"
#include "../include/libsbp/file_io.h"
#include "../include/libsbp/flash.h"
#include "../include/libsbp/gnss.h"
#include "../include/libsbp/imu.h"
#include "../include/libsbp/logging.h"
#include "../include/libsbp/navigation.h"
#include "../include/libsbp/ndb.h"
#include "../include/libsbp/observation.h"
#include "../include/libsbp/piksi.h"
#include "../include/libsbp/settings.h"
#include "../include/libsbp/system.h"
#include "../include/libsbp/tracking.h"
#include "../include/libsbp/user.h"

/*****************************************************************************
 * Automatically generated from acquisition.yaml 
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup  
 *
 * * Satellite acquisition messages from the device.
 * \{ */


 #define MSG_001F_TO_JSON msg_acq_result_t_to_json_str


int msg_acq_result_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_acq_result_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"cn0\": %f", in->cn0);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"cp\": %f", in->cp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"cf\": %f", in->cf);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"sid\":");
  json_bufp += sbp_gnss_signal_t_to_json_str(&in->sid, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_0014_TO_JSON msg_acq_result_dep_b_t_to_json_str


int msg_acq_result_dep_b_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_acq_result_dep_b_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"snr\": %f", in->snr);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"cp\": %f", in->cp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"cf\": %f", in->cf);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"sid\":");
  json_bufp += sbp_gnss_signal_t_to_json_str(&in->sid, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_0015_TO_JSON msg_acq_result_dep_a_t_to_json_str


int msg_acq_result_dep_a_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_acq_result_dep_a_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
   
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"snr\": %f, \"cp\": %f, \"cf\": %f, \"prn\": %hhu}", msg_type, sender_id, msg_len, in->snr, in->cp, in->cf, in->prn);} 
 
int acq_sv_profile_t_to_json_str( acq_sv_profile_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp; 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"job_type\": %hhu", in->job_type);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"status\": %hhu", in->status);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"cn0\": %hu", in->cn0);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"int_time\": %hhu", in->int_time);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"sid\":");
  json_bufp += sbp_gnss_signal_t_to_json_str(&in->sid, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"bin_width\": %hu", in->bin_width);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"timestamp\": %u", in->timestamp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"time_spent\": %u", in->time_spent);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"cf_min\": %d", in->cf_min);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"cf_max\": %d", in->cf_max);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"cf\": %d", in->cf);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"cp\": %u", in->cp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_001E_TO_JSON msg_acq_sv_profile_t_to_json_str


int msg_acq_sv_profile_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_acq_sv_profile_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 




/*****************************************************************************
 * Automatically generated from bootload.yaml 
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup  
 *
 *  * Messages for the bootloading configuration of a Piksi 2.3.1.  This message
 * group does not apply to Piksi Multi.
 * 
 * Note that some of these messages share the same message type ID for both the
 * host request and the device response.
 * \{ */


 #define MSG_00B3_TO_JSON msg_bootloader_handshake_req_t_to_json_str


int msg_bootloader_handshake_req_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, void * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_00B4_TO_JSON msg_bootloader_handshake_resp_t_to_json_str


int msg_bootloader_handshake_resp_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_bootloader_handshake_resp_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"flags\": %u", in->flags);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_00B1_TO_JSON msg_bootloader_jump_to_app_t_to_json_str


int msg_bootloader_jump_to_app_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_bootloader_jump_to_app_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
   
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"jump\": %hhu}", msg_type, sender_id, msg_len, in->jump);} 
 #define MSG_00DE_TO_JSON msg_nap_device_dna_req_t_to_json_str


int msg_nap_device_dna_req_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, void * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_00DD_TO_JSON msg_nap_device_dna_resp_t_to_json_str


int msg_nap_device_dna_resp_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_nap_device_dna_resp_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"dna\": {");
  
  for (int i=0; i < 8; i++) {json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->dna[i]);}json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_00B0_TO_JSON msg_bootloader_handshake_dep_a_t_to_json_str


int msg_bootloader_handshake_dep_a_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_bootloader_handshake_dep_a_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 




/*****************************************************************************
 * Automatically generated from ext_events.yaml 
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup  
 *
 *  * Messages reporting accurately-timestamped external events,
 * e.g. camera shutter time.
 * \{ */


 #define MSG_0101_TO_JSON msg_ext_event_t_to_json_str


int msg_ext_event_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_ext_event_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
   
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"wn\": %hu, \"tow\": %u, \"ns_residual\": %d, \"flags\": %hhu, \"pin\": %hhu}", msg_type, sender_id, msg_len, in->wn, in->tow, in->ns_residual, in->flags, in->pin);} 




/*****************************************************************************
 * Automatically generated from file_io.yaml 
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup  
 *
 *  * Messages for using device's onboard flash filesystem
 * functionality. This allows data to be stored persistently in the
 * device's program flash with wear-levelling using a simple filesystem
 * interface. The file system interface (CFS) defines an abstract API
 * for reading directories and for reading and writing files.
 * 
 * Note that some of these messages share the same message type ID for both the
 * host request and the device response.
 * \{ */


 #define MSG_00A8_TO_JSON msg_fileio_read_req_t_to_json_str


int msg_fileio_read_req_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_fileio_read_req_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"sequence\": %u", in->sequence);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"offset\": %u", in->offset);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"chunk_size\": %hhu", in->chunk_size);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_00A3_TO_JSON msg_fileio_read_resp_t_to_json_str


int msg_fileio_read_resp_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_fileio_read_resp_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"sequence\": %u", in->sequence);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_00A9_TO_JSON msg_fileio_read_dir_req_t_to_json_str


int msg_fileio_read_dir_req_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_fileio_read_dir_req_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"sequence\": %u", in->sequence);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"offset\": %u", in->offset);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_00AA_TO_JSON msg_fileio_read_dir_resp_t_to_json_str


int msg_fileio_read_dir_resp_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_fileio_read_dir_resp_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"sequence\": %u", in->sequence);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_00AC_TO_JSON msg_fileio_remove_t_to_json_str


int msg_fileio_remove_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_fileio_remove_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_00AD_TO_JSON msg_fileio_write_req_t_to_json_str


int msg_fileio_write_req_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_fileio_write_req_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"sequence\": %u", in->sequence);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"offset\": %u", in->offset);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_00AB_TO_JSON msg_fileio_write_resp_t_to_json_str


int msg_fileio_write_resp_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_fileio_write_resp_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
   
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"sequence\": %u}", msg_type, sender_id, msg_len, in->sequence);} 




/*****************************************************************************
 * Automatically generated from flash.yaml 
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup  
 *
 *  * Messages for reading/writing the device's onboard flash memory. Many
 * of these messages target specific flash memory peripherals used in
 * Swift Navigation devices: the STM32 flash and the M25Pxx FPGA
 * configuration flash from Piksi 2.3.1.  This module does not apply 
 * to Piksi Multi.
 * \{ */


 #define MSG_00E6_TO_JSON msg_flash_program_t_to_json_str


int msg_flash_program_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_flash_program_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"target\": %hhu", in->target);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"addr_start\": {");
  
  for (int i=0; i < 3; i++) {json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->addr_start[i]);}json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"addr_len\": %hhu", in->addr_len);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_00E0_TO_JSON msg_flash_done_t_to_json_str


int msg_flash_done_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_flash_done_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
   
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"response\": %hhu}", msg_type, sender_id, msg_len, in->response);} 
 #define MSG_00E7_TO_JSON msg_flash_read_req_t_to_json_str


int msg_flash_read_req_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_flash_read_req_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"target\": %hhu", in->target);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"addr_start\": {");
  
  for (int i=0; i < 3; i++) {json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->addr_start[i]);}json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"addr_len\": %hhu", in->addr_len);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_00E1_TO_JSON msg_flash_read_resp_t_to_json_str


int msg_flash_read_resp_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_flash_read_resp_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"target\": %hhu", in->target);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"addr_start\": {");
  
  for (int i=0; i < 3; i++) {json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->addr_start[i]);}json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"addr_len\": %hhu", in->addr_len);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_00E2_TO_JSON msg_flash_erase_t_to_json_str


int msg_flash_erase_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_flash_erase_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
   
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"target\": %hhu, \"sector_num\": %u}", msg_type, sender_id, msg_len, in->target, in->sector_num);} 
 #define MSG_00E3_TO_JSON msg_stm_flash_lock_sector_t_to_json_str


int msg_stm_flash_lock_sector_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_stm_flash_lock_sector_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
   
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"sector\": %u}", msg_type, sender_id, msg_len, in->sector);} 
 #define MSG_00E4_TO_JSON msg_stm_flash_unlock_sector_t_to_json_str


int msg_stm_flash_unlock_sector_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_stm_flash_unlock_sector_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
   
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"sector\": %u}", msg_type, sender_id, msg_len, in->sector);} 
 #define MSG_00E8_TO_JSON msg_stm_unique_id_req_t_to_json_str


int msg_stm_unique_id_req_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, void * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_00E5_TO_JSON msg_stm_unique_id_resp_t_to_json_str


int msg_stm_unique_id_resp_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_stm_unique_id_resp_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"stm_id\": {");
  
  for (int i=0; i < 12; i++) {json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->stm_id[i]);}json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_00F3_TO_JSON msg_m25_flash_write_status_t_to_json_str


int msg_m25_flash_write_status_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_m25_flash_write_status_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"status\": {");
  
  for (int i=0; i < 1; i++) {json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->status[i]);}json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 




/*****************************************************************************
 * Automatically generated from gnss.yaml 
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup  
 *
 * * Various structs shared between modules
 * \{ */


 
int gnss_signal16_t_to_json_str( gnss_signal16_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"sat\": %hhu, \"code\": %hhu}", in->sat, in->code);} 
 
int sbp_gnss_signal_t_to_json_str( sbp_gnss_signal_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"sat\": %hu, \"code\": %hhu, \"reserved\": %hhu}", in->sat, in->code, in->reserved);} 
 
int sbp_gps_time_t_to_json_str( sbp_gps_time_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"tow\": %u, \"wn\": %hu}", in->tow, in->wn);} 
 
int gps_time_sec_t_to_json_str( gps_time_sec_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"tow\": %u, \"wn\": %hu}", in->tow, in->wn);} 
 
int gps_time_nano_t_to_json_str( gps_time_nano_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"tow\": %u, \"ns_residual\": %d, \"wn\": %hu}", in->tow, in->ns_residual, in->wn);} 
 
int carrier_phase_t_to_json_str( carrier_phase_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"i\": %d, \"f\": %hhu}", in->i, in->f);} 




/*****************************************************************************
 * Automatically generated from imu.yaml 
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup  
 *
 * * Inertial Measurement Unit (IMU) messages.
 * \{ */


 #define MSG_0900_TO_JSON msg_imu_raw_t_to_json_str


int msg_imu_raw_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_imu_raw_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
   
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tow\": %u, \"tow_f\": %hhu, \"acc_x\": %hd, \"acc_y\": %hd, \"acc_z\": %hd, \"gyr_x\": %hd, \"gyr_y\": %hd, \"gyr_z\": %hd}", msg_type, sender_id, msg_len, in->tow, in->tow_f, in->acc_x, in->acc_y, in->acc_z, in->gyr_x, in->gyr_y, in->gyr_z);} 
 #define MSG_0901_TO_JSON msg_imu_aux_t_to_json_str


int msg_imu_aux_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_imu_aux_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
   
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"imu_type\": %hhu, \"temp\": %hd, \"imu_conf\": %hhu}", msg_type, sender_id, msg_len, in->imu_type, in->temp, in->imu_conf);} 




/*****************************************************************************
 * Automatically generated from logging.yaml 
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup  
 *
 *  * Logging and debugging messages from the device.
 * \{ */


 #define MSG_0401_TO_JSON msg_log_t_to_json_str


int msg_log_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_log_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"level\": %hhu", in->level);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_0402_TO_JSON msg_fwd_t_to_json_str


int msg_fwd_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_fwd_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"source\": %hhu", in->source);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"protocol\": %hhu", in->protocol);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_0012_TO_JSON msg_tweet_t_to_json_str


int msg_tweet_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_tweet_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"tweet\":\"");
  for (int i=0; i < 140; i++) {
    unsigned char c = in->tweet[i];
    if (isprint(c) && c != '\\') {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "%c", c);
    }
    else {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "\\\\u00%02x", c);
    }
  }
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_0010_TO_JSON msg_print_dep_t_to_json_str


int msg_print_dep_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_print_dep_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 




/*****************************************************************************
 * Automatically generated from navigation.yaml 
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup  
 *
 *  * Geodetic navigation messages reporting GPS time, position, velocity,
 * and baseline position solutions. For position solutions, these
 * messages define several different position solutions: single-point
 * (SPP), RTK, and pseudo-absolute position solutions.
 * 
 * The SPP is the standalone, absolute GPS position solution using only
 * a single receiver. The RTK solution is the differential GPS
 * solution, which can use either a fixed/integer or floating carrier
 * phase ambiguity. The pseudo-absolute position solution uses a
 * user-provided, well-surveyed base station position (if available)
 * and the RTK solution in tandem.
 * \{ */


 #define MSG_0102_TO_JSON msg_gps_time_t_to_json_str


int msg_gps_time_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_gps_time_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
   
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"wn\": %hu, \"tow\": %u, \"ns_residual\": %d, \"flags\": %hhu}", msg_type, sender_id, msg_len, in->wn, in->tow, in->ns_residual, in->flags);} 
 #define MSG_0103_TO_JSON msg_utc_time_t_to_json_str


int msg_utc_time_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_utc_time_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
   
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"flags\": %hhu, \"tow\": %u, \"year\": %hu, \"month\": %hhu, \"day\": %hhu, \"hours\": %hhu, \"minutes\": %hhu, \"seconds\": %hhu, \"ns\": %u}", msg_type, sender_id, msg_len, in->flags, in->tow, in->year, in->month, in->day, in->hours, in->minutes, in->seconds, in->ns);} 
 #define MSG_0208_TO_JSON msg_dops_t_to_json_str


int msg_dops_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_dops_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
   
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tow\": %u, \"gdop\": %hu, \"pdop\": %hu, \"tdop\": %hu, \"hdop\": %hu, \"vdop\": %hu, \"flags\": %hhu}", msg_type, sender_id, msg_len, in->tow, in->gdop, in->pdop, in->tdop, in->hdop, in->vdop, in->flags);} 
 #define MSG_0209_TO_JSON msg_pos_ecef_t_to_json_str


int msg_pos_ecef_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_pos_ecef_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
   
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tow\": %u, \"x\": %f, \"y\": %f, \"z\": %f, \"accuracy\": %hu, \"n_sats\": %hhu, \"flags\": %hhu}", msg_type, sender_id, msg_len, in->tow, in->x, in->y, in->z, in->accuracy, in->n_sats, in->flags);} 
 #define MSG_020A_TO_JSON msg_pos_llh_t_to_json_str


int msg_pos_llh_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_pos_llh_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
   
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tow\": %u, \"lat\": %f, \"lon\": %f, \"height\": %f, \"h_accuracy\": %hu, \"v_accuracy\": %hu, \"n_sats\": %hhu, \"flags\": %hhu}", msg_type, sender_id, msg_len, in->tow, in->lat, in->lon, in->height, in->h_accuracy, in->v_accuracy, in->n_sats, in->flags);} 
 #define MSG_020B_TO_JSON msg_baseline_ecef_t_to_json_str


int msg_baseline_ecef_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_baseline_ecef_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
   
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tow\": %u, \"x\": %d, \"y\": %d, \"z\": %d, \"accuracy\": %hu, \"n_sats\": %hhu, \"flags\": %hhu}", msg_type, sender_id, msg_len, in->tow, in->x, in->y, in->z, in->accuracy, in->n_sats, in->flags);} 
 #define MSG_020C_TO_JSON msg_baseline_ned_t_to_json_str


int msg_baseline_ned_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_baseline_ned_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
   
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tow\": %u, \"n\": %d, \"e\": %d, \"d\": %d, \"h_accuracy\": %hu, \"v_accuracy\": %hu, \"n_sats\": %hhu, \"flags\": %hhu}", msg_type, sender_id, msg_len, in->tow, in->n, in->e, in->d, in->h_accuracy, in->v_accuracy, in->n_sats, in->flags);} 
 #define MSG_020D_TO_JSON msg_vel_ecef_t_to_json_str


int msg_vel_ecef_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_vel_ecef_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
   
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tow\": %u, \"x\": %d, \"y\": %d, \"z\": %d, \"accuracy\": %hu, \"n_sats\": %hhu, \"flags\": %hhu}", msg_type, sender_id, msg_len, in->tow, in->x, in->y, in->z, in->accuracy, in->n_sats, in->flags);} 
 #define MSG_020E_TO_JSON msg_vel_ned_t_to_json_str


int msg_vel_ned_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_vel_ned_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
   
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tow\": %u, \"n\": %d, \"e\": %d, \"d\": %d, \"h_accuracy\": %hu, \"v_accuracy\": %hu, \"n_sats\": %hhu, \"flags\": %hhu}", msg_type, sender_id, msg_len, in->tow, in->n, in->e, in->d, in->h_accuracy, in->v_accuracy, in->n_sats, in->flags);} 
 #define MSG_020F_TO_JSON msg_baseline_heading_t_to_json_str


int msg_baseline_heading_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_baseline_heading_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
   
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tow\": %u, \"heading\": %u, \"n_sats\": %hhu, \"flags\": %hhu}", msg_type, sender_id, msg_len, in->tow, in->heading, in->n_sats, in->flags);} 
 #define MSG_0210_TO_JSON msg_age_corrections_t_to_json_str


int msg_age_corrections_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_age_corrections_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
   
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tow\": %u, \"age\": %hu}", msg_type, sender_id, msg_len, in->tow, in->age);} 
 #define MSG_0100_TO_JSON msg_gps_time_dep_a_t_to_json_str


int msg_gps_time_dep_a_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_gps_time_dep_a_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
   
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"wn\": %hu, \"tow\": %u, \"ns_residual\": %d, \"flags\": %hhu}", msg_type, sender_id, msg_len, in->wn, in->tow, in->ns_residual, in->flags);} 
 #define MSG_0206_TO_JSON msg_dops_dep_a_t_to_json_str


int msg_dops_dep_a_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_dops_dep_a_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
   
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tow\": %u, \"gdop\": %hu, \"pdop\": %hu, \"tdop\": %hu, \"hdop\": %hu, \"vdop\": %hu}", msg_type, sender_id, msg_len, in->tow, in->gdop, in->pdop, in->tdop, in->hdop, in->vdop);} 
 #define MSG_0200_TO_JSON msg_pos_ecef_dep_a_t_to_json_str


int msg_pos_ecef_dep_a_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_pos_ecef_dep_a_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
   
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tow\": %u, \"x\": %f, \"y\": %f, \"z\": %f, \"accuracy\": %hu, \"n_sats\": %hhu, \"flags\": %hhu}", msg_type, sender_id, msg_len, in->tow, in->x, in->y, in->z, in->accuracy, in->n_sats, in->flags);} 
 #define MSG_0201_TO_JSON msg_pos_llh_dep_a_t_to_json_str


int msg_pos_llh_dep_a_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_pos_llh_dep_a_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
   
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tow\": %u, \"lat\": %f, \"lon\": %f, \"height\": %f, \"h_accuracy\": %hu, \"v_accuracy\": %hu, \"n_sats\": %hhu, \"flags\": %hhu}", msg_type, sender_id, msg_len, in->tow, in->lat, in->lon, in->height, in->h_accuracy, in->v_accuracy, in->n_sats, in->flags);} 
 #define MSG_0202_TO_JSON msg_baseline_ecef_dep_a_t_to_json_str


int msg_baseline_ecef_dep_a_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_baseline_ecef_dep_a_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
   
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tow\": %u, \"x\": %d, \"y\": %d, \"z\": %d, \"accuracy\": %hu, \"n_sats\": %hhu, \"flags\": %hhu}", msg_type, sender_id, msg_len, in->tow, in->x, in->y, in->z, in->accuracy, in->n_sats, in->flags);} 
 #define MSG_0203_TO_JSON msg_baseline_ned_dep_a_t_to_json_str


int msg_baseline_ned_dep_a_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_baseline_ned_dep_a_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
   
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tow\": %u, \"n\": %d, \"e\": %d, \"d\": %d, \"h_accuracy\": %hu, \"v_accuracy\": %hu, \"n_sats\": %hhu, \"flags\": %hhu}", msg_type, sender_id, msg_len, in->tow, in->n, in->e, in->d, in->h_accuracy, in->v_accuracy, in->n_sats, in->flags);} 
 #define MSG_0204_TO_JSON msg_vel_ecef_dep_a_t_to_json_str


int msg_vel_ecef_dep_a_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_vel_ecef_dep_a_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
   
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tow\": %u, \"x\": %d, \"y\": %d, \"z\": %d, \"accuracy\": %hu, \"n_sats\": %hhu, \"flags\": %hhu}", msg_type, sender_id, msg_len, in->tow, in->x, in->y, in->z, in->accuracy, in->n_sats, in->flags);} 
 #define MSG_0205_TO_JSON msg_vel_ned_dep_a_t_to_json_str


int msg_vel_ned_dep_a_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_vel_ned_dep_a_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
   
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tow\": %u, \"n\": %d, \"e\": %d, \"d\": %d, \"h_accuracy\": %hu, \"v_accuracy\": %hu, \"n_sats\": %hhu, \"flags\": %hhu}", msg_type, sender_id, msg_len, in->tow, in->n, in->e, in->d, in->h_accuracy, in->v_accuracy, in->n_sats, in->flags);} 
 #define MSG_0207_TO_JSON msg_baseline_heading_dep_a_t_to_json_str


int msg_baseline_heading_dep_a_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_baseline_heading_dep_a_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
   
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tow\": %u, \"heading\": %u, \"n_sats\": %hhu, \"flags\": %hhu}", msg_type, sender_id, msg_len, in->tow, in->heading, in->n_sats, in->flags);} 




/*****************************************************************************
 * Automatically generated from ndb.yaml 
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup  
 *
 *  * Messages for logging NDB events.
 * \{ */


 #define MSG_0400_TO_JSON msg_ndb_event_t_to_json_str


int msg_ndb_event_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_ndb_event_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"recv_time\": %llu", in->recv_time);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"event\": %hhu", in->event);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"object_type\": %hhu", in->object_type);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"result\": %hhu", in->result);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"data_source\": %hhu", in->data_source);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"object_sid\":");
  json_bufp += gnss_signal16_t_to_json_str(&in->object_sid, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"src_sid\":");
  json_bufp += gnss_signal16_t_to_json_str(&in->src_sid, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"original_sender\": %hu", in->original_sender);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 




/*****************************************************************************
 * Automatically generated from observation.yaml 
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup  
 *
 * * Satellite observation messages from the device.
 * \{ */


 
int observation_header_t_to_json_str( observation_header_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp; 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"t\":");
  json_bufp += gps_time_nano_t_to_json_str(&in->t, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"n_obs\": %hhu", in->n_obs);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 
int doppler_t_to_json_str( doppler_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"i\": %hd, \"f\": %hhu}", in->i, in->f);} 
 
int packed_obs_content_t_to_json_str( packed_obs_content_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp; 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"P\": %u", in->P);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"L\":");
  json_bufp += carrier_phase_t_to_json_str(&in->L, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"D\":");
  json_bufp += doppler_t_to_json_str(&in->D, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"cn0\": %hhu", in->cn0);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"lock\": %hhu", in->lock);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"flags\": %hhu", in->flags);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"sid\":");
  json_bufp += gnss_signal16_t_to_json_str(&in->sid, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_004A_TO_JSON msg_obs_t_to_json_str


int msg_obs_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_obs_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"header\":");
  json_bufp += observation_header_t_to_json_str(&in->header, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_0044_TO_JSON msg_base_pos_llh_t_to_json_str


int msg_base_pos_llh_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_base_pos_llh_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
   
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"lat\": %f, \"lon\": %f, \"height\": %f}", msg_type, sender_id, msg_len, in->lat, in->lon, in->height);} 
 #define MSG_0048_TO_JSON msg_base_pos_ecef_t_to_json_str


int msg_base_pos_ecef_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_base_pos_ecef_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
   
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"x\": %f, \"y\": %f, \"z\": %f}", msg_type, sender_id, msg_len, in->x, in->y, in->z);} 
 
int ephemeris_common_content_t_to_json_str( ephemeris_common_content_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp; 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"sid\":");
  json_bufp += gnss_signal16_t_to_json_str(&in->sid, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"toe\":");
  json_bufp += gps_time_sec_t_to_json_str(&in->toe, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"ura\": %f", in->ura);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"fit_interval\": %u", in->fit_interval);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"valid\": %hhu", in->valid);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"health_bits\": %hhu", in->health_bits);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 
int ephemeris_common_content_dep_a_t_to_json_str( ephemeris_common_content_dep_a_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp; 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"sid\":");
  json_bufp += sbp_gnss_signal_t_to_json_str(&in->sid, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"toe\":");
  json_bufp += sbp_gps_time_t_to_json_str(&in->toe, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"ura\": %f", in->ura);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"fit_interval\": %u", in->fit_interval);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"valid\": %hhu", in->valid);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"health_bits\": %hhu", in->health_bits);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_0081_TO_JSON msg_ephemeris_gps_dep_e_t_to_json_str


int msg_ephemeris_gps_dep_e_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_ephemeris_gps_dep_e_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"common\":");
  json_bufp += ephemeris_common_content_dep_a_t_to_json_str(&in->common, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"tgd\": %f", in->tgd);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"c_rs\": %f", in->c_rs);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"c_rc\": %f", in->c_rc);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"c_uc\": %f", in->c_uc);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"c_us\": %f", in->c_us);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"c_ic\": %f", in->c_ic);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"c_is\": %f", in->c_is);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"dn\": %f", in->dn);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"m0\": %f", in->m0);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"ecc\": %f", in->ecc);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"sqrta\": %f", in->sqrta);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"omega0\": %f", in->omega0);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"omegadot\": %f", in->omegadot);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"w\": %f", in->w);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"inc\": %f", in->inc);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"inc_dot\": %f", in->inc_dot);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"af0\": %f", in->af0);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"af1\": %f", in->af1);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"af2\": %f", in->af2);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"toc\":");
  json_bufp += sbp_gps_time_t_to_json_str(&in->toc, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"iode\": %hhu", in->iode);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"iodc\": %hu", in->iodc);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_0086_TO_JSON msg_ephemeris_gps_t_to_json_str


int msg_ephemeris_gps_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_ephemeris_gps_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"common\":");
  json_bufp += ephemeris_common_content_t_to_json_str(&in->common, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"tgd\": %f", in->tgd);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"c_rs\": %f", in->c_rs);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"c_rc\": %f", in->c_rc);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"c_uc\": %f", in->c_uc);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"c_us\": %f", in->c_us);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"c_ic\": %f", in->c_ic);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"c_is\": %f", in->c_is);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"dn\": %f", in->dn);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"m0\": %f", in->m0);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"ecc\": %f", in->ecc);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"sqrta\": %f", in->sqrta);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"omega0\": %f", in->omega0);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"omegadot\": %f", in->omegadot);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"w\": %f", in->w);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"inc\": %f", in->inc);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"inc_dot\": %f", in->inc_dot);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"af0\": %f", in->af0);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"af1\": %f", in->af1);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"af2\": %f", in->af2);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"toc\":");
  json_bufp += gps_time_sec_t_to_json_str(&in->toc, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"iode\": %hhu", in->iode);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"iodc\": %hu", in->iodc);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_0082_TO_JSON msg_ephemeris_sbas_dep_a_t_to_json_str


int msg_ephemeris_sbas_dep_a_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_ephemeris_sbas_dep_a_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"common\":");
  json_bufp += ephemeris_common_content_dep_a_t_to_json_str(&in->common, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"pos\": {");
  
  for (int i=0; i < 3; i++) {json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->pos[i]);}json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"vel\": {");
  
  for (int i=0; i < 3; i++) {json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->vel[i]);}json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"acc\": {");
  
  for (int i=0; i < 3; i++) {json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->acc[i]);}json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"a_gf0\": %f", in->a_gf0);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"a_gf1\": %f", in->a_gf1);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_0083_TO_JSON msg_ephemeris_glo_dep_a_t_to_json_str


int msg_ephemeris_glo_dep_a_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_ephemeris_glo_dep_a_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"common\":");
  json_bufp += ephemeris_common_content_dep_a_t_to_json_str(&in->common, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"gamma\": %f", in->gamma);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"tau\": %f", in->tau);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"pos\": {");
  
  for (int i=0; i < 3; i++) {json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->pos[i]);}json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"vel\": {");
  
  for (int i=0; i < 3; i++) {json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->vel[i]);}json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"acc\": {");
  
  for (int i=0; i < 3; i++) {json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->acc[i]);}json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_0084_TO_JSON msg_ephemeris_sbas_t_to_json_str


int msg_ephemeris_sbas_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_ephemeris_sbas_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"common\":");
  json_bufp += ephemeris_common_content_t_to_json_str(&in->common, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"pos\": {");
  
  for (int i=0; i < 3; i++) {json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->pos[i]);}json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"vel\": {");
  
  for (int i=0; i < 3; i++) {json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->vel[i]);}json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"acc\": {");
  
  for (int i=0; i < 3; i++) {json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->acc[i]);}json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"a_gf0\": %f", in->a_gf0);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"a_gf1\": %f", in->a_gf1);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_0085_TO_JSON msg_ephemeris_glo_dep_b_t_to_json_str


int msg_ephemeris_glo_dep_b_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_ephemeris_glo_dep_b_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"common\":");
  json_bufp += ephemeris_common_content_t_to_json_str(&in->common, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"gamma\": %f", in->gamma);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"tau\": %f", in->tau);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"pos\": {");
  
  for (int i=0; i < 3; i++) {json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->pos[i]);}json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"vel\": {");
  
  for (int i=0; i < 3; i++) {json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->vel[i]);}json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"acc\": {");
  
  for (int i=0; i < 3; i++) {json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->acc[i]);}json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_0087_TO_JSON msg_ephemeris_glo_dep_c_t_to_json_str


int msg_ephemeris_glo_dep_c_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_ephemeris_glo_dep_c_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"common\":");
  json_bufp += ephemeris_common_content_t_to_json_str(&in->common, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"gamma\": %f", in->gamma);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"tau\": %f", in->tau);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"d_tau\": %f", in->d_tau);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"pos\": {");
  
  for (int i=0; i < 3; i++) {json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->pos[i]);}json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"vel\": {");
  
  for (int i=0; i < 3; i++) {json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->vel[i]);}json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"acc\": {");
  
  for (int i=0; i < 3; i++) {json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->acc[i]);}json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"fcn\": %hhu", in->fcn);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_0088_TO_JSON msg_ephemeris_glo_t_to_json_str


int msg_ephemeris_glo_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_ephemeris_glo_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"common\":");
  json_bufp += ephemeris_common_content_t_to_json_str(&in->common, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"gamma\": %f", in->gamma);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"tau\": %f", in->tau);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"d_tau\": %f", in->d_tau);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"pos\": {");
  
  for (int i=0; i < 3; i++) {json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->pos[i]);}json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"vel\": {");
  
  for (int i=0; i < 3; i++) {json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->vel[i]);}json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"acc\": {");
  
  for (int i=0; i < 3; i++) {json_bufp += snprintf(json_bufp, json_end - json_bufp, "%f", in->acc[i]);}json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"fcn\": %hhu", in->fcn);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"iod\": %hhu", in->iod);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_0080_TO_JSON msg_ephemeris_dep_d_t_to_json_str


int msg_ephemeris_dep_d_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_ephemeris_dep_d_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"tgd\": %f", in->tgd);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"c_rs\": %f", in->c_rs);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"c_rc\": %f", in->c_rc);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"c_uc\": %f", in->c_uc);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"c_us\": %f", in->c_us);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"c_ic\": %f", in->c_ic);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"c_is\": %f", in->c_is);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"dn\": %f", in->dn);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"m0\": %f", in->m0);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"ecc\": %f", in->ecc);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"sqrta\": %f", in->sqrta);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"omega0\": %f", in->omega0);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"omegadot\": %f", in->omegadot);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"w\": %f", in->w);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"inc\": %f", in->inc);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"inc_dot\": %f", in->inc_dot);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"af0\": %f", in->af0);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"af1\": %f", in->af1);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"af2\": %f", in->af2);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"toe_tow\": %f", in->toe_tow);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"toe_wn\": %hu", in->toe_wn);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"toc_tow\": %f", in->toc_tow);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"toc_wn\": %hu", in->toc_wn);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"valid\": %hhu", in->valid);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"healthy\": %hhu", in->healthy);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"sid\":");
  json_bufp += sbp_gnss_signal_t_to_json_str(&in->sid, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"iode\": %hhu", in->iode);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"iodc\": %hu", in->iodc);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"reserved\": %u", in->reserved);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_001A_TO_JSON msg_ephemeris_dep_a_t_to_json_str


int msg_ephemeris_dep_a_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_ephemeris_dep_a_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
   
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tgd\": %f, \"c_rs\": %f, \"c_rc\": %f, \"c_uc\": %f, \"c_us\": %f, \"c_ic\": %f, \"c_is\": %f, \"dn\": %f, \"m0\": %f, \"ecc\": %f, \"sqrta\": %f, \"omega0\": %f, \"omegadot\": %f, \"w\": %f, \"inc\": %f, \"inc_dot\": %f, \"af0\": %f, \"af1\": %f, \"af2\": %f, \"toe_tow\": %f, \"toe_wn\": %hu, \"toc_tow\": %f, \"toc_wn\": %hu, \"valid\": %hhu, \"healthy\": %hhu, \"prn\": %hhu}", msg_type, sender_id, msg_len, in->tgd, in->c_rs, in->c_rc, in->c_uc, in->c_us, in->c_ic, in->c_is, in->dn, in->m0, in->ecc, in->sqrta, in->omega0, in->omegadot, in->w, in->inc, in->inc_dot, in->af0, in->af1, in->af2, in->toe_tow, in->toe_wn, in->toc_tow, in->toc_wn, in->valid, in->healthy, in->prn);} 
 #define MSG_0046_TO_JSON msg_ephemeris_dep_b_t_to_json_str


int msg_ephemeris_dep_b_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_ephemeris_dep_b_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
   
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"tgd\": %f, \"c_rs\": %f, \"c_rc\": %f, \"c_uc\": %f, \"c_us\": %f, \"c_ic\": %f, \"c_is\": %f, \"dn\": %f, \"m0\": %f, \"ecc\": %f, \"sqrta\": %f, \"omega0\": %f, \"omegadot\": %f, \"w\": %f, \"inc\": %f, \"inc_dot\": %f, \"af0\": %f, \"af1\": %f, \"af2\": %f, \"toe_tow\": %f, \"toe_wn\": %hu, \"toc_tow\": %f, \"toc_wn\": %hu, \"valid\": %hhu, \"healthy\": %hhu, \"prn\": %hhu, \"iode\": %hhu}", msg_type, sender_id, msg_len, in->tgd, in->c_rs, in->c_rc, in->c_uc, in->c_us, in->c_ic, in->c_is, in->dn, in->m0, in->ecc, in->sqrta, in->omega0, in->omegadot, in->w, in->inc, in->inc_dot, in->af0, in->af1, in->af2, in->toe_tow, in->toe_wn, in->toc_tow, in->toc_wn, in->valid, in->healthy, in->prn, in->iode);} 
 #define MSG_0047_TO_JSON msg_ephemeris_dep_c_t_to_json_str


int msg_ephemeris_dep_c_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_ephemeris_dep_c_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"tgd\": %f", in->tgd);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"c_rs\": %f", in->c_rs);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"c_rc\": %f", in->c_rc);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"c_uc\": %f", in->c_uc);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"c_us\": %f", in->c_us);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"c_ic\": %f", in->c_ic);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"c_is\": %f", in->c_is);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"dn\": %f", in->dn);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"m0\": %f", in->m0);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"ecc\": %f", in->ecc);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"sqrta\": %f", in->sqrta);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"omega0\": %f", in->omega0);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"omegadot\": %f", in->omegadot);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"w\": %f", in->w);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"inc\": %f", in->inc);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"inc_dot\": %f", in->inc_dot);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"af0\": %f", in->af0);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"af1\": %f", in->af1);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"af2\": %f", in->af2);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"toe_tow\": %f", in->toe_tow);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"toe_wn\": %hu", in->toe_wn);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"toc_tow\": %f", in->toc_tow);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"toc_wn\": %hu", in->toc_wn);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"valid\": %hhu", in->valid);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"healthy\": %hhu", in->healthy);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"sid\":");
  json_bufp += sbp_gnss_signal_t_to_json_str(&in->sid, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"iode\": %hhu", in->iode);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"iodc\": %hu", in->iodc);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"reserved\": %u", in->reserved);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 
int observation_header_dep_t_to_json_str( observation_header_dep_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp; 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"t\":");
  json_bufp += sbp_gps_time_t_to_json_str(&in->t, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"n_obs\": %hhu", in->n_obs);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 
int carrier_phase_dep_a_t_to_json_str( carrier_phase_dep_a_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"i\": %d, \"f\": %hhu}", in->i, in->f);} 
 
int packed_obs_content_dep_a_t_to_json_str( packed_obs_content_dep_a_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp; 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"P\": %u", in->P);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"L\":");
  json_bufp += carrier_phase_dep_a_t_to_json_str(&in->L, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"cn0\": %hhu", in->cn0);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"lock\": %hu", in->lock);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"prn\": %hhu", in->prn);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 
int packed_obs_content_dep_b_t_to_json_str( packed_obs_content_dep_b_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp; 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"P\": %u", in->P);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"L\":");
  json_bufp += carrier_phase_dep_a_t_to_json_str(&in->L, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"cn0\": %hhu", in->cn0);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"lock\": %hu", in->lock);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"sid\":");
  json_bufp += sbp_gnss_signal_t_to_json_str(&in->sid, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 
int packed_obs_content_dep_c_t_to_json_str( packed_obs_content_dep_c_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp; 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"P\": %u", in->P);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"L\":");
  json_bufp += carrier_phase_t_to_json_str(&in->L, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"cn0\": %hhu", in->cn0);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"lock\": %hu", in->lock);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"sid\":");
  json_bufp += sbp_gnss_signal_t_to_json_str(&in->sid, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_0045_TO_JSON msg_obs_dep_a_t_to_json_str


int msg_obs_dep_a_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_obs_dep_a_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"header\":");
  json_bufp += observation_header_dep_t_to_json_str(&in->header, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_0043_TO_JSON msg_obs_dep_b_t_to_json_str


int msg_obs_dep_b_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_obs_dep_b_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"header\":");
  json_bufp += observation_header_dep_t_to_json_str(&in->header, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_0049_TO_JSON msg_obs_dep_c_t_to_json_str


int msg_obs_dep_c_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_obs_dep_c_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"header\":");
  json_bufp += observation_header_dep_t_to_json_str(&in->header, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_0090_TO_JSON msg_iono_t_to_json_str


int msg_iono_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_iono_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"t_nmct\":");
  json_bufp += gps_time_sec_t_to_json_str(&in->t_nmct, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"a0\": %f", in->a0);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"a1\": %f", in->a1);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"a2\": %f", in->a2);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"a3\": %f", in->a3);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"b0\": %f", in->b0);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"b1\": %f", in->b1);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"b2\": %f", in->b2);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"b3\": %f", in->b3);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_0091_TO_JSON msg_sv_configuration_gps_t_to_json_str


int msg_sv_configuration_gps_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_sv_configuration_gps_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"t_nmct\":");
  json_bufp += gps_time_sec_t_to_json_str(&in->t_nmct, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"l2c_mask\": %u", in->l2c_mask);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_0092_TO_JSON msg_group_delay_dep_a_t_to_json_str


int msg_group_delay_dep_a_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_group_delay_dep_a_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"t_op\":");
  json_bufp += sbp_gps_time_t_to_json_str(&in->t_op, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"prn\": %hhu", in->prn);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"valid\": %hhu", in->valid);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"tgd\": %hd", in->tgd);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"isc_l1ca\": %hd", in->isc_l1ca);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"isc_l2c\": %hd", in->isc_l2c);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_0093_TO_JSON msg_group_delay_t_to_json_str


int msg_group_delay_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_group_delay_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"t_op\":");
  json_bufp += gps_time_sec_t_to_json_str(&in->t_op, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"sid\":");
  json_bufp += sbp_gnss_signal_t_to_json_str(&in->sid, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"valid\": %hhu", in->valid);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"tgd\": %hd", in->tgd);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"isc_l1ca\": %hd", in->isc_l1ca);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"isc_l2c\": %hd", in->isc_l2c);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 
int almanac_common_content_t_to_json_str( almanac_common_content_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp; 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"sid\":");
  json_bufp += sbp_gnss_signal_t_to_json_str(&in->sid, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"toa\":");
  json_bufp += gps_time_sec_t_to_json_str(&in->toa, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"ura\": %f", in->ura);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"fit_interval\": %u", in->fit_interval);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"valid\": %hhu", in->valid);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"health_bits\": %hhu", in->health_bits);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_0070_TO_JSON msg_almanac_gps_t_to_json_str


int msg_almanac_gps_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_almanac_gps_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"common\":");
  json_bufp += almanac_common_content_t_to_json_str(&in->common, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"m0\": %f", in->m0);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"ecc\": %f", in->ecc);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"sqrta\": %f", in->sqrta);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"omega0\": %f", in->omega0);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"omegadot\": %f", in->omegadot);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"w\": %f", in->w);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"inc\": %f", in->inc);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"af0\": %f", in->af0);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"af1\": %f", in->af1);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_0071_TO_JSON msg_almanac_glo_t_to_json_str


int msg_almanac_glo_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_almanac_glo_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"common\":");
  json_bufp += almanac_common_content_t_to_json_str(&in->common, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"lambda_na\": %f", in->lambda_na);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"t_lambda_na\": %f", in->t_lambda_na);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"i\": %f", in->i);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"t\": %f", in->t);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"t_dot\": %f", in->t_dot);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"epsilon\": %f", in->epsilon);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"omega\": %f", in->omega);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_0072_TO_JSON msg_fcns_glo_t_to_json_str


int msg_fcns_glo_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_fcns_glo_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"wn\": %hu", in->wn);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"tow_ms\": %u", in->tow_ms);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"fcns\": {");
  
  for (int i=0; i < 32; i++) {json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->fcns[i]);}json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 




/*****************************************************************************
 * Automatically generated from piksi.yaml 
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup  
 *
 *  * System health, configuration, and diagnostic messages specific to
 * the Piksi L1 receiver, including a variety of legacy messages that
 * may no longer be used.
 * \{ */


 #define MSG_0069_TO_JSON msg_almanac_t_to_json_str


int msg_almanac_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, void * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_0068_TO_JSON msg_set_time_t_to_json_str


int msg_set_time_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, void * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_00B6_TO_JSON msg_reset_t_to_json_str


int msg_reset_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_reset_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
   
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"flags\": %u}", msg_type, sender_id, msg_len, in->flags);} 
 #define MSG_00B2_TO_JSON msg_reset_dep_t_to_json_str


int msg_reset_dep_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, void * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_00C0_TO_JSON msg_cw_results_t_to_json_str


int msg_cw_results_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, void * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_00C1_TO_JSON msg_cw_start_t_to_json_str


int msg_cw_start_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, void * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_0022_TO_JSON msg_reset_filters_t_to_json_str


int msg_reset_filters_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_reset_filters_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
   
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"filter\": %hhu}", msg_type, sender_id, msg_len, in->filter);} 
 #define MSG_0023_TO_JSON msg_init_base_t_to_json_str


int msg_init_base_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, void * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_0017_TO_JSON msg_thread_state_t_to_json_str


int msg_thread_state_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_thread_state_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"name\":\"");
  for (int i=0; i < 20; i++) {
    unsigned char c = in->name[i];
    if (isprint(c) && c != '\\') {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "%c", c);
    }
    else {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "\\\\u00%02x", c);
    }
  }
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"cpu\": %hu", in->cpu);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"stack_free\": %u", in->stack_free);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 
int uart_channel_t_to_json_str( uart_channel_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"tx_throughput\": %f, \"rx_throughput\": %f, \"crc_error_count\": %hu, \"io_error_count\": %hu, \"tx_buffer_level\": %hhu, \"rx_buffer_level\": %hhu}", in->tx_throughput, in->rx_throughput, in->crc_error_count, in->io_error_count, in->tx_buffer_level, in->rx_buffer_level);} 
 
int period_t_to_json_str( period_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"avg\": %d, \"pmin\": %d, \"pmax\": %d, \"current\": %d}", in->avg, in->pmin, in->pmax, in->current);} 
 
int latency_t_to_json_str( latency_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"avg\": %d, \"lmin\": %d, \"lmax\": %d, \"current\": %d}", in->avg, in->lmin, in->lmax, in->current);} 
 #define MSG_001D_TO_JSON msg_uart_state_t_to_json_str


int msg_uart_state_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_uart_state_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"uart_a\":");
  json_bufp += uart_channel_t_to_json_str(&in->uart_a, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"uart_b\":");
  json_bufp += uart_channel_t_to_json_str(&in->uart_b, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"uart_ftdi\":");
  json_bufp += uart_channel_t_to_json_str(&in->uart_ftdi, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"latency\":");
  json_bufp += latency_t_to_json_str(&in->latency, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"obs_period\":");
  json_bufp += period_t_to_json_str(&in->obs_period, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_0018_TO_JSON msg_uart_state_depa_t_to_json_str


int msg_uart_state_depa_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_uart_state_depa_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"uart_a\":");
  json_bufp += uart_channel_t_to_json_str(&in->uart_a, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"uart_b\":");
  json_bufp += uart_channel_t_to_json_str(&in->uart_b, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"uart_ftdi\":");
  json_bufp += uart_channel_t_to_json_str(&in->uart_ftdi, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"latency\":");
  json_bufp += latency_t_to_json_str(&in->latency, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_0019_TO_JSON msg_iar_state_t_to_json_str


int msg_iar_state_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_iar_state_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
   
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"num_hyps\": %u}", msg_type, sender_id, msg_len, in->num_hyps);} 
 #define MSG_001B_TO_JSON msg_mask_satellite_t_to_json_str


int msg_mask_satellite_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_mask_satellite_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"mask\": %hhu", in->mask);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"sid\":");
  json_bufp += sbp_gnss_signal_t_to_json_str(&in->sid, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_00B5_TO_JSON msg_device_monitor_t_to_json_str


int msg_device_monitor_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_device_monitor_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
   
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"dev_vin\": %hd, \"cpu_vint\": %hd, \"cpu_vaux\": %hd, \"cpu_temperature\": %hd, \"fe_temperature\": %hd}", msg_type, sender_id, msg_len, in->dev_vin, in->cpu_vint, in->cpu_vaux, in->cpu_temperature, in->fe_temperature);} 
 #define MSG_00B8_TO_JSON msg_command_req_t_to_json_str


int msg_command_req_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_command_req_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"sequence\": %u", in->sequence);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_00B9_TO_JSON msg_command_resp_t_to_json_str


int msg_command_resp_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_command_resp_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
   
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"sequence\": %u, \"code\": %d}", msg_type, sender_id, msg_len, in->sequence, in->code);} 
 #define MSG_00BC_TO_JSON msg_command_output_t_to_json_str


int msg_command_output_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_command_output_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"sequence\": %u", in->sequence);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_00BA_TO_JSON msg_network_state_req_t_to_json_str


int msg_network_state_req_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, void * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_00BB_TO_JSON msg_network_state_resp_t_to_json_str


int msg_network_state_resp_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_network_state_resp_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"ipv4_address\": {");
  
  for (int i=0; i < 4; i++) {json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->ipv4_address[i]);}json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"ipv4_mask_size\": %hhu", in->ipv4_mask_size);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"ipv6_address\": {");
  
  for (int i=0; i < 16; i++) {json_bufp += snprintf(json_bufp, json_end - json_bufp, "%hhu", in->ipv6_address[i]);}json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"ipv6_mask_size\": %hhu", in->ipv6_mask_size);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"rx_bytes\": %u", in->rx_bytes);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"tx_bytes\": %u", in->tx_bytes);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"interface_name\":\"");
  for (int i=0; i < 16; i++) {
    unsigned char c = in->interface_name[i];
    if (isprint(c) && c != '\\') {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "%c", c);
    }
    else {
    json_bufp += snprintf(json_bufp, json_end - json_bufp, "\\\\u00%02x", c);
    }
  }
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "\"");
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"flags\": %u", in->flags);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_0050_TO_JSON msg_specan_t_to_json_str


int msg_specan_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_specan_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"channel_tag\": %hu", in->channel_tag);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"t\":");
  json_bufp += sbp_gps_time_t_to_json_str(&in->t, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"freq_ref\": %f", in->freq_ref);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"freq_step\": %f", in->freq_step);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"amplitude_ref\": %f", in->amplitude_ref);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"amplitude_unit\": %f", in->amplitude_unit);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 




/*****************************************************************************
 * Automatically generated from settings.yaml 
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup  
 *
 *  * Messages for reading and writing the device's device settings.
 * 
 * Note that some of these messages share the same message type ID for both the
 * host request and the device response. See the accompanying document for
 * descriptions of settings configurations and examples:
 * 
 * https://github.com/swift-nav/piksi\_firmware/blob/master/docs/settings.pdf
 * \{ */


 #define MSG_00A1_TO_JSON msg_settings_save_t_to_json_str


int msg_settings_save_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, void * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_00A0_TO_JSON msg_settings_write_t_to_json_str


int msg_settings_write_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_settings_write_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_00A4_TO_JSON msg_settings_read_req_t_to_json_str


int msg_settings_read_req_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_settings_read_req_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_00A5_TO_JSON msg_settings_read_resp_t_to_json_str


int msg_settings_read_resp_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_settings_read_resp_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_00A2_TO_JSON msg_settings_read_by_index_req_t_to_json_str


int msg_settings_read_by_index_req_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_settings_read_by_index_req_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
   
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"index\": %hu}", msg_type, sender_id, msg_len, in->index);} 
 #define MSG_00A7_TO_JSON msg_settings_read_by_index_resp_t_to_json_str


int msg_settings_read_by_index_resp_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_settings_read_by_index_resp_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"index\": %hu", in->index);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_00A6_TO_JSON msg_settings_read_by_index_done_t_to_json_str


int msg_settings_read_by_index_done_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, void * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_00AE_TO_JSON msg_settings_register_t_to_json_str


int msg_settings_register_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_settings_register_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 




/*****************************************************************************
 * Automatically generated from system.yaml 
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup  
 *
 * * Standardized system messages from Swift Navigation devices.
 * \{ */


 #define MSG_FF00_TO_JSON msg_startup_t_to_json_str


int msg_startup_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_startup_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
   
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"cause\": %hhu, \"startup_type\": %hhu, \"reserved\": %hu}", msg_type, sender_id, msg_len, in->cause, in->startup_type, in->reserved);} 
 #define MSG_FF02_TO_JSON msg_dgnss_status_t_to_json_str


int msg_dgnss_status_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_dgnss_status_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"flags\": %hhu", in->flags);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"latency\": %hu", in->latency);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"num_signals\": %hhu", in->num_signals);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_FFFF_TO_JSON msg_heartbeat_t_to_json_str


int msg_heartbeat_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_heartbeat_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
   
  return sprintf(out_str, "{\"msg_type\": %u, \"sender\": %u, \"length\": %u, \"flags\": %u}", msg_type, sender_id, msg_len, in->flags);} 




/*****************************************************************************
 * Automatically generated from tracking.yaml 
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup  
 *
 *  * Satellite code and carrier-phase tracking messages from the device.
 * \{ */


 #define MSG_0011_TO_JSON msg_tracking_state_detailed_t_to_json_str


int msg_tracking_state_detailed_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_tracking_state_detailed_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"recv_time\": %llu", in->recv_time);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"tot\":");
  json_bufp += sbp_gps_time_t_to_json_str(&in->tot, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"P\": %u", in->P);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"P_std\": %hu", in->P_std);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"L\":");
  json_bufp += carrier_phase_t_to_json_str(&in->L, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"cn0\": %hhu", in->cn0);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"lock\": %hu", in->lock);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"sid\":");
  json_bufp += sbp_gnss_signal_t_to_json_str(&in->sid, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"doppler\": %d", in->doppler);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"doppler_std\": %hu", in->doppler_std);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"uptime\": %u", in->uptime);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"clock_offset\": %hd", in->clock_offset);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"clock_drift\": %hd", in->clock_drift);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"corr_spacing\": %hu", in->corr_spacing);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"acceleration\": %hhd", in->acceleration);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"sync_flags\": %hhu", in->sync_flags);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"tow_flags\": %hhu", in->tow_flags);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"track_flags\": %hhu", in->track_flags);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"nav_flags\": %hhu", in->nav_flags);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"pset_flags\": %hhu", in->pset_flags);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"misc_flags\": %hhu", in->misc_flags);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 
int tracking_channel_state_t_to_json_str( tracking_channel_state_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp; 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"sid\":");
  json_bufp += gnss_signal16_t_to_json_str(&in->sid, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"fcn\": %hhu", in->fcn);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"cn0\": %hhu", in->cn0);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_0041_TO_JSON msg_tracking_state_t_to_json_str


int msg_tracking_state_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_tracking_state_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 
int tracking_channel_correlation_t_to_json_str( tracking_channel_correlation_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"I\": %d, \"Q\": %d}", in->I, in->Q);} 
 #define MSG_001C_TO_JSON msg_tracking_iq_t_to_json_str


int msg_tracking_iq_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_tracking_iq_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"channel\": %hhu", in->channel);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"sid\":");
  json_bufp += sbp_gnss_signal_t_to_json_str(&in->sid, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"corrs\": {");
  
  for (int i=0; i < 3; i++) {json_bufp += tracking_channel_correlation_t_to_json_str(in->corrs, json_end - json_bufp, json_bufp);}json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 
int tracking_channel_state_dep_a_t_to_json_str( tracking_channel_state_dep_a_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
  
  return sprintf(out_str, "{\"state\": %hhu, \"prn\": %hhu, \"cn0\": %f}", in->state, in->prn, in->cn0);} 
 #define MSG_0016_TO_JSON msg_tracking_state_dep_a_t_to_json_str


int msg_tracking_state_dep_a_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_tracking_state_dep_a_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 
int tracking_channel_state_dep_b_t_to_json_str( tracking_channel_state_dep_b_t * in, uint64_t max_len, char* out_str) {
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp; 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"state\": %hhu", in->state);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"sid\":");
  json_bufp += sbp_gnss_signal_t_to_json_str(&in->sid, json_end - json_bufp, json_bufp);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, ", \"cn0\": %f", in->cn0);
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 
 #define MSG_0013_TO_JSON msg_tracking_state_dep_b_t_to_json_str


int msg_tracking_state_dep_b_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_tracking_state_dep_b_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 




/*****************************************************************************
 * Automatically generated from user.yaml 
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup  
 *
 *  * Messages reserved for use by the user.
 * \{ */


 #define MSG_0800_TO_JSON msg_user_data_t_to_json_str


int msg_user_data_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_user_data_t * in, uint64_t max_len, char* out_str) {
  (void) sender_id;
  (void) msg_type;
  (void) msg_len;
  (void) in;
  (void) out_str;
  (void) max_len;
     
  char * const json_end = (char*) out_str + max_len; 
  char * json_bufp = (char*) out_str;
  (void) json_end;
  (void) json_bufp;
  json_bufp += snprintf(out_str, json_end - json_bufp, "{\"msg_type\": %u, \"sender\":%u, \"length\":%u", msg_type, sender_id, msg_len); 
   
  json_bufp += snprintf(json_bufp, json_end - json_bufp, "}");
  return json_bufp - out_str;} 




int sbp2json(u16 sender_id, u16 msg_type, u8 msg_len,
                       u8 payload[], uint64_t max_len, char* out_str) {
switch(msg_type) {
  case 31:
    return msg_acq_result_t_to_json_str(sender_id, msg_type, msg_len, ( msg_acq_result_t *) payload,
           max_len, out_str);
  case 20:
    return msg_acq_result_dep_b_t_to_json_str(sender_id, msg_type, msg_len, ( msg_acq_result_dep_b_t *) payload,
           max_len, out_str);
  case 21:
    return msg_acq_result_dep_a_t_to_json_str(sender_id, msg_type, msg_len, ( msg_acq_result_dep_a_t *) payload,
           max_len, out_str);
  case 30:
    return msg_acq_sv_profile_t_to_json_str(sender_id, msg_type, msg_len, ( msg_acq_sv_profile_t *) payload,
           max_len, out_str);
  case 179:
    return msg_bootloader_handshake_req_t_to_json_str(sender_id, msg_type, msg_len, ( void *) payload,
           max_len, out_str);
  case 180:
    return msg_bootloader_handshake_resp_t_to_json_str(sender_id, msg_type, msg_len, ( msg_bootloader_handshake_resp_t *) payload,
           max_len, out_str);
  case 177:
    return msg_bootloader_jump_to_app_t_to_json_str(sender_id, msg_type, msg_len, ( msg_bootloader_jump_to_app_t *) payload,
           max_len, out_str);
  case 222:
    return msg_nap_device_dna_req_t_to_json_str(sender_id, msg_type, msg_len, ( void *) payload,
           max_len, out_str);
  case 221:
    return msg_nap_device_dna_resp_t_to_json_str(sender_id, msg_type, msg_len, ( msg_nap_device_dna_resp_t *) payload,
           max_len, out_str);
  case 176:
    return msg_bootloader_handshake_dep_a_t_to_json_str(sender_id, msg_type, msg_len, ( msg_bootloader_handshake_dep_a_t *) payload,
           max_len, out_str);
  case 257:
    return msg_ext_event_t_to_json_str(sender_id, msg_type, msg_len, ( msg_ext_event_t *) payload,
           max_len, out_str);
  case 168:
    return msg_fileio_read_req_t_to_json_str(sender_id, msg_type, msg_len, ( msg_fileio_read_req_t *) payload,
           max_len, out_str);
  case 163:
    return msg_fileio_read_resp_t_to_json_str(sender_id, msg_type, msg_len, ( msg_fileio_read_resp_t *) payload,
           max_len, out_str);
  case 169:
    return msg_fileio_read_dir_req_t_to_json_str(sender_id, msg_type, msg_len, ( msg_fileio_read_dir_req_t *) payload,
           max_len, out_str);
  case 170:
    return msg_fileio_read_dir_resp_t_to_json_str(sender_id, msg_type, msg_len, ( msg_fileio_read_dir_resp_t *) payload,
           max_len, out_str);
  case 172:
    return msg_fileio_remove_t_to_json_str(sender_id, msg_type, msg_len, ( msg_fileio_remove_t *) payload,
           max_len, out_str);
  case 173:
    return msg_fileio_write_req_t_to_json_str(sender_id, msg_type, msg_len, ( msg_fileio_write_req_t *) payload,
           max_len, out_str);
  case 171:
    return msg_fileio_write_resp_t_to_json_str(sender_id, msg_type, msg_len, ( msg_fileio_write_resp_t *) payload,
           max_len, out_str);
  case 230:
    return msg_flash_program_t_to_json_str(sender_id, msg_type, msg_len, ( msg_flash_program_t *) payload,
           max_len, out_str);
  case 224:
    return msg_flash_done_t_to_json_str(sender_id, msg_type, msg_len, ( msg_flash_done_t *) payload,
           max_len, out_str);
  case 231:
    return msg_flash_read_req_t_to_json_str(sender_id, msg_type, msg_len, ( msg_flash_read_req_t *) payload,
           max_len, out_str);
  case 225:
    return msg_flash_read_resp_t_to_json_str(sender_id, msg_type, msg_len, ( msg_flash_read_resp_t *) payload,
           max_len, out_str);
  case 226:
    return msg_flash_erase_t_to_json_str(sender_id, msg_type, msg_len, ( msg_flash_erase_t *) payload,
           max_len, out_str);
  case 227:
    return msg_stm_flash_lock_sector_t_to_json_str(sender_id, msg_type, msg_len, ( msg_stm_flash_lock_sector_t *) payload,
           max_len, out_str);
  case 228:
    return msg_stm_flash_unlock_sector_t_to_json_str(sender_id, msg_type, msg_len, ( msg_stm_flash_unlock_sector_t *) payload,
           max_len, out_str);
  case 232:
    return msg_stm_unique_id_req_t_to_json_str(sender_id, msg_type, msg_len, ( void *) payload,
           max_len, out_str);
  case 229:
    return msg_stm_unique_id_resp_t_to_json_str(sender_id, msg_type, msg_len, ( msg_stm_unique_id_resp_t *) payload,
           max_len, out_str);
  case 243:
    return msg_m25_flash_write_status_t_to_json_str(sender_id, msg_type, msg_len, ( msg_m25_flash_write_status_t *) payload,
           max_len, out_str);
  case 2304:
    return msg_imu_raw_t_to_json_str(sender_id, msg_type, msg_len, ( msg_imu_raw_t *) payload,
           max_len, out_str);
  case 2305:
    return msg_imu_aux_t_to_json_str(sender_id, msg_type, msg_len, ( msg_imu_aux_t *) payload,
           max_len, out_str);
  case 1025:
    return msg_log_t_to_json_str(sender_id, msg_type, msg_len, ( msg_log_t *) payload,
           max_len, out_str);
  case 1026:
    return msg_fwd_t_to_json_str(sender_id, msg_type, msg_len, ( msg_fwd_t *) payload,
           max_len, out_str);
  case 18:
    return msg_tweet_t_to_json_str(sender_id, msg_type, msg_len, ( msg_tweet_t *) payload,
           max_len, out_str);
  case 16:
    return msg_print_dep_t_to_json_str(sender_id, msg_type, msg_len, ( msg_print_dep_t *) payload,
           max_len, out_str);
  case 258:
    return msg_gps_time_t_to_json_str(sender_id, msg_type, msg_len, ( msg_gps_time_t *) payload,
           max_len, out_str);
  case 259:
    return msg_utc_time_t_to_json_str(sender_id, msg_type, msg_len, ( msg_utc_time_t *) payload,
           max_len, out_str);
  case 520:
    return msg_dops_t_to_json_str(sender_id, msg_type, msg_len, ( msg_dops_t *) payload,
           max_len, out_str);
  case 521:
    return msg_pos_ecef_t_to_json_str(sender_id, msg_type, msg_len, ( msg_pos_ecef_t *) payload,
           max_len, out_str);
  case 522:
    return msg_pos_llh_t_to_json_str(sender_id, msg_type, msg_len, ( msg_pos_llh_t *) payload,
           max_len, out_str);
  case 523:
    return msg_baseline_ecef_t_to_json_str(sender_id, msg_type, msg_len, ( msg_baseline_ecef_t *) payload,
           max_len, out_str);
  case 524:
    return msg_baseline_ned_t_to_json_str(sender_id, msg_type, msg_len, ( msg_baseline_ned_t *) payload,
           max_len, out_str);
  case 525:
    return msg_vel_ecef_t_to_json_str(sender_id, msg_type, msg_len, ( msg_vel_ecef_t *) payload,
           max_len, out_str);
  case 526:
    return msg_vel_ned_t_to_json_str(sender_id, msg_type, msg_len, ( msg_vel_ned_t *) payload,
           max_len, out_str);
  case 527:
    return msg_baseline_heading_t_to_json_str(sender_id, msg_type, msg_len, ( msg_baseline_heading_t *) payload,
           max_len, out_str);
  case 528:
    return msg_age_corrections_t_to_json_str(sender_id, msg_type, msg_len, ( msg_age_corrections_t *) payload,
           max_len, out_str);
  case 256:
    return msg_gps_time_dep_a_t_to_json_str(sender_id, msg_type, msg_len, ( msg_gps_time_dep_a_t *) payload,
           max_len, out_str);
  case 518:
    return msg_dops_dep_a_t_to_json_str(sender_id, msg_type, msg_len, ( msg_dops_dep_a_t *) payload,
           max_len, out_str);
  case 512:
    return msg_pos_ecef_dep_a_t_to_json_str(sender_id, msg_type, msg_len, ( msg_pos_ecef_dep_a_t *) payload,
           max_len, out_str);
  case 513:
    return msg_pos_llh_dep_a_t_to_json_str(sender_id, msg_type, msg_len, ( msg_pos_llh_dep_a_t *) payload,
           max_len, out_str);
  case 514:
    return msg_baseline_ecef_dep_a_t_to_json_str(sender_id, msg_type, msg_len, ( msg_baseline_ecef_dep_a_t *) payload,
           max_len, out_str);
  case 515:
    return msg_baseline_ned_dep_a_t_to_json_str(sender_id, msg_type, msg_len, ( msg_baseline_ned_dep_a_t *) payload,
           max_len, out_str);
  case 516:
    return msg_vel_ecef_dep_a_t_to_json_str(sender_id, msg_type, msg_len, ( msg_vel_ecef_dep_a_t *) payload,
           max_len, out_str);
  case 517:
    return msg_vel_ned_dep_a_t_to_json_str(sender_id, msg_type, msg_len, ( msg_vel_ned_dep_a_t *) payload,
           max_len, out_str);
  case 519:
    return msg_baseline_heading_dep_a_t_to_json_str(sender_id, msg_type, msg_len, ( msg_baseline_heading_dep_a_t *) payload,
           max_len, out_str);
  case 1024:
    return msg_ndb_event_t_to_json_str(sender_id, msg_type, msg_len, ( msg_ndb_event_t *) payload,
           max_len, out_str);
  case 74:
    return msg_obs_t_to_json_str(sender_id, msg_type, msg_len, ( msg_obs_t *) payload,
           max_len, out_str);
  case 68:
    return msg_base_pos_llh_t_to_json_str(sender_id, msg_type, msg_len, ( msg_base_pos_llh_t *) payload,
           max_len, out_str);
  case 72:
    return msg_base_pos_ecef_t_to_json_str(sender_id, msg_type, msg_len, ( msg_base_pos_ecef_t *) payload,
           max_len, out_str);
  case 129:
    return msg_ephemeris_gps_dep_e_t_to_json_str(sender_id, msg_type, msg_len, ( msg_ephemeris_gps_dep_e_t *) payload,
           max_len, out_str);
  case 134:
    return msg_ephemeris_gps_t_to_json_str(sender_id, msg_type, msg_len, ( msg_ephemeris_gps_t *) payload,
           max_len, out_str);
  case 130:
    return msg_ephemeris_sbas_dep_a_t_to_json_str(sender_id, msg_type, msg_len, ( msg_ephemeris_sbas_dep_a_t *) payload,
           max_len, out_str);
  case 131:
    return msg_ephemeris_glo_dep_a_t_to_json_str(sender_id, msg_type, msg_len, ( msg_ephemeris_glo_dep_a_t *) payload,
           max_len, out_str);
  case 132:
    return msg_ephemeris_sbas_t_to_json_str(sender_id, msg_type, msg_len, ( msg_ephemeris_sbas_t *) payload,
           max_len, out_str);
  case 133:
    return msg_ephemeris_glo_dep_b_t_to_json_str(sender_id, msg_type, msg_len, ( msg_ephemeris_glo_dep_b_t *) payload,
           max_len, out_str);
  case 135:
    return msg_ephemeris_glo_dep_c_t_to_json_str(sender_id, msg_type, msg_len, ( msg_ephemeris_glo_dep_c_t *) payload,
           max_len, out_str);
  case 136:
    return msg_ephemeris_glo_t_to_json_str(sender_id, msg_type, msg_len, ( msg_ephemeris_glo_t *) payload,
           max_len, out_str);
  case 128:
    return msg_ephemeris_dep_d_t_to_json_str(sender_id, msg_type, msg_len, ( msg_ephemeris_dep_d_t *) payload,
           max_len, out_str);
  case 26:
    return msg_ephemeris_dep_a_t_to_json_str(sender_id, msg_type, msg_len, ( msg_ephemeris_dep_a_t *) payload,
           max_len, out_str);
  case 70:
    return msg_ephemeris_dep_b_t_to_json_str(sender_id, msg_type, msg_len, ( msg_ephemeris_dep_b_t *) payload,
           max_len, out_str);
  case 71:
    return msg_ephemeris_dep_c_t_to_json_str(sender_id, msg_type, msg_len, ( msg_ephemeris_dep_c_t *) payload,
           max_len, out_str);
  case 69:
    return msg_obs_dep_a_t_to_json_str(sender_id, msg_type, msg_len, ( msg_obs_dep_a_t *) payload,
           max_len, out_str);
  case 67:
    return msg_obs_dep_b_t_to_json_str(sender_id, msg_type, msg_len, ( msg_obs_dep_b_t *) payload,
           max_len, out_str);
  case 73:
    return msg_obs_dep_c_t_to_json_str(sender_id, msg_type, msg_len, ( msg_obs_dep_c_t *) payload,
           max_len, out_str);
  case 144:
    return msg_iono_t_to_json_str(sender_id, msg_type, msg_len, ( msg_iono_t *) payload,
           max_len, out_str);
  case 145:
    return msg_sv_configuration_gps_t_to_json_str(sender_id, msg_type, msg_len, ( msg_sv_configuration_gps_t *) payload,
           max_len, out_str);
  case 146:
    return msg_group_delay_dep_a_t_to_json_str(sender_id, msg_type, msg_len, ( msg_group_delay_dep_a_t *) payload,
           max_len, out_str);
  case 147:
    return msg_group_delay_t_to_json_str(sender_id, msg_type, msg_len, ( msg_group_delay_t *) payload,
           max_len, out_str);
  case 112:
    return msg_almanac_gps_t_to_json_str(sender_id, msg_type, msg_len, ( msg_almanac_gps_t *) payload,
           max_len, out_str);
  case 113:
    return msg_almanac_glo_t_to_json_str(sender_id, msg_type, msg_len, ( msg_almanac_glo_t *) payload,
           max_len, out_str);
  case 114:
    return msg_fcns_glo_t_to_json_str(sender_id, msg_type, msg_len, ( msg_fcns_glo_t *) payload,
           max_len, out_str);
  case 105:
    return msg_almanac_t_to_json_str(sender_id, msg_type, msg_len, ( void *) payload,
           max_len, out_str);
  case 104:
    return msg_set_time_t_to_json_str(sender_id, msg_type, msg_len, ( void *) payload,
           max_len, out_str);
  case 182:
    return msg_reset_t_to_json_str(sender_id, msg_type, msg_len, ( msg_reset_t *) payload,
           max_len, out_str);
  case 178:
    return msg_reset_dep_t_to_json_str(sender_id, msg_type, msg_len, ( void *) payload,
           max_len, out_str);
  case 192:
    return msg_cw_results_t_to_json_str(sender_id, msg_type, msg_len, ( void *) payload,
           max_len, out_str);
  case 193:
    return msg_cw_start_t_to_json_str(sender_id, msg_type, msg_len, ( void *) payload,
           max_len, out_str);
  case 34:
    return msg_reset_filters_t_to_json_str(sender_id, msg_type, msg_len, ( msg_reset_filters_t *) payload,
           max_len, out_str);
  case 35:
    return msg_init_base_t_to_json_str(sender_id, msg_type, msg_len, ( void *) payload,
           max_len, out_str);
  case 23:
    return msg_thread_state_t_to_json_str(sender_id, msg_type, msg_len, ( msg_thread_state_t *) payload,
           max_len, out_str);
  case 29:
    return msg_uart_state_t_to_json_str(sender_id, msg_type, msg_len, ( msg_uart_state_t *) payload,
           max_len, out_str);
  case 24:
    return msg_uart_state_depa_t_to_json_str(sender_id, msg_type, msg_len, ( msg_uart_state_depa_t *) payload,
           max_len, out_str);
  case 25:
    return msg_iar_state_t_to_json_str(sender_id, msg_type, msg_len, ( msg_iar_state_t *) payload,
           max_len, out_str);
  case 27:
    return msg_mask_satellite_t_to_json_str(sender_id, msg_type, msg_len, ( msg_mask_satellite_t *) payload,
           max_len, out_str);
  case 181:
    return msg_device_monitor_t_to_json_str(sender_id, msg_type, msg_len, ( msg_device_monitor_t *) payload,
           max_len, out_str);
  case 184:
    return msg_command_req_t_to_json_str(sender_id, msg_type, msg_len, ( msg_command_req_t *) payload,
           max_len, out_str);
  case 185:
    return msg_command_resp_t_to_json_str(sender_id, msg_type, msg_len, ( msg_command_resp_t *) payload,
           max_len, out_str);
  case 188:
    return msg_command_output_t_to_json_str(sender_id, msg_type, msg_len, ( msg_command_output_t *) payload,
           max_len, out_str);
  case 186:
    return msg_network_state_req_t_to_json_str(sender_id, msg_type, msg_len, ( void *) payload,
           max_len, out_str);
  case 187:
    return msg_network_state_resp_t_to_json_str(sender_id, msg_type, msg_len, ( msg_network_state_resp_t *) payload,
           max_len, out_str);
  case 80:
    return msg_specan_t_to_json_str(sender_id, msg_type, msg_len, ( msg_specan_t *) payload,
           max_len, out_str);
  case 161:
    return msg_settings_save_t_to_json_str(sender_id, msg_type, msg_len, ( void *) payload,
           max_len, out_str);
  case 160:
    return msg_settings_write_t_to_json_str(sender_id, msg_type, msg_len, ( msg_settings_write_t *) payload,
           max_len, out_str);
  case 164:
    return msg_settings_read_req_t_to_json_str(sender_id, msg_type, msg_len, ( msg_settings_read_req_t *) payload,
           max_len, out_str);
  case 165:
    return msg_settings_read_resp_t_to_json_str(sender_id, msg_type, msg_len, ( msg_settings_read_resp_t *) payload,
           max_len, out_str);
  case 162:
    return msg_settings_read_by_index_req_t_to_json_str(sender_id, msg_type, msg_len, ( msg_settings_read_by_index_req_t *) payload,
           max_len, out_str);
  case 167:
    return msg_settings_read_by_index_resp_t_to_json_str(sender_id, msg_type, msg_len, ( msg_settings_read_by_index_resp_t *) payload,
           max_len, out_str);
  case 166:
    return msg_settings_read_by_index_done_t_to_json_str(sender_id, msg_type, msg_len, ( void *) payload,
           max_len, out_str);
  case 174:
    return msg_settings_register_t_to_json_str(sender_id, msg_type, msg_len, ( msg_settings_register_t *) payload,
           max_len, out_str);
  case 65280:
    return msg_startup_t_to_json_str(sender_id, msg_type, msg_len, ( msg_startup_t *) payload,
           max_len, out_str);
  case 65282:
    return msg_dgnss_status_t_to_json_str(sender_id, msg_type, msg_len, ( msg_dgnss_status_t *) payload,
           max_len, out_str);
  case 65535:
    return msg_heartbeat_t_to_json_str(sender_id, msg_type, msg_len, ( msg_heartbeat_t *) payload,
           max_len, out_str);
  case 17:
    return msg_tracking_state_detailed_t_to_json_str(sender_id, msg_type, msg_len, ( msg_tracking_state_detailed_t *) payload,
           max_len, out_str);
  case 65:
    return msg_tracking_state_t_to_json_str(sender_id, msg_type, msg_len, ( msg_tracking_state_t *) payload,
           max_len, out_str);
  case 28:
    return msg_tracking_iq_t_to_json_str(sender_id, msg_type, msg_len, ( msg_tracking_iq_t *) payload,
           max_len, out_str);
  case 22:
    return msg_tracking_state_dep_a_t_to_json_str(sender_id, msg_type, msg_len, ( msg_tracking_state_dep_a_t *) payload,
           max_len, out_str);
  case 19:
    return msg_tracking_state_dep_b_t_to_json_str(sender_id, msg_type, msg_len, ( msg_tracking_state_dep_b_t *) payload,
           max_len, out_str);
  case 2048:
    return msg_user_data_t_to_json_str(sender_id, msg_type, msg_len, ( msg_user_data_t *) payload,
           max_len, out_str);
  default:
    return 0;
  }
}