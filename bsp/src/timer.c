/*
 * timer.c
 *
 *  Created on: 25 févr. 2022
 *      Author: 33640
 */

#include "timer.h"
#include "stm32f0xx.h"

void bsp_timer_init_timebase() {
RCC->APB1ENR |= (1<<4);

TIM6->CR1 = 0x0000;
TIM6->CR2 = 0x0000;

TIM6->PSC = (unsigned int) 48000-1;
TIM6->ARR = (unsigned int) 1000-1;

TIM6->CR1 |= (1<<7);
TIM6->CR1 |= (1<<0);
}

void bsp_timer_init_IRQ() {

	TIM6->CR1 &= ~(1<<0);

	NVIC_SetPriority(TIM6_DAC_IRQn,1);
	NVIC_EnableIRQ(TIM6_DAC_IRQn);

	TIM6->DIER |= (1<<0);
	TIM6->CR1 |= (1<<0);
}

