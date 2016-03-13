#include <stdio.h>
#include "mac_udp.h"

int main(void) {

	UmeshMacUdp udp;

	umesh_mac_udp_init(&udp);
	umesh_mac_udp_start(&udp, "localhost", "43000");

	umesh_mac_send(&udp.mac, 0, (uint8_t *)"sdfD", 4);

	umesh_mac_udp_stop(&udp);


}

