/*
 * Rpi0W.h
 *
 *  Created on: 9 nov. 2019
 *      Author: Emilien
 */

// This file defines several constants, structures and enumerations useful for Raspberry Pi Zero Wireless hardware compatibility

#ifndef RPI0W_H_
#define RPI0W_H_

#include "bsp_common.h"

// CONSTANTS

#define BASE_ADDRESS_GPIO 					0x20000000
#define BASE_ADDRESS_ITR_CONTROL		0x3F00B200

#define RPI0W_GPIO_INPUT 			0
#define RPI0W_GPIO_OUTPUT 		1

#define RPI0W_GPIO_PULL_DOWN 	1
#define RPI0W_GPIO_PULL_UP 		2

// STRUCTURES



typedef struct __attribute__((packed)) rpi0w_gpio_registers {

	/* GPIO Function Select registers RW
	   Chaque GPFSEL reg g�re 10 pins
	   GPFSEL0 g�re les pins GPIO0 � GPIO9
	   Chaque pin utilise 3 bits :
		0b000 : input
		0b001 : output
		0b100 : alternate function 0
		0b101 : alternate function 1
		0b110 : alternate function 2
		0b111 : alternate function 3
		0b011 : alternate function 4
		0b010 : alternate function 5

		Reg : pin 0 en LSB, pin 9 en MSB, bits 30-31 en reserved
	*/
	uint32_t GPFSEL[6];

	uint32_t reserved1;
	//RESERVED32;

	// GPIO Pin Output Set registers W
	// Bit field : Ecrire 1 pour setter la pin correspondante (0 pas d'effet)
	uint32_t GPSET[2];

	uint32_t reserved2;
	//RESERVED32;

	// GPIO Pin Output Clear registers W
	// Bit field : Ecrire 1 pour clear la pin correspondante (0 pas d'effet)
	uint32_t GPCLR[2];

	uint32_t reserved3;
	//RESERVED32;

	// GPIO Pin Level registers R
	// Bit field : 1 la pin est high, 0 si elle est low
	uint32_t GPLEV[2];

	uint32_t reserved4;
	//RESERVED32;

	// GPIO Pin Event Detect Status registers RW
	uint32_t GPEDS[2];

	uint32_t reserved5;
	//RESERVED32;

	// GPIO Pin Rising Edge Detect Enable registers RW
	uint32_t GPREN[2];

	uint32_t reserved6;
	//RESERVED32;

	// GPIO Pin Falling Edge Detect Enable registers RW
	uint32_t GPFEN[2];

	uint32_t reserved7;
	//RESERVED32;

	// GPIO Pin High Detect Enable registers RW
	uint32_t GPHEN[2];

	uint32_t reserved8;
	//RESERVED32;

	// GPIO Pin Low Detect Enable registers RW
	uint32_t GPLEN[2];

	uint32_t reserved9;
	//RESERVED32;

	// GPIO Pin Async. Rising Edge Detect registers RW
	uint32_t GPAREN[2];

	uint32_t reserved10;
	//RESERVED32;

	// GPIO Pin Async. Falling Edge Detect registers RW
	uint32_t GPAFEN[2];

	uint32_t reserved11;
	//RESERVED32;

	// GPIO Pin Pull-up/down Enable RW
	uint32_t GPPUD;
	// GPIO Pin Pull-up/down Enable Clock registers RW
	uint32_t GPPUDCLK[2];

	uint32_t reserved12;
	//RESERVED32;
	uint32_t reserved13;
	//RESERVED32;
}rpi0w_gpio_registers_t;



//Functions
void rpi0w_set_pin_behaviour(void *pininfo, void *result);
void rpi0w_set_pin_level(void *pininfo, void *result);

#endif /* RPI0W_H_ */
