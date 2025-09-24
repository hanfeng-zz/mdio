/*
 * Copyright (C) 2025-09-24  zheng zhao
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License v3.0 or later.
 * See <https://www.gnu.org/licenses/>.
 */

#include "mdio.h"
#include "mdiocommon.h"
#include <sys/ioctl.h>
#include <sys/queue.h>
#include <string.h>
#include <malloc.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>
#include <net/if.h>
#include <linux/mii.h>
#include <linux/sockios.h>

struct entry {
    int id;
    int sock;
    char interface[50];
    LIST_ENTRY(entry) entries;
};

LIST_HEAD(list_node, entry);

struct list_node list_head;

static struct entry *match_id(const int id) {
    struct entry *node = LIST_FIRST(&list_head);
    while (NULL != node) {
        if (node->id == id) {
            break;
        }
        node = LIST_NEXT(node, entries);
    };
    return node;
}

static void mdio_free(struct entry *node) {
    LIST_REMOVE(node, entries);
    free(node);
    node = NULL;
}


int mdio_open(const char *const interface, const int id) {

    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        return -errno;
    }

    struct entry *node = (struct entry *)calloc(1, sizeof(struct entry));
    if (NULL == node) {
        return -errno;
    }

    node->sock = sock;
    node->id = id;
    memcpy(node->interface, interface, strlen(interface));

    LIST_INSERT_HEAD(&list_head, node, entries);
    return 0;
}

int mdio_read(const int id, const uint16_t addr, uint16_t *val) {
    struct entry *node = match_id(id);
    if (!node) {
        return MDIO_ERR;
    }

    struct ifreq ifr = {0};
    struct mii_ioctl_data* mii = (struct mii_ioctl_data *)(&ifr.ifr_data);

    strncpy(ifr.ifr_name, node->interface, sizeof(ifr.ifr_name));
    mii->phy_id  = node->id;
    mii->reg_num = addr;

    int rc = ioctl(node->sock, SIOCGMIIREG, &ifr);
    if (rc == -1) {
        return -errno;
    }

    *val = mii->val_out;
    return 0;
}

int mdio_write(const int id, const uint16_t addr, const uint16_t val) {
    struct entry *node = match_id(id);
    if (!node) {
        return MDIO_ERR;
    }

    struct ifreq ifr = {0};
    struct mii_ioctl_data* mii = (struct mii_ioctl_data *)(&ifr.ifr_data);

    strncpy(ifr.ifr_name, node->interface, sizeof(ifr.ifr_name));
    mii->phy_id  = node->id;
    mii->reg_num = addr;
    mii->val_in = val;

    int rc = ioctl(node->sock, SIOCSMIIREG, &ifr);
    if (rc == -1) {
        return -errno;
    }

    return 0;
}

int mdio_close(const int id) {
    struct entry *node = match_id(id);
    if (node) {
        int rc = close(id);
        if ( rc == -1) {
            return -errno;
        }
        mdio_free(node);
    }
    return 0;
}