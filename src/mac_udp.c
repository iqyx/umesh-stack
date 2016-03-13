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

#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/socket.h>

#include "umesh_types.h"
#include "mac_udp.h"
#include "mac.h"


/* Called from the MAC interface */
static umesh_retval_t mac_send(void *context, int packet_type, uint8_t *data, size_t len) {
	UmeshMacUdp *self = (UmeshMacUdp *)context;
	assert(self != NULL);

	(void)packet_type;
	(void)data;
	(void)len;

	if (self->udp_socket == 0) {
		return UMESH_MAC_SEND_FAILED;
	}

	ssize_t written = write(self->udp_socket, data, len);
	if (written != (ssize_t)len) {
		return UMESH_MAC_SEND_FAILED;
	}

	printf("som tu\n");

	return UMESH_MAC_SEND_OK;

}

umesh_retval_t umesh_mac_udp_init(UmeshMacUdp *self) {

	/* Initialize the Mac interface */
	/** @todo error checking */
	umesh_mac_init(&self->mac, (void *)self);
	self->mac.vmt.send = mac_send;

	/**
	 * @todo set methods provided by the udp mac
	 *
	 * self->mac->vmt.
	 */

	return UMESH_MAC_UDP_INIT_OK;
}


umesh_retval_t umesh_mac_udp_free(UmeshMacUdp *self) {
	/** @todo error checking */
	umesh_mac_free(&self->mac);
	return UMESH_MAC_FREE_OK;
}


umesh_retval_t umesh_mac_udp_start(UmeshMacUdp *self, const char *hostname, const char *service) {
	assert(self != NULL);
	assert(hostname != NULL);
	assert(service != NULL);

	struct addrinfo hints;
	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_DGRAM;
	hints.ai_flags = 0;
	hints.ai_protocol = 0;

	struct addrinfo *result, *rp;
	int retval = getaddrinfo(hostname, service, &hints, &result);
	if (retval != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(retval));
		return UMESH_MAC_UDP_START_FAILED;
	}

	for (rp = result; rp != NULL; rp = rp->ai_next) {
		self->udp_socket = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
		if (self->udp_socket == -1) {
			continue;
		}

		if (connect(self->udp_socket, rp->ai_addr, rp->ai_addrlen) != -1) {
			break;
		}

		close(self->udp_socket);
	}

	if (rp == NULL) {
		fprintf(stderr, "Could not connect\n");
		return UMESH_MAC_UDP_START_FAILED;
	}

	freeaddrinfo(result);

	/* sfd contains the socket usable for communication */
	return UMESH_MAC_UDP_START_OK;
}


umesh_retval_t umesh_mac_udp_stop(UmeshMacUdp *self) {
	assert(self != NULL);

	if (self->udp_socket != 0) {
		close(self->udp_socket);
		self->udp_socket = 0;
	} else {
		return UMESH_MAC_UDP_STOP_FAILED;
	}

	return UMESH_MAC_UDP_STOP_OK;
}
