/*******************************************************************************
 *
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated from the registers file.
 * Edits to this file will be lost when it is regenerated.
 * Tool: INTERNAL/regs/xgs/generate-pmd.pl
 *
 * $Copyright: Copyright 2018-2023 Broadcom. All rights reserved.
 * The term 'Broadcom' refers to Broadcom Inc. and/or its subsidiaries.
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License 
 * version 2 as published by the Free Software Foundation.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * A copy of the GNU General Public License version 2 (GPLv2) can
 * be found in the LICENSES folder.$
 *
 * This file provides TXPMD access functions for BCM56080_A0.
 *
 ******************************************************************************/

#include <sal/sal_types.h>
#include <bcmpkt/bcmpkt_txpmd_internal.h>

#define MASK(_bn) (((uint32_t)0x1<<(_bn))-1)
#define WORD_FIELD_GET(_d,_s,_l) (((_d) >> (_s)) & MASK(_l))
#define WORD_FIELD_SET(_d,_s,_l,_v) (_d)=(((_d) & ~(MASK(_l) << (_s))) | (((_v) & MASK(_l)) << (_s)))
#define WORD_FIELD_MASK(_d,_s,_l) (_d)=((_d) | (MASK(_l) << (_s)))
/*******************************************************************************
 * SWFORMAT:  TXPMD
 * BLOCKS:
 * SIZE:     128
 ******************************************************************************/
static void bcmpkt_txpmd_start_set(uint32_t *data, uint32_t val)
{
    WORD_FIELD_SET(data[0], 30, 2, val);
}

static uint32_t bcmpkt_txpmd_start_get(uint32_t *data)
{
    uint32_t val;
    val = WORD_FIELD_GET(data[0], 30, 2);
    return val;
}

static void bcmpkt_txpmd_header_type_set(uint32_t *data, uint32_t val)
{
    WORD_FIELD_SET(data[0], 24, 6, val);
}

static uint32_t bcmpkt_txpmd_header_type_get(uint32_t *data)
{
    uint32_t val;
    val = WORD_FIELD_GET(data[0], 24, 6);
    return val;
}

static void bcmpkt_txpmd_sop_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_FROM_CPU) {
        return;
    }
    WORD_FIELD_SET(data[2], 17, 1, val);
}

static uint32_t bcmpkt_txpmd_sop_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_FROM_CPU) {
        return 0;
    }
    val = WORD_FIELD_GET(data[2], 17, 1);
    return val;
}

static void bcmpkt_txpmd_eop_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_FROM_CPU) {
        return;
    }
    WORD_FIELD_SET(data[3], 29, 1, val);
}

static uint32_t bcmpkt_txpmd_eop_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_FROM_CPU) {
        return 0;
    }
    val = WORD_FIELD_GET(data[3], 29, 1);
    return val;
}

static void bcmpkt_txpmd_cell_error_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_FROM_CPU) {
        return;
    }
    WORD_FIELD_SET(data[3], 0, 1, val);
}

static uint32_t bcmpkt_txpmd_cell_error_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_FROM_CPU) {
        return 0;
    }
    val = WORD_FIELD_GET(data[3], 0, 1);
    return val;
}

static void bcmpkt_txpmd_src_modid_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_FROM_CPU) {
        return;
    }
    WORD_FIELD_SET(data[2], 23, 8, val);
}

static uint32_t bcmpkt_txpmd_src_modid_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_FROM_CPU) {
        return 0;
    }
    val = WORD_FIELD_GET(data[2], 23, 8);
    return val;
}

static void bcmpkt_txpmd_cos_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_FROM_CPU) {
        return;
    }
    WORD_FIELD_SET(data[3], 3, 6, val);
}

static uint32_t bcmpkt_txpmd_cos_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_FROM_CPU) {
        return 0;
    }
    val = WORD_FIELD_GET(data[3], 3, 6);
    return val;
}

static void bcmpkt_txpmd_input_pri_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_FROM_CPU) {
        return;
    }
    WORD_FIELD_SET(data[2], 9, 4, val);
}

static uint32_t bcmpkt_txpmd_input_pri_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_FROM_CPU) {
        return 0;
    }
    val = WORD_FIELD_GET(data[2], 9, 4);
    return val;
}

static void bcmpkt_txpmd_unicast_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_FROM_CPU) {
        return;
    }
    WORD_FIELD_SET(data[1], 0, 1, val);
}

static uint32_t bcmpkt_txpmd_unicast_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_FROM_CPU) {
        return 0;
    }
    val = WORD_FIELD_GET(data[1], 0, 1);
    return val;
}

static void bcmpkt_txpmd_rqe_q_num_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_FROM_CPU) {
        return;
    }
    WORD_FIELD_SET(data[2], 13, 4, val);
}

static uint32_t bcmpkt_txpmd_rqe_q_num_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_FROM_CPU) {
        return 0;
    }
    val = WORD_FIELD_GET(data[2], 13, 4);
    return val;
}

static void bcmpkt_txpmd_ieee1588_one_step_enable_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_FROM_CPU) {
        return;
    }
    WORD_FIELD_SET(data[3], 31, 1, val);
}

static uint32_t bcmpkt_txpmd_ieee1588_one_step_enable_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_FROM_CPU) {
        return 0;
    }
    val = WORD_FIELD_GET(data[3], 31, 1);
    return val;
}

static void bcmpkt_txpmd_ieee1588_regen_udp_checksum_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_FROM_CPU) {
        return;
    }
    WORD_FIELD_SET(data[2], 0, 1, val);
}

static uint32_t bcmpkt_txpmd_ieee1588_regen_udp_checksum_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_FROM_CPU) {
        return 0;
    }
    val = WORD_FIELD_GET(data[2], 0, 1);
    return val;
}

static void bcmpkt_txpmd_ieee1588_ingress_timestamp_sign_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_FROM_CPU) {
        return;
    }
    WORD_FIELD_SET(data[3], 30, 1, val);
}

static uint32_t bcmpkt_txpmd_ieee1588_ingress_timestamp_sign_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_FROM_CPU) {
        return 0;
    }
    val = WORD_FIELD_GET(data[3], 30, 1);
    return val;
}

static void bcmpkt_txpmd_ieee1588_timestamp_hdr_offset_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_FROM_CPU) {
        return;
    }
    WORD_FIELD_SET(data[2], 1, 8, val);
}

static uint32_t bcmpkt_txpmd_ieee1588_timestamp_hdr_offset_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_FROM_CPU) {
        return 0;
    }
    val = WORD_FIELD_GET(data[2], 1, 8);
    return val;
}

static void bcmpkt_txpmd_tx_ts_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_FROM_CPU) {
        return;
    }
    WORD_FIELD_SET(data[2], 31, 1, val);
}

static uint32_t bcmpkt_txpmd_tx_ts_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_FROM_CPU) {
        return 0;
    }
    val = WORD_FIELD_GET(data[2], 31, 1);
    return val;
}

static void bcmpkt_txpmd_spid_override_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_FROM_CPU) {
        return;
    }
    WORD_FIELD_SET(data[2], 22, 1, val);
}

static uint32_t bcmpkt_txpmd_spid_override_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_FROM_CPU) {
        return 0;
    }
    val = WORD_FIELD_GET(data[2], 22, 1);
    return val;
}

static void bcmpkt_txpmd_spid_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_FROM_CPU) {
        return;
    }
    WORD_FIELD_SET(data[2], 20, 2, val);
}

static uint32_t bcmpkt_txpmd_spid_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_FROM_CPU) {
        return 0;
    }
    val = WORD_FIELD_GET(data[2], 20, 2);
    return val;
}

static void bcmpkt_txpmd_spap_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_FROM_CPU) {
        return;
    }
    WORD_FIELD_SET(data[2], 18, 2, val);
}

static uint32_t bcmpkt_txpmd_spap_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_FROM_CPU) {
        return 0;
    }
    val = WORD_FIELD_GET(data[2], 18, 2);
    return val;
}

static void bcmpkt_txpmd_cng_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_FROM_CPU) {
        return;
    }
    WORD_FIELD_SET(data[3], 1, 2, val);
}

static uint32_t bcmpkt_txpmd_cng_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_FROM_CPU) {
        return 0;
    }
    val = WORD_FIELD_GET(data[3], 1, 2);
    return val;
}

static void bcmpkt_txpmd_destination_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_FROM_CPU) {
        return;
    }
    WORD_FIELD_SET(data[3], 9, 16, val);
}

static uint32_t bcmpkt_txpmd_destination_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_FROM_CPU) {
        return 0;
    }
    val = WORD_FIELD_GET(data[3], 9, 16);
    return val;
}

static void bcmpkt_txpmd_destination_type_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_FROM_CPU) {
        return;
    }
    if (val == BCMPKT_TXPMD_DESTINATION_T_INVALID) {
        val = 9;
    }
    WORD_FIELD_SET(data[3], 25, 4, val);
}

static uint32_t bcmpkt_txpmd_destination_type_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_FROM_CPU) {
        return 0;
    }
    val = WORD_FIELD_GET(data[3], 25, 4);
    if (val == 9) {
        val = BCMPKT_TXPMD_DESTINATION_T_INVALID;
    }
    return val;
}

static void bcmpkt_txpmd_wred_mark_eligible_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_FROM_CPU) {
        return;
    }
    WORD_FIELD_SET(data[1], 1, 1, val);
}

static uint32_t bcmpkt_txpmd_wred_mark_eligible_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_FROM_CPU) {
        return 0;
    }
    val = WORD_FIELD_GET(data[1], 1, 1);
    return val;
}

static void bcmpkt_txpmd_wred_response_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_FROM_CPU) {
        return;
    }
    WORD_FIELD_SET(data[1], 2, 1, val);
}

static uint32_t bcmpkt_txpmd_wred_response_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_FROM_CPU) {
        return 0;
    }
    val = WORD_FIELD_GET(data[1], 2, 1);
    return val;
}

static void bcmpkt_txpmd_cpu_tx_mcast_lb_index_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_CPU_TX) {
        return;
    }
    WORD_FIELD_SET(data[3], 0, 7, val);
}

static uint32_t bcmpkt_txpmd_cpu_tx_mcast_lb_index_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_CPU_TX) {
        return 0;
    }
    val = WORD_FIELD_GET(data[3], 0, 7);
    return val;
}

static void bcmpkt_txpmd_cpu_tx_ecmp_member_id_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_CPU_TX) {
        return;
    }
    WORD_FIELD_SET(data[3], 0, 10, val);
}

static uint32_t bcmpkt_txpmd_cpu_tx_ecmp_member_id_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_CPU_TX) {
        return 0;
    }
    val = WORD_FIELD_GET(data[3], 0, 10);
    return val;
}

static void bcmpkt_txpmd_cpu_tx_destination_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_CPU_TX) {
        return;
    }
    WORD_FIELD_SET(data[3], 10, 16, val);
}

static uint32_t bcmpkt_txpmd_cpu_tx_destination_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_CPU_TX) {
        return 0;
    }
    val = WORD_FIELD_GET(data[3], 10, 16);
    return val;
}

static void bcmpkt_txpmd_cpu_tx_destination_type_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_CPU_TX) {
        return;
    }
    if (val == BCMPKT_TXPMD_CPU_TX_DESTINATION_T_INVALID) {
        val = 9;
    }
    WORD_FIELD_SET(data[3], 26, 4, val);
}

static uint32_t bcmpkt_txpmd_cpu_tx_destination_type_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_CPU_TX) {
        return 0;
    }
    val = WORD_FIELD_GET(data[3], 26, 4);
    if (val == 9) {
        val = BCMPKT_TXPMD_CPU_TX_DESTINATION_T_INVALID;
    }
    return val;
}

static void bcmpkt_txpmd_cpu_tx_dp_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_CPU_TX) {
        return;
    }
    WORD_FIELD_SET(data[3], 30, 2, val);
}

static uint32_t bcmpkt_txpmd_cpu_tx_dp_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_CPU_TX) {
        return 0;
    }
    val = WORD_FIELD_GET(data[3], 30, 2);
    return val;
}

static void bcmpkt_txpmd_cpu_tx_input_pri_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_CPU_TX) {
        return;
    }
    WORD_FIELD_SET(data[2], 0, 4, val);
}

static uint32_t bcmpkt_txpmd_cpu_tx_input_pri_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_CPU_TX) {
        return 0;
    }
    val = WORD_FIELD_GET(data[2], 0, 4);
    return val;
}

static void bcmpkt_txpmd_cpu_tx_int_cn_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_CPU_TX) {
        return;
    }
    WORD_FIELD_SET(data[2], 4, 2, val);
}

static uint32_t bcmpkt_txpmd_cpu_tx_int_cn_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_CPU_TX) {
        return 0;
    }
    val = WORD_FIELD_GET(data[2], 4, 2);
    return val;
}

static void bcmpkt_txpmd_cpu_tx_int_pri_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_CPU_TX) {
        return;
    }
    WORD_FIELD_SET(data[2], 6, 4, val);
}

static uint32_t bcmpkt_txpmd_cpu_tx_int_pri_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_CPU_TX) {
        return 0;
    }
    val = WORD_FIELD_GET(data[2], 6, 4);
    return val;
}

static void bcmpkt_txpmd_cpu_tx_mcast_lb_index_vld_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_CPU_TX) {
        return;
    }
    WORD_FIELD_SET(data[2], 10, 1, val);
}

static uint32_t bcmpkt_txpmd_cpu_tx_mcast_lb_index_vld_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_CPU_TX) {
        return 0;
    }
    val = WORD_FIELD_GET(data[2], 10, 1);
    return val;
}

static void bcmpkt_txpmd_cpu_tx_pkt_profile_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_CPU_TX) {
        return;
    }
    WORD_FIELD_SET(data[2], 11, 3, val);
}

static uint32_t bcmpkt_txpmd_cpu_tx_pkt_profile_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_CPU_TX) {
        return 0;
    }
    val = WORD_FIELD_GET(data[2], 11, 3);
    return val;
}

static void bcmpkt_txpmd_cpu_tx_qos_fields_vld_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_CPU_TX) {
        return;
    }
    WORD_FIELD_SET(data[2], 14, 1, val);
}

static uint32_t bcmpkt_txpmd_cpu_tx_qos_fields_vld_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_CPU_TX) {
        return 0;
    }
    val = WORD_FIELD_GET(data[2], 14, 1);
    return val;
}

static void bcmpkt_txpmd_cpu_tx_routed_pkt_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_CPU_TX) {
        return;
    }
    WORD_FIELD_SET(data[2], 15, 1, val);
}

static uint32_t bcmpkt_txpmd_cpu_tx_routed_pkt_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_CPU_TX) {
        return 0;
    }
    val = WORD_FIELD_GET(data[2], 15, 1);
    return val;
}

static void bcmpkt_txpmd_cpu_tx_unicast_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_CPU_TX) {
        return;
    }
    WORD_FIELD_SET(data[2], 17, 1, val);
}

static uint32_t bcmpkt_txpmd_cpu_tx_unicast_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_CPU_TX) {
        return 0;
    }
    val = WORD_FIELD_GET(data[2], 17, 1);
    return val;
}

static void bcmpkt_txpmd_cpu_tx_sop_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_CPU_TX) {
        return;
    }
    WORD_FIELD_SET(data[2], 16, 1, val);
}

static uint32_t bcmpkt_txpmd_cpu_tx_sop_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_CPU_TX) {
        return 0;
    }
    val = WORD_FIELD_GET(data[2], 16, 1);
    return val;
}

static void bcmpkt_txpmd_cpu_tx_vrf_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_CPU_TX) {
        return;
    }
    WORD_FIELD_SET(data[2], 18, 6, val);
}

static uint32_t bcmpkt_txpmd_cpu_tx_vrf_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_CPU_TX) {
        return 0;
    }
    val = WORD_FIELD_GET(data[2], 18, 6);
    return val;
}

static void bcmpkt_txpmd_cpu_tx_vrf_valid_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_CPU_TX) {
        return;
    }
    WORD_FIELD_SET(data[2], 24, 1, val);
}

static uint32_t bcmpkt_txpmd_cpu_tx_vrf_valid_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_CPU_TX) {
        return 0;
    }
    val = WORD_FIELD_GET(data[2], 24, 1);
    return val;
}

static void bcmpkt_txpmd_cpu_tx_wcmp_sel_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_CPU_TX) {
        return;
    }
    WORD_FIELD_SET(data[2], 25, 1, val);
}

static uint32_t bcmpkt_txpmd_cpu_tx_wcmp_sel_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_CPU_TX) {
        return 0;
    }
    val = WORD_FIELD_GET(data[2], 25, 1);
    return val;
}

static void bcmpkt_txpmd_oam_downmep_tx_cell_error_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_OAM_DOWNMEP_TX) {
        return;
    }
    WORD_FIELD_SET(data[3], 0, 1, val);
}

static uint32_t bcmpkt_txpmd_oam_downmep_tx_cell_error_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_OAM_DOWNMEP_TX) {
        return 0;
    }
    val = WORD_FIELD_GET(data[3], 0, 1);
    return val;
}

static void bcmpkt_txpmd_oam_downmep_tx_cell_length_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_OAM_DOWNMEP_TX) {
        return;
    }
    WORD_FIELD_SET(data[3], 1, 8, val);
}

static uint32_t bcmpkt_txpmd_oam_downmep_tx_cell_length_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_OAM_DOWNMEP_TX) {
        return 0;
    }
    val = WORD_FIELD_GET(data[3], 1, 8);
    return val;
}

static void bcmpkt_txpmd_oam_downmep_tx_cos_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_OAM_DOWNMEP_TX) {
        return;
    }
    WORD_FIELD_SET(data[3], 9, 6, val);
}

static uint32_t bcmpkt_txpmd_oam_downmep_tx_cos_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_OAM_DOWNMEP_TX) {
        return 0;
    }
    val = WORD_FIELD_GET(data[3], 9, 6);
    return val;
}

static void bcmpkt_txpmd_oam_downmep_tx_destination_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_OAM_DOWNMEP_TX) {
        return;
    }
    WORD_FIELD_SET(data[3], 15, 16, val);
}

static uint32_t bcmpkt_txpmd_oam_downmep_tx_destination_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_OAM_DOWNMEP_TX) {
        return 0;
    }
    val = WORD_FIELD_GET(data[3], 15, 16);
    return val;
}

static void bcmpkt_txpmd_oam_downmep_tx_destination_type_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_OAM_DOWNMEP_TX) {
        return;
    }
    WORD_FIELD_SET(data[3], 31, 1, val & MASK(1));
    WORD_FIELD_SET(data[2], 0, 3, (val >> 1) & MASK(3));
}

static uint32_t bcmpkt_txpmd_oam_downmep_tx_destination_type_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_OAM_DOWNMEP_TX) {
        return 0;
    }
    val = (WORD_FIELD_GET(data[3], 31, 1) | (WORD_FIELD_GET(data[2], 0, 3) << 1)) ;
    return val;
}

static void bcmpkt_txpmd_oam_downmep_tx_eop_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_OAM_DOWNMEP_TX) {
        return;
    }
    WORD_FIELD_SET(data[2], 3, 1, val);
}

static uint32_t bcmpkt_txpmd_oam_downmep_tx_eop_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_OAM_DOWNMEP_TX) {
        return 0;
    }
    val = WORD_FIELD_GET(data[2], 3, 1);
    return val;
}

static void bcmpkt_txpmd_oam_downmep_tx_input_pri_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_OAM_DOWNMEP_TX) {
        return;
    }
    WORD_FIELD_SET(data[2], 4, 4, val);
}

static uint32_t bcmpkt_txpmd_oam_downmep_tx_input_pri_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_OAM_DOWNMEP_TX) {
        return 0;
    }
    val = WORD_FIELD_GET(data[2], 4, 4);
    return val;
}

static void bcmpkt_txpmd_oam_downmep_tx_lm_counter_action_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_OAM_DOWNMEP_TX) {
        return;
    }
    WORD_FIELD_SET(data[2], 8, 2, val);
}

static uint32_t bcmpkt_txpmd_oam_downmep_tx_lm_counter_action_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_OAM_DOWNMEP_TX) {
        return 0;
    }
    val = WORD_FIELD_GET(data[2], 8, 2);
    return val;
}

static void bcmpkt_txpmd_oam_downmep_tx_lm_counter_id_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_OAM_DOWNMEP_TX) {
        return;
    }
    WORD_FIELD_SET(data[2], 10, 9, val);
}

static uint32_t bcmpkt_txpmd_oam_downmep_tx_lm_counter_id_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_OAM_DOWNMEP_TX) {
        return 0;
    }
    val = WORD_FIELD_GET(data[2], 10, 9);
    return val;
}

static void bcmpkt_txpmd_oam_downmep_tx_oam_replacement_offset_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_OAM_DOWNMEP_TX) {
        return;
    }
    WORD_FIELD_SET(data[2], 19, 6, val);
}

static uint32_t bcmpkt_txpmd_oam_downmep_tx_oam_replacement_offset_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_OAM_DOWNMEP_TX) {
        return 0;
    }
    val = WORD_FIELD_GET(data[2], 19, 6);
    return val;
}

static void bcmpkt_txpmd_oam_downmep_tx_pkt_length_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_OAM_DOWNMEP_TX) {
        return;
    }
    WORD_FIELD_SET(data[2], 25, 7, val & MASK(7));
    WORD_FIELD_SET(data[1], 0, 7, (val >> 7) & MASK(7));
}

static uint32_t bcmpkt_txpmd_oam_downmep_tx_pkt_length_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_OAM_DOWNMEP_TX) {
        return 0;
    }
    val = (WORD_FIELD_GET(data[2], 25, 7) | (WORD_FIELD_GET(data[1], 0, 7) << 7)) ;
    return val;
}

static void bcmpkt_txpmd_oam_downmep_tx_rqe_q_num_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_OAM_DOWNMEP_TX) {
        return;
    }
    WORD_FIELD_SET(data[1], 7, 4, val);
}

static uint32_t bcmpkt_txpmd_oam_downmep_tx_rqe_q_num_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_OAM_DOWNMEP_TX) {
        return 0;
    }
    val = WORD_FIELD_GET(data[1], 7, 4);
    return val;
}

static void bcmpkt_txpmd_oam_downmep_tx_sop_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_OAM_DOWNMEP_TX) {
        return;
    }
    WORD_FIELD_SET(data[1], 11, 1, val);
}

static uint32_t bcmpkt_txpmd_oam_downmep_tx_sop_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_OAM_DOWNMEP_TX) {
        return 0;
    }
    val = WORD_FIELD_GET(data[1], 11, 1);
    return val;
}

static void bcmpkt_txpmd_oam_downmep_tx_spap_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_OAM_DOWNMEP_TX) {
        return;
    }
    WORD_FIELD_SET(data[1], 12, 2, val);
}

static uint32_t bcmpkt_txpmd_oam_downmep_tx_spap_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_OAM_DOWNMEP_TX) {
        return 0;
    }
    val = WORD_FIELD_GET(data[1], 12, 2);
    return val;
}

static void bcmpkt_txpmd_oam_downmep_tx_spid_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_OAM_DOWNMEP_TX) {
        return;
    }
    WORD_FIELD_SET(data[1], 14, 2, val);
}

static uint32_t bcmpkt_txpmd_oam_downmep_tx_spid_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_OAM_DOWNMEP_TX) {
        return 0;
    }
    val = WORD_FIELD_GET(data[1], 14, 2);
    return val;
}

static void bcmpkt_txpmd_oam_downmep_tx_spid_override_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_OAM_DOWNMEP_TX) {
        return;
    }
    WORD_FIELD_SET(data[1], 16, 1, val);
}

static uint32_t bcmpkt_txpmd_oam_downmep_tx_spid_override_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_OAM_DOWNMEP_TX) {
        return 0;
    }
    val = WORD_FIELD_GET(data[1], 16, 1);
    return val;
}

static void bcmpkt_txpmd_oam_downmep_tx_src_modid_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_OAM_DOWNMEP_TX) {
        return;
    }
    WORD_FIELD_SET(data[1], 17, 8, val);
}

static uint32_t bcmpkt_txpmd_oam_downmep_tx_src_modid_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_OAM_DOWNMEP_TX) {
        return 0;
    }
    val = WORD_FIELD_GET(data[1], 17, 8);
    return val;
}

static void bcmpkt_txpmd_oam_downmep_tx_timestamp_action_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_OAM_DOWNMEP_TX) {
        return;
    }
    WORD_FIELD_SET(data[1], 25, 1, val);
}

static uint32_t bcmpkt_txpmd_oam_downmep_tx_timestamp_action_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_OAM_DOWNMEP_TX) {
        return 0;
    }
    val = WORD_FIELD_GET(data[1], 25, 1);
    return val;
}

static void bcmpkt_txpmd_oam_downmep_tx_unicast_set(uint32_t *data, uint32_t val)
{
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_OAM_DOWNMEP_TX) {
        return;
    }
    WORD_FIELD_SET(data[1], 26, 1, val);
}

static uint32_t bcmpkt_txpmd_oam_downmep_tx_unicast_get(uint32_t *data)
{
    uint32_t val;
    if (bcmpkt_txpmd_header_type_get(data) != BCMPKT_TXPMD_HEADER_T_OAM_DOWNMEP_TX) {
        return 0;
    }
    val = WORD_FIELD_GET(data[1], 26, 1);
    return val;
}

static uint32_t bcmpkt_txpmd_i_size_get(uint32_t *data, uint32_t **addr)
{
    return 4;
}


const bcmpkt_txpmd_fget_t bcm56080_a0_txpmd_fget = {
    {
        bcmpkt_txpmd_start_get,
        bcmpkt_txpmd_header_type_get,
        NULL,
        NULL,
        bcmpkt_txpmd_sop_get,
        bcmpkt_txpmd_eop_get,
        NULL,
        bcmpkt_txpmd_cell_error_get,
        NULL,
        bcmpkt_txpmd_src_modid_get,
        bcmpkt_txpmd_cos_get,
        bcmpkt_txpmd_input_pri_get,
        bcmpkt_txpmd_unicast_get,
        bcmpkt_txpmd_rqe_q_num_get,
        NULL,
        bcmpkt_txpmd_ieee1588_one_step_enable_get,
        bcmpkt_txpmd_ieee1588_regen_udp_checksum_get,
        bcmpkt_txpmd_ieee1588_ingress_timestamp_sign_get,
        bcmpkt_txpmd_ieee1588_timestamp_hdr_offset_get,
        bcmpkt_txpmd_tx_ts_get,
        bcmpkt_txpmd_spid_override_get,
        bcmpkt_txpmd_spid_get,
        bcmpkt_txpmd_spap_get,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        bcmpkt_txpmd_cng_get,
        bcmpkt_txpmd_destination_get,
        bcmpkt_txpmd_destination_type_get,
        bcmpkt_txpmd_wred_mark_eligible_get,
        bcmpkt_txpmd_wred_response_get,
        bcmpkt_txpmd_cpu_tx_mcast_lb_index_get,
        bcmpkt_txpmd_cpu_tx_ecmp_member_id_get,
        bcmpkt_txpmd_cpu_tx_destination_get,
        bcmpkt_txpmd_cpu_tx_destination_type_get,
        bcmpkt_txpmd_cpu_tx_dp_get,
        bcmpkt_txpmd_cpu_tx_input_pri_get,
        bcmpkt_txpmd_cpu_tx_int_cn_get,
        bcmpkt_txpmd_cpu_tx_int_pri_get,
        bcmpkt_txpmd_cpu_tx_mcast_lb_index_vld_get,
        bcmpkt_txpmd_cpu_tx_pkt_profile_get,
        bcmpkt_txpmd_cpu_tx_qos_fields_vld_get,
        bcmpkt_txpmd_cpu_tx_routed_pkt_get,
        bcmpkt_txpmd_cpu_tx_unicast_get,
        bcmpkt_txpmd_cpu_tx_sop_get,
        bcmpkt_txpmd_cpu_tx_vrf_get,
        bcmpkt_txpmd_cpu_tx_vrf_valid_get,
        bcmpkt_txpmd_cpu_tx_wcmp_sel_get,
        bcmpkt_txpmd_oam_downmep_tx_cell_error_get,
        bcmpkt_txpmd_oam_downmep_tx_cell_length_get,
        bcmpkt_txpmd_oam_downmep_tx_cos_get,
        bcmpkt_txpmd_oam_downmep_tx_destination_get,
        bcmpkt_txpmd_oam_downmep_tx_destination_type_get,
        bcmpkt_txpmd_oam_downmep_tx_eop_get,
        bcmpkt_txpmd_oam_downmep_tx_input_pri_get,
        bcmpkt_txpmd_oam_downmep_tx_lm_counter_action_get,
        bcmpkt_txpmd_oam_downmep_tx_lm_counter_id_get,
        bcmpkt_txpmd_oam_downmep_tx_oam_replacement_offset_get,
        bcmpkt_txpmd_oam_downmep_tx_pkt_length_get,
        bcmpkt_txpmd_oam_downmep_tx_rqe_q_num_get,
        bcmpkt_txpmd_oam_downmep_tx_sop_get,
        bcmpkt_txpmd_oam_downmep_tx_spap_get,
        bcmpkt_txpmd_oam_downmep_tx_spid_get,
        bcmpkt_txpmd_oam_downmep_tx_spid_override_get,
        bcmpkt_txpmd_oam_downmep_tx_src_modid_get,
        bcmpkt_txpmd_oam_downmep_tx_timestamp_action_get,
        bcmpkt_txpmd_oam_downmep_tx_unicast_get,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL
    }
};


const bcmpkt_txpmd_fset_t bcm56080_a0_txpmd_fset = {
    {
        bcmpkt_txpmd_start_set,
        bcmpkt_txpmd_header_type_set,
        NULL,
        NULL,
        bcmpkt_txpmd_sop_set,
        bcmpkt_txpmd_eop_set,
        NULL,
        bcmpkt_txpmd_cell_error_set,
        NULL,
        bcmpkt_txpmd_src_modid_set,
        bcmpkt_txpmd_cos_set,
        bcmpkt_txpmd_input_pri_set,
        bcmpkt_txpmd_unicast_set,
        bcmpkt_txpmd_rqe_q_num_set,
        NULL,
        bcmpkt_txpmd_ieee1588_one_step_enable_set,
        bcmpkt_txpmd_ieee1588_regen_udp_checksum_set,
        bcmpkt_txpmd_ieee1588_ingress_timestamp_sign_set,
        bcmpkt_txpmd_ieee1588_timestamp_hdr_offset_set,
        bcmpkt_txpmd_tx_ts_set,
        bcmpkt_txpmd_spid_override_set,
        bcmpkt_txpmd_spid_set,
        bcmpkt_txpmd_spap_set,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        bcmpkt_txpmd_cng_set,
        bcmpkt_txpmd_destination_set,
        bcmpkt_txpmd_destination_type_set,
        bcmpkt_txpmd_wred_mark_eligible_set,
        bcmpkt_txpmd_wred_response_set,
        bcmpkt_txpmd_cpu_tx_mcast_lb_index_set,
        bcmpkt_txpmd_cpu_tx_ecmp_member_id_set,
        bcmpkt_txpmd_cpu_tx_destination_set,
        bcmpkt_txpmd_cpu_tx_destination_type_set,
        bcmpkt_txpmd_cpu_tx_dp_set,
        bcmpkt_txpmd_cpu_tx_input_pri_set,
        bcmpkt_txpmd_cpu_tx_int_cn_set,
        bcmpkt_txpmd_cpu_tx_int_pri_set,
        bcmpkt_txpmd_cpu_tx_mcast_lb_index_vld_set,
        bcmpkt_txpmd_cpu_tx_pkt_profile_set,
        bcmpkt_txpmd_cpu_tx_qos_fields_vld_set,
        bcmpkt_txpmd_cpu_tx_routed_pkt_set,
        bcmpkt_txpmd_cpu_tx_unicast_set,
        bcmpkt_txpmd_cpu_tx_sop_set,
        bcmpkt_txpmd_cpu_tx_vrf_set,
        bcmpkt_txpmd_cpu_tx_vrf_valid_set,
        bcmpkt_txpmd_cpu_tx_wcmp_sel_set,
        bcmpkt_txpmd_oam_downmep_tx_cell_error_set,
        bcmpkt_txpmd_oam_downmep_tx_cell_length_set,
        bcmpkt_txpmd_oam_downmep_tx_cos_set,
        bcmpkt_txpmd_oam_downmep_tx_destination_set,
        bcmpkt_txpmd_oam_downmep_tx_destination_type_set,
        bcmpkt_txpmd_oam_downmep_tx_eop_set,
        bcmpkt_txpmd_oam_downmep_tx_input_pri_set,
        bcmpkt_txpmd_oam_downmep_tx_lm_counter_action_set,
        bcmpkt_txpmd_oam_downmep_tx_lm_counter_id_set,
        bcmpkt_txpmd_oam_downmep_tx_oam_replacement_offset_set,
        bcmpkt_txpmd_oam_downmep_tx_pkt_length_set,
        bcmpkt_txpmd_oam_downmep_tx_rqe_q_num_set,
        bcmpkt_txpmd_oam_downmep_tx_sop_set,
        bcmpkt_txpmd_oam_downmep_tx_spap_set,
        bcmpkt_txpmd_oam_downmep_tx_spid_set,
        bcmpkt_txpmd_oam_downmep_tx_spid_override_set,
        bcmpkt_txpmd_oam_downmep_tx_src_modid_set,
        bcmpkt_txpmd_oam_downmep_tx_timestamp_action_set,
        bcmpkt_txpmd_oam_downmep_tx_unicast_set,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL
    }
};


const bcmpkt_txpmd_figet_t bcm56080_a0_txpmd_figet = {
    {
        bcmpkt_txpmd_i_size_get
    }
};

static shr_enum_map_t bcm56080_a0_txpmd_view_types[] = {
    {"sobmh_from_cpu", 1},
    {"oam_downmep_tx", 12},
    {"cpu_tx", 2},
    {NULL, -1},
};

/* -2: unsupported, -1: global, others: view's value */
static int bcm56080_a0_txpmd_view_infos[BCMPKT_TXPMD_FID_COUNT] = {
     -1, -1, -2, -2,  1,  1, -2,  1, -2,  1,  1,  1,  1,  1, -2,  1,
      1,  1,  1,  1,  1,  1,  1, -2, -2, -2, -2, -2, -2, -2,  1,  1,
      1,  1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
      2,  2,  2,  2, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
     12, 12, 12, 12, 12, 12, 12, -2, -2, -2, -2, -2, -2, -2, -2, -2,
     -2, -2, -2,
};


void bcm56080_a0_txpmd_view_info_get(bcmpkt_pmd_view_info_t *info)
{
    info->view_infos = bcm56080_a0_txpmd_view_infos;
    info->view_types = bcm56080_a0_txpmd_view_types;
    info->view_type_get = bcmpkt_txpmd_header_type_get;
}
