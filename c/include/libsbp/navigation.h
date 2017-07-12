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
 * Automatically generated from yaml/swiftnav/sbp/navigation.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup navigation Navigation
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

#ifndef LIBSBP_NAVIGATION_MESSAGES_H
#define LIBSBP_NAVIGATION_MESSAGES_H

#include "common.h"


/** GPS Time
 *
 * This message reports the GPS time, representing the time since
 * the GPS epoch began on midnight January 6, 1980 UTC. GPS time
 * counts the weeks and seconds of the week. The weeks begin at the
 * Saturday/Sunday transition. GPS week 0 began at the beginning of
 * the GPS time scale.
 * 
 * Within each week number, the GPS time of the week is between
 * between 0 and 604800 seconds (=60*60*24*7). Note that GPS time
 * does not accumulate leap seconds, and as of now, has a small
 * offset from UTC. In a message stream, this message precedes a
 * set of other navigation messages referenced to the same time
 * (but lacking the ns field) and indicates a more precise time of
 * these messages.
 */
#define SBP_MSG_GPS_TIME               0x0102
typedef struct __attribute__((packed)) {
  u16 wn;             /**< GPS week number [weeks] */
  u32 tow;            /**< GPS time of week rounded to the nearest millisecond [ms] */
  s32 ns_residual;    /**< Nanosecond residual of millisecond-rounded TOW (ranges
from -500000 to 500000)
 [ns] */
  u8 flags;          /**< Status flags (reserved) */
} msg_gps_time_t;

#define MSG_0102_TO_JSON msg_gps_time_t_to_json_str
static inline int msg_gps_time_t_to_json_str( msg_gps_time_t * in, char* out_str, int max_len) {
  (void) max_len;
  return sprintf(out_str, "{wn: %hu, tow: %u, ns_residual: %d, flags: %hhu}", in->wn, in->tow, in->ns_residual, in->flags);
 }

/** UTC Time
 *
 * This message reports the Universal Coordinated Time (UTC).  Note the flags
 * which indicate the source of the UTC offset value and source of the time fix.
 */
#define SBP_MSG_UTC_TIME               0x0103
typedef struct __attribute__((packed)) {
  u8 flags;      /**< Indicates source and time validity */
  u32 tow;        /**< GPS time of week rounded to the nearest millisecond [ms] */
  u16 year;       /**< Year [year] */
  u8 month;      /**< Month (range 1 .. 12) [months] */
  u8 day;        /**< days in the month (range 1-31) [day] */
  u8 hours;      /**< hours of day (range 0-23) [hours] */
  u8 minutes;    /**< minutes of hour (range 0-59) [minutes] */
  u8 seconds;    /**< seconds of minute (range 0-60) rounded down [seconds] */
  u32 ns;         /**< nanoseconds of second (range 0-999999999) [nanoseconds] */
} msg_utc_time_t;

#define MSG_0103_TO_JSON msg_utc_time_t_to_json_str
static inline int msg_utc_time_t_to_json_str( msg_utc_time_t * in, char* out_str, int max_len) {
  (void) max_len;
  return sprintf(out_str, "{flags: %hhu, tow: %u, year: %hu, month: %hhu, day: %hhu, hours: %hhu, minutes: %hhu, seconds: %hhu, ns: %u}", in->flags, in->tow, in->year, in->month, in->day, in->hours, in->minutes, in->seconds, in->ns);
 }

/** Dilution of Precision
 *
 * This dilution of precision (DOP) message describes the effect of
 * navigation satellite geometry on positional measurement
 * precision.  The flags field indicated whether the DOP reported
 * corresponds to differential or SPP solution.
 */
#define SBP_MSG_DOPS                   0x0208
typedef struct __attribute__((packed)) {
  u32 tow;      /**< GPS Time of Week [ms] */
  u16 gdop;     /**< Geometric Dilution of Precision [0.01] */
  u16 pdop;     /**< Position Dilution of Precision [0.01] */
  u16 tdop;     /**< Time Dilution of Precision [0.01] */
  u16 hdop;     /**< Horizontal Dilution of Precision [0.01] */
  u16 vdop;     /**< Vertical Dilution of Precision [0.01] */
  u8 flags;    /**< Indicates the position solution with which the DOPS message corresponds */
} msg_dops_t;

#define MSG_0208_TO_JSON msg_dops_t_to_json_str
static inline int msg_dops_t_to_json_str( msg_dops_t * in, char* out_str, int max_len) {
  (void) max_len;
  return sprintf(out_str, "{tow: %u, gdop: %hu, pdop: %hu, tdop: %hu, hdop: %hu, vdop: %hu, flags: %hhu}", in->tow, in->gdop, in->pdop, in->tdop, in->hdop, in->vdop, in->flags);
 }

/** Single-point position in ECEF
 *
 * The position solution message reports absolute Earth Centered
 * Earth Fixed (ECEF) coordinates and the status (single point vs
 * pseudo-absolute RTK) of the position solution. If the rover
 * receiver knows the surveyed position of the base station and has
 * an RTK solution, this reports a pseudo-absolute position
 * solution using the base station position and the rover's RTK
 * baseline vector. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow).
 */
#define SBP_MSG_POS_ECEF               0x0209
typedef struct __attribute__((packed)) {
  u32 tow;         /**< GPS Time of Week [ms] */
  double x;           /**< ECEF X coordinate [m] */
  double y;           /**< ECEF Y coordinate [m] */
  double z;           /**< ECEF Z coordinate [m] */
  u16 accuracy;    /**< Position accuracy estimate. [mm] */
  u8 n_sats;      /**< Number of satellites used in solution */
  u8 flags;       /**< Status flags */
} msg_pos_ecef_t;

#define MSG_0209_TO_JSON msg_pos_ecef_t_to_json_str
static inline int msg_pos_ecef_t_to_json_str( msg_pos_ecef_t * in, char* out_str, int max_len) {
  (void) max_len;
  return sprintf(out_str, "{tow: %u, x: %f, y: %f, z: %f, accuracy: %hu, n_sats: %hhu, flags: %hhu}", in->tow, in->x, in->y, in->z, in->accuracy, in->n_sats, in->flags);
 }

/** Geodetic Position
 *
 * This position solution message reports the absolute geodetic
 * coordinates and the status (single point vs pseudo-absolute RTK)
 * of the position solution. If the rover receiver knows the
 * surveyed position of the base station and has an RTK solution,
 * this reports a pseudo-absolute position solution using the base
 * station position and the rover's RTK baseline vector. The full
 * GPS time is given by the preceding MSG_GPS_TIME with the
 * matching time-of-week (tow).
 */
#define SBP_MSG_POS_LLH                0x020A
typedef struct __attribute__((packed)) {
  u32 tow;           /**< GPS Time of Week [ms] */
  double lat;           /**< Latitude [deg] */
  double lon;           /**< Longitude [deg] */
  double height;        /**< Height above WGS84 ellipsoid [m] */
  u16 h_accuracy;    /**< Horizontal position accuracy estimate. [mm] */
  u16 v_accuracy;    /**< Vertical position accuracy estimate. [mm] */
  u8 n_sats;        /**< Number of satellites used in solution. */
  u8 flags;         /**< Status flags */
} msg_pos_llh_t;

#define MSG_020A_TO_JSON msg_pos_llh_t_to_json_str
static inline int msg_pos_llh_t_to_json_str( msg_pos_llh_t * in, char* out_str, int max_len) {
  (void) max_len;
  return sprintf(out_str, "{tow: %u, lat: %f, lon: %f, height: %f, h_accuracy: %hu, v_accuracy: %hu, n_sats: %hhu, flags: %hhu}", in->tow, in->lat, in->lon, in->height, in->h_accuracy, in->v_accuracy, in->n_sats, in->flags);
 }

/** Baseline Position in ECEF
 *
 * This message reports the baseline solution in Earth Centered
 * Earth Fixed (ECEF) coordinates. This baseline is the relative
 * vector distance from the base station to the rover receiver. The
 * full GPS time is given by the preceding MSG_GPS_TIME with the
 * matching time-of-week (tow).
 */
#define SBP_MSG_BASELINE_ECEF          0x020B
typedef struct __attribute__((packed)) {
  u32 tow;         /**< GPS Time of Week [ms] */
  s32 x;           /**< Baseline ECEF X coordinate [mm] */
  s32 y;           /**< Baseline ECEF Y coordinate [mm] */
  s32 z;           /**< Baseline ECEF Z coordinate [mm] */
  u16 accuracy;    /**< Position accuracy estimate [mm] */
  u8 n_sats;      /**< Number of satellites used in solution */
  u8 flags;       /**< Status flags */
} msg_baseline_ecef_t;

#define MSG_020B_TO_JSON msg_baseline_ecef_t_to_json_str
static inline int msg_baseline_ecef_t_to_json_str( msg_baseline_ecef_t * in, char* out_str, int max_len) {
  (void) max_len;
  return sprintf(out_str, "{tow: %u, x: %d, y: %d, z: %d, accuracy: %hu, n_sats: %hhu, flags: %hhu}", in->tow, in->x, in->y, in->z, in->accuracy, in->n_sats, in->flags);
 }

/** Baseline in NED
 *
 * This message reports the baseline solution in North East Down
 * (NED) coordinates. This baseline is the relative vector distance
 * from the base station to the rover receiver, and NED coordinate
 * system is defined at the local WGS84 tangent plane centered at the
 * base station position.  The full GPS time is given by the
 * preceding MSG_GPS_TIME with the matching time-of-week (tow).
 */
#define SBP_MSG_BASELINE_NED           0x020C
typedef struct __attribute__((packed)) {
  u32 tow;           /**< GPS Time of Week [ms] */
  s32 n;             /**< Baseline North coordinate [mm] */
  s32 e;             /**< Baseline East coordinate [mm] */
  s32 d;             /**< Baseline Down coordinate [mm] */
  u16 h_accuracy;    /**< Horizontal position accuracy estimate [mm] */
  u16 v_accuracy;    /**< Vertical position accuracy estimate [mm] */
  u8 n_sats;        /**< Number of satellites used in solution */
  u8 flags;         /**< Status flags */
} msg_baseline_ned_t;

#define MSG_020C_TO_JSON msg_baseline_ned_t_to_json_str
static inline int msg_baseline_ned_t_to_json_str( msg_baseline_ned_t * in, char* out_str, int max_len) {
  (void) max_len;
  return sprintf(out_str, "{tow: %u, n: %d, e: %d, d: %d, h_accuracy: %hu, v_accuracy: %hu, n_sats: %hhu, flags: %hhu}", in->tow, in->n, in->e, in->d, in->h_accuracy, in->v_accuracy, in->n_sats, in->flags);
 }

/** Velocity in ECEF
 *
 * This message reports the velocity in Earth Centered Earth Fixed
 * (ECEF) coordinates. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow).
 */
#define SBP_MSG_VEL_ECEF               0x020D
typedef struct __attribute__((packed)) {
  u32 tow;         /**< GPS Time of Week [ms] */
  s32 x;           /**< Velocity ECEF X coordinate [mm/s] */
  s32 y;           /**< Velocity ECEF Y coordinate [mm/s] */
  s32 z;           /**< Velocity ECEF Z coordinate [mm/s] */
  u16 accuracy;    /**< Velocity accuracy estimate
 [mm/s] */
  u8 n_sats;      /**< Number of satellites used in solution */
  u8 flags;       /**< Status flags */
} msg_vel_ecef_t;

#define MSG_020D_TO_JSON msg_vel_ecef_t_to_json_str
static inline int msg_vel_ecef_t_to_json_str( msg_vel_ecef_t * in, char* out_str, int max_len) {
  (void) max_len;
  return sprintf(out_str, "{tow: %u, x: %d, y: %d, z: %d, accuracy: %hu, n_sats: %hhu, flags: %hhu}", in->tow, in->x, in->y, in->z, in->accuracy, in->n_sats, in->flags);
 }

/** Velocity in NED
 *
 * This message reports the velocity in local North East Down (NED)
 * coordinates. The NED coordinate system is defined as the local WGS84
 * tangent plane centered at the current position. The full GPS time is
 * given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
 */
#define SBP_MSG_VEL_NED                0x020E
typedef struct __attribute__((packed)) {
  u32 tow;           /**< GPS Time of Week [ms] */
  s32 n;             /**< Velocity North coordinate [mm/s] */
  s32 e;             /**< Velocity East coordinate [mm/s] */
  s32 d;             /**< Velocity Down coordinate [mm/s] */
  u16 h_accuracy;    /**< Horizontal velocity accuracy estimate
 [mm/s] */
  u16 v_accuracy;    /**< Vertical velocity accuracy estimate
 [mm/s] */
  u8 n_sats;        /**< Number of satellites used in solution */
  u8 flags;         /**< Status flags */
} msg_vel_ned_t;

#define MSG_020E_TO_JSON msg_vel_ned_t_to_json_str
static inline int msg_vel_ned_t_to_json_str( msg_vel_ned_t * in, char* out_str, int max_len) {
  (void) max_len;
  return sprintf(out_str, "{tow: %u, n: %d, e: %d, d: %d, h_accuracy: %hu, v_accuracy: %hu, n_sats: %hhu, flags: %hhu}", in->tow, in->n, in->e, in->d, in->h_accuracy, in->v_accuracy, in->n_sats, in->flags);
 }

/** Heading relative to True North
 *
 * This message reports the baseline heading pointing from the base station
 * to the rover relative to True North. The full GPS time is given by the
 * preceding MSG_GPS_TIME with the matching time-of-week (tow). It is intended
 * that time-matched RTK mode is used when the base station is moving.
 */
#define SBP_MSG_BASELINE_HEADING       0x020F
typedef struct __attribute__((packed)) {
  u32 tow;        /**< GPS Time of Week [ms] */
  u32 heading;    /**< Heading [mdeg] */
  u8 n_sats;     /**< Number of satellites used in solution */
  u8 flags;      /**< Status flags */
} msg_baseline_heading_t;

#define MSG_020F_TO_JSON msg_baseline_heading_t_to_json_str
static inline int msg_baseline_heading_t_to_json_str( msg_baseline_heading_t * in, char* out_str, int max_len) {
  (void) max_len;
  return sprintf(out_str, "{tow: %u, heading: %u, n_sats: %hhu, flags: %hhu}", in->tow, in->heading, in->n_sats, in->flags);
 }

/** Age of corrections
 *
 * This message reports the Age of the corrections used for the current
 * Differential solution
 */
#define SBP_MSG_AGE_CORRECTIONS        0x0210
typedef struct __attribute__((packed)) {
  u32 tow;    /**< GPS Time of Week [ms] */
  u16 age;    /**< Age of the corrections (0xFFFF indicates invalid) [deciseconds] */
} msg_age_corrections_t;

#define MSG_0210_TO_JSON msg_age_corrections_t_to_json_str
static inline int msg_age_corrections_t_to_json_str( msg_age_corrections_t * in, char* out_str, int max_len) {
  (void) max_len;
  return sprintf(out_str, "{tow: %u, age: %hu}", in->tow, in->age);
 }

/** GPS Time (v1.0)
 *
 * This message reports the GPS time, representing the time since
 * the GPS epoch began on midnight January 6, 1980 UTC. GPS time
 * counts the weeks and seconds of the week. The weeks begin at the
 * Saturday/Sunday transition. GPS week 0 began at the beginning of
 * the GPS time scale.
 * 
 * Within each week number, the GPS time of the week is between
 * between 0 and 604800 seconds (=60*60*24*7). Note that GPS time
 * does not accumulate leap seconds, and as of now, has a small
 * offset from UTC. In a message stream, this message precedes a
 * set of other navigation messages referenced to the same time
 * (but lacking the ns field) and indicates a more precise time of
 * these messages.
 */
#define SBP_MSG_GPS_TIME_DEP_A         0x0100
typedef struct __attribute__((packed)) {
  u16 wn;             /**< GPS week number [weeks] */
  u32 tow;            /**< GPS time of week rounded to the nearest millisecond [ms] */
  s32 ns_residual;    /**< Nanosecond residual of millisecond-rounded TOW (ranges
from -500000 to 500000)
 [ns] */
  u8 flags;          /**< Status flags (reserved) */
} msg_gps_time_dep_a_t;

#define MSG_0100_TO_JSON msg_gps_time_dep_a_t_to_json_str
static inline int msg_gps_time_dep_a_t_to_json_str( msg_gps_time_dep_a_t * in, char* out_str, int max_len) {
  (void) max_len;
  return sprintf(out_str, "{wn: %hu, tow: %u, ns_residual: %d, flags: %hhu}", in->wn, in->tow, in->ns_residual, in->flags);
 }

/** Dilution of Precision
 *
 * This dilution of precision (DOP) message describes the effect of
 * navigation satellite geometry on positional measurement
 * precision.
 */
#define SBP_MSG_DOPS_DEP_A             0x0206
typedef struct __attribute__((packed)) {
  u32 tow;     /**< GPS Time of Week [ms] */
  u16 gdop;    /**< Geometric Dilution of Precision [0.01] */
  u16 pdop;    /**< Position Dilution of Precision [0.01] */
  u16 tdop;    /**< Time Dilution of Precision [0.01] */
  u16 hdop;    /**< Horizontal Dilution of Precision [0.01] */
  u16 vdop;    /**< Vertical Dilution of Precision [0.01] */
} msg_dops_dep_a_t;

#define MSG_0206_TO_JSON msg_dops_dep_a_t_to_json_str
static inline int msg_dops_dep_a_t_to_json_str( msg_dops_dep_a_t * in, char* out_str, int max_len) {
  (void) max_len;
  return sprintf(out_str, "{tow: %u, gdop: %hu, pdop: %hu, tdop: %hu, hdop: %hu, vdop: %hu}", in->tow, in->gdop, in->pdop, in->tdop, in->hdop, in->vdop);
 }

/** Single-point position in ECEF
 *
 * The position solution message reports absolute Earth Centered
 * Earth Fixed (ECEF) coordinates and the status (single point vs
 * pseudo-absolute RTK) of the position solution. If the rover
 * receiver knows the surveyed position of the base station and has
 * an RTK solution, this reports a pseudo-absolute position
 * solution using the base station position and the rover's RTK
 * baseline vector. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow).
 */
#define SBP_MSG_POS_ECEF_DEP_A         0x0200
typedef struct __attribute__((packed)) {
  u32 tow;         /**< GPS Time of Week [ms] */
  double x;           /**< ECEF X coordinate [m] */
  double y;           /**< ECEF Y coordinate [m] */
  double z;           /**< ECEF Z coordinate [m] */
  u16 accuracy;    /**< Position accuracy estimate (not implemented). Defaults
to 0.
 [mm] */
  u8 n_sats;      /**< Number of satellites used in solution */
  u8 flags;       /**< Status flags */
} msg_pos_ecef_dep_a_t;

#define MSG_0200_TO_JSON msg_pos_ecef_dep_a_t_to_json_str
static inline int msg_pos_ecef_dep_a_t_to_json_str( msg_pos_ecef_dep_a_t * in, char* out_str, int max_len) {
  (void) max_len;
  return sprintf(out_str, "{tow: %u, x: %f, y: %f, z: %f, accuracy: %hu, n_sats: %hhu, flags: %hhu}", in->tow, in->x, in->y, in->z, in->accuracy, in->n_sats, in->flags);
 }

/** Geodetic Position
 *
 * This position solution message reports the absolute geodetic
 * coordinates and the status (single point vs pseudo-absolute RTK)
 * of the position solution. If the rover receiver knows the
 * surveyed position of the base station and has an RTK solution,
 * this reports a pseudo-absolute position solution using the base
 * station position and the rover's RTK baseline vector. The full
 * GPS time is given by the preceding MSG_GPS_TIME with the
 * matching time-of-week (tow).
 */
#define SBP_MSG_POS_LLH_DEP_A          0x0201
typedef struct __attribute__((packed)) {
  u32 tow;           /**< GPS Time of Week [ms] */
  double lat;           /**< Latitude [deg] */
  double lon;           /**< Longitude [deg] */
  double height;        /**< Height [m] */
  u16 h_accuracy;    /**< Horizontal position accuracy estimate (not
implemented). Defaults to 0.
 [mm] */
  u16 v_accuracy;    /**< Vertical position accuracy estimate (not
implemented). Defaults to 0.
 [mm] */
  u8 n_sats;        /**< Number of satellites used in solution. */
  u8 flags;         /**< Status flags */
} msg_pos_llh_dep_a_t;

#define MSG_0201_TO_JSON msg_pos_llh_dep_a_t_to_json_str
static inline int msg_pos_llh_dep_a_t_to_json_str( msg_pos_llh_dep_a_t * in, char* out_str, int max_len) {
  (void) max_len;
  return sprintf(out_str, "{tow: %u, lat: %f, lon: %f, height: %f, h_accuracy: %hu, v_accuracy: %hu, n_sats: %hhu, flags: %hhu}", in->tow, in->lat, in->lon, in->height, in->h_accuracy, in->v_accuracy, in->n_sats, in->flags);
 }

/** Baseline Position in ECEF
 *
 * This message reports the baseline solution in Earth Centered
 * Earth Fixed (ECEF) coordinates. This baseline is the relative
 * vector distance from the base station to the rover receiver. The
 * full GPS time is given by the preceding MSG_GPS_TIME with the
 * matching time-of-week (tow).
 */
#define SBP_MSG_BASELINE_ECEF_DEP_A    0x0202
typedef struct __attribute__((packed)) {
  u32 tow;         /**< GPS Time of Week [ms] */
  s32 x;           /**< Baseline ECEF X coordinate [mm] */
  s32 y;           /**< Baseline ECEF Y coordinate [mm] */
  s32 z;           /**< Baseline ECEF Z coordinate [mm] */
  u16 accuracy;    /**< Position accuracy estimate
 [mm] */
  u8 n_sats;      /**< Number of satellites used in solution */
  u8 flags;       /**< Status flags */
} msg_baseline_ecef_dep_a_t;

#define MSG_0202_TO_JSON msg_baseline_ecef_dep_a_t_to_json_str
static inline int msg_baseline_ecef_dep_a_t_to_json_str( msg_baseline_ecef_dep_a_t * in, char* out_str, int max_len) {
  (void) max_len;
  return sprintf(out_str, "{tow: %u, x: %d, y: %d, z: %d, accuracy: %hu, n_sats: %hhu, flags: %hhu}", in->tow, in->x, in->y, in->z, in->accuracy, in->n_sats, in->flags);
 }

/** Baseline in NED
 *
 * This message reports the baseline solution in North East Down
 * (NED) coordinates. This baseline is the relative vector distance
 * from the base station to the rover receiver, and NED coordinate
 * system is defined at the local WGS84 tangent plane centered at the
 * base station position.  The full GPS time is given by the
 * preceding MSG_GPS_TIME with the matching time-of-week (tow).
 */
#define SBP_MSG_BASELINE_NED_DEP_A     0x0203
typedef struct __attribute__((packed)) {
  u32 tow;           /**< GPS Time of Week [ms] */
  s32 n;             /**< Baseline North coordinate [mm] */
  s32 e;             /**< Baseline East coordinate [mm] */
  s32 d;             /**< Baseline Down coordinate [mm] */
  u16 h_accuracy;    /**< Horizontal position accuracy estimate (not
implemented). Defaults to 0.
 [mm] */
  u16 v_accuracy;    /**< Vertical position accuracy estimate (not
implemented). Defaults to 0.
 [mm] */
  u8 n_sats;        /**< Number of satellites used in solution */
  u8 flags;         /**< Status flags */
} msg_baseline_ned_dep_a_t;

#define MSG_0203_TO_JSON msg_baseline_ned_dep_a_t_to_json_str
static inline int msg_baseline_ned_dep_a_t_to_json_str( msg_baseline_ned_dep_a_t * in, char* out_str, int max_len) {
  (void) max_len;
  return sprintf(out_str, "{tow: %u, n: %d, e: %d, d: %d, h_accuracy: %hu, v_accuracy: %hu, n_sats: %hhu, flags: %hhu}", in->tow, in->n, in->e, in->d, in->h_accuracy, in->v_accuracy, in->n_sats, in->flags);
 }

/** Velocity in ECEF
 *
 * This message reports the velocity in Earth Centered Earth Fixed
 * (ECEF) coordinates. The full GPS time is given by the preceding
 * MSG_GPS_TIME with the matching time-of-week (tow).
 */
#define SBP_MSG_VEL_ECEF_DEP_A         0x0204
typedef struct __attribute__((packed)) {
  u32 tow;         /**< GPS Time of Week [ms] */
  s32 x;           /**< Velocity ECEF X coordinate [mm/s] */
  s32 y;           /**< Velocity ECEF Y coordinate [mm/s] */
  s32 z;           /**< Velocity ECEF Z coordinate [mm/s] */
  u16 accuracy;    /**< Velocity accuracy estimate (not implemented). Defaults
to 0.
 [mm/s] */
  u8 n_sats;      /**< Number of satellites used in solution */
  u8 flags;       /**< Status flags (reserved) */
} msg_vel_ecef_dep_a_t;

#define MSG_0204_TO_JSON msg_vel_ecef_dep_a_t_to_json_str
static inline int msg_vel_ecef_dep_a_t_to_json_str( msg_vel_ecef_dep_a_t * in, char* out_str, int max_len) {
  (void) max_len;
  return sprintf(out_str, "{tow: %u, x: %d, y: %d, z: %d, accuracy: %hu, n_sats: %hhu, flags: %hhu}", in->tow, in->x, in->y, in->z, in->accuracy, in->n_sats, in->flags);
 }

/** Velocity in NED
 *
 * This message reports the velocity in local North East Down (NED)
 * coordinates. The NED coordinate system is defined as the local WGS84
 * tangent plane centered at the current position. The full GPS time is
 * given by the preceding MSG_GPS_TIME with the matching time-of-week (tow).
 */
#define SBP_MSG_VEL_NED_DEP_A          0x0205
typedef struct __attribute__((packed)) {
  u32 tow;           /**< GPS Time of Week [ms] */
  s32 n;             /**< Velocity North coordinate [mm/s] */
  s32 e;             /**< Velocity East coordinate [mm/s] */
  s32 d;             /**< Velocity Down coordinate [mm/s] */
  u16 h_accuracy;    /**< Horizontal velocity accuracy estimate (not
implemented). Defaults to 0.
 [mm/s] */
  u16 v_accuracy;    /**< Vertical velocity accuracy estimate (not
implemented). Defaults to 0.
 [mm/s] */
  u8 n_sats;        /**< Number of satellites used in solution */
  u8 flags;         /**< Status flags (reserved) */
} msg_vel_ned_dep_a_t;

#define MSG_0205_TO_JSON msg_vel_ned_dep_a_t_to_json_str
static inline int msg_vel_ned_dep_a_t_to_json_str( msg_vel_ned_dep_a_t * in, char* out_str, int max_len) {
  (void) max_len;
  return sprintf(out_str, "{tow: %u, n: %d, e: %d, d: %d, h_accuracy: %hu, v_accuracy: %hu, n_sats: %hhu, flags: %hhu}", in->tow, in->n, in->e, in->d, in->h_accuracy, in->v_accuracy, in->n_sats, in->flags);
 }

/** Heading relative to True North
 *
 * This message reports the baseline heading pointing from the base station
 * to the rover relative to True North. The full GPS time is given by the
 * preceding MSG_GPS_TIME with the matching time-of-week (tow).
 */
#define SBP_MSG_BASELINE_HEADING_DEP_A 0x0207
typedef struct __attribute__((packed)) {
  u32 tow;        /**< GPS Time of Week [ms] */
  u32 heading;    /**< Heading [mdeg] */
  u8 n_sats;     /**< Number of satellites used in solution */
  u8 flags;      /**< Status flags */
} msg_baseline_heading_dep_a_t;

#define MSG_0207_TO_JSON msg_baseline_heading_dep_a_t_to_json_str
static inline int msg_baseline_heading_dep_a_t_to_json_str( msg_baseline_heading_dep_a_t * in, char* out_str, int max_len) {
  (void) max_len;
  return sprintf(out_str, "{tow: %u, heading: %u, n_sats: %hhu, flags: %hhu}", in->tow, in->heading, in->n_sats, in->flags);
 }

/** \} */

#endif /* LIBSBP_NAVIGATION_MESSAGES_H */