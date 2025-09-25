/*
 * Copyright (C) 2025-09-24  zheng zhao
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License v3.0 or later.
 * See <https://www.gnu.org/licenses/>.
 */

#include "mdioc++.h"
#include <sys/ioctl.h>
#include <sys/queue.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>
#include <net/if.h>
#include <linux/mii.h>
#include <linux/sockios.h>

MdioDriver::~MdioDriver() {
    close();
}

int MdioDriver::open(const std::string &interface, const uint16_t &id) {
    int sock = ::socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        return -errno;
    }

    _sock = sock;
    _id = id;
    _interface = interface;

    return 0;
}

int MdioDriver::read(const uint16_t &addr, uint16_t &val) {

    struct ifreq ifr = {0};
    struct mii_ioctl_data* mii = (struct mii_ioctl_data *)(&ifr.ifr_data);

    strncpy(ifr.ifr_name, _interface.c_str(), sizeof(ifr.ifr_name));
    mii->phy_id  = _id;
    mii->reg_num = addr;

    int rc = ::ioctl(_sock, SIOCGMIIREG, &ifr);
    if (rc == -1) {
        return -errno;
    }

    val = mii->val_out;
    return 0;
}

int MdioDriver::write(const uint16_t &addr, const uint16_t &val) {
    struct ifreq ifr = {0};
    struct mii_ioctl_data* mii = (struct mii_ioctl_data *)(&ifr.ifr_data);

    strncpy(ifr.ifr_name, _interface.c_str(), sizeof(ifr.ifr_name));
    mii->phy_id  = _id;
    mii->reg_num = addr;
    mii->val_in = val;

    int rc = ::ioctl(_sock, SIOCSMIIREG, &ifr);
    if (rc == -1) {
        return -errno;
    }

    return 0;
}

int MdioDriver::close() {
    if (_sock == -1) {
        return 0;
    }

    int rc = ::close(_sock);
    if (rc == -1) {
        return -errno;
    }

    return 0;
}