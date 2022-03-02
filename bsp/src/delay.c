/*
 * delay.c
 *
 *  Created on: 8 févr. 2022
 *      Author: 33640
 */

#include "delay.h"

void bsp_delay_ms(unsigned int delay) {
	unsigned int i;
	for(i=0; i<(delay*6000);i++);
}

void bsp_delay_us(unsigned int delay) {
	unsigned int i;
	for(i=0; i<(delay*10);i++);
}

unsigned int bsp_delay_ms_nb(unsigned int delay) {
	static unsigned int i=0;
	bsp_delay_ms(1);
	if(i >= delay) {
		i=0;
		return 1;
	} else {
		i++;
		return 0;
	}
}

unsigned int bsp_delay_us_nb(unsigned int delay) {
	static unsigned int i=0;
	bsp_delay_us(1);
	if(i >= delay) {
		i=0;
		return 1;
	} else {
		i++;
		return 0;
	}
}
