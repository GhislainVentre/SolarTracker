/*
 * adc.c
 *
 *  Created on: 21 févr. 2022
 *      Author: 33640
 */

#include "adc.h"
#include "stm32f0xx.h"

void bsp_adc_init() {
	// Activation de horloge du GPIOC
	// Mettre a '1' le bit b19 du registre RCC_AHBENR
	RCC->AHBENR |= (1<<19);
	// Configure le pin PC1 en mode Analog
	// Mettre à "11" les bits b3b2 du registre GPIOC_MODER
	GPIOC->MODER |= (0x03 <<1);
	// Activation de horloge de ADC
	// Mettre a '1' le bit b9 du registre RCC_APB2ENR
	// voir page 130 pour les autres bits
	RCC->APB2ENR |= (1<<9);
	// Reset de la configuration de ADC
	// Mise a zero des regsitres de configuration de ADC
	ADC1->CR = 0x00000000;
	ADC1->CFGR1 = 0x00000000;
	ADC1->CFGR2 = 0x00000000;
	ADC1->CHSELR = 0x00000000;
	// Choix du mode de conversion
	// bit b13 (CONT) du registre ADC1_CFGR1
	// '0' : conversion une seule fois : a la demande
	// '1' : conversion une en continue
	ADC1->CFGR1 |= (1<<13);
	// Choix de la resolution (nombre de bits des data)
	// bits b4b3 (Data resolution)
	// 00: 12 bits
	// 01: 10 bits
	// 10: 8 bits
	// 11: 6 bits
	ADC1->CFGR1 &= ~(0x03 <<4);
	// Choix de la source horloge pour ADC
	// bits b31b30 CKMODE[1:0]: ADC clock mode
	// 00: ADCCLK (Asynchronous clock mode), generated at product level
	 // 01: PCLK/2 (Synchronous clock mode)
	 // 10: PCLK/4 (Synchronous clock mode)
	 // 11: Reserved
	ADC1->CFGR2 |= (0x01 <<31UL);
	// Choix de la periode chantillonnage
	// Bits b2b1b0 (SMP[2:0]: Sampling time selection) du registre ADC
	// 000: 1.5 ADC clock cycles
	// 001: 7.5 ADC clock cycles
	// 010: 13.5 ADC clock cycles
	// 011: 28.5 ADC clock cycles
	// 100: 41.5 ADC clock cycles
	// 101: 55.5 ADC clock cycles
	// 110: 71.5 ADC clock cycles
	// 111: 239.5 ADC clock cycles
	ADC1->SMPR = 0x03;
	// Selectionner le canal 11 pour la conversion
	// bit b11 du registre ADC channel selection register (ADC_CHSELR)
	// Select channel 11
	ADC1->CHSELR |= ADC_CHSELR_CHSEL11;
	// Activer ADC
	// Mettre a '1' le bit b0 du registre ADC_CR
	ADC1->CR |= (1<<0);
	// Demarrer la conversion
	// Mettre a '1' le bit b2 du registre ADC_CR
	ADC1->CR |= (1<<2);
}

void bsp_adc_off() {
	ADC1->CR &= ~(1<<2);
}

void bsp_adc_on() {
	ADC1->CR |= (1<<2);
}
