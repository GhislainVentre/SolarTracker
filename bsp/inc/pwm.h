/*
 * pwm.h
 *
 *  Created on: 25 févr. 2022
 *      Author: 33640
 */

#ifndef BSP_INC_PWM_H_
#define BSP_INC_PWM_H_

void bsp_timer_pwm_init();
void bsp_pwm_duty(unsigned int duty1, unsigned int duty2);

#endif /* BSP_INC_PWM_H_ */
