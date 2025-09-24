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

    int read(const uint16_t &addr, uint16_t &val) {
        return _mdio->read(addr, val);
    }

    int write(const uint16_t &addr, const uint16_t &val) {
        return _mdio->write(addr, val);
    }

private:
    std::shared_ptr<MdioDriver> _mdio = nullptr;
};