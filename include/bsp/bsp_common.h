/*
 * bsp_common.h
 *
 *  Created on: 9 nov. 2019
 *      Author: Emilien
 */

#ifndef BSP_COMMON_H_
#define BSP_COMMON_H_

#include <stdint.h>

#define RESERVED32 uint32_t :32

// COMMON MACROS
#define GPIO_HIGH 			1
#define GPIO_LOW 			0

typedef struct pin_info{
	uint32_t pin_port;
	uint32_t pin_number;
	uint32_t pin_behaviour;
	uint32_t pin_level;
	uint32_t pin_edge;
	uint32_t pin_pull;
} pin_info_t;

#endif /* BSP_COMMON_H_ */
