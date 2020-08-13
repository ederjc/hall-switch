#include <stdint.h>
#include <iostream>
#include "hall-switch-rpi.hpp"

//#define HALL_SWITCH_FRAMEWORK HALL_SWITCH_FRMWK_RPI

HallSwitchRpi    hs;

int main() {
	hs.init();
	hs.enable();

	while (true) {
		hs.getStatus();
		usleep(1 * 1000 * 1000);
	}
}

main();