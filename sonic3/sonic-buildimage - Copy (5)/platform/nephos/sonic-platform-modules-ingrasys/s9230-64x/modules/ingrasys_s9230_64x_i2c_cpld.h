/* header file for i2c cpld driver of ingrasys_s9230_64x
 *
 * Copyright (C) 2017 Ingrasys Technology Corporation.
 * Leo Lin <feng.lee.usa@ingrasys.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef INGRASYS_S9230_64X_I2C_CPLD_H
#define INGRASYS_S9230_64X_I2C_CPLD_H

/* CPLD device index value */
enum cpld_id {
    cpld1,
    cpld2,
    cpld3,
    cpld4,
    cpld5
};

/* port number on CPLD */
#define CPLD_1_PORT_NUM 12
#define CPLD_2_PORT_NUM 13

/* QSFP port number */
#define QSFP_MAX_PORT_NUM   64
#define QSFP_MIN_PORT_NUM   1

/* SFP+ port number */
#define SFP_MAX_PORT_NUM    2
#define SFP_MIN_PORT_NUM    1


/* CPLD registers */
#define CPLD_BOARD_TYPE_REG             0x0
#define CPLD_EXT_BOARD_TYPE_REG         0x7
#define CPLD_VERSION_REG                0x1
#define CPLD_ID_REG                     0x2
#define CPLD_QSFP_PORT_STATUS_BASE_REG  0x20
#define CPLD_QSFP_PORT_CONFIG_BASE_REG  0x30
#define CPLD_QSFP_PORT_INTERRUPT_REG    0x40
#define CPLD_SFP_PORT_STATUS_REG        0x2F
#define CPLD_SFP_PORT_CONFIG_REG        0x3F
#define CPLD_QSFP_PORT_INTERRUPT_REG    0x40
#define CPLD_10GMUX_CONFIG_REG          0x41
#define CPLD_BMC_STATUS_REG             0x42
#define CPLD_BMC_WATCHDOG_REG           0x43
#define CPLD_USB_STATUS_REG             0x44
#define CPLD_REST_CONTROL_REG           0x4A


/* bit definition for register value */
enum CPLD_QSFP_PORT_STATUS_BITS {
    CPLD_QSFP_PORT_STATUS_INT_BIT,
    CPLD_QSFP_PORT_STATUS_ABS_BIT,
};
enum CPLD_QSFP_PORT_CONFIG_BITS {
    CPLD_QSFP_PORT_CONFIG_RESET_BIT,
    CPLD_QSFP_PORT_CONFIG_RESERVE_BIT,
    CPLD_QSFP_PORT_CONFIG_LPMODE_BIT,
};
enum CPLD_SFP_PORT_STATUS_BITS {
    CPLD_SFP_PORT_STATUS_PRESENT_BIT,
    CPLD_SFP_PORT_STATUS_TXFAULT_BIT,
    CPLD_SFP_PORT_STATUS_RXLOS_BIT,
};
enum CPLD_SFP_PORT_CONFIG_BITS {
    CPLD_SFP_PORT_CONFIG_TXDIS_BIT,
    CPLD_SFP_PORT_CONFIG_RS_BIT,
    CPLD_SFP_PORT_CONFIG_TS_BIT,
};
enum CPLD_10GMUX_CONFIG_BITS {
    CPLD_10GMUX_CONFIG_ENSMB_BIT,
    CPLD_10GMUX_CONFIG_ENINPUT_BIT,
    CPLD_10GMUX_CONFIG_SEL1_BIT,
    CPLD_10GMUX_CONFIG_SEL0_BIT,
};
enum CPLD_BMC_WATCHDOG_BITS {
    CPLD_10GMUX_CONFIG_ENTIMER_BIT,
    CPLD_10GMUX_CONFIG_TIMEOUT_BIT,
};
enum CPLD_RESET_CONTROL_BITS {
    CPLD_RESET_CONTROL_SWRST_BIT,
    CPLD_RESET_CONTROL_CP2104RST_BIT,
    CPLD_RESET_CONTROL_82P33814RST_BIT,
    CPLD_RESET_CONTROL_BMCRST_BIT,
};

/* bit field structure for register value */
struct cpld_reg_board_type_t {
    u8 build_rev:2;
    u8 hw_rev:2;
    u8 board_id:4;
};

struct cpld_reg_version_t {
    u8 revision:6;
    u8 release:1;
    u8 reserve:1;
};

struct cpld_reg_id_t {
    u8 id:3;
    u8 release:5;
};

/* common manipulation */
#define INVALID(i, min, max)    ((i < min) || (i > max) ? 1u : 0u)
#define READ_BIT(val, bit)      ((0u == (val & (1<<bit))) ? 0u : 1u)
#define SET_BIT(val, bit)       (val |= (1 << bit))
#define CLEAR_BIT(val, bit)     (val &= ~(1 << bit))
#define TOGGLE_BIT(val, bit)    (val ^= (1 << bit))
#define _BIT(n)                 (1<<(n))
#define _BIT_MASK(len)          (BIT(len)-1)

/* bitfield of register manipulation */
#define READ_BF(bf_struct, val, bf_name, bf_value) \
    (bf_value = ((struct bf_struct *)&val)->bf_name)
#define READ_BF_1(bf_struct, val, bf_name, bf_value) \
    bf_struct bf; \
    bf.data = val; \
    bf_value = bf.bf_name
#define BOARD_TYPE_BUILD_REV_GET(val, res) \
    READ_BF(cpld_reg_board_type_t, val, build_rev, res)
#define BOARD_TYPE_HW_REV_GET(val, res) \
    READ_BF(cpld_reg_board_type_t, val, hw_rev, res)
#define BOARD_TYPE_BOARD_ID_GET(val, res) \
    READ_BF(cpld_reg_board_type_t, val, board_id, res)
#define CPLD_VERSION_REV_GET(val, res) \
    READ_BF(cpld_reg_version_t, val, revision, res)
#define CPLD_VERSION_REL_GET(val, res) \
    READ_BF(cpld_reg_version_t, val, release, res)
#define CPLD_ID_ID_GET(val, res) \
    READ_BF(cpld_reg_id_t, val, id, res)
#define CPLD_ID_REL_GET(val, res) \
    READ_BF(cpld_reg_id_t, val, release, res)
/* QSFP/SFP registers manipulation */
#define QSFP_TO_CPLD_IDX(qsfp_port, cpld_index, cpld_port) \
{ \
    if (QSFP_MIN_PORT_NUM <= qsfp_port && qsfp_port <= CPLD_1_PORT_NUM) { \
        cpld_index = cpld1; \
        cpld_port = qsfp_port - 1; \
    } else if (CPLD_1_PORT_NUM < qsfp_port \
        && qsfp_port <= QSFP_MAX_PORT_NUM) { \
        cpld_index = cpld2 + (qsfp_port - 1 - CPLD_1_PORT_NUM) \
                / CPLD_2_PORT_NUM; \
        cpld_port = (qsfp_port - 1 - CPLD_1_PORT_NUM) % \
                CPLD_2_PORT_NUM; \
    } else { \
        cpld_index = 0; \
        cpld_port = 0; \
    } \
}
#define SFP_TO_CPLD_IDX(sfp_port, cpld_index) \
    (cpld_index = sfp_port - SFP_MIN_PORT_NUM)
#define QSFP_PORT_STATUS_REG(cpld_port) \
    (CPLD_QSFP_PORT_STATUS_BASE_REG + cpld_port)
#define QSFP_PORT_CONFIG_REG(cpld_port) \
    (CPLD_QSFP_PORT_CONFIG_BASE_REG + cpld_port)
#define QSFP_PORT_INT_BIT_GET(port_status_value) \
    READ_BIT(port_status_value, CPLD_QSFP_PORT_STATUS_INT_BIT)
#define QSFP_PORT_ABS_BIT_GET(port_status_value) \
    READ_BIT(port_status_value, CPLD_QSFP_PORT_STATUS_ABS_BIT)
#define QSFP_PORT_RESET_BIT_GET(port_config_value) \
    READ_BIT(port_config_value, CPLD_QSFP_PORT_CONFIG_RESET_BIT)
#define QSFP_PORT_LPMODE_BIT_GET(port_config_value) \
    READ_BIT(port_config_value, CPLD_QSFP_PORT_CONFIG_LPMODE_BIT)
#define QSFP_PORT_RESET_BIT_SET(port_config_value) \
    SET_BIT(port_config_value, CPLD_QSFP_PORT_CONFIG_RESET_BIT)
#define QSFP_PORT_RESET_BIT_CLEAR(port_config_value) \
    CLEAR_BIT(port_config_value, CPLD_QSFP_PORT_CONFIG_RESET_BIT)
#define QSFP_PORT_LPMODE_BIT_SET(port_config_value) \
    SET_BIT(port_config_value, CPLD_QSFP_PORT_CONFIG_LPMODE_BIT)
#define QSFP_PORT_LPMODE_BIT_CLEAR(port_config_value) \
    CLEAR_BIT(port_config_value, CPLD_QSFP_PORT_CONFIG_LPMODE_BIT)
#define SFP_PORT_PRESENT_BIT_GET(port_status_value) \
    READ_BIT(port_status_value, CPLD_SFP_PORT_STATUS_PRESENT_BIT)

#define SFP_PORT_TXFAULT_BIT_GET(port_status_value) \
    READ_BIT(port_status_value, CPLD_SFP_PORT_STATUS_TXFAULT_BIT)
#define SFP_PORT_RXLOS_BIT_GET(port_status_value) \
    READ_BIT(port_status_value, CPLD_SFP_PORT_STATUS_RXLOS_BIT)
#define SFP_PORT_TXDIS_BIT_GET(port_status_value) \
    READ_BIT(port_status_value, CPLD_SFP_PORT_CONFIG_TXDIS_BIT)
#define SFP_PORT_RS_BIT_GET(port_config_value) \
    READ_BIT(port_config_value, CPLD_SFP_PORT_CONFIG_RS_BIT)
#define SFP_PORT_TS_BIT_GET(port_config_value) \
    READ_BIT(port_config_value, CPLD_SFP_PORT_CONFIG_TS_BIT)
#define SFP_PORT_TXDIS_BIT_SET(port_config_value) \
    SET_BIT(port_config_value, CPLD_SFP_PORT_CONFIG_TXDIS_BIT)
#define SFP_PORT_TXDIS_BIT_CLEAR(port_config_value) \
    CLEAR_BIT(port_config_value, CPLD_SFP_PORT_CONFIG_TXDIS_BIT)
#define SFP_PORT_RS_BIT_SET(port_config_value) \
    SET_BIT(port_config_value, CPLD_SFP_PORT_CONFIG_RS_BIT)
#define SFP_PORT_RS_BIT_CLEAR(port_config_value) \
    CLEAR_BIT(port_config_value, CPLD_SFP_PORT_CONFIG_RS_BIT)
#define SFP_PORT_TS_BIT_SET(port_config_value) \
    SET_BIT(port_config_value, CPLD_SFP_PORT_CONFIG_TS_BIT)
#define SFP_PORT_TS_BIT_CLEAR(port_config_value) \
    CLEAR_BIT(port_config_value, CPLD_SFP_PORT_CONFIG_TS_BIT)

/* CPLD access functions */
extern int ingrasys_i2c_cpld_get_qsfp_port_status_val(u8 port_num);
extern int ingrasys_i2c_cpld_get_qsfp_port_config_val(u8 port_num);
extern int ingrasys_i2c_cpld_set_qsfp_port_config_val(u8 port_num, u8 reg_val);
extern int ingrasys_i2c_cpld_get_sfp_port_status_val(u8 port_num);
extern int ingrasys_i2c_cpld_get_sfp_port_config_val(u8 port_num);
extern int ingrasys_i2c_cpld_set_sfp_port_config_val(u8 port_num, u8 reg_val);
extern u8 fp_port_to_phy_port(u8 fp_port);
#endif

