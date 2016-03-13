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

#include <stdint.h>
#include <string.h>
#include <assert.h>
#include "umesh_types.h"
#include "mac.h"


umesh_retval_t umesh_mac_init(UmeshMac *self, void *context) {
	memset(self, 0, sizeof(UmeshMac));
	self->vmt.context = context;
	return UMESH_MAC_INIT_OK;
}


umesh_retval_t umesh_mac_free(UmeshMac *self) {
	(void)self;
	return UMESH_MAC_FREE_OK;
}


umesh_retval_t umesh_mac_set_received_callback(UmeshMac *self, umesh_retval_t (*received_callback)(void *context, int packet_type, uint8_t *data, size_t len), void *context) {
	assert(self != NULL);
	assert(received_callback != NULL);

	self->received_callback = received_callback;
	self->received_callback_context = context;

	return UMESH_MAC_SET_RECEIVED_CALLBACK_OK;
}


umesh_retval_t umesh_mac_received_callback(UmeshMac *self, int packet_type, uint8_t *data, size_t len) {
	assert(self != NULL);
	assert(data != NULL);

	if (self->received_callback) {
		return self->received_callback(self->received_callback_context, packet_type, data, len);
	}

	return UMESH_MAC_RECEIVED_CALLBACK_FAILED;
}


umesh_retval_t umesh_mac_send(UmeshMac *self, int packet_type, uint8_t *data, size_t len) {
	assert(self != NULL);
	assert(data != NULL);

	if (self->vmt.send != NULL) {
		return self->vmt.send(self->vmt.context, packet_type, data, len);
	}

	return UMESH_MAC_SEND_FAILED;
}

