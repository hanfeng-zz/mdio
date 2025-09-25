/*
 * Copyright (C) 2025-09-24  zheng zhao
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License v3.0 or later.
 * See <https://www.gnu.org/licenses/>.
 */

#pragma once
#include <iostream>
#include "mdiocommon.h"

class MdioDriver {
public:
    MdioDriver(const MdioDriver &) = delete;

    MdioDriver &operator=(const MdioDriver&) = delete;

    MdioDriver(const MdioDriver &&) = delete;

    MdioDriver &operator=(const MdioDriver&&) = delete;

    MdioDriver() = default;

    virtual ~MdioDriver();
    
    int open(const std::string &interface, const uint16_t &id);

    int read(const uint16_t &addr, uint16_t &val);

    int write(const uint16_t &addr, const uint16_t &val);
    // auto release file descriptor, also possible to release manually
    int close();
private:
    std::string _interface {};

    int _sock = -1;

    uint16_t _id = 0;
};