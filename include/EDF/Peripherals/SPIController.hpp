/*
 * Copyright (c) 2024, Adam Veazey
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#pragma once

#include <cstdint>

namespace EDF {

class SPIController {
public:
    enum class Response {
        Ok,
        ErrorBusy,
        ErrorOverrun,
        Error,
        ErrorTimeout,
    };
public:
    virtual ~SPIController() = default;
    virtual void select() = 0;
    virtual void deselect() = 0;
    virtual Response transfer( uint8_t& dataInOut ) = 0;
    virtual Response transfer( uint8_t* dataInOut, std::size_t n ) = 0;
};

} /* EDF */