/*
 * com.c
 *
 *  Created on: 21 févr. 2022
 *      Author: 33640
 */

#include "com.h"
#include "stm32f0xx.h"

void printf() {

}

void bsp_com_init() {

	RCC->AHBENR |= (1<<17);
	RCC -> APB1ENR |= (1<<17);

	//PA2 Tx
	GPIOA->MODER &= ~(1<<4);
	GPIOA->MODER |= (1<<5);

	GPIOA->AFR[0] &= ~(1<<11);
	GPIOA->AFR[0] &= ~(1<<10);
	GPIOA->AFR[0] &= ~(1<<9);
	GPIOA->AFR[0] |= (1<<8);

	//PA3 Rx
	GPIOA->MODER &= ~(1<<6);
	GPIOA->MODER |= (1<<7);

	GPIOA->AFR[0] &= ~(1<<15);
	GPIOA->AFR[0] &= ~(1<<14);
	GPIOA->AFR[0] &= ~(1<<13);
	GPIOA->AFR[0] |= (1<<12);

	USART2->CR1 = 0x00000000;
	USART2->CR2 = 0x00000000;
	USART2->CR3 = 0x00000000;

	RCC->CFGR3 &= ~(1<<17);
	RCC->CFGR3 &= ~(1<<16);

	USART2->CR1 |= (1<<15);
	// ecrire la valeur du Baud Rate dans le registre USART2_BRR
	USART2->BRR = 833;
	// Activer la transmision : ecrire '1' sur le bit b3 de USART2_CR1
	USART2->CR1 |= (1<<3);
	// Activer la reception : ecrire '1' sur le bit b2 de USART2_CR1
	USART2->CR1 |= (1<<2);
	// activer le peripherique USART2 en dernier
	// mettre a '1' le bit bit b0 de USART2_CR1
	USART2->CR1 |= (1<<0);
}
