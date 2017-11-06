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
 * Automatically generated from yaml/swiftnav/sbp/imu.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup imu Imu
 *
 * * Inertial Measurement Unit (IMU) messages.
 * \{ */

#ifndef LIBSBP_IMU_MESSAGES_H
#define LIBSBP_IMU_MESSAGES_H

#include "common.h"


/** Raw IMU data
 *
 * Raw data from the Inertial Measurement Unit, containing accelerometer and
 * gyroscope readings.
 */
#define SBP_MSG_IMU_RAW 0x0900
typedef struct __attribute__((packed)) {
  u32 tow;      /**< Milliseconds since start of GPS week. If the high bit is set, the
time is unknown or invalid.
 [ms] */
  u8 tow_f;    /**< Milliseconds since start of GPS week, fractional part
 [ms / 256] */
  s16 acc_x;    /**< Acceleration in the body frame X axis */
  s16 acc_y;    /**< Acceleration in the body frame Y axis */
  s16 acc_z;    /**< Acceleration in the body frame Z axis */
  s16 gyr_x;    /**< Angular rate around the body frame X axis */
  s16 gyr_y;    /**< Angular rate around the body frame Y axis */
  s16 gyr_z;    /**< Angular rate around the body frame Z axis */
} msg_imu_raw_t;
int msg_imu_raw_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_imu_raw_t * in, uint64_t max_len, char* out_str);

/** Auxiliary IMU data
 *
 * Auxiliary data specific to a particular IMU. The `imu_type` field will
 * always be consistent but the rest of the payload is device specific and
 * depends on the value of `imu_type`.
 */
#define SBP_MSG_IMU_AUX 0x0901
typedef struct __attribute__((packed)) {
  u8 imu_type;    /**< IMU type */
  s16 temp;        /**< Raw IMU temperature */
  u8 imu_conf;    /**< IMU configuration */
} msg_imu_aux_t;
int msg_imu_aux_t_to_json_str( u16 sender_id, u16 msg_type, u8 msg_len, msg_imu_aux_t * in, uint64_t max_len, char* out_str);

/** \} */

#endif /* LIBSBP_IMU_MESSAGES_H */