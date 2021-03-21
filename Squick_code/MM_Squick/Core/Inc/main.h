/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define PT_A_Pin GPIO_PIN_13
#define PT_A_GPIO_Port GPIOC
#define PT_B_Pin GPIO_PIN_14
#define PT_B_GPIO_Port GPIOC
#define PT_C_Pin GPIO_PIN_15
#define PT_C_GPIO_Port GPIOC
#define BUT_1_Pin GPIO_PIN_1
#define BUT_1_GPIO_Port GPIOH
#define VL_INT_R_Pin GPIO_PIN_0
#define VL_INT_R_GPIO_Port GPIOC
#define VL_INT_F_Pin GPIO_PIN_1
#define VL_INT_F_GPIO_Port GPIOC
#define VL_INT_L_Pin GPIO_PIN_2
#define VL_INT_L_GPIO_Port GPIOC
#define VL_XSHUT_Pin GPIO_PIN_3
#define VL_XSHUT_GPIO_Port GPIOC
#define V_batt_Pin GPIO_PIN_0
#define V_batt_GPIO_Port GPIOA
#define KTIR_1_Pin GPIO_PIN_1
#define KTIR_1_GPIO_Port GPIOA
#define KTIR_2_Pin GPIO_PIN_2
#define KTIR_2_GPIO_Port GPIOA
#define KTIR_3_Pin GPIO_PIN_3
#define KTIR_3_GPIO_Port GPIOA
#define KTIR_4_Pin GPIO_PIN_4
#define KTIR_4_GPIO_Port GPIOA
#define PT_MEAS_Pin GPIO_PIN_5
#define PT_MEAS_GPIO_Port GPIOA
#define LED_3_Pin GPIO_PIN_1
#define LED_3_GPIO_Port GPIOB
#define LED_2_Pin GPIO_PIN_2
#define LED_2_GPIO_Port GPIOB
#define LED_1_Pin GPIO_PIN_10
#define LED_1_GPIO_Port GPIOB
#define IR_C_Pin GPIO_PIN_13
#define IR_C_GPIO_Port GPIOB
#define IR_B_Pin GPIO_PIN_14
#define IR_B_GPIO_Port GPIOB
#define IR_A_Pin GPIO_PIN_15
#define IR_A_GPIO_Port GPIOB
#define TX_TO_DEBUG_Pin GPIO_PIN_6
#define TX_TO_DEBUG_GPIO_Port GPIOC
#define RX_FROM_DEBUG_Pin GPIO_PIN_7
#define RX_FROM_DEBUG_GPIO_Port GPIOC
#define L_IN1_Pin GPIO_PIN_8
#define L_IN1_GPIO_Port GPIOC
#define L_IN2_Pin GPIO_PIN_9
#define L_IN2_GPIO_Port GPIOC
#define PWM_L_Pin GPIO_PIN_8
#define PWM_L_GPIO_Port GPIOA
#define PWM_R_Pin GPIO_PIN_9
#define PWM_R_GPIO_Port GPIOA
#define R_IN2_Pin GPIO_PIN_10
#define R_IN2_GPIO_Port GPIOA
#define R_IN1_Pin GPIO_PIN_11
#define R_IN1_GPIO_Port GPIOA
#define BUT_2_Pin GPIO_PIN_12
#define BUT_2_GPIO_Port GPIOA
#define SYS_SWDIO_Pin GPIO_PIN_13
#define SYS_SWDIO_GPIO_Port GPIOA
#define SYS_SWCLK_Pin GPIO_PIN_14
#define SYS_SWCLK_GPIO_Port GPIOA
#define BT_EN_Pin GPIO_PIN_10
#define BT_EN_GPIO_Port GPIOC
#define BT_State_Pin GPIO_PIN_11
#define BT_State_GPIO_Port GPIOC
#define IMU_CS_Pin GPIO_PIN_12
#define IMU_CS_GPIO_Port GPIOC
#define IMU_INT_Pin GPIO_PIN_2
#define IMU_INT_GPIO_Port GPIOD
#define SCK_Pin GPIO_PIN_3
#define SCK_GPIO_Port GPIOB
#define MISO_Pin GPIO_PIN_4
#define MISO_GPIO_Port GPIOB
#define MOSI_Pin GPIO_PIN_5
#define MOSI_GPIO_Port GPIOB
#define TX_TO_BT_Pin GPIO_PIN_6
#define TX_TO_BT_GPIO_Port GPIOB
#define RX_FROM_BT_Pin GPIO_PIN_7
#define RX_FROM_BT_GPIO_Port GPIOB
#define SCL_Pin GPIO_PIN_8
#define SCL_GPIO_Port GPIOB
#define SDA_Pin GPIO_PIN_9
#define SDA_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
