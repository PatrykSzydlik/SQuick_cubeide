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
	HIGH_SPEED=0,
	HIGH_ACCURACY,
	LONG_RANGE,
}RangingModeConfig;



/* Pobierz pomiar */
uint8_t VL_get_measurement(VL53L0X_DEV dev, int16_t* distance);

/* Zatrzymaj pomiar */
uint8_t VL_stop_measurment(VL53L0X_DEV dev);

/* Ustawienie parametrów i trybu czujnika */
uint8_t VL_init_parameters(VL53L0X_Dev_t *dev, RangingModeConfig rangingConfig, VL53L0X_DeviceModes mode);

/* Inicjacja czujnika z podanym adresem */
uint8_t VL_init_sensor_setAddres(VL53L0X_DEV dev, uint8_t addr);

/* Ustawienie czujnika w tryb restartu */
void VL_Reset(VL53L0X_DEV dev);

/* Ustawienie trybu przerwań */
uint8_t VL_set_interrupt(VL53L0X_DEV dev, uint8_t state, VL53L0X_InterruptPolarity polarity);

/* Start measurement, don't wait for response */
uint8_t VL_start_measurement_non_blocking(VL53L0X_DEV dev);

/* Return 0 if there is new distance data. Return -1 if out of range */
uint8_t VL_get_measurement_if_ready(VL53L0X_DEV dev, int16_t* distance);

/* Block if out of range */
uint8_t VL_single_measurement_blocking(VL53L0X_DEV dev, int16_t* distance);

/* Enable addres initialization*/
void VL_Enable(uint8_t VL_Index);


#endif /* API_VL53L0X_VL_STM32_API_H_ */
