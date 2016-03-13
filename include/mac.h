/**
 * MAC interface description
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

#include <stdint.h>
#include "umesh_types.h"


struct umesh_mac_vmt {
	umesh_retval_t (*send)(void *context, int packet_type, uint8_t *data, size_t len);

	void *context;
};


typedef struct umesh_mac {
	struct umesh_mac_vmt vmt;

	umesh_retval_t (*received_callback)(void *context, int packet_type, uint8_t *data, size_t len);
	void *received_callback_context;

} UmeshMac;


umesh_retval_t umesh_mac_init(UmeshMac *self, void *context);
#define UMESH_MAC_INIT_OK 0
#define UMESH_MAC_INIT_FAILED -1

umesh_retval_t umesh_mac_free(UmeshMac *self);
#define UMESH_MAC_FREE_OK 0
#define UMESH_MAC_FREE_FAILED -1

umesh_retval_t umesh_mac_set_received_callback(UmeshMac *self, umesh_retval_t (*received_callback)(void *context, int packet_type, uint8_t *data, size_t len), void *context);
#define UMESH_MAC_SET_RECEIVED_CALLBACK_OK 0
#define UMESH_MAC_SET_RECEIVED_CALLBACK_FAILED -1

umesh_retval_t umesh_mac_received_callback(UmeshMac *self, int packet_type, uint8_t *data, size_t len);
#define UMESH_MAC_RECEIVED_CALLBACK_OK 0
#define UMESH_MAC_RECEIVED_CALLBACK_FAILED -1

umesh_retval_t umesh_mac_send(UmeshMac *self, int packet_type, uint8_t *data, size_t len);
#define UMESH_MAC_SEND_OK 0
#define UMESH_MAC_SEND_FAILED -1
