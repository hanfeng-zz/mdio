/*
 * Copyright (C) 2025-09-24  zheng zhao
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License v3.0 or later.
 * See <https://www.gnu.org/licenses/>.
 */

#ifndef MDIO_H
#define MDIO_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>


int mdio_open(const char *const interface, const int id);

int mdio_read(const int id, const uint16_t addr, uint16_t *val);

int mdio_write(const int id, const uint16_t addr, const uint16_t val);

int mdio_close(const int id);

int mdio_debug();
#ifdef __cplusplus
}
#endif
#endif //MDIO_H