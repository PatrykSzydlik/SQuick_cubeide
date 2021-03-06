/*
 * VL53L0X.c
 *
 *  Created on: 14 maj 2021
 *      Author: Piotr
 */


#include "VL53L0X.h"




/* PATRYK USUNAL
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == VL_INT_L_Pin){  // left sensor
		VL_Data_Ready[0] = 1;
	}

	else if(GPIO_Pin == VL_INT_F_Pin){  // front sensor
		VL_Data_Ready[1] = 1;
	}

	else if(GPIO_Pin == VL_INT_R_Pin){  // right sensor
		VL_Data_Ready[2] = 1;
	}

} // L, F, R
*/


VL53L0X_Dev_t devs[VL_DEV_NUMBER];
VL_Sensor VL_List[VL_DEV_NUMBER];
vl_struct VLS;
VL53L0X_DEV vldev;
uint8_t VL_Data_Updated[3] = {0,0,0};
uint8_t VL_Data_Ready[3] = {0,0,0};

uint8_t VL_Init_All(I2C_HandleTypeDef * hi2c){
	uint8_t j = 0;

	//HAL_Delay(1000);

	for(j=0; j<VL_DEV_NUMBER; j++)  // 3
	{
		VL_List[j].Device = &devs[j];
		VL_List[j].Device->I2cDevAddr = VL_DEFAULT_ADDRESS;
		VL_List[j].Device->i2c_handle = hi2c;
		VL_List[j].ID = j;

		VLS.MEMORY[j] = -1;
		VLS.STATE[j] = -1;

		VL_Enable(j);
		VL_init_sensor_setAddres(VL_List[j].Device, (VL_DEFAULT_ADDRESS + j*2 + 2));
		HAL_Delay(50);
		VL_init_parameters(VL_List[j].Device, LONG_RANGE, VL53L0X_DEVICEMODE_CONTINUOUS_RANGING);
		HAL_Delay(50);
		VL_set_interrupt(VL_List[j].Device, 1, VL53L0X_INTERRUPTPOLARITY_LOW);
		HAL_Delay(50);
		VL_start_measurement_non_blocking(VL_List[j].Device);
		HAL_Delay(50);
	}

	HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, 1);
	VL_Enable(42);
	return 1;
}



void VL_Enable(uint8_t VL_Index){
    switch(VL_Index){
		case 0:
			HAL_GPIO_WritePin(VL_XSHUT_L_GPIO_Port, VL_XSHUT_L_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(VL_XSHUT_F_GPIO_Port, VL_XSHUT_F_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(VL_XSHUT_R_GPIO_Port, VL_XSHUT_R_Pin, GPIO_PIN_RESET);
				break;
		case 1:
			HAL_GPIO_WritePin(VL_XSHUT_L_GPIO_Port, VL_XSHUT_L_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(VL_XSHUT_F_GPIO_Port, VL_XSHUT_F_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(VL_XSHUT_R_GPIO_Port, VL_XSHUT_R_Pin, GPIO_PIN_RESET);
		    	break;
		case 2:
			HAL_GPIO_WritePin(VL_XSHUT_L_GPIO_Port, VL_XSHUT_L_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(VL_XSHUT_F_GPIO_Port, VL_XSHUT_F_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(VL_XSHUT_R_GPIO_Port, VL_XSHUT_R_Pin, GPIO_PIN_SET);
		    	break;
		case 42:
			HAL_GPIO_WritePin(VL_XSHUT_L_GPIO_Port, VL_XSHUT_L_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(VL_XSHUT_F_GPIO_Port, VL_XSHUT_F_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(VL_XSHUT_R_GPIO_Port, VL_XSHUT_R_Pin, GPIO_PIN_SET);
			break;
    }
    HAL_Delay(3);
}

uint8_t VL_Check()
{
	int j;

	for(j=0; j<VL_DEV_NUMBER; j++)
	{
		if(VL_Data_Ready[j])
		{
			VL_Data_Ready[j] = 0;
			VL_get_measurement(VL_List[j].Device, &VLS.STATE[j]);
			HAL_Delay(35);
			VL_Data_Updated[j] = 1;
		}
	}


	if(VLS.STATE[0]>0 || VLS.STATE[1]>0 || VLS.STATE[2]>0)
	{
		for(j=0; j<VL_DEV_NUMBER; j++)
		{
			if(VLS.MEMORY[j] != VLS.MEMORY_OLD[j]){
				VLS.MEMORY_OLD[j] = VLS.MEMORY[j];
			};
			VLS.MEMORY[j] = VLS.STATE[j];

		}
	}

	int8_t Temp = VLS.TARGET_DIR;
	VLS.TARGET_DIR = VLS.MEMORY[0]*(-4) + VLS.MEMORY[1]*(-1) + VLS.MEMORY[2]*(-2);

	if(VLS.TARGET_DIR != Temp)
		VLS.TARGET_DIR_OLD = Temp;

	return 0;
}

void f_SH_ClearMemory(int16_t* MEM)
{
	uint8_t i = 0;
	for (i=0; i<VL_DEV_NUMBER; i++)
	{
		MEM[i] = -1;
	}
}



      /*___________________*
       *                   *
       * WALLS IN CURRENT  *
       *       FIELD       *
       *___________________*/

/* NO WALLS */
uint8_t sNone(int16_t* MEM)
{	if(MEM[0]==-1 && MEM[1]==-1 && MEM[2]==-1)
		{	return 1;	}
	return 0;

}

/* 1 WALL */
uint8_t sLeft(int16_t* MEM)
{	if(MEM[0]>=0 && MEM[1]==-1 && MEM[2]==-1)
		{	return 1;	}
	return 0;
}

uint8_t sFront(int16_t* MEM)
{	if(MEM[0]==-1 && MEM[1]>=0 && MEM[2]==-1)
		{	return 1;	}
	return 0;
}

uint8_t sRight(int16_t* MEM)
{	if(MEM[0]==-1 && MEM[1]==-1 && MEM[2]>=0)
		{	return 1;	}
	return 0;
}


/* 2 WALLS */
uint8_t sLeft_sFront(int16_t* MEM)
{	if(MEM[0]>=0 && MEM[1]>=0 && MEM[2]==-1)
		{	return 1;	}
	return 0;
}


uint8_t sRight_sFront(int16_t* MEM)
{	if(MEM[0]==-1 && MEM[1]>=0 && MEM[2]>=0)
		{	return 1;	}
	return 0;
}


uint8_t sLeft_sRight(int16_t* MEM)
{	if(MEM[0]>=0 && MEM[1]==-1 && MEM[2]>=0)
		{	return 1;	}
	return 0;
}

/* 3 WALLS */
uint8_t sLeft_sFront_sRight(int16_t* MEM)
{	if(MEM[0]>=0 && MEM[1]>=0 && MEM[2]>=0)
		{	return 1;	}
	return 0;
}
