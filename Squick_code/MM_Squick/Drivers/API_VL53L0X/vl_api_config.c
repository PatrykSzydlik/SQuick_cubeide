/*
 * vl_api_config.c
 *
 *  Created on: 3 maj 2021
 *      Author: Piotr
 */

#include <vl_api_config.h>

/* Odczekanie czasu w ms */
void vl_api_delay(uint16_t time_ms){
	HAL_Delay(time_ms); // to można czymś zastąpić
}
