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

/*****************************************************************************
 * Automatically generated from yaml/swiftnav/sbp/ext_events.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup ext_events Ext_events
 *
 *  * Messages reporting accurately-timestamped external events,
 * e.g. camera shutter time.
 * \{ */

#ifndef LIBSBP_EXT_EVENTS_MESSAGES_H
#define LIBSBP_EXT_EVENTS_MESSAGES_H

#include "common.h"


/** Reports timestamped external pin event
 *
 * Reports detection of an external event, the GPS time it occurred,
 * which pin it was and whether it was rising or falling.
 */
#define SBP_MSG_EXT_EVENT 0x0101
typedef struct __attribute__((packed)) {
  u16 wn;             /**< GPS week number [weeks] */
  u32 tow;            /**< GPS time of week rounded to the nearest millisecond [ms] */
  s32 ns_residual;    /**< Nanosecond residual of millisecond-rounded TOW (ranges
from -500000 to 500000)
 [ns] */
  u8 flags;          /**< Flags */
  u8 pin;            /**< Pin number.  0..9 = DEBUG0..9. */
} msg_ext_event_t;

#define MSG_0101_TO_JSON msg_ext_event_t_to_json_str
static inline int msg_ext_event_t_to_json_str( msg_ext_event_t * in, char* out_str, int max_len) {
  (void) max_len;
  return sprintf(out_str, "{wn: %hu, tow: %u, ns_residual: %d, flags: %hhu, pin: %hhu}", in->wn, in->tow, in->ns_residual, in->flags, in->pin);
 }

/** \} */

#endif /* LIBSBP_EXT_EVENTS_MESSAGES_H */