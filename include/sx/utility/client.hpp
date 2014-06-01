/*
 * Copyright (c) 2011-2014 sx developers (see AUTHORS)
 *
 * This file is part of sx.
 *
 * sx is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License with
 * additional permissions to the one published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version. For more information see LICENSE.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SX_CLIENT_HPP
#define SX_CLIENT_HPP

#include <bitcoin/bitcoin.hpp>
#include <obelisk/obelisk.hpp>

namespace sx {

/**
 * This prevents code repetition while retaining stack-based allocation.
 */
#define OBELISK_FULLNODE(__pool__, __fullnode__) \
    config_map_type __config__; \
    get_config(__config__); \
    threadpool __pool__(1); \
    obelisk::fullnode_interface __fullnode__( \
        __pool__, \
        __config__["service"], \
        __config__["client-certificate"], \
        __config__["server-public-key"])

/**
 * Poll obelisk for changes until stopped.
 *
 * @param[in]  fullnode  An instance of the obelisk full node interface.
 * @param[in]  pool      The threadpool used by fullnode to poll.
 * @param[in]  stopped   A flag that signals cessation of polling.
 */
void poll(obelisk::fullnode_interface& fullnode,
    bc::threadpool& pool, bool& stopped);

} // sx

#endif