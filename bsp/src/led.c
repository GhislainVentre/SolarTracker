/*
 * led.c
 *
 *  Created on: 8 févr. 2022
 *      Author: 33640
 */

#include "led.h"
#include "stm32f0xx.h"

void bsp_led_init() {
	RCC->AHBENR |= (1<<17);

	GPIOA->MODER &= ~(1<<11);
	GPIOA->MODER |= (1<<10);

	GPIOA->OTYPER &= ~(1<<5);

	GPIOA->OSPEEDR |= (1<<11);
	GPIOA->OSPEEDR |= (1<<10);

	GPIOA->PUPDR &= ~ (1<<11);
	GPIOA->PUPDR &= ~ (1<<10);

	GPIOA->ODR &= ~(1<<5);
}

void bsp_led_on() {
	GPIOA->ODR |= (1<<5);
}

void bsp_led_off() {
	GPIOA->ODR &= ~(1<<5);
}

void bsp_led_toggle() {
	GPIOA->ODR ^= (1<<5);
}
