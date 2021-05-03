/*
 * vl_stm32_api.c
 *
 *  Created on: 3 maj 2021
 *      Author: Piotr
 */
#include "vl_api_config.h"
#icnlude "vl_stm32_api.h"


uint8_t VL_set_interrupt(VL53L0X_DEV dev, uint8_t state, VL53L0X_InterruptPolarity polarity)
{
	if(state) // 0 - wyłączone przerwania / 1 - włączone przerwania
	{
		return VL53L0X_SetGpioConfig(dev, 0, VL53L0X_DEVICEMODE_SINGLE_RANGING, VL53L0X_GPIOFUNCTIONALITY_NEW_MEASURE_READY, polarity);
	} else {
		return VL53L0X_SetGpioConfig(dev, 0, VL53L0X_DEVICEMODE_SINGLE_RANGING, VL53L0X_GPIOFUNCTIONALITY_OFF, polarity);
	}
}



/* Brutalny reset czujnika */
void VL_Reset(VL53L0X_DEV dev)
{
	HAL_GPIO_WritePin(dev->GPIOx_reset, dev->GPIO_PIN_RESET, DISABLE);
}



uint8_t VL_init_sensor_setAddres(VL53L0X_DEV dev, uint8_t addr)
{
	uint8_t status=0;
	vl_api_delay(100);

	status |= VL53L0X_DataInit(dev);
	status |= VL53L0X_SetDeviceAddress(dev, addr);

	if(status){return status;}

	dev->I2cDevAddr = addr;
	return status;
}



uint8_t VL_init_parameters(VL53L0X_DEV *dev, RangingModeConfig rmConfig, VL53L0X_DeviceModes mode){
	return 0;
}

