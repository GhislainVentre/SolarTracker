/*
 * port.c
 *
 *  Created on: 8 févr. 2022
 *      Author: 33640
 */

#include "PB3.h"
#include "stm32f0xx.h"

void bsp_PB3_init() {
	RCC->AHBENR |= (1<<18);

	GPIOB->MODER &= ~(1<<1);
	GPIOB->MODER |= (1<<0);

	GPIOB->OTYPER &= ~(1<<0);

	GPIOB->OSPEEDR |= (1<<1);
	GPIOB->OSPEEDR |= (1<<0);

	GPIOB->PUPDR &= ~(1<<1);
	GPIOB->PUPDR &= ~(1<<0);

	GPIOB->ODR |= (1<<0);
}

void bsp_PB3_on() {
	GPIOB->ODR |= (1<<3);
}

void bsp_PB3_off() {
	GPIOB->ODR &= ~(1<<3);
}

void bsp_PB3_toggle() {
	GPIOB->ODR ^= (1<<3);
}
