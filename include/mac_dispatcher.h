/**
 * MAC message dispatcher
 *
 * Copyright (C) 2015, Marek Koza, qyx@krtko.org
 *
 * This file is part of uMesh node firmware (http://qyx.krtko.org/projects/umesh)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

/**
 * The MAC message dispatcher takes care of the following actions:
 *   - registering and managing handlers for different message types
 *   - providing an API to send messages (unicast, broadcast)
 *   - layer 2 message parsing and building
 *   - message encryption and decryption
 *   - message authenticity checking
 *   - forward error correction
 *
 * It uses a MAC key manager instance to retrieve all required cryptographic material (encryption and decryption keys).
 * Data is being sent and received using an interface manager instance.
 */

#include "umesh_types.h"
//~ #include "mac_key_manager.h"
#include "mac_messages.pb.h"

struct umesh_mac_dispatcher_msgtypes {

};


typedef struct umesh_mac_dispatcher {
	/* UmeshMacKeyManager *mac_key_manager; */
	/* UmeshInterfaceManager *interface_manager; */


} UmeshMacDispatcher;



umesh_retval_t umesh_mac_dispatcher_init(UmeshMacDispatcher *self);
#define UMESH_MAC_DISPATCHER_INIT_OK 0
#define UMESH_MAC_DISPATCHER_INIT_FAILED -1


