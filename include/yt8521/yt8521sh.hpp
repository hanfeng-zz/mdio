/*
 * Copyright (C) 2025-09-24  zheng zhao
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License v3.0 or later.
 * See <https://www.gnu.org/licenses/>.
 */
#pragma once

#include "mdioc++.h"
#include <memory>
#include <vector>

#define YT8521_PER_STEP_PS  150

enum yt8521WorkMode {
    YT8521_WM_UTP_TO_RGMII,
    YT8521_WM_FIBER_TO_RGMII,
    YT8521_WM_UTP_FIBER_TO_RGMII,
    YT8521_WM_UTP_TO_SGMII,
    YT8521_WM_SGPHY_TO_RGMAC,
    YT8521_WM_SGMAC_TO_RGPHY,
    YT8521_WM_UTP_TO_FIBER_AUTO,
    YT8521_WM_UTP_TO_FIBER_FORCE
};

enum yt8521Register : uint16_t {
    //common register
    YT8521_REG_EXT_SMI_SDS_PHY                                          = 0xA000,
    YT8521_REG_EXT_CHIP_CONFIG                                          = 0xA001,
    YT8521_REG_EXT_SDS_CONFIG                                           = 0xA002,
    YT8521_REG_EXT_RGMII_CONFIG1                                        = 0xA003,
    YT8521_REG_EXT_RGMII_CONFIG2                                        = 0xA004,
    YT8521_REG_EXT_MDIO_CFG_AND_RGMII_OOB_MON                           = 0xA005,
    YT8521_REG_EXT_MISC_CONFIG                                          = 0xA006,
    YT8521_REG_EXT_MAC_ADDR_CFG1                                        = 0xA007,
    YT8521_REG_EXT_MAC_ADDR_CFG2                                        = 0xA008,
    YT8521_REG_EXT_MAC_ADDR_CFG3                                        = 0xA009,
    YT8521_REG_EXT_WOL_CFG                                              = 0xA00A,
    YT8521_REG_EXT_LED_GENERAL_CFG                                      = 0xA00B,
    YT8521_REG_EXT_LED0_CFG                                             = 0xA00C,
    YT8521_REG_EXT_LED1_CFG                                             = 0xA00D,
    YT8521_REG_EXT_LED2_CFG                                             = 0xA00E,
    YT8521_REG_EXT_LED_BLINK_CFG                                        = 0xA00F,
    YT8521_REG_EXT_PAD_DRIVE_STRENGTH_CFG                               = 0xA010,
    YT8521_REG_EXT_SYNCE_CFG                                            = 0xA012,

    //utp mii register
    YT8521_REG_BASIC_CONTROL_REG                                        = 0x0000,
    YT8521_REG_BASIC_CONTROL_STATUS                                     = 0x0001,
    YT8521_REG_PHY_IDENTIFICATION_REG1                                  = 0x0002,
    YT8521_REG_PHY_IDENTIFICATION_REG2                                  = 0x0003,
    YT8521_REG_AUTO_NEGOTIATION_ADVERTISEMENT                           = 0x0004,
    YT8521_REG_AUTO_NEGOTIATION_LINK_PARTNER_ABILITY                    = 0x0005,
    YT8521_REG_AUTO_NEGOTIATION_EXPANSION_REG                           = 0x0006,
    YT8521_REG_AUTO_NEGOTIATION_NEXT_PAGE_REG                           = 0x0007,
    YT8521_REG_AUTO_NEGOTIATION_LINK_PARTNER_RECEIVED_NEXT_PAGE_REG     = 0x0008,
    YT8521_REG_MASTER_SLAVE_CONTROL_REG                                 = 0x0009,
    YT8521_REG_MASTER_SLAVE_STATUS_REG                                  = 0x000A,

    YT8521_REG_MMD_ACCESS_CONTROL_REG                                   = 0x000D,
    YT8521_REG_MMD_ACCESS_DATA_REG                                      = 0x000E,
    YT8521_REG_EXTENDED_STATUS_REG                                      = 0x000F,
    YT8521_REG_PHY_SPECIFIC_FUNCTION_CONTROL_REG                        = 0x0010,
    YT8521_REG_PHY_SPECIFIC_FUNCTION_STATUS_REG                         = 0x0011,
    YT8521_REG_INTERRUPT_MASK_REG                                       = 0x0012,
    YT8521_REG_INTERRUPT_STATUS_REG                                     = 0x0013,
    YT8521_REG_SPEED_AUTO_DOWNGRADE_CONTROL_REG                         = 0x0014,
    YT8521_REG_RX_ERROR_COUNTER_REG                                     = 0x0015,

    YT8521_REG_EXTENDED_REG_ADDR_OFFSET_REG                             = 0x001E,
    YT8521_REG_EXTENDED_REG_DATA_REG                                    = 0x001F,

    //utp mmd reg
    YT8521_REG_UTP_MMD_PCS_CONTROL1_REG                                 = 0x0000,
    YT8521_REG_UTP_MMD_PCS_STATUS1_REG                                  = 0x0001,
    YT8521_REG_UTP_MMD_EEE_CONTROL_AND_CAPAILITY_REG                    = 0x0014,
    YT8521_REG_UTP_MMD_EEE_WAKE_ERROR_COUNTER                           = 0x0016,
    YT8521_REG_UTP_MMD_LOCAL_DEVICE_EEE_ABILITY                         = 0x003C,
    YT8521_REG_UTP_MMD_LINK_PARTNER_EEE_ABILITY                         = 0x003D,
    //utp lds
    YT8521_REG_UTP_LDS_LRE_CONTROL                                      = 0x0000,
    YT8521_REG_UTP_LDS_LRE_STATUS                                       = 0x0001,
    YT8521_REG_UTP_LDS_PHYID_REG1                                       = 0x0002,
    YT8521_REG_UTP_LDS_PHYID_REG2                                       = 0x0003,
    YT8521_REG_UTP_LDS_AUTO_NEGOTIATION_ADVERTISED_ABILITY              = 0x0004,
    YT8521_REG_UTP_LDS_LINK_PARTNER_ABILITY                             = 0x0007,
    YT8521_REG_UTP_LDS_EXPANSION                                        = 0x000A,
    YT8521_REG_UTP_LDS_RESULTS                                          = 0x000B,
    //utp ext
    YT8521_REG_UTP_EXT_PKGEN_CFG1                                       = 0x0038,
    YT8521_REG_UTP_EXT_PKGEN_CFG3                                       = 0x003A,
    YT8521_REG_UTP_EXT_PKGEN_CFG0                                       = 0x00A0,
    YT8521_REG_UTP_EXT_PKGEN_CFG2                                       = 0x00A1,
    YT8521_REG_UTP_EXT_PKG_RX_VALID0                                    = 0x00A3,
    YT8521_REG_UTP_EXT_PKG_RX_VALID1                                    = 0x00A4,
    YT8521_REG_UTP_EXT_PKG_RX_OS0                                       = 0x00A5,
    YT8521_REG_UTP_EXT_PKG_RX_OS1                                       = 0x00A6,
    YT8521_REG_UTP_EXT_PKG_RX_US0                                       = 0x00A7,
    YT8521_REG_UTP_EXT_PKG_RX_US1                                       = 0x00A8,
    YT8521_REG_UTP_EXT_PKG_RX_ERR                                       = 0x00A9,
    YT8521_REG_UTP_EXT_PKG_RX_OS_BAD                                    = 0x00AA,
    YT8521_REG_UTP_EXT_PKG_RX_FRAGMENT                                  = 0x00AB,
    YT8521_REG_UTP_EXT_PKG_RX_NOSFD                                     = 0x00AC,
    YT8521_REG_UTP_EXT_PKG_TX_VALID0                                    = 0x00AD,
    YT8521_REG_UTP_EXT_PKG_TX_VALID1                                    = 0x00AE,
    YT8521_REG_UTP_EXT_PKG_TX_OS0                                       = 0x00AF,
    YT8521_REG_UTP_EXT_PKG_TX_OS1                                       = 0x00B0,
    YT8521_REG_UTP_EXT_PKG_TX_US0                                       = 0x00B1,
    YT8521_REG_UTP_EXT_PKG_TX_US1                                       = 0x00B2,
    YT8521_REG_UTP_EXT_PKG_TX_ERR                                       = 0x00B3,
    YT8521_REG_UTP_EXT_PKG_TX_OS_BAD                                    = 0x00B4,
    YT8521_REG_UTP_EXT_PKG_TX_FRAGMENT                                  = 0x00B5,
    YT8521_REG_UTP_EXT_PKG_TX_NOSFD                                     = 0x00B6,
    //sds mii
//    YT8521_REG_SDS_MII_BASIC_CONTROL_REG                                = 0x0000, //see udp mii reg
//    YT8521_REG_SDS_MII_BASIC_STATUS_REG                                 = 0x0001,
//    YT8521_REG_SDS_MII_SDS_IDENTIFICATION_REG1                          = 0x0002,
//    YT8521_REG_SDS_MII_SDS_IDENTIFICATION_REG2                          = 0x0003,
//    YT8521_REG_SDS_MII_AUTO_NEGO_ADVERTISEMENT                          = 0x0004,
//    YT8521_REG_SDS_MII_AUTO_NEGO_LINK_PARTNER_ABILITY                   = 0x0005,
//    YT8521_REG_SDS_MII_AUTO_NEGO_EXPANSION_REG                          = 0x0006,
//    YT8521_REG_SDS_MII_AUTO_NEGO_NEXT_PAGE_REG                          = 0x0007,
//    YT8521_REG_SDS_MII_AUTO_NEGO_LINK_OARTNER_RECV_NEXT_PAGE_REG        = 0x0008,
    YT8521_REG_SDS_MII_EXTENDED_STATUS_REG                              = 0x000F,
    YT8521_REG_SDS_MII_SDS_SPEC_STATUS_REG                              = 0x0011,
    YT8521_REG_SDS_MII_100BASE_FX_CFG                                   = 0x0014,
    YT8521_REG_SDS_MII_ERR_CNT                                          = 0x0015,
    YT8521_REG_SDS_MII_LINKFAIL_CNT                                     = 0x0016,
    //sds ext
    YT8521_REG_SDS_EXT_PKGEN_CFG1                                       = 0x0038,
    YT8521_REG_SDS_EXT_PKGEN_CFG3                                       = 0x003A,
    YT8521_REG_SDS_EXT_PKGEN_CFG0                                       = 0x01A0,
    YT8521_REG_SDS_EXT_PKGEN_CFG2                                       = 0x01A1,
    YT8521_REG_SDS_EXT_PKG_RX_VALID0                                    = 0x01A3,
    YT8521_REG_SDS_EXT_PKG_RX_VALID1                                    = 0x01A4,
    YT8521_REG_SDS_EXT_PKG_RX_OS0                                       = 0x01A5,
    YT8521_REG_SDS_EXT_PKG_RX_OS1                                       = 0x01A6,
    YT8521_REG_SDS_EXT_PKG_RX_US0                                       = 0x01A7,
    YT8521_REG_SDS_EXT_PKG_RX_US1                                       = 0x01A8,
    YT8521_REG_SDS_EXT_PKG_RX_ERR                                       = 0x01A9,
    YT8521_REG_SDS_EXT_PKG_RX_OS_BAD                                    = 0x01AA,
    YT8521_REG_SDS_EXT_PKG_RX_FRAGMENT                                  = 0x01AB,
    YT8521_REG_SDS_EXT_PKG_RX_NOSFD                                     = 0x01AC,
    YT8521_REG_SDS_EXT_PKG_TX_VALID0                                    = 0x01AD,
    YT8521_REG_SDS_EXT_PKG_TX_VALID1                                    = 0x01AE,
    YT8521_REG_SDS_EXT_PKG_TX_OS0                                       = 0x01AF,
    YT8521_REG_SDS_EXT_PKG_TX_OS1                                       = 0x01B0,
    YT8521_REG_SDS_EXT_PKG_TX_US0                                       = 0x01B1,
    YT8521_REG_SDS_EXT_PKG_TX_US1                                       = 0x01B2,
    YT8521_REG_SDS_EXT_PKG_TX_ERR                                       = 0x01B3,
    YT8521_REG_SDS_EXT_PKG_TX_OS_BAD                                    = 0x01B4,
    YT8521_REG_SDS_EXT_PKG_TX_FRAGMENT                                  = 0x01B5,
    YT8521_REG_SDS_EXT_PKG_TX_NOSFD                                     = 0x01B6,
};

enum yt8521Bits {
    //0xA001
    YT8521_BITS_SW_RST                                                  = 1 << 15,
    YT8521_BITS_RGMII_CLK_DELAY_ENABLE                                  = 1 << 8,
    YT8521_BITS_ENABLE_IDO                                              = 1 << 6,
    //0xA002
    //see https://en.wikipedia.org/wiki/Media-independent_interface
    /* 功能说明
    正常情况下：
    当 MAC 在发送数据时检测到某种错误（如 FIFO underflow、编码错误等），会在 TX_EN 高电平时把 TX_ER 拉高，告诉 PHY：当前传输数据出错。
    开启 SUPPRESS_TX_ER 时：
    会 禁止/抑制 MAC 向 PHY 发送 TX_ER 信号。
    也就是说，即使 MAC 侧产生了发送错误，TX_ER 也不会传递给 PHY。
    PHY 只会看到 TX_EN + TXD，不会因为 TX_ER 而中止或标记帧错误。
    使用场景
    某些 MAC/PHY 不需要 TX_ER：SGMII、RGMII、RMII 等精简接口里，有时根本没有 TX_ER 线，为了兼容就提供这个控制。
    调试/特殊应用：
    如果上层软件希望错误帧也发出去（例如做测试），可以 suppress TX_ER。
在链路层或协议栈自己处理错误，而不是交给 PHY 时，会用到这个功能。*/
    YT8521_BITS_ENABLE_SURPPRESS_TXER                                   = 1 << 12,
    //0xA003
    YT8521_BITS_RGMII_CFG1_RGMAC_CFG_MODE                               = 1 << 15,
    YT8521_BITS_RGMII_CFG1_TX_CLK_SEL                                   = 1 << 14,
    //0xA004
    YT8521_BITS_RGMII_CFG2_DUPLEX_RGPHY                                 = 1 << 13,
    YT8521_BITS_RGMII_CFG2_LINK_UP_RGPHY                                = 1 << 12,
    YT8521_BITS_RGMII_CFG2_DUPLEX_RGMAC                                 = 1 << 5,
    YT8521_BITS_RGMII_CFG2_LINK_UP_RGMAC                                = 1 << 4,
    //0xA005
    YT8521_BITS_DUPLEX_RGMAC_OB                                         = 1 << 13,
    YT8521_BITS_LINKUP_RGMAC_OB                                         = 1 << 12,
    /*
     * 0xA006
     *  | Bit   | Symbol                | Default | Description / 作用解释
        | ----- | --------------------- | ------- | --------------------------------------------------------
        | 15:12 | `Clk_out_sel`         | 0x0     | 选择调试时钟输出到 `RX_CLK` 引脚，用于观察时钟信号。
        | 11    | `En_dbg_data_todac`   | 0x0     | 将 ADC 数据输出到 DAC 以便调试（一般用于芯片内部信号分析）。
        | 10    | `En_output_clk`       | 0x0     | 使能调试时钟输出到 `RX_CLK`，与 `Clk_out_sel` 配合使用。
        | 9     | `Reserved`            | 0x0     | 保留位，无功能。
        | 8     | `Fiber_high_pri_cmb`  | 0x0     | 在 UTP\_FIBER\_TO\_RGMII 模式下，fiber 链路优先级更高；否则 UTP 优先。
        | 7     | `Jumbo_enable`        | 0x0     | 使能 Jumbo Frame（大于 1500 字节以太网帧）。
        | 6     | `Rem_lpblk_sds`       | 0x0     | 为 **SDS（串行差分接口 / SerDes）** 设置远端环回（remote loopback）。
        | 5     | `Rem_lpblk_phy`       | 0x0     | 为 **UTP PHY** 设置远端环回。
        | 4     | `Uldata_rloopback`    | 0x0     | 当设置了远端环回（Rem\_lpblk）时，是否保留上传数据；1=保留。
        | 3     | `Bp_gmii_fatal_rst`   | 0x1     | 绕过 GMII FIFO overflow/underflow 的复位（bypass fatal reset）。
        | 2:1   | `Comb_wait_timer_sel` | 0x2     | 当次优先链路建立后，选择等待第一优先链路的时间：<br>00=1s, 01=5s, 10=15s, 11=25s
        | 0     | `Fib_speed_sel`       | 0x1     | 当自动感应关闭时，选择 fiber 速度：1=1000BX, 0=100FX
    */

};

class yt8521Driver {
public:
    yt8521Driver(const yt8521Driver &) = delete;

    yt8521Driver &operator=(const yt8521Driver&) = delete;

    yt8521Driver(const yt8521Driver &&) = delete;

    yt8521Driver &operator=(const yt8521Driver&&) = delete;

    yt8521Driver() {
        _mdio = std::make_shared<MdioDriver>();
    };

    virtual ~yt8521Driver() = default;

    int open(const std::string &interface, const uint16_t &id) {
        return _mdio->open(interface, id);
    }
/*
 * register type:
 * - mii register: 0x00 ~ 0x1f
 *      - read()
 *      - write()
 * - extended register: access via 0x1e,0x1f
 *      - read_ext()
 *      - write_ext()
 * - mmd register: access via 0xd,0xe
 *      - read_mmd() //todo: TBD
 *      - write_mmd() //todo: TBD
 *
 * */
    int read(const uint16_t &addr, uint16_t &val) {
        return _mdio->read(addr, val);
    }

    int write(const uint16_t &addr, const uint16_t &val) {
        return _mdio->write(addr, val);
    }

    int read_ext(const uint16_t &addr, uint16_t &val) {
        if (addr <= YT8521_REG_EXTENDED_REG_DATA_REG) {
            return MDIO_OVER_LIMIT;
        }

        int rc = write(YT8521_REG_EXTENDED_REG_ADDR_OFFSET_REG, addr);
        if (rc) {
            return rc;
        }

        return read(YT8521_REG_EXTENDED_REG_DATA_REG, val);
    }

    int write_ext(const uint16_t &addr, uint16_t &val) {
        if (addr <= YT8521_REG_EXTENDED_REG_DATA_REG) {
            return MDIO_OVER_LIMIT;
        }

        int rc = write(YT8521_REG_EXTENDED_REG_ADDR_OFFSET_REG, addr);
        if (rc) {
            return rc;
        }

        return write(YT8521_REG_EXTENDED_REG_DATA_REG, val);
    }

    int reset_software() {
        uint16_t val;

        int rc = read_ext(YT8521_REG_EXT_CHIP_CONFIG, val);
        if (rc) {
            return rc;
        }

        val &= (~YT8521_BITS_SW_RST);

        return write_ext(YT8521_REG_EXT_CHIP_CONFIG, val);
    }

    void detect() {
        uint16_t val, val1, val2, val3, val4, val5, speed;

        int rc = read_ext(YT8521_REG_EXT_SMI_SDS_PHY, val);
        if (rc) {
            std::cout << "read:0x" << std::hex << YT8521_REG_EXT_SMI_SDS_PHY << " failed!" << std::endl;
            return;
        }

        std::cout << "reg:0x" << std::hex << YT8521_REG_EXT_SMI_SDS_PHY << " val:0x" << std::hex << val << std::endl;
        std::cout << "space:" << getAccessSpace(val) << std::endl;

        rc = read_ext(YT8521_REG_EXT_CHIP_CONFIG, val1);
        if (rc) {
            std::cout << "read:0x" << std::hex << YT8521_REG_EXT_CHIP_CONFIG << " failed!" << std::endl;
            return;
        }

        std::cout << "reg:0x" << std::hex << YT8521_REG_EXT_CHIP_CONFIG << " val:0x" << std::hex << val1 << std::endl;
        std::cout << "work mode:" << getChipMode(val1) << std::endl;
        std::cout << "Rgmii Ldo:" << ((val1 & YT8521_BITS_ENABLE_IDO) ? "enable" : "disable") << std::endl;
        std::cout << "Rgmii Ldo voltage control:" << getChipCfgIdo(val1) << std::endl;
        std::cout << "Rgmii clk 2ns delay control:" << (val1 & YT8521_BITS_RGMII_CLK_DELAY_ENABLE ? "enable" : "disable") << std::endl;

        rc = read_ext(YT8521_REG_EXT_SDS_CONFIG, val2);
        if (rc) {
            std::cout << "read:0x" << std::hex << YT8521_REG_EXT_SDS_CONFIG << " failed!" << std::endl;
            return;
        }

        std::cout << "reg:0x" << std::hex << YT8521_REG_EXT_SDS_CONFIG << " val:0x" << std::hex << val2 << std::endl;
        std::cout << "surppress txer:" << (val2 & YT8521_BITS_ENABLE_SURPPRESS_TXER ? "enable" : "disable") << std::endl;

        rc = read_ext(YT8521_REG_EXT_RGMII_CONFIG1, val3);
        if (rc) {
            std::cout << "read:0x" << std::hex << YT8521_REG_EXT_RGMII_CONFIG1 << " failed!" << std::endl;
            return;
        }

        rc = read_ext(YT8521_REG_EXT_RGMII_CONFIG2, val4);
        if (rc) {
            std::cout << "read:0x" << std::hex << YT8521_REG_EXT_RGMII_CONFIG2 << " failed!" << std::endl;
            return;
        }

        rc = read_ext(YT8521_REG_EXT_MDIO_CFG_AND_RGMII_OOB_MON, val5);
        if (rc) {
            std::cout << "read:0x" << std::hex << YT8521_REG_EXT_MDIO_CFG_AND_RGMII_OOB_MON << " failed!" << std::endl;
            return;
        }

        std::cout << "reg:0x" << std::hex << YT8521_REG_EXT_RGMII_CONFIG1 << " val:0x" << std::hex << val3 << std::endl;
        std::cout << "reg:0x" << std::hex << YT8521_REG_EXT_RGMII_CONFIG2 << " val:0x" << std::hex << val4 << std::endl;
        std::cout << "reg:0x" << std::hex << YT8521_REG_EXT_MDIO_CFG_AND_RGMII_OOB_MON << " val:0x" << std::hex << val5 << std::endl;

        auto workmode = getWorkMode(val3);

        if (YT8521_WM_SGPHY_TO_RGMAC == workmode) {
            if (val3 & YT8521_BITS_RGMII_CFG1_RGMAC_CFG_MODE) {
                //0xa004
                speed = (val4 >> 6) & 0x3;
                std::cout << "rgmii mac config info:\nspeed:0x" << std::hex << speed
                          << " duplex:" << (val4 & YT8521_BITS_RGMII_CFG2_DUPLEX_RGMAC ? "true" : "false")
                          << " link:" << (val4 & YT8521_BITS_RGMII_CFG2_LINK_UP_RGMAC ? "up" : "down")
                          << std::endl;
            } else {
                //0xa005
                speed = val5 >> 14;
                std::cout << "rgmii mac oob info:\nspeed:0x" << std::hex << speed
                          << " duplex:" << (val4 & YT8521_BITS_DUPLEX_RGMAC_OB ? "true" : "false")
                          << " link:" << (val4 & YT8521_BITS_LINKUP_RGMAC_OB ? "up" : "down")
                          << std::endl;
            }
        }

        std::cout << "rgmii rx_clk delay(ps):" << std::dec << getRgmiiRxDelay(val3) << std::endl;
        std::cout << "rgmii tx_clk fe delay(ps):" << std::dec << getRgmiiTxDelayFe(val3) << std::endl;
        std::cout << "rgmii tx_clk delay(ps):" << std::dec << getRgmiiTxDelay(val3) << std::endl;


    }
    //note: MdioDriver auto close
protected:
/*-------------------------0xA000-----start-----------------------------*/
    std::string getAccessSpace(const uint16_t &val) {
        std::vector<std::string> str_space {
            "UTP_SPACE",
            "SDS_SPACE"
        };
        return str_space.at((val >> 1) & 0x1);
    };
/*-------------------------0xA000-----end-----------------------------*/
/*-------------------------0xA001-----start-----------------------------*/
    enum yt8521WorkMode getWorkMode(const uint16_t &val) {
        return yt8521WorkMode(val & 0x7);
    }

    std::string getChipMode(const uint16_t &val) {
        std::vector<std::string> str_workmode {
                "YT8521_WM_UTP_TO_RGMII",
                "YT8521_WM_FIBER_TO_RGMII",
                "YT8521_WM_UTP_FIBER_TO_RGMII",
                "YT8521_WM_UTP_TO_SGMII",
                "YT8521_WM_SGPHY_TO_RGMAC",
                "YT8521_WM_SGMAC_TO_RGPHY",
                "YT8521_WM_UTP_TO_FIBER_AUTO",
                "YT8521_WM_UTP_TO_FIBER_FORCE"
        };
        return str_workmode.at(val & 0x7);
    }

    std::string getChipCfgIdo(const uint16_t &val) {
        std::vector<std::string> str_ido {
                "3.3v",
                "2.5v",
                "1.8v",
                "1.8v",
        };
        return str_ido.at((val >> 4) & 0x3);
    };
/*-------------------------0xA001-----end-----------------------------*/

/*-------------------------0xA003-----start-----------------------------*/
    int getRgmiiRxDelay(const uint16_t &val) {
        return ((val >> 10) & 0xF) * YT8521_PER_STEP_PS; // step * 150ps
    }
    //for 100M or 10M
    int getRgmiiTxDelayFe(const uint16_t &val) {
        return ((val >> 4) & 0xF) * YT8521_PER_STEP_PS; // step * 150ps
    }
    //for 1000M
    int getRgmiiTxDelay(const uint16_t &val) {
        return (val & 0xF) * YT8521_PER_STEP_PS; // step * 150ps
    }
/*-------------------------0xA003-----end-----------------------------*/

/*-------------------------0xA004-----start-----------------------------*/
    uint16_t getSpeedRgPhy(const int16_t &val) {
        return val >> 14;
    }
    uint16_t getSpeedRgMac(const int16_t &val) {
        return val >> 6;
    }
/*-------------------------0xA004-----end-----------------------------*/
private:
    std::shared_ptr<MdioDriver> _mdio = nullptr;
};