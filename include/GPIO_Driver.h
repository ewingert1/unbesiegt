/*
 * GPIO_Control.h
 *
 *  Created on: 20 févr. 2018
 *      Author: Emilien
 */

#ifndef GPIO_CONTROL_H_
#define GPIO_CONTROL_H_
#include <stdint.h>
#include <stdlib.h>

// Macros to enable specific BSP, one can only be active at a time
#define RPI0W_BSP
//#define RPI3B_BSP


#ifdef RPI0W_BSP

#include "rpi0w/rpi0w_gpio.h"

#define GPIO_INPUT 			RPI0W_GPIO_INPUT
#define GPIO_OUTPUT 		RPI0W_GPIO_OUTPUT

#define GPIO_PULL_UP 		RPI0W_GPIO_PULL_UP
#define GPIO_PULL_DOWN 		RPI0W_GPIO_PULL_DOWN

#endif







// Type gpio_handler : takes pin informations, and result
typedef void (*gpio_handler_t)(void* info, void* result);

typedef struct gpio_driver{
	gpio_handler_t init;
	gpio_handler_t set_pin_behaviour;
	gpio_handler_t get_pin_behaviour;
	gpio_handler_t set_pin_level;
	gpio_handler_t get_pin_level;
}gpio_driver_t;


//Functions

gpio_driver_t* create_gpio_driver();




#endif /* GPIO_CONTROL_H_ */
