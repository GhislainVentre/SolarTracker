/*
 * delay.h
 *
 *  Created on: 8 févr. 2022
 *      Author: 33640
 */

#ifndef BSP_INC_DELAY_H_
#define BSP_INC_DELAY_H_

void bsp_delay_ms(unsigned int delay);
void bsp_delay_us(unsigned int delay);
unsigned int bsp_delay_ms_nb(unsigned int delay);
unsigned int bsp_delay_us_nb(unsigned int delay);


#endif /* BSP_INC_DELAY_H_ */
