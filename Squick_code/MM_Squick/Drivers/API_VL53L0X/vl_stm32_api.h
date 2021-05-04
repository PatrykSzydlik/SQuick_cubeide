/*
 * vl_stm32_api.h
 *
 *  Created on: 3 maj 2021
 *      Author: Piotr
 */

#ifndef API_VL53L0X_VL_STM32_API_H_
#define API_VL53L0X_VL_STM32_API_H_

#include "vl53l0x_api.h"


/* Tryb pracy czujników */
typedef enum{
	HIGH_SPEED_MODE=0,
	HIGH_ACCURACY_MODE,
	LONG_RANGE_MODE,
}RangingModeConfig;



/* Pobierz pomiar */
uint8_t VL_get_measurement(VL53L0X_DEV dev, int16_t* distance);

/* Zatrzymaj pomiar */
uint8_t VL_stop_measurment(VL53L0X_DEV dev);

/* Ustawienie parametrów i trybu czujnika */
uint8_t VL_init_parameters(VL53L0X_DEV *dev, RangingModeConfig rmConfig, VL53L0X_DeviceModes mode);

/* Inicjacja czujnika z podanym adresem */
uint8_t VL_init_sensor_setAddres(VL53L0X_DEV dev, uint8_t addr);

/* Ustawienie czujnika w tryb restartu */
void VL_Reset(VL53L0X_DEV dev);

/* Ustawienie trybu przerwań */
uint8_t VL_set_interrupt(VL53L0X_DEV dev, uint8_t state, VL53L0X_InterruptPolarity polarity);



#endif /* API_VL53L0X_VL_STM32_API_H_ */
