/**
 * Simple MAC communicating using the UDP protocol
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

#include "mac.h"


typedef struct umesh_mac_udp_t {
	UmeshMac mac;

	int udp_socket;

} UmeshMacUdp;


umesh_retval_t umesh_mac_udp_init(UmeshMacUdp *self);
#define UMESH_MAC_UDP_INIT_OK 0
#define UMESH_MAC_UDP_INIT_FAILED -1

umesh_retval_t umesh_mac_udp_free(UmeshMacUdp *self);
#define UMESH_MAC_UDP_FREE_OK 0
#define UMESH_MAC_UDP_FREE_FAILED -1

umesh_retval_t umesh_mac_udp_start(UmeshMacUdp *self, const char *hostname, const char *service);
#define UMESH_MAC_UDP_START_OK 0
#define UMESH_MAC_UDP_START_FAILED -1

umesh_retval_t umesh_mac_udp_stop(UmeshMacUdp *self);
#define UMESH_MAC_UDP_STOP_OK 0
#define UMESH_MAC_UDP_STOP_FAILED -1
