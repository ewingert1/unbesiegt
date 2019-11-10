/*
 * Rpi0W.c
 *
 *  Created on: 9 nov. 2019
 *      Author: Emilien
 */

#include "rpi0w/rpi0w_gpio.h"

//#define SET_GPIO_PIN_IN(GPIO_N) (gpio_add[GPIO_N/10] &= ~(0b111<<(3*(GPIO_N%10))))
//#define SET_GPIO_PIN_OUT(GPIO_N) (gpio_add[GPIO_N/10] = (gpio_add[GPIO_N/10] & ~(0b111<<(3*(GPIO_N%10)))) | (1<<(3*(GPIO_N%10))))
//
//#define SET_GPIO_PIN_ASYNC_RISING_EDGE(GPIO_N) (gpio_add[0x7C/4 + (GPIO_N/32)] |= (1<<(GPIO_N%32)))
//#define SET_GPIO_PIN_SYNC_RISING_EDGE(GPIO_N) (gpio_add[0x4C/4 + (GPIO_N/32)] |= (1<<(GPIO_N%32)))
//#define SET_GPIO_PIN_ASYNC_FALLING_EDGE(GPIO_N) (gpio_add[0x88/4 + (GPIO_N/32)] |= (1<<(GPIO_N%32)))
//#define SET_GPIO_PIN_SYNC_FALLING_EDGE(GPIO_N) (gpio_add[0x58/4 + (GPIO_N/32)] |= (1<<(GPIO_N%32)))
//
//#define SET_GPIO_PIN_HIGH(GPIO_N) {gpio_add[0x1C/4+(GPIO_N/32)] = (1 << (GPIO_N%32) );}
////#define SET_GPIO_PIN_HIGH(GPIO_N) {gpio_add[0x1C/4+(GPIO_N/32)] |= (1 << (GPIO_N%32) );}
//
////#define SET_GPIO_PIN_LOW(GPIO_N) {	gpio_add[0x1C/4+(GPIO_N/32)] &= ~(1 << (GPIO_N%32) );}
//#define SET_GPIO_PIN_LOW(GPIO_N) {gpio_add[0x28/4+(GPIO_N/32)] = (1 << (GPIO_N%32) );}
//
//#define PIN_HAS_EVENT(GPIO_N) 		(((gpio_add[0x40/4 + (GPIO_N/32)])&(1<<(GPIO_N%32))) == (1<<(GPIO_N%32)))



//static rpi0w_gpio_registers_t* gpio_regs = (rpi0w_gpio_registers_t*)BASE_ADDRESS_GPIO;


//void initInterrupt()
//{
//	//Enable IRQ49, IRQ50, IRQ51, IRQ52
//	*((uint32_t*)Enable_IRQs2_Reg_Address) |= (0xF << 17);
//}

void rpi0w_set_pin_behaviour(void *pininfo, void *result){
	rpi0w_gpio_registers_t* gpio_regs = (rpi0w_gpio_registers_t*)BASE_ADDRESS_GPIO;
	pin_info_t *pin_info = (pin_info_t*)pininfo;
	gpio_regs->GPFSEL[pin_info->pin_number/10] &= ~(0b111<<(3*(pin_info->pin_number%10)));

	if(pin_info->pin_behaviour == RPI0W_GPIO_OUTPUT)
		gpio_regs->GPFSEL[pin_info->pin_number/10] |= pin_info->pin_behaviour<<(3*(pin_info->pin_number%10));
}


void rpi0w_set_pin_level(void *pininfo, void *result)
{
	rpi0w_gpio_registers_t* gpio_regs = (rpi0w_gpio_registers_t*)BASE_ADDRESS_GPIO;
	pin_info_t *pin_info = (pin_info_t*)pininfo;

	if(pin_info->pin_level == GPIO_HIGH){
		gpio_regs->GPSET[pin_info->pin_number/32] = (1 << (pin_info->pin_number%32) );
	}
	else{
		gpio_regs->GPCLR[pin_info->pin_number/32] = (1 << (pin_info->pin_number%32) );
	}
}

//void set_pin_pull_Res(unsigned int gpio_n , unsigned int Up_Down)
//{
//	//First we need to get the value of the GPPUD register, in which we will choose whether we want a pull up or a pull down
//	    unsigned int offsetGPPUD = 0x94/4;
//
//
//	    // So in this register we know that the only first bits are used to set Pull up / pull down / disable
//	    // The combination are :
//	    //      - 00 to disable
//	    //      - 01 to enable pull down
//	    //      - 10 to enable pull up
//	    // So first we need to clear the first 2 bits
//	    // We'll clear the first 2 bits by applying a 0xFFFFFFFC mask to the register
//	    unsigned int mask = 0xFFFFFFFC;
//
//	    // Now we have our clear mask ready
//	    // We just have to fetch the value of the register, clear the first 2 bits, then replace them with the ones that are passed via the argument pull
//	    // The pull type contains PULL_UP and PULL_DOWN as enumerated values
//	    // PULL_UP and PULL_DOWN have been purposely attributed to the integers 2 and 1, because in order to set a pull down, we write 0b01 (1) in the 2 bits
//	    // And in order to set a pull up, we write 10 (2) in the 2 bits
//
//	    //unsigned int value = gpio_add[offsetGPPUD];
//	    //value = (value&mask)|Up_Down;
//	    //gpio_add[offsetGPPUD] = value;
//
//	    gpio_add[0x94/4] &= 0xFFFFFFFC;
//	    gpio_add[0x94/4] |= (uint32_t) Up_Down;
//
//	    // So now we set that the GPIO pin will be a pull up.
//	    // We now must to wait 150 cycles, as the official method says we do.
//	    // This amount of time "provides the required time for the control signal" (BCM2835 PERIPHERALS)
//
//	    // So basically, we'll just have a variable to count to 200 to ensure the 150 cycles are respected
//	    // Let's just hope the branch predictions won't allow the code to end with less cycles
//
//	    unsigned int wait = 0;
//	    for(wait=0;wait<200;wait++);
//
//	    // We now have to choose the right pin in the GPIOPullUpDownClockRegister (GPPUDCLKn) which is located at the offset 0x98 + RegisterToUse
//	    unsigned int offsetGPPUDCLK = 0x98/4;
//	    unsigned int RegisterToUse = gpio_n/(unsigned int)32; //We divide by 32 because a GPPIDCLK register 1 bit per pin to set
////	    value = gpio_add[offsetGPPUDCLK+RegisterToUse];
////	    value = value|(1<<gpio_n%32);
//	    gpio_add[0x98/4+(gpio_n/32)] |= (1<<(gpio_n%32));
////	    gpio_add[offsetGPPUDCLK+RegisterToUse]=value;
//
//	    //Second wait cycle
//	    for(wait=0;wait<200;wait++);
//
//	    //Now we must reset the registers we just used
//	    gpio_add[offsetGPPUDCLK+(gpio_n/32)] &= (~(1<<(gpio_n%32)));//We clear the bit of the pin
//	    gpio_add[offsetGPPUD] = gpio_add[offsetGPPUD]&mask;
//}

