/*
 * vl_stm32_api.c
 *
 *  Created on: 3 maj 2021
 *      Author: Piotr
 */
#include "vl_api_config.h"
#include "vl_stm32_api.h"



uint8_t VL_init_parameters(VL53L0X_Dev_t *dev, RangingConfig_e rangingConfig,VL53L0X_DeviceModes mode)
{
	int status;
	uint8_t VhvSettings;
	uint8_t PhaseCal;
	uint32_t refSpadCount;
	uint8_t isApertureSpads;
	FixPoint1616_t signalLimit = (FixPoint1616_t) (1 * 65536);
	FixPoint1616_t sigmaLimit = (FixPoint1616_t) (50 * 65536);
	uint32_t timingBudget = 33000;
	uint8_t preRangeVcselPeriod = 14;
	uint8_t finalRangeVcselPeriod = 10;

	status = VL53L0X_StaticInit(dev);
	if (status) {
		return status;
	}

	status = VL53L0X_PerformRefCalibration(dev, &VhvSettings,
			&PhaseCal);
	if (status) {
		return status;
	}



	status = VL53L0X_PerformRefSpadManagement(dev, &refSpadCount,
			&isApertureSpads);
	if (status) {
		return status;
	}

	status = VL53L0X_SetDeviceMode(dev, mode);
	if (status) {
		return status;
	}

	status = VL53L0X_SetLimitCheckEnable(dev,
	VL53L0X_CHECKENABLE_SIGMA_FINAL_RANGE, 1); // Enable Sigma limit
	if (status) {
		return status;
	}

	status = VL53L0X_SetLimitCheckEnable(dev,
	VL53L0X_CHECKENABLE_SIGNAL_RATE_FINAL_RANGE, 1); // Enable Signa limit
	if (status) {
		return status;
	}
	/* Ranging configuration */
	switch (rangingConfig) {
	case LONG_RANGE:
		signalLimit = (FixPoint1616_t) (0.1 * 65536);
		sigmaLimit = (FixPoint1616_t) (60 * 65536);
		timingBudget = 33000;
		preRangeVcselPeriod = 18;
		finalRangeVcselPeriod = 14;
		break;
	case HIGH_ACCURACY:
		signalLimit = (FixPoint1616_t) (0.25 * 65536);
		sigmaLimit = (FixPoint1616_t) (18 * 65536);
		timingBudget = 200000;
		preRangeVcselPeriod = 14;
		finalRangeVcselPeriod = 10;
		break;
	case HIGH_SPEED:
		signalLimit = (FixPoint1616_t) (1 * 65536);
		sigmaLimit = (FixPoint1616_t) (50 * 65536);
		timingBudget = 20000;
		preRangeVcselPeriod = 14;
		finalRangeVcselPeriod = 10;
		break;
	default:
		return status;
	}

	status = VL53L0X_SetLimitCheckValue(dev,
	VL53L0X_CHECKENABLE_SIGNAL_RATE_FINAL_RANGE, signalLimit);
	if (status) {
		return status;
	}

	status = VL53L0X_SetLimitCheckValue(dev,
	VL53L0X_CHECKENABLE_SIGMA_FINAL_RANGE, sigmaLimit);
	if (status) {
		return status;
	}

	status = VL53L0X_SetMeasurementTimingBudgetMicroSeconds(dev,
			timingBudget);
	if (status) {
		return status;
	}

	status = VL53L0X_SetVcselPulsePeriod(dev,
	VL53L0X_VCSEL_PERIOD_PRE_RANGE, preRangeVcselPeriod);
	if (status) {
		return status;
	}

	status = VL53L0X_SetVcselPulsePeriod(dev,
	VL53L0X_VCSEL_PERIOD_FINAL_RANGE, finalRangeVcselPeriod);
	if (status) {
		return status;
	}

	status = VL53L0X_PerformRefCalibration(dev, &VhvSettings,
			&PhaseCal);
	if (status) {
		return status;
	}
return 0;
}


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


/* Ustawienie adresu czujnika */
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


/* Inicjalizacja parametrów czujnika */
/*
uint8_t VL_init_parameters(VL53L0X_DEV *dev, RangingModeConfig rmConfig, VL53L0X_DeviceModes mode){
	return 0;
} */


/* Ustawienie trybu przerwań */
uint8_t VL_set_interrupt(VL53L0X_DEV dev, uint8_t state, VL53L0X_InterruptPolarity polarity)
{
	if(state) // jeśli włączone przerwania
	{
		return VL53L0X_SetGpioConfig(dev, 0, VL53L0X_DEVICEMODE_SINGLE_RANGING, VL53L0X_GPIOFUNCTIONALITY_NEW_MEASURE_READY, polarity);
	}else{  // jeśli wyłączone przerwania
		return VL53L0X_SetGpioConfig(dev, 0, VL53L0X_DEVICEMODE_SINGLE_RANGING, VL53L0X_GPIOFUNCTIONALITY_OFF, polarity);
}


/* Pobierz pomiar */
uint8_t VL_get_measurement(VL53L0X_DEV dev, int16_t* distance)
{
	VL53L0X_RangingMeasurementData_t measurement;
	uint8_t state=0;

	state |= VL53L0X_GetRangingMeasurementData(dev, &measurement);  //pomiar dystansu z czujnika
	state |= VL53L0X_ClearInterruptMask(dev, 0); // wyczyszczenie maski przerwań

	if(measurement.RangeMilliMeter > 2900) //max odległość do ściany w labiryncie: 16x18cm - długość robota + bufor bezpieczeństwa
	{
		*distance = -1; // ujemny dystans informuje o błędnym pomiarze
	} else {
		*distance = measurement.RangeMilliMeter;
	}
	return state;
}


/* Zatrzymaj pomiar */
uint8_t VL_stop_measurment(VL53L0X_DEV dev)
{
	return VL53L0X_StopMeasurement(dev);
}

