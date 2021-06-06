/*
 * VL53L0X.h
 *
 *  Created on: 14 maj 2021
 *      Author: Piotr
 */

#ifndef INC_VL53L0X_H_
#define INC_VL53L0X_H_


#include "vl_stm32_api.h"
#include "main.h"
//#include "gpio.h"
#include "i2c.h"

#define VL_DEFAULT_ADDRESS 0x52
#define VL_DEV_NUMBER 3



typedef struct
{
	VL53L0X_DEV Device;
	uint8_t ID;
} VL_Sensor;

extern VL_Sensor VL_List[];
extern uint8_t VL_Data_Updated[];

typedef struct
{
	int16_t STATE[3];
	int16_t MEMORY[3];
	int16_t MEMORY_OLD[3];
	int8_t TARGET_DIR;
	int8_t TARGET_DIR_OLD;
} vl_struct;

extern vl_struct VLS;
extern uint8_t VL_Data_Ready[3];
extern uint8_t VL_Data_Updated[3];

uint8_t VL_Init_All();
uint8_t VL_Check();

void VL_ClearMemory(int16_t* MEM);


uint8_t sLeft(int16_t* MEM);
uint8_t sRight(int16_t* MEM);
uint8_t sFront(int16_t* MEM);

uint8_t sLeft_sRight(int16_t* MEM);
uint8_t sLeft_sFront(int16_t* MEM);
uint8_t sRight_sFront(int16_t* MEM);

uint8_t sNone(int16_t* MEM); // crossroads
uint8_t sLeft_sFront_sRight(int16_t* MEM);  // blind alley


#endif /* INC_VL53L0X_H_ */
