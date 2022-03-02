/*
 * pwm.c
 *
 *  Created on: 25 févr. 2022
 *      Author: 33640
 */

#include "pwm.h"
#include "stm32f0xx.h"

void bsp_timer_pwm_init() {
	// Activer horloge du GPIOA
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
	// Configurer PA8 et PA9 en mode Alternate Function
	GPIOA->MODER &= ~(GPIO_MODER_MODER8_Msk | GPIO_MODER_MODER9_Msk);
	GPIOA->MODER |= (0x02 <<GPIO_MODER_MODER8_Pos) | (0x02
	<<GPIO_MODER_MODER9_Pos);
	// Choisir Alternate Function AF2 (TIM1)
	GPIOA->AFR[1] &= ~(0x000000FF);
	GPIOA->AFR[1] |= (0x00000022);
	// ACtiver horloge du Timer TIM1
	RCC -> APB2ENR |= RCC_APB2ENR_TIM1EN;
	// Faire un Reset de la configuration du TIM1
	TIM1->CR1 = 0x0000;
	TIM1->CR2 = 0x0000;
	TIM1->CCER = 0x0000;
	// Configuration frequence de comptage
	// Prescaler : registre TIM61PSC
	// Fck = 48MHz -> /48 = 1MHz frequence de comptage : 1ums
	TIM1->PSC = (uint16_t) 48 -1;
	// Configuration periode des evenements
	//ARR: registre TIM6_ARR
	// periode PWM = 20 ms
	TIM1->ARR = (uint16_t) 20000;
	// Activer le registre Auto-Reload Preload
	// prechargement
	TIM1->CR1 |= TIM_CR1_ARPE;
	// Reset de la configuration
	TIM1->CCMR1 = 0x0000;
	TIM1->CCMR2 = 0x0000;
	// Choix du mode PWM mode 1 pour les 2 cannaux
	TIM1->CCMR1 |= (0x06 <<TIM_CCMR1_OC1M_Pos) | TIM_CCMR1_OC1PE;
	TIM1->CCMR1 |= (0x06 <<TIM_CCMR1_OC2M_Pos) | TIM_CCMR1_OC2PE;
	// Definir les valeurs initiales pour le rapport cyclique des 2 PWM
	TIM1->CCR1 = 1500;
	TIM1->CCR2 = 1500;
	// Activer les sorties
	TIM1->CCER |= TIM_CCER_CC1E | TIM_CCER_CC2E;
	// Activer la sortie principale
	TIM1->BDTR |= TIM_BDTR_MOE;
	// Lancer le Timer TIM1
	TIM1->CR1 |= TIM_CR1_CEN;
}

//Duty en pourcentage
void bsp_pwm_duty(unsigned int duty1, unsigned int duty2) {
	TIM1->CCR1 = (duty1*200);
	TIM1->CCR2 = (duty2*200);
}
