
#include "GPIO_Driver.h"


int  notmain()
{
//	gpio_driver_t *gpio_drv = create_gpio_driver();
	pin_info_t info;
	info.pin_number = 21;
	info.pin_behaviour = GPIO_OUTPUT;
	info.pin_level = GPIO_HIGH;
//	gpio_drv->set_pin_behaviour(&info, NULL);
//	gpio_drv->set_pin_level(&info, NULL);
	rpi0w_set_pin_behaviour(&info,NULL);
	rpi0w_set_pin_level(&info,NULL);
	while(1);
	return 1;
}
