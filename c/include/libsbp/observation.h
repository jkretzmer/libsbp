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
 * Automatically generated from yaml/swiftnav/sbp/observation.yaml
 * with generate.py. Please do not hand edit!
 *****************************************************************************/

/** \defgroup observation Observation
 *
 * * Satellite observation messages from the device.
 * \{ */

#ifndef LIBSBP_OBSERVATION_MESSAGES_H
#define LIBSBP_OBSERVATION_MESSAGES_H

#include "common.h"
#include "gnss.h"


/** Header for observation message.
 *
* Header of a GNSS observation message.
 */
typedef struct __attribute__((packed)) {
  gps_time_nano_t t;        /**< GNSS time of this observation */
  u8 n_obs;    /**< Total number of observations. First nibble is the size
of the sequence (n), second nibble is the zero-indexed
counter (ith packet of n)
 */
} observation_header_t;

static inline int observation_header_t_to_json_str( observation_header_t * in, char* out_str, int max_len) {
  (void) max_len; (void) in; (void) out_str; 
  return 0;
 }

/** GNSS doppler measurement.
 *
 * Doppler measurement in Hz represented as a 24-bit
 * fixed point number with Q16.8 layout, i.e. 16-bits of whole
 * doppler and 8-bits of fractional doppler. This doppler is defined
 * as positive for approaching satellites.
 */
typedef struct __attribute__((packed)) {
  s16 i;    /**< Doppler whole Hz [Hz] */
  u8 f;    /**< Doppler fractional part [Hz / 256] */
} doppler_t;

static inline int doppler_t_to_json_str( doppler_t * in, char* out_str, int max_len) {
  (void) max_len;
  return sprintf(out_str, "{i: %hd, f: %hhu}", in->i, in->f);
 }

/** GNSS observations for a particular satellite signal.
 *
 * Pseudorange and carrier phase observation for a satellite being
 * tracked. The observations are interoperable with 3rd party
 * receivers and conform with typical RTCMv3 GNSS observations.
 */
typedef struct __attribute__((packed)) {
  u32 P;        /**< Pseudorange observation [2 cm] */
  carrier_phase_t L;        /**< Carrier phase observation with typical sign convention. [cycles] */
  doppler_t D;        /**< Doppler observation with typical sign convention. [Hz] */
  u8 cn0;      /**< Carrier-to-Noise density.  Zero implies invalid cn0. [dB Hz / 4] */
  u8 lock;     /**< Lock timer. This value gives an indication of the time
for which a signal has maintained continuous phase lock.
Whenever a signal has lost and regained lock, this
value is reset to zero. It is encoded according to DF402 from
the RTCM 10403.2 Amendment 2 specification.  Valid values range
from 0 to 15 and the most significant nibble is reserved for future use.
 */
  u8 flags;    /**< Measurement status flags. A bit field of flags providing the
status of this observation.  If this field is 0 it means only the Cn0
estimate for the signal is valid.
 */
  gnss_signal16_t sid;      /**< GNSS signal identifier (16 bit) */
} packed_obs_content_t;

static inline int packed_obs_content_t_to_json_str( packed_obs_content_t * in, char* out_str, int max_len) {
  (void) max_len; (void) in; (void) out_str; 
  return 0;
 }

/** GPS satellite observations
 *
 * The GPS observations message reports all the raw pseudorange and
 * carrier phase observations for the satellites being tracked by
 * the device. Carrier phase observation here is represented as a
 * 40-bit fixed point number with Q32.8 layout (i.e. 32-bits of
 * whole cycles and 8-bits of fractional cycles). The observations
 * are be interoperable with 3rd party receivers and conform
 * with typical RTCMv3 GNSS observations.
 */
#define SBP_MSG_OBS                  0x004A
typedef struct __attribute__((packed)) {
  observation_header_t header;    /**< Header of a GPS observation message */
  packed_obs_content_t obs[0];    /**< Pseudorange and carrier phase observation for a
satellite being tracked.
 */
} msg_obs_t;

static inline int msg_obs_t_to_json_str( msg_obs_t * in, char* out_str, int max_len) {
  (void) max_len; (void) in; (void) out_str; 
  return 0;
 }

/** Base station position
 *
 * The base station position message is the position reported by
 * the base station itself. It is used for pseudo-absolute RTK
 * positioning, and is required to be a high-accuracy surveyed
 * location of the base station. Any error here will result in an
 * error in the pseudo-absolute position output.
 */
#define SBP_MSG_BASE_POS_LLH         0x0044
typedef struct __attribute__((packed)) {
  double lat;       /**< Latitude [deg] */
  double lon;       /**< Longitude [deg] */
  double height;    /**< Height [m] */
} msg_base_pos_llh_t;

#define MSG_0044_TO_JSON msg_base_pos_llh_t_to_json_str
static inline int msg_base_pos_llh_t_to_json_str( msg_base_pos_llh_t * in, char* out_str, int max_len) {
  (void) max_len;
  return sprintf(out_str, "{lat: %f, lon: %f, height: %f}", in->lat, in->lon, in->height);
 }

/** Base station position in ECEF
 *
 * The base station position message is the position reported by
 * the base station itself in absolute Earth Centered Earth Fixed
 * coordinates. It is used for pseudo-absolute RTK positioning, and
 * is required to be a high-accuracy surveyed location of the base
 * station. Any error here will result in an error in the
 * pseudo-absolute position output.
 */
#define SBP_MSG_BASE_POS_ECEF        0x0048
typedef struct __attribute__((packed)) {
  double x;    /**< ECEF X coodinate [m] */
  double y;    /**< ECEF Y coordinate [m] */
  double z;    /**< ECEF Z coordinate [m] */
} msg_base_pos_ecef_t;

#define MSG_0048_TO_JSON msg_base_pos_ecef_t_to_json_str
static inline int msg_base_pos_ecef_t_to_json_str( msg_base_pos_ecef_t * in, char* out_str, int max_len) {
  (void) max_len;
  return sprintf(out_str, "{x: %f, y: %f, z: %f}", in->x, in->y, in->z);
 }

typedef struct __attribute__((packed)) {
  gnss_signal16_t sid;             /**< GNSS signal identifier (16 bit) */
  gps_time_sec_t toe;             /**< Time of Ephemerides */
  double ura;             /**< User Range Accuracy [m] */
  u32 fit_interval;    /**< Curve fit interval [s] */
  u8 valid;           /**< Status of ephemeris, 1 = valid, 0 = invalid */
  u8 health_bits;     /**< Satellite health status.
GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
SBAS: 0 = valid, non-zero = invalid
GLO: 0 = valid, non-zero = invalid
 */
} ephemeris_common_content_t;

static inline int ephemeris_common_content_t_to_json_str( ephemeris_common_content_t * in, char* out_str, int max_len) {
  (void) max_len; (void) in; (void) out_str; 
  return 0;
 }

typedef struct __attribute__((packed)) {
  sbp_gnss_signal_t sid;             /**< GNSS signal identifier */
  sbp_gps_time_t toe;             /**< Time of Ephemerides */
  double ura;             /**< User Range Accuracy [m] */
  u32 fit_interval;    /**< Curve fit interval [s] */
  u8 valid;           /**< Status of ephemeris, 1 = valid, 0 = invalid */
  u8 health_bits;     /**< Satellite health status.
GPS: ICD-GPS-200, chapter 20.3.3.3.1.4
SBAS: 0 = valid, non-zero = invalid
GLO: 0 = valid, non-zero = invalid
 */
} ephemeris_common_content_dep_a_t;

static inline int ephemeris_common_content_dep_a_t_to_json_str( ephemeris_common_content_dep_a_t * in, char* out_str, int max_len) {
  (void) max_len; (void) in; (void) out_str; 
  return 0;
 }

/** Satellite broadcast ephemeris for GPS
 *
 * The ephemeris message returns a set of satellite orbit
 * parameters that is used to calculate GPS satellite position,
 * velocity, and clock offset. Please see the Navstar GPS
 * Space Segment/Navigation user interfaces (ICD-GPS-200, Table
 * 20-III) for more details.
 */
#define SBP_MSG_EPHEMERIS_GPS_DEP_E  0x0081
typedef struct __attribute__((packed)) {
  ephemeris_common_content_dep_a_t common;      /**< Values common for all ephemeris types */
  double tgd;         /**< Group delay differential between L1 and L2 [s] */
  double c_rs;        /**< Amplitude of the sine harmonic correction term to the orbit radius [m] */
  double c_rc;        /**< Amplitude of the cosine harmonic correction term to the orbit radius [m] */
  double c_uc;        /**< Amplitude of the cosine harmonic correction term to the argument of latitude [rad] */
  double c_us;        /**< Amplitude of the sine harmonic correction term to the argument of latitude [rad] */
  double c_ic;        /**< Amplitude of the cosine harmonic correction term to the angle of inclination [rad] */
  double c_is;        /**< Amplitude of the sine harmonic correction term to the angle of inclination [rad] */
  double dn;          /**< Mean motion difference [rad/s] */
  double m0;          /**< Mean anomaly at reference time [rad] */
  double ecc;         /**< Eccentricity of satellite orbit */
  double sqrta;       /**< Square root of the semi-major axis of orbit [m^(1/2)] */
  double omega0;      /**< Longitude of ascending node of orbit plane at weekly epoch [rad] */
  double omegadot;    /**< Rate of right ascension [rad/s] */
  double w;           /**< Argument of perigee [rad] */
  double inc;         /**< Inclination [rad] */
  double inc_dot;     /**< Inclination first derivative [rad/s] */
  double af0;         /**< Polynomial clock correction coefficient (clock bias) [s] */
  double af1;         /**< Polynomial clock correction coefficient (clock drift) [s/s] */
  double af2;         /**< Polynomial clock correction coefficient (rate of clock drift) [s/s^2] */
  sbp_gps_time_t toc;         /**< Clock reference */
  u8 iode;        /**< Issue of ephemeris data */
  u16 iodc;        /**< Issue of clock data */
} msg_ephemeris_gps_dep_e_t;

static inline int msg_ephemeris_gps_dep_e_t_to_json_str( msg_ephemeris_gps_dep_e_t * in, char* out_str, int max_len) {
  (void) max_len; (void) in; (void) out_str; 
  return 0;
 }

/** Satellite broadcast ephemeris for GPS
 *
 * The ephemeris message returns a set of satellite orbit
 * parameters that is used to calculate GPS satellite position,
 * velocity, and clock offset. Please see the Navstar GPS
 * Space Segment/Navigation user interfaces (ICD-GPS-200, Table
 * 20-III) for more details.
 */
#define SBP_MSG_EPHEMERIS_GPS        0x0086
typedef struct __attribute__((packed)) {
  ephemeris_common_content_t common;      /**< Values common for all ephemeris types */
  double tgd;         /**< Group delay differential between L1 and L2 [s] */
  double c_rs;        /**< Amplitude of the sine harmonic correction term to the orbit radius [m] */
  double c_rc;        /**< Amplitude of the cosine harmonic correction term to the orbit radius [m] */
  double c_uc;        /**< Amplitude of the cosine harmonic correction term to the argument of latitude [rad] */
  double c_us;        /**< Amplitude of the sine harmonic correction term to the argument of latitude [rad] */
  double c_ic;        /**< Amplitude of the cosine harmonic correction term to the angle of inclination [rad] */
  double c_is;        /**< Amplitude of the sine harmonic correction term to the angle of inclination [rad] */
  double dn;          /**< Mean motion difference [rad/s] */
  double m0;          /**< Mean anomaly at reference time [rad] */
  double ecc;         /**< Eccentricity of satellite orbit */
  double sqrta;       /**< Square root of the semi-major axis of orbit [m^(1/2)] */
  double omega0;      /**< Longitude of ascending node of orbit plane at weekly epoch [rad] */
  double omegadot;    /**< Rate of right ascension [rad/s] */
  double w;           /**< Argument of perigee [rad] */
  double inc;         /**< Inclination [rad] */
  double inc_dot;     /**< Inclination first derivative [rad/s] */
  double af0;         /**< Polynomial clock correction coefficient (clock bias) [s] */
  double af1;         /**< Polynomial clock correction coefficient (clock drift) [s/s] */
  double af2;         /**< Polynomial clock correction coefficient (rate of clock drift) [s/s^2] */
  gps_time_sec_t toc;         /**< Clock reference */
  u8 iode;        /**< Issue of ephemeris data */
  u16 iodc;        /**< Issue of clock data */
} msg_ephemeris_gps_t;

static inline int msg_ephemeris_gps_t_to_json_str( msg_ephemeris_gps_t * in, char* out_str, int max_len) {
  (void) max_len; (void) in; (void) out_str; 
  return 0;
 }

#define SBP_MSG_EPHEMERIS_SBAS_DEP_A 0x0082
typedef struct __attribute__((packed)) {
  ephemeris_common_content_dep_a_t common;    /**< Values common for all ephemeris types */
  double pos[3];    /**< Position of the GEO at time toe [m] */
  double vel[3];    /**< Velocity of the GEO at time toe [m/s] */
  double acc[3];    /**< Acceleration of the GEO at time toe [m/s^2] */
  double a_gf0;     /**< Time offset of the GEO clock w.r.t. SBAS Network Time [s] */
  double a_gf1;     /**< Drift of the GEO clock w.r.t. SBAS Network Time [s/s] */
} msg_ephemeris_sbas_dep_a_t;

static inline int msg_ephemeris_sbas_dep_a_t_to_json_str( msg_ephemeris_sbas_dep_a_t * in, char* out_str, int max_len) {
  (void) max_len; (void) in; (void) out_str; 
  return 0;
 }

/** Satellite broadcast ephemeris for GLO
 *
 * The ephemeris message returns a set of satellite orbit
 * parameters that is used to calculate GLO satellite position,
 * velocity, and clock offset. Please see the GLO ICD 5.1 "Table 4.5
 * Characteristics of words of immediate information (ephemeris parameters)"
 * for more details.
 */
#define SBP_MSG_EPHEMERIS_GLO_DEP_A  0x0083
typedef struct __attribute__((packed)) {
  ephemeris_common_content_dep_a_t common;    /**< Values common for all ephemeris types */
  double gamma;     /**< Relative deviation of predicted carrier frequency from nominal */
  double tau;       /**< Correction to the SV time [s] */
  double pos[3];    /**< Position of the SV at tb in PZ-90.02 coordinates system [m] */
  double vel[3];    /**< Velocity vector of the SV at tb in PZ-90.02 coordinates system [m/s] */
  double acc[3];    /**< Acceleration vector of the SV at tb in PZ-90.02 coordinates sys [m/s^2] */
} msg_ephemeris_glo_dep_a_t;

static inline int msg_ephemeris_glo_dep_a_t_to_json_str( msg_ephemeris_glo_dep_a_t * in, char* out_str, int max_len) {
  (void) max_len; (void) in; (void) out_str; 
  return 0;
 }

#define SBP_MSG_EPHEMERIS_SBAS       0x0084
typedef struct __attribute__((packed)) {
  ephemeris_common_content_t common;    /**< Values common for all ephemeris types */
  double pos[3];    /**< Position of the GEO at time toe [m] */
  double vel[3];    /**< Velocity of the GEO at time toe [m/s] */
  double acc[3];    /**< Acceleration of the GEO at time toe [m/s^2] */
  double a_gf0;     /**< Time offset of the GEO clock w.r.t. SBAS Network Time [s] */
  double a_gf1;     /**< Drift of the GEO clock w.r.t. SBAS Network Time [s/s] */
} msg_ephemeris_sbas_t;

static inline int msg_ephemeris_sbas_t_to_json_str( msg_ephemeris_sbas_t * in, char* out_str, int max_len) {
  (void) max_len; (void) in; (void) out_str; 
  return 0;
 }

/** Satellite broadcast ephemeris for GLO
 *
 * The ephemeris message returns a set of satellite orbit
 * parameters that is used to calculate GLO satellite position,
 * velocity, and clock offset. Please see the GLO ICD 5.1 "Table 4.5
 * Characteristics of words of immediate information (ephemeris parameters)"
 * for more details.
 */
#define SBP_MSG_EPHEMERIS_GLO_DEP_B  0x0085
typedef struct __attribute__((packed)) {
  ephemeris_common_content_t common;    /**< Values common for all ephemeris types */
  double gamma;     /**< Relative deviation of predicted carrier frequency from nominal */
  double tau;       /**< Correction to the SV time [s] */
  double pos[3];    /**< Position of the SV at tb in PZ-90.02 coordinates system [m] */
  double vel[3];    /**< Velocity vector of the SV at tb in PZ-90.02 coordinates system [m/s] */
  double acc[3];    /**< Acceleration vector of the SV at tb in PZ-90.02 coordinates sys [m/s^2] */
} msg_ephemeris_glo_dep_b_t;

static inline int msg_ephemeris_glo_dep_b_t_to_json_str( msg_ephemeris_glo_dep_b_t * in, char* out_str, int max_len) {
  (void) max_len; (void) in; (void) out_str; 
  return 0;
 }

/** Satellite broadcast ephemeris for GLO
 *
 * The ephemeris message returns a set of satellite orbit
 * parameters that is used to calculate GLO satellite position,
 * velocity, and clock offset. Please see the GLO ICD 5.1 "Table 4.5
 * Characteristics of words of immediate information (ephemeris parameters)"
 * for more details.
 */
#define SBP_MSG_EPHEMERIS_GLO_DEP_C  0x0087
typedef struct __attribute__((packed)) {
  ephemeris_common_content_t common;    /**< Values common for all ephemeris types */
  double gamma;     /**< Relative deviation of predicted carrier frequency from nominal */
  double tau;       /**< Correction to the SV time [s] */
  double d_tau;     /**< Equipment delay between L1 and L2 [s] */
  double pos[3];    /**< Position of the SV at tb in PZ-90.02 coordinates system [m] */
  double vel[3];    /**< Velocity vector of the SV at tb in PZ-90.02 coordinates system [m/s] */
  double acc[3];    /**< Acceleration vector of the SV at tb in PZ-90.02 coordinates sys [m/s^2] */
  u8 fcn;       /**< Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid */
} msg_ephemeris_glo_dep_c_t;

static inline int msg_ephemeris_glo_dep_c_t_to_json_str( msg_ephemeris_glo_dep_c_t * in, char* out_str, int max_len) {
  (void) max_len; (void) in; (void) out_str; 
  return 0;
 }

/** Satellite broadcast ephemeris for GLO
 *
 * The ephemeris message returns a set of satellite orbit
 * parameters that is used to calculate GLO satellite position,
 * velocity, and clock offset. Please see the GLO ICD 5.1 "Table 4.5
 * Characteristics of words of immediate information (ephemeris parameters)"
 * for more details.
 */
#define SBP_MSG_EPHEMERIS_GLO        0x0088
typedef struct __attribute__((packed)) {
  ephemeris_common_content_t common;    /**< Values common for all ephemeris types */
  double gamma;     /**< Relative deviation of predicted carrier frequency from nominal */
  double tau;       /**< Correction to the SV time [s] */
  double d_tau;     /**< Equipment delay between L1 and L2 [s] */
  double pos[3];    /**< Position of the SV at tb in PZ-90.02 coordinates system [m] */
  double vel[3];    /**< Velocity vector of the SV at tb in PZ-90.02 coordinates system [m/s] */
  double acc[3];    /**< Acceleration vector of the SV at tb in PZ-90.02 coordinates sys [m/s^2] */
  u8 fcn;       /**< Frequency slot. FCN+8 (that is [1..14]). 0 or 0xFF for invalid */
  u8 iod;       /**< Issue of ephemeris data */
} msg_ephemeris_glo_t;

static inline int msg_ephemeris_glo_t_to_json_str( msg_ephemeris_glo_t * in, char* out_str, int max_len) {
  (void) max_len; (void) in; (void) out_str; 
  return 0;
 }

/** Satellite broadcast ephemeris
 *
 * The ephemeris message returns a set of satellite orbit
 * parameters that is used to calculate GPS satellite position,
 * velocity, and clock offset. Please see the Navstar GPS
 * Space Segment/Navigation user interfaces (ICD-GPS-200, Table
 * 20-III) for more details.
 */
#define SBP_MSG_EPHEMERIS_DEP_D      0x0080
typedef struct __attribute__((packed)) {
  double tgd;         /**< Group delay differential between L1 and L2 [s] */
  double c_rs;        /**< Amplitude of the sine harmonic correction term to the orbit radius [m] */
  double c_rc;        /**< Amplitude of the cosine harmonic correction term to the orbit radius [m] */
  double c_uc;        /**< Amplitude of the cosine harmonic correction term to the argument of latitude [rad] */
  double c_us;        /**< Amplitude of the sine harmonic correction term to the argument of latitude [rad] */
  double c_ic;        /**< Amplitude of the cosine harmonic correction term to the angle of inclination [rad] */
  double c_is;        /**< Amplitude of the sine harmonic correction term to the angle of inclination [rad] */
  double dn;          /**< Mean motion difference [rad/s] */
  double m0;          /**< Mean anomaly at reference time [rad] */
  double ecc;         /**< Eccentricity of satellite orbit */
  double sqrta;       /**< Square root of the semi-major axis of orbit [m^(1/2)] */
  double omega0;      /**< Longitude of ascending node of orbit plane at weekly epoch [rad] */
  double omegadot;    /**< Rate of right ascension [rad/s] */
  double w;           /**< Argument of perigee [rad] */
  double inc;         /**< Inclination [rad] */
  double inc_dot;     /**< Inclination first derivative [rad/s] */
  double af0;         /**< Polynomial clock correction coefficient (clock bias) [s] */
  double af1;         /**< Polynomial clock correction coefficient (clock drift) [s/s] */
  double af2;         /**< Polynomial clock correction coefficient (rate of clock drift) [s/s^2] */
  double toe_tow;     /**< Time of week [s] */
  u16 toe_wn;      /**< Week number [week] */
  double toc_tow;     /**< Clock reference time of week [s] */
  u16 toc_wn;      /**< Clock reference week number [week] */
  u8 valid;       /**< Is valid? */
  u8 healthy;     /**< Satellite is healthy? */
  sbp_gnss_signal_t sid;         /**< GNSS signal identifier */
  u8 iode;        /**< Issue of ephemeris data */
  u16 iodc;        /**< Issue of clock data */
  u32 reserved;    /**< Reserved field */
} msg_ephemeris_dep_d_t;

static inline int msg_ephemeris_dep_d_t_to_json_str( msg_ephemeris_dep_d_t * in, char* out_str, int max_len) {
  (void) max_len; (void) in; (void) out_str; 
  return 0;
 }

/** Deprecated
 *
* Deprecated.
 */
#define SBP_MSG_EPHEMERIS_DEP_A      0x001A
typedef struct __attribute__((packed)) {
  double tgd;         /**< Group delay differential between L1 and L2 [s] */
  double c_rs;        /**< Amplitude of the sine harmonic correction term to the orbit radius [m] */
  double c_rc;        /**< Amplitude of the cosine harmonic correction term to the orbit radius [m] */
  double c_uc;        /**< Amplitude of the cosine harmonic correction term to the argument of latitude [rad] */
  double c_us;        /**< Amplitude of the sine harmonic correction term to the argument of latitude [rad] */
  double c_ic;        /**< Amplitude of the cosine harmonic correction term to the angle of inclination [rad] */
  double c_is;        /**< Amplitude of the sine harmonic correction term to the angle of inclination [rad] */
  double dn;          /**< Mean motion difference [rad/s] */
  double m0;          /**< Mean anomaly at reference time [rad] */
  double ecc;         /**< Eccentricity of satellite orbit */
  double sqrta;       /**< Square root of the semi-major axis of orbit [m^(1/2)] */
  double omega0;      /**< Longitude of ascending node of orbit plane at weekly epoch [rad] */
  double omegadot;    /**< Rate of right ascension [rad/s] */
  double w;           /**< Argument of perigee [rad] */
  double inc;         /**< Inclination [rad] */
  double inc_dot;     /**< Inclination first derivative [rad/s] */
  double af0;         /**< Polynomial clock correction coefficient (clock bias) [s] */
  double af1;         /**< Polynomial clock correction coefficient (clock drift) [s/s] */
  double af2;         /**< Polynomial clock correction coefficient (rate of clock drift) [s/s^2] */
  double toe_tow;     /**< Time of week [s] */
  u16 toe_wn;      /**< Week number [week] */
  double toc_tow;     /**< Clock reference time of week [s] */
  u16 toc_wn;      /**< Clock reference week number [week] */
  u8 valid;       /**< Is valid? */
  u8 healthy;     /**< Satellite is healthy? */
  u8 prn;         /**< PRN being tracked */
} msg_ephemeris_dep_a_t;

#define MSG_001A_TO_JSON msg_ephemeris_dep_a_t_to_json_str
static inline int msg_ephemeris_dep_a_t_to_json_str( msg_ephemeris_dep_a_t * in, char* out_str, int max_len) {
  (void) max_len;
  return sprintf(out_str, "{tgd: %f, c_rs: %f, c_rc: %f, c_uc: %f, c_us: %f, c_ic: %f, c_is: %f, dn: %f, m0: %f, ecc: %f, sqrta: %f, omega0: %f, omegadot: %f, w: %f, inc: %f, inc_dot: %f, af0: %f, af1: %f, af2: %f, toe_tow: %f, toe_wn: %hu, toc_tow: %f, toc_wn: %hu, valid: %hhu, healthy: %hhu, prn: %hhu}", in->tgd, in->c_rs, in->c_rc, in->c_uc, in->c_us, in->c_ic, in->c_is, in->dn, in->m0, in->ecc, in->sqrta, in->omega0, in->omegadot, in->w, in->inc, in->inc_dot, in->af0, in->af1, in->af2, in->toe_tow, in->toe_wn, in->toc_tow, in->toc_wn, in->valid, in->healthy, in->prn);
 }

/** Deprecated
 *
* Deprecated.
 */
#define SBP_MSG_EPHEMERIS_DEP_B      0x0046
typedef struct __attribute__((packed)) {
  double tgd;         /**< Group delay differential between L1 and L2 [s] */
  double c_rs;        /**< Amplitude of the sine harmonic correction term to the orbit radius [m] */
  double c_rc;        /**< Amplitude of the cosine harmonic correction term to the orbit radius [m] */
  double c_uc;        /**< Amplitude of the cosine harmonic correction term to the argument of latitude [rad] */
  double c_us;        /**< Amplitude of the sine harmonic correction term to the argument of latitude [rad] */
  double c_ic;        /**< Amplitude of the cosine harmonic correction term to the angle of inclination [rad] */
  double c_is;        /**< Amplitude of the sine harmonic correction term to the angle of inclination [rad] */
  double dn;          /**< Mean motion difference [rad/s] */
  double m0;          /**< Mean anomaly at reference time [rad] */
  double ecc;         /**< Eccentricity of satellite orbit */
  double sqrta;       /**< Square root of the semi-major axis of orbit [m^(1/2)] */
  double omega0;      /**< Longitude of ascending node of orbit plane at weekly epoch [rad] */
  double omegadot;    /**< Rate of right ascension [rad/s] */
  double w;           /**< Argument of perigee [rad] */
  double inc;         /**< Inclination [rad] */
  double inc_dot;     /**< Inclination first derivative [rad/s] */
  double af0;         /**< Polynomial clock correction coefficient (clock bias) [s] */
  double af1;         /**< Polynomial clock correction coefficient (clock drift) [s/s] */
  double af2;         /**< Polynomial clock correction coefficient (rate of clock drift) [s/s^2] */
  double toe_tow;     /**< Time of week [s] */
  u16 toe_wn;      /**< Week number [week] */
  double toc_tow;     /**< Clock reference time of week [s] */
  u16 toc_wn;      /**< Clock reference week number [week] */
  u8 valid;       /**< Is valid? */
  u8 healthy;     /**< Satellite is healthy? */
  u8 prn;         /**< PRN being tracked */
  u8 iode;        /**< Issue of ephemeris data */
} msg_ephemeris_dep_b_t;

#define MSG_0046_TO_JSON msg_ephemeris_dep_b_t_to_json_str
static inline int msg_ephemeris_dep_b_t_to_json_str( msg_ephemeris_dep_b_t * in, char* out_str, int max_len) {
  (void) max_len;
  return sprintf(out_str, "{tgd: %f, c_rs: %f, c_rc: %f, c_uc: %f, c_us: %f, c_ic: %f, c_is: %f, dn: %f, m0: %f, ecc: %f, sqrta: %f, omega0: %f, omegadot: %f, w: %f, inc: %f, inc_dot: %f, af0: %f, af1: %f, af2: %f, toe_tow: %f, toe_wn: %hu, toc_tow: %f, toc_wn: %hu, valid: %hhu, healthy: %hhu, prn: %hhu, iode: %hhu}", in->tgd, in->c_rs, in->c_rc, in->c_uc, in->c_us, in->c_ic, in->c_is, in->dn, in->m0, in->ecc, in->sqrta, in->omega0, in->omegadot, in->w, in->inc, in->inc_dot, in->af0, in->af1, in->af2, in->toe_tow, in->toe_wn, in->toc_tow, in->toc_wn, in->valid, in->healthy, in->prn, in->iode);
 }

/** Satellite broadcast ephemeris
 *
 * The ephemeris message returns a set of satellite orbit
 * parameters that is used to calculate GPS satellite position,
 * velocity, and clock offset. Please see the Navstar GPS
 * Space Segment/Navigation user interfaces (ICD-GPS-200, Table
 * 20-III) for more details.
 */
#define SBP_MSG_EPHEMERIS_DEP_C      0x0047
typedef struct __attribute__((packed)) {
  double tgd;         /**< Group delay differential between L1 and L2 [s] */
  double c_rs;        /**< Amplitude of the sine harmonic correction term to the orbit radius [m] */
  double c_rc;        /**< Amplitude of the cosine harmonic correction term to the orbit radius [m] */
  double c_uc;        /**< Amplitude of the cosine harmonic correction term to the argument of latitude [rad] */
  double c_us;        /**< Amplitude of the sine harmonic correction term to the argument of latitude [rad] */
  double c_ic;        /**< Amplitude of the cosine harmonic correction term to the angle of inclination [rad] */
  double c_is;        /**< Amplitude of the sine harmonic correction term to the angle of inclination [rad] */
  double dn;          /**< Mean motion difference [rad/s] */
  double m0;          /**< Mean anomaly at reference time [rad] */
  double ecc;         /**< Eccentricity of satellite orbit */
  double sqrta;       /**< Square root of the semi-major axis of orbit [m^(1/2)] */
  double omega0;      /**< Longitude of ascending node of orbit plane at weekly epoch [rad] */
  double omegadot;    /**< Rate of right ascension [rad/s] */
  double w;           /**< Argument of perigee [rad] */
  double inc;         /**< Inclination [rad] */
  double inc_dot;     /**< Inclination first derivative [rad/s] */
  double af0;         /**< Polynomial clock correction coefficient (clock bias) [s] */
  double af1;         /**< Polynomial clock correction coefficient (clock drift) [s/s] */
  double af2;         /**< Polynomial clock correction coefficient (rate of clock drift) [s/s^2] */
  double toe_tow;     /**< Time of week [s] */
  u16 toe_wn;      /**< Week number [week] */
  double toc_tow;     /**< Clock reference time of week [s] */
  u16 toc_wn;      /**< Clock reference week number [week] */
  u8 valid;       /**< Is valid? */
  u8 healthy;     /**< Satellite is healthy? */
  sbp_gnss_signal_t sid;         /**< GNSS signal identifier */
  u8 iode;        /**< Issue of ephemeris data */
  u16 iodc;        /**< Issue of clock data */
  u32 reserved;    /**< Reserved field */
} msg_ephemeris_dep_c_t;

static inline int msg_ephemeris_dep_c_t_to_json_str( msg_ephemeris_dep_c_t * in, char* out_str, int max_len) {
  (void) max_len; (void) in; (void) out_str; 
  return 0;
 }

/** Header for observation message.
 *
* Header of a GPS observation message.
 */
typedef struct __attribute__((packed)) {
  sbp_gps_time_t t;        /**< GPS time of this observation */
  u8 n_obs;    /**< Total number of observations. First nibble is the size
of the sequence (n), second nibble is the zero-indexed
counter (ith packet of n)
 */
} observation_header_dep_t;

static inline int observation_header_dep_t_to_json_str( observation_header_dep_t * in, char* out_str, int max_len) {
  (void) max_len; (void) in; (void) out_str; 
  return 0;
 }

/** GPS carrier phase measurement.
 *
 * Carrier phase measurement in cycles represented as a 40-bit
 * fixed point number with Q32.8 layout, i.e. 32-bits of whole
 * cycles and 8-bits of fractional cycles. This has the opposite
 * sign convention than a typical GPS receiver and the phase has
 * the opposite sign as the pseudorange.
 */
typedef struct __attribute__((packed)) {
  s32 i;    /**< Carrier phase whole cycles [cycles] */
  u8 f;    /**< Carrier phase fractional part [cycles / 256] */
} carrier_phase_dep_a_t;

static inline int carrier_phase_dep_a_t_to_json_str( carrier_phase_dep_a_t * in, char* out_str, int max_len) {
  (void) max_len;
  return sprintf(out_str, "{i: %d, f: %hhu}", in->i, in->f);
 }

/** Deprecated
 *
* Deprecated.
 */
typedef struct __attribute__((packed)) {
  u32 P;       /**< Pseudorange observation [cm] */
  carrier_phase_dep_a_t L;       /**< Carrier phase observation with opposite sign from typical convention */
  u8 cn0;     /**< Carrier-to-Noise density [dB Hz / 4] */
  u16 lock;    /**< Lock indicator. This value changes whenever a satellite
signal has lost and regained lock, indicating that the
carrier phase ambiguity may have changed.
 */
  u8 prn;     /**< PRN-1 identifier of the satellite signal */
} packed_obs_content_dep_a_t;

static inline int packed_obs_content_dep_a_t_to_json_str( packed_obs_content_dep_a_t * in, char* out_str, int max_len) {
  (void) max_len; (void) in; (void) out_str; 
  return 0;
 }

/** GPS observations for a particular satellite signal.
 *
 * Pseudorange and carrier phase observation for a satellite being
 * tracked.  Pseudoranges are referenced to a nominal pseudorange.
 */
typedef struct __attribute__((packed)) {
  u32 P;       /**< Pseudorange observation [cm] */
  carrier_phase_dep_a_t L;       /**< Carrier phase observation with opposite sign from typical convention. */
  u8 cn0;     /**< Carrier-to-Noise density [dB Hz / 4] */
  u16 lock;    /**< Lock indicator. This value changes whenever a satellite
signal has lost and regained lock, indicating that the
carrier phase ambiguity may have changed.
 */
  sbp_gnss_signal_t sid;     /**< GNSS signal identifier */
} packed_obs_content_dep_b_t;

static inline int packed_obs_content_dep_b_t_to_json_str( packed_obs_content_dep_b_t * in, char* out_str, int max_len) {
  (void) max_len; (void) in; (void) out_str; 
  return 0;
 }

/** GPS observations for a particular satellite signal.
 *
 * Pseudorange and carrier phase observation for a satellite being
 * tracked. The observations are be interoperable with 3rd party
 * receivers and conform with typical RTCMv3 GNSS observations.
 */
typedef struct __attribute__((packed)) {
  u32 P;       /**< Pseudorange observation [2 cm] */
  carrier_phase_t L;       /**< Carrier phase observation with typical sign convention. [cycles] */
  u8 cn0;     /**< Carrier-to-Noise density [dB Hz / 4] */
  u16 lock;    /**< Lock indicator. This value changes whenever a satellite
signal has lost and regained lock, indicating that the
carrier phase ambiguity may have changed.
 */
  sbp_gnss_signal_t sid;     /**< GNSS signal identifier */
} packed_obs_content_dep_c_t;

static inline int packed_obs_content_dep_c_t_to_json_str( packed_obs_content_dep_c_t * in, char* out_str, int max_len) {
  (void) max_len; (void) in; (void) out_str; 
  return 0;
 }

/** Deprecated
 *
* Deprecated.
 */
#define SBP_MSG_OBS_DEP_A            0x0045
typedef struct __attribute__((packed)) {
  observation_header_dep_t header;    /**< Header of a GPS observation message */
  packed_obs_content_dep_a_t obs[0];    /**< Pseudorange and carrier phase observation for a
satellite being tracked.
 */
} msg_obs_dep_a_t;

static inline int msg_obs_dep_a_t_to_json_str( msg_obs_dep_a_t * in, char* out_str, int max_len) {
  (void) max_len; (void) in; (void) out_str; 
  return 0;
 }

/** Deprecated
 *
 * This observation message has been deprecated in favor of
 * observations that are more interoperable. This message
 * should be used for observations referenced to
 * a nominal pseudorange which are not interoperable with
 * most 3rd party GNSS receievers or typical RTCMv3
 * observations.
 */
#define SBP_MSG_OBS_DEP_B            0x0043
typedef struct __attribute__((packed)) {
  observation_header_dep_t header;    /**< Header of a GPS observation message */
  packed_obs_content_dep_b_t obs[0];    /**< Pseudorange and carrier phase observation for a
satellite being tracked.
 */
} msg_obs_dep_b_t;

static inline int msg_obs_dep_b_t_to_json_str( msg_obs_dep_b_t * in, char* out_str, int max_len) {
  (void) max_len; (void) in; (void) out_str; 
  return 0;
 }

/** Deprecated
 *
 * The GPS observations message reports all the raw pseudorange and
 * carrier phase observations for the satellites being tracked by
 * the device. Carrier phase observation here is represented as a
 * 40-bit fixed point number with Q32.8 layout (i.e. 32-bits of
 * whole cycles and 8-bits of fractional cycles). The observations
 * are interoperable with 3rd party receivers and conform
 * with typical RTCMv3 GNSS observations.
 */
#define SBP_MSG_OBS_DEP_C            0x0049
typedef struct __attribute__((packed)) {
  observation_header_dep_t header;    /**< Header of a GPS observation message */
  packed_obs_content_dep_c_t obs[0];    /**< Pseudorange and carrier phase observation for a
satellite being tracked.
 */
} msg_obs_dep_c_t;

static inline int msg_obs_dep_c_t_to_json_str( msg_obs_dep_c_t * in, char* out_str, int max_len) {
  (void) max_len; (void) in; (void) out_str; 
  return 0;
 }

/** Iono corrections
 *
 * The ionospheric parameters which allow the "L1 only" or "L2 only" user to
 * utilize the ionospheric model for computation of the ionospheric delay.
 * Please see ICD-GPS-200 (Chapter 20.3.3.5.1.7) for more details.
 */
#define SBP_MSG_IONO                 0x0090
typedef struct __attribute__((packed)) {
  gps_time_sec_t t_nmct;    /**< Navigation Message Correction Table Valitidy Time */
  double a0;       
  double a1;       
  double a2;       
  double a3;       
  double b0;       
  double b1;       
  double b2;       
  double b3;       
} msg_iono_t;

static inline int msg_iono_t_to_json_str( msg_iono_t * in, char* out_str, int max_len) {
  (void) max_len; (void) in; (void) out_str; 
  return 0;
 }

/** L2C capability mask
 *
 * Please see ICD-GPS-200 (Chapter 20.3.3.5.1.4) for more details.
 */
#define SBP_MSG_SV_CONFIGURATION_GPS 0x0091
typedef struct __attribute__((packed)) {
  gps_time_sec_t t_nmct;      /**< Navigation Message Correction Table Valitidy Time */
  u32 l2c_mask;    /**< L2C capability mask, SV32 bit being MSB, SV1 bit being LSB */
} msg_sv_configuration_gps_t;

static inline int msg_sv_configuration_gps_t_to_json_str( msg_sv_configuration_gps_t * in, char* out_str, int max_len) {
  (void) max_len; (void) in; (void) out_str; 
  return 0;
 }

/** Group Delay
 *
* Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
 */
#define SBP_MSG_GROUP_DELAY_DEP_A    0x0092
typedef struct __attribute__((packed)) {
  sbp_gps_time_t t_op;        /**< Data Predict Time of Week */
  u8 prn;         /**< Satellite number */
  u8 valid;       /**< bit-field indicating validity of the values,
LSB indicating tgd validity etc.
1 = value is valid, 0 = value is not valid.
 */
  s16 tgd;        
  s16 isc_l1ca;   
  s16 isc_l2c;    
} msg_group_delay_dep_a_t;

static inline int msg_group_delay_dep_a_t_to_json_str( msg_group_delay_dep_a_t * in, char* out_str, int max_len) {
  (void) max_len; (void) in; (void) out_str; 
  return 0;
 }

/** Group Delay
 *
* Please see ICD-GPS-200 (30.3.3.3.1.1) for more details.
 */
#define SBP_MSG_GROUP_DELAY          0x0093
typedef struct __attribute__((packed)) {
  gps_time_sec_t t_op;        /**< Data Predict Time of Week */
  sbp_gnss_signal_t sid;         /**< GNSS signal identifier */
  u8 valid;       /**< bit-field indicating validity of the values,
LSB indicating tgd validity etc.
1 = value is valid, 0 = value is not valid.
 */
  s16 tgd;        
  s16 isc_l1ca;   
  s16 isc_l2c;    
} msg_group_delay_t;

static inline int msg_group_delay_t_to_json_str( msg_group_delay_t * in, char* out_str, int max_len) {
  (void) max_len; (void) in; (void) out_str; 
  return 0;
 }

typedef struct __attribute__((packed)) {
  sbp_gnss_signal_t sid;             /**< GNSS signal identifier */
  gps_time_sec_t toa;             /**< Reference time of almanac */
  double ura;             /**< User Range Accuracy [m] */
  u32 fit_interval;    /**< Curve fit interval [s] */
  u8 valid;           /**< Status of almanac, 1 = valid, 0 = invalid */
  u8 health_bits;     /**< Satellite health status for GPS:
  - bits 5-7: NAV data health status. See IS-GPS-200H
    Table 20-VII: NAV Data Health Indications.
  - bits 0-4: Signal health status. See IS-GPS-200H
    Table 20-VIII. Codes for Health of SV Signal
    Components.
Satellite health status for GLO:
  See GLO ICD 5.1 table 5.1 for details
  - bit 0: C(n), "unhealthy" flag that is transmitted within
    non-immediate data and indicates overall constellation status
    at the moment of almanac uploading.
    '0' indicates malfunction of n-satellite.
    '1' indicates that n-satellite is operational.
  - bit 1: Bn(ln), '0' indicates the satellite is operational
    and suitable for navigation.
 */
} almanac_common_content_t;

static inline int almanac_common_content_t_to_json_str( almanac_common_content_t * in, char* out_str, int max_len) {
  (void) max_len; (void) in; (void) out_str; 
  return 0;
 }

/** Satellite broadcast ephemeris for GPS
 *
 * The almanac message returns a set of satellite orbit parameters. Almanac
 * data is not very precise and is considered valid for up to several months.
 * Please see the Navstar GPS Space Segment/Navigation user interfaces
 * (ICD-GPS-200, Chapter 20.3.3.5.1.2 Almanac Data) for more details.
 */
#define SBP_MSG_ALMANAC_GPS          0x0070
typedef struct __attribute__((packed)) {
  almanac_common_content_t common;      /**< Values common for all almanac types */
  double m0;          /**< Mean anomaly at reference time [rad] */
  double ecc;         /**< Eccentricity of satellite orbit */
  double sqrta;       /**< Square root of the semi-major axis of orbit [m^(1/2)] */
  double omega0;      /**< Longitude of ascending node of orbit plane at weekly epoch [rad] */
  double omegadot;    /**< Rate of right ascension [rad/s] */
  double w;           /**< Argument of perigee [rad] */
  double inc;         /**< Inclination [rad] */
  double af0;         /**< Polynomial clock correction coefficient (clock bias) [s] */
  double af1;         /**< Polynomial clock correction coefficient (clock drift) [s/s] */
} msg_almanac_gps_t;

static inline int msg_almanac_gps_t_to_json_str( msg_almanac_gps_t * in, char* out_str, int max_len) {
  (void) max_len; (void) in; (void) out_str; 
  return 0;
 }

/** Satellite broadcast ephemeris for GLO
 *
 * The almanac message returns a set of satellite orbit parameters. Almanac
 * data is not very precise and is considered valid for up to several months.
 * Please see the GLO ICD 5.1 "Chapter 4.5 Non-immediate information and
 * almanac" for details.
 */
#define SBP_MSG_ALMANAC_GLO          0x0071
typedef struct __attribute__((packed)) {
  almanac_common_content_t common;         /**< Values common for all almanac types */
  double lambda_na;      /**< Longitude of the first ascending node of the orbit in PZ-90.02
coordinate system
 [rad] */
  double t_lambda_na;    /**< Time of the first ascending node passage [s] */
  double i;              /**< Value of inclination at instant of t_lambda [rad] */
  double t;              /**< Value of Draconian period at instant of t_lambda [s/orbital period] */
  double t_dot;          /**< Rate of change of the Draconian period [s/(orbital period^2)] */
  double epsilon;        /**< Eccentricity at instant of t_lambda */
  double omega;          /**< Argument of perigee at instant of t_lambda [rad] */
} msg_almanac_glo_t;

static inline int msg_almanac_glo_t_to_json_str( msg_almanac_glo_t * in, char* out_str, int max_len) {
  (void) max_len; (void) in; (void) out_str; 
  return 0;
 }

/** GLONASS SV orbital and frequency slots mapping information
 *
 * The message reports mapping information regarding GLONASS SV orbital and
 * frequency slots.
 * Mapped as follow:
 * index (SV orbital slot)  fcns[index]
 * 0                        0xFF
 * 1                        FCN for SV orbital slot 1
 * ...                      ...
 * 28                       FCN for SV orbital slot 28
 * 29                       0xFF
 * 30                       0xFF
 * 31                       0xFF
 */
#define SBP_MSG_FCNS_GLO             0x0072
typedef struct __attribute__((packed)) {
  u16 wn;        /**< GPS Week number [week] */
  u32 tow_ms;    /**< GPS Time of week [ms] */
  u8 fcns[32];  /**< GLONASS fequency number per orbital slot */
} msg_fcns_glo_t;

static inline int msg_fcns_glo_t_to_json_str( msg_fcns_glo_t * in, char* out_str, int max_len) {
  (void) max_len; (void) in; (void) out_str; 
  return 0;
 }

/** \} */

#endif /* LIBSBP_OBSERVATION_MESSAGES_H */