
#include "GPIO_Driver.h"


// #define SET_GPIO_PIN_IN(GPIO_N) (gpio_add[GPIO_N/10] &= ~(0b111<<(3*(GPIO_N%10))))
// #define SET_GPIO_PIN_OUT(GPIO_N) (gpio_add[GPIO_N/10] = (gpio_add[GPIO_N/10] & ~(0b111<<(3*(GPIO_N%10)))) | (1<<(3*(GPIO_N%10))))
//
// #define SET_GPIO_PIN_HIGH(GPIO_N) {gpio_add[0x1C/4+(GPIO_N/32)] = (1 << (GPIO_N%32) );}
// #define SET_GPIO_PIN_LOW(GPIO_N) {gpio_add[0x28/4+(GPIO_N/32)] = (1 << (GPIO_N%32) );}
//
// #define GPIO_ADDRESS 0x20200000
// volatile uint32_t* gpio_add =  (uint32_t*)GPIO_ADDRESS;


int  notmain()
{

	// SET_GPIO_PIN_OUT(26);
	// SET_GPIO_PIN_HIGH(26);
//	gpio_driver_t *gpio_drv = create_gpio_driver();
	pin_info_t info;
	info.pin_number = 26;
	info.pin_behaviour = GPIO_OUTPUT;
	info.pin_level = GPIO_HIGH;
//	gpio_drv->set_pin_behaviour(&info, NULL);
//	gpio_drv->set_pin_level(&info, NULL);
	rpi0w_set_pin_behaviour(&info,NULL);
	rpi0w_set_pin_level(&info,NULL);
	while(1);
	return 1;
}
