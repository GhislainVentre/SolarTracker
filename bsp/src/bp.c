/*
 * bp.c
 *
 *  Created on: 8 févr. 2022
 *      Author: 33640
 */

#include "bp.h"
#include "stm32f0xx.h"

void bsp_bp_init() {
	RCC->AHBENR |= (1<<19);

	GPIOC->MODER &= ~(1<<27);
	GPIOC->MODER &= ~(1<<26);

	GPIOC->PUPDR &= ~(1<<27);
	GPIOC->PUPDR &= ~(1<<26);
}

unsigned int bsp_bp_getstate() {

	unsigned int state;

	if ((GPIOC->IDR & (1<<13)) == (1<<13)) {
	state = 0; //bouton off
	} else {
	state = 1; //bouton on
	}
	return state;
}
