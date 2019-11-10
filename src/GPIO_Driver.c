/*
 * GPIO_Driver.c
 *
 *  Created on: 9 nov. 2019
 *      Author: Emilien
 */

#include "GPIO_Driver.h"

static gpio_driver_t driver;

gpio_driver_t* create_gpio_driver(){

#ifdef RPI0W_BSP
	driver.init = NULL;
	driver.get_pin_behaviour = NULL;
	driver.get_pin_level = NULL;
	driver.set_pin_behaviour = rpi0w_set_pin_behaviour;
	driver.set_pin_level = rpi0w_set_pin_level;
#endif

	return &driver;

}



