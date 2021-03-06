/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "pid.h"
#include "VL53L0X.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
struct encoder{
	int curr_speed; // mm/s *10
	int absolute_pos; // mm *10
};
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define MOTOR_MAX 9999
#define ENC_ZERO 32768
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;
DMA_HandleTypeDef hdma_adc1;

I2C_HandleTypeDef hi2c1;

SPI_HandleTypeDef hspi1;

TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim10;
TIM_HandleTypeDef htim11;

UART_HandleTypeDef huart1;
UART_HandleTypeDef huart6;

/* USER CODE BEGIN PV */
int pwm_value=0;
volatile struct encoder ENC_L, ENC_P;

int rozpocznij_pomiar=0;
int prog=0;
uint32_t pomiar[10];

int debug=0;

uint16_t predkosc_zadana = 0;
uint16_t zasilanie=0;

uint8_t bt_data;
uint8_t bt_settings[14];
int transmission_request=0;

uint8_t direction=0;
volatile uint8_t rx_flag=0;
volatile uint8_t vl_flag=0;
volatile uint8_t timer_flag=0;
volatile uint8_t adc_flag=0;
volatile short speed_mm=0;
volatile uint8_t option=0;
volatile uint8_t initialization_encoders=0;
volatile uint8_t direction_set[2]={0,0};
volatile short kp=0,ki=0,kd=0;
cpid_t pid_L, pid_P;

vl_struct VLS;
VL53L0X_DEV dev;

volatile uint16_t adc_measurements[6];

int16_t VLdistanceL=0;
int16_t VLdistanceF=0;
int16_t VLdistanceR=0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_I2C1_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_USART6_UART_Init(void);
static void MX_TIM1_Init(void);
static void MX_ADC1_Init(void);
static void MX_SPI1_Init(void);
static void MX_TIM2_Init(void);
static void MX_TIM3_Init(void);
static void MX_TIM10_Init(void);
static void MX_TIM11_Init(void);
/* USER CODE BEGIN PFP */
int _write(int file, uint8_t *ptr, int len){
	HAL_UART_Transmit(&huart1, ptr, len, 100);
	return  len;
};

int abs(int zmienna) {
	if (zmienna < 0) {
		zmienna = -zmienna;
	};
	return zmienna;
}


void read_encoders(){
	printf("LEFT  :  POS[mm] : %d     VEL[mm/s] : %d  \r\n", ENC_L.absolute_pos/10, ENC_L.curr_speed/10);
	printf("RIGHT :  POS[mm] : %d     VEL[mm/s] : %d  \r\n", ENC_P.absolute_pos/10, ENC_P.curr_speed/10);
}



void get_encoder_pos(){
	int diff=0;
	int pos_L=0, pos_P=0;
	pos_L = htim2.Instance->CNT;
	pos_P = htim3.Instance->CNT;
	htim2.Instance->CNT = ENC_ZERO;
	htim3.Instance->CNT = ENC_ZERO;


	diff = pos_L - ENC_ZERO;
	diff = diff*170/51;
	ENC_L.absolute_pos -= diff;
	ENC_L.curr_speed = - diff*463/10;

	diff = pos_P - ENC_ZERO;
	diff = diff*170/51;
	ENC_P.absolute_pos += diff;
	ENC_P.curr_speed = diff*463/10;
}




void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){

	transmission_request=0;
	bt_data=0;
	//HAL_UART_Receive_IT(&huart1, &bt_data, 1);

}

void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart){
	__NOP();
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){


	if(huart->Instance==USART1){
//		if(transmission_request==100){ 					// SET PARAMETERS
//			data_decrypt();
//			transmission_request=0;
//			bt_data=0;
//			HAL_UART_Receive_IT(&huart1, &bt_data, 1);
//		}else{											// UNRECOGNIZED OR ZERO
//			transmission_request=bt_data;
//			if(bt_data==100){
//				HAL_UART_Receive_IT(&huart1, bt_settings, 14);
//			}else if(bt_data==101){
//				data_encrypt();
//				HAL_UART_Transmit_IT(&huart1, bt_settings, 14);
//			}else{
//				HAL_UART_Receive_IT(&huart1, &bt_data, 1);
//			};
//		};
		rx_flag=1;
		if(bt_data=='w'){
			direction='w';
		}
		if(bt_data=='s'){
			direction='s';
		}
		if(bt_data=='a'){
			direction='a';
		}
		if(bt_data=='d'){
			direction='d';
		}
		if(bt_data=='p'){
			option='p';
		}
		if(bt_data==']'){
			option=']';
		}
		if(bt_data=='r'){
			option='r';
		}
		if(bt_data=='z'){
			option='z';
		}
		if(bt_data=='g'){
			option='g';
		}
		if(bt_data=='k'){
			option='k';
		}
		if(bt_data=='0'){
			speed_mm=0;
		}
		if(bt_data=='1'){
			speed_mm=100;
		}
		if(bt_data=='2'){
			speed_mm=200;
		}
		if(bt_data=='3'){
			speed_mm=300;
		}
		if(bt_data=='4'){
			speed_mm=400;
		}
		if(bt_data=='5'){
			speed_mm=500;
		}
		if(bt_data=='6'){
			speed_mm=600;
		}
		if(bt_data=='7'){
			speed_mm=700;
		}
		if(bt_data=='8'){
			speed_mm=800;
		}
		if(bt_data=='9'){
			speed_mm=900;
		}
		if(bt_data=='c'){
			option='Q';
			kp++;
		}
		if(bt_data=='v'){
			option='Q';
			kp--;
		}
		if(bt_data=='b'){
			option='Q';
			ki++;
		}
		if(bt_data=='n'){
			option='Q';
			ki--;
		}
		if(bt_data=='m'){
			option='Q';
			kd++;
		}
		if(bt_data==','){
			option='Q';
			kd--;
		}
		if(bt_data=='='){
			option='=';
		}
		HAL_UART_Receive_IT(&huart1, &bt_data, 1);
	};

}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim->Instance==TIM10){
		get_encoder_pos();
		if(initialization_encoders==0){
			initialization_encoders=1;
			ENC_P.absolute_pos=0;
			ENC_L.absolute_pos=0;

		}
		timer_flag=1;
	}
	if(htim->Instance==TIM11){
		adc_flag=1;
	}
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	if(GPIO_Pin==BUT_2_Pin){
		HAL_GPIO_TogglePin(LED_2_GPIO_Port, LED_2_Pin);
		pwm_value-=50;
		printf("Kliknieto BUT_2  PWM = %d \r\n", pwm_value);
	}
	if(GPIO_Pin == VL_INT_L_Pin){  // left sensor
		printf("LEWY READY \r\n");
		VL_Data_Ready[0] = 1;
		vl_flag=1;
	}
	if(GPIO_Pin == VL_INT_F_Pin){  // front sensor
		printf("FRONT READY \r\n");
		VL_Data_Ready[1] = 1;
		vl_flag=1;
	}
	if(GPIO_Pin == VL_INT_R_Pin){  // right sensor
		printf("PRAWY READY \r\n");
		VL_Data_Ready[2] = 1;
		vl_flag=1;
	}
}



void PWM(int lewy, int prawy) {
	if (lewy >= 0) {
		if (lewy > MOTOR_MAX) {
			lewy = MOTOR_MAX;
		};
		if(direction_set[0]!=1){
			HAL_GPIO_WritePin(L_IN1_GPIO_Port, L_IN1_Pin, 1);
			HAL_GPIO_WritePin(L_IN2_GPIO_Port, L_IN2_Pin, 0);
			direction_set[0]=1;
		}
	} else if (lewy < 0) {
		if (lewy < -MOTOR_MAX) {
			lewy = -MOTOR_MAX;
		};
		if(direction_set[0]!=2){
			HAL_GPIO_WritePin(L_IN1_GPIO_Port, L_IN1_Pin, 0);
			HAL_GPIO_WritePin(L_IN2_GPIO_Port, L_IN2_Pin, 1);
			direction_set[0]=2;
		}

	};

	if (prawy >= 0) {
		if (prawy > MOTOR_MAX) {
			prawy = MOTOR_MAX;
		};
		if(direction_set[1]!=1){
			HAL_GPIO_WritePin(R_IN1_GPIO_Port, R_IN1_Pin, 0);
			HAL_GPIO_WritePin(R_IN2_GPIO_Port, R_IN2_Pin, 1);
			direction_set[1]=1;
		}
	} else if (prawy < 0) {
		if (prawy < -MOTOR_MAX) {
			prawy = -MOTOR_MAX;
		};
		if(direction_set[1]!=2){
			HAL_GPIO_WritePin(R_IN1_GPIO_Port, R_IN1_Pin, 1);
			HAL_GPIO_WritePin(R_IN2_GPIO_Port, R_IN2_Pin, 0);
			direction_set[1]=2;
		}
	};

	if(prawy==0 && lewy==0){
		direction_set[1]=0;
		direction_set[0]=0;
		HAL_GPIO_WritePin(R_IN1_GPIO_Port, R_IN1_Pin, 1);
		HAL_GPIO_WritePin(R_IN2_GPIO_Port, R_IN2_Pin, 1);
		HAL_GPIO_WritePin(L_IN1_GPIO_Port, L_IN1_Pin, 1);
		HAL_GPIO_WritePin(L_IN2_GPIO_Port, L_IN2_Pin, 1);

	}
	__HAL_TIM_SET_COMPARE(&htim1 , TIM_CHANNEL_1, abs(lewy));
	__HAL_TIM_SET_COMPARE(&htim1 , TIM_CHANNEL_2, abs(prawy));
}


void pos_and_speed_measurement(){
	PWM(speed_mm*10, speed_mm*10);
	for(int i=0; i<10; i++){
		HAL_Delay(100);
		read_encoders();
	}
	PWM(0,0);


}

void initialize_PID(short k_p, short k_i, short k_d){
	  //Regulator zosta?? nastrojony przy pomocy metody r??cznej
	  // Najpierw zmieniaj??c Kp a?? do wyst??pienia oscylacji i wybra?? polowe wartosci
	  // Potem ustalaj??c Ki az do skrocenia czasu regulacji
	  // Na koncu regulacja Kd

	  pid_init(&pid_L, kp*0.1f, ki*0.01f, kd*0.01f, 4, 40);  // 10ms ze wzgledu na 25Hz
	  pid_L.p_max = pid_scale(&pid_L, MOTOR_MAX);
	  pid_L.p_min = pid_scale(&pid_L, -MOTOR_MAX);
	  pid_L.i_max = pid_scale(&pid_L, MOTOR_MAX);
	  pid_L.i_min = pid_scale(&pid_L, -MOTOR_MAX);
	  pid_L.d_max = pid_scale(&pid_L, MOTOR_MAX);
	  pid_L.d_min = pid_scale(&pid_L, -MOTOR_MAX);
	  pid_L.total_max = pid_scale(&pid_L, MOTOR_MAX);
	  pid_L.total_min = pid_scale(&pid_L, -MOTOR_MAX);

	  //Regulator zosta?? nastrojony przy pomocy metody r??cznej
	  // Najpierw zmieniaj??c Kp a?? do wyst??pienia oscylacji i wybra?? polowe wartosci
	  // Potem ustalaj??c Ki az do skrocenia czasu regulacji
	  // Na koncu regulacja Kd
	  pid_init(&pid_P, kp*0.1f, ki*0.01f, kd*0.01f, 4, 40);  // 40ms ze wzgledu na 25Hz
	  pid_P.p_max = pid_scale(&pid_P, MOTOR_MAX);
	  pid_P.p_min = pid_scale(&pid_P, -MOTOR_MAX);
	  pid_P.i_max = pid_scale(&pid_P, MOTOR_MAX);
	  pid_P.i_min = pid_scale(&pid_P, -MOTOR_MAX);
	  pid_P.d_max = pid_scale(&pid_P, MOTOR_MAX);
	  pid_P.d_min = pid_scale(&pid_P, -MOTOR_MAX);
	  pid_P.total_max = pid_scale(&pid_P, MOTOR_MAX);
	  pid_P.total_min = pid_scale(&pid_P, -MOTOR_MAX);
}

void PT_change_sensor(uint8_t sensor){
	if(sensor==0){
		HAL_GPIO_WritePin(PT_A_GPIO_Port, PT_A_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(PT_B_GPIO_Port, PT_B_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(PT_C_GPIO_Port, PT_C_Pin, GPIO_PIN_RESET);
	}
	else if(sensor==1){
		HAL_GPIO_WritePin(PT_A_GPIO_Port, PT_A_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(PT_B_GPIO_Port, PT_B_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(PT_C_GPIO_Port, PT_C_Pin, GPIO_PIN_RESET);
	}
	else if(sensor==2){
		HAL_GPIO_WritePin(PT_A_GPIO_Port, PT_A_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(PT_B_GPIO_Port, PT_B_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(PT_C_GPIO_Port, PT_C_Pin, GPIO_PIN_RESET);
	}
	else if(sensor==3){
		HAL_GPIO_WritePin(PT_A_GPIO_Port, PT_A_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(PT_B_GPIO_Port, PT_B_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(PT_C_GPIO_Port, PT_C_Pin, GPIO_PIN_RESET);
	}
	else if(sensor==4){
		HAL_GPIO_WritePin(PT_A_GPIO_Port, PT_A_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(PT_B_GPIO_Port, PT_B_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(PT_C_GPIO_Port, PT_C_Pin, GPIO_PIN_RESET);
	}
	else if(sensor==5){
		HAL_GPIO_WritePin(PT_A_GPIO_Port, PT_A_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(PT_B_GPIO_Port, PT_B_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(PT_C_GPIO_Port, PT_C_Pin, GPIO_PIN_SET);
	}
	else{
		HAL_GPIO_WritePin(PT_A_GPIO_Port, PT_A_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(PT_B_GPIO_Port, PT_B_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(PT_C_GPIO_Port, PT_C_Pin, GPIO_PIN_SET);
	}
}

void IR_set(uint8_t diode){
	if(diode==0){
		HAL_GPIO_WritePin(IR_A_GPIO_Port, IR_A_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(IR_B_GPIO_Port, IR_B_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(IR_C_GPIO_Port, IR_C_Pin, GPIO_PIN_RESET);
	}
	else if(diode==1){
		HAL_GPIO_WritePin(IR_A_GPIO_Port, IR_A_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(IR_B_GPIO_Port, IR_B_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(IR_C_GPIO_Port, IR_C_Pin, GPIO_PIN_RESET);
	}
	else if(diode==2){
		HAL_GPIO_WritePin(IR_A_GPIO_Port, IR_A_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(IR_B_GPIO_Port, IR_B_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(IR_C_GPIO_Port, IR_C_Pin, GPIO_PIN_RESET);
	}
	else if(diode==3){
		HAL_GPIO_WritePin(IR_A_GPIO_Port, IR_A_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(IR_B_GPIO_Port, IR_B_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(IR_C_GPIO_Port, IR_C_Pin, GPIO_PIN_RESET);
	}
	else if(diode==4){
		HAL_GPIO_WritePin(IR_A_GPIO_Port, IR_A_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(IR_B_GPIO_Port, IR_B_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(IR_C_GPIO_Port, IR_C_Pin, GPIO_PIN_RESET);
	}
	else if(diode==5){
		HAL_GPIO_WritePin(IR_A_GPIO_Port, IR_A_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(IR_B_GPIO_Port, IR_B_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(IR_C_GPIO_Port, IR_C_Pin, GPIO_PIN_SET);
	}
	else{
		HAL_GPIO_WritePin(IR_A_GPIO_Port, IR_A_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(IR_B_GPIO_Port, IR_B_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(IR_C_GPIO_Port, IR_C_Pin, GPIO_PIN_SET);
	}
}

void IR_reset(){
	IR_set(99);
}

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	int L_pwm_pid=0, P_pwm_pid=0;
	uint8_t sensor;
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_I2C1_Init();
  MX_USART1_UART_Init();
  MX_USART6_UART_Init();
  MX_TIM1_Init();
  MX_ADC1_Init();
  MX_SPI1_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_TIM10_Init();
  MX_TIM11_Init();
  /* USER CODE BEGIN 2 */
  __HAL_TIM_SET_COMPARE(&htim1 , TIM_CHANNEL_1, 0 );
  __HAL_TIM_SET_COMPARE(&htim1 , TIM_CHANNEL_2, 0 );
  HAL_TIM_PWM_Start(&htim1 , TIM_CHANNEL_1);
  HAL_TIM_PWM_Start(&htim1 , TIM_CHANNEL_2);
  HAL_GPIO_WritePin(L_IN1_GPIO_Port, L_IN1_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(L_IN2_GPIO_Port, L_IN2_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(R_IN1_GPIO_Port, R_IN1_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(R_IN2_GPIO_Port, R_IN2_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, GPIO_PIN_SET);
  HAL_UART_Receive_IT(&huart1, &bt_data, 1);
  VL_Init_All(&hi2c1);
  HAL_TIM_Base_Start_IT(&htim10);
  HAL_TIM_Base_Start_IT(&htim11);
  HAL_TIM_Encoder_Start(&htim3, TIM_CHANNEL_ALL);
  HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_ALL);
  htim2.Instance->CNT = ENC_ZERO;
  htim3.Instance->CNT = ENC_ZERO;

  initialize_PID(kp, ki, kd);

  HAL_ADC_Start_DMA(&hadc1, adc_measurements, 6);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  if(adc_flag==1){

		  adc_flag=0;
	  }
	  if(adc_measurements[0]<2700){
		  HAL_Delay(1000);
		  HAL_GPIO_TogglePin(LED_3_GPIO_Port, LED_3_Pin);
	  }else{
		  if(timer_flag==1){
		  		  timer_flag=0;
		  		  L_pwm_pid = pid_calc(&pid_L, ENC_L.curr_speed, speed_mm*10);
		  		  P_pwm_pid = pid_calc(&pid_P, ENC_P.curr_speed, speed_mm*10);
		  		  if(option=='g'){
		  			  printf("SET: %d     MEAS:  %d     RES:  %d \r\n", speed_mm*10, ENC_L.curr_speed, L_pwm_pid );
		  			  PWM(speed_mm*10+L_pwm_pid, speed_mm*10+P_pwm_pid);
		  		  }
		  	  }
		  	  if(rx_flag==1){
		  		  switch(direction){
					 case 'w':
						  PWM(speed_mm*10,speed_mm*10);
						  break;
					  case 'a':
						  PWM(-speed_mm*6,speed_mm*6);
						  break;
					  case 's':
						  PWM(-speed_mm*10,-speed_mm*10);
						  break;
					  case 'd':
						  PWM(speed_mm*6,-speed_mm*6);
						  break;
		  		  }
		  		  if(direction != ' '){
		  			  HAL_Delay(100);
		  			  printf("Stopping\r\n");
		  			  PWM(0,0);
		  			  direction=' ';
		  		  }

		  		  switch(option){
		  		case 'k':
					  sensor = speed_mm/100;
					  printf("Measuring IR %d sensor value .... \r\n", sensor);
					  PT_change_sensor(sensor);
					  IR_set(sensor);
					  HAL_Delay(250);
					  printf("ADC MEASUREMENTS \r\n");
					  printf(" Batt : %d \r\n", adc_measurements[0]);
					  printf(" KTIR_1 : %d \r\n", adc_measurements[1]);
					  printf(" KTIR_2 : %d \r\n", adc_measurements[2]);
					  printf(" KTIR_3 : %d \r\n", adc_measurements[3]);
					  printf(" KTIR_4 : %d \r\n", adc_measurements[4]);
					  printf(" IR sensor : %d \r\n", adc_measurements[5]);
					  option=' ';
					  break;
		  		  case 'p':
		  			  read_encoders();
		  			  option=' ';
		  			  break;
		  		  case 'Q':
		  			  printf("Kp %d  Ki  %d  Kd  %d \r\n", kp, ki, kd );
		  			  initialize_PID(kp, ki, kd);
		  			  break;
		  		  case 'z':
		  			  ENC_L.absolute_pos=0;
		  			  ENC_P.absolute_pos=0;
		  			  option=' ';
		  			  break;
		  		  case ']':
		  			  pos_and_speed_measurement();
		  			  option=' ';
		  			  break;
		  		  case 'r':
		  			  PWM(speed_mm*10, speed_mm*10);
		  			  option=' ';
		  			  break;
		  		  case '=':
		  			f_SH_ClearMemory(VLS.MEMORY);
		  			printf("Clear memory VL\r\n");
		  			VL_Check();
		  			VL_single_measurement_blocking(dev, VLdistanceL);
		  			printf("VL_L: %d %d \r\n", VLS.MEMORY[0], VLS.STATE[0]);
		  			break;
		  		  case 'g':
		  			  break;
		  		  }
		  		  rx_flag=0;
		  	  }
	  }
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 96;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */
  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV8;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.ScanConvMode = ENABLE;
  hadc1.Init.ContinuousConvMode = ENABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 6;
  hadc1.Init.DMAContinuousRequests = ENABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_0;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_480CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_15;
  sConfig.Rank = 2;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_2;
  sConfig.Rank = 3;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_3;
  sConfig.Rank = 4;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_4;
  sConfig.Rank = 5;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_5;
  sConfig.Rank = 6;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_16;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};
  TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 24;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 9999;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
  if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
  sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
  sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
  sBreakDeadTimeConfig.DeadTime = 0;
  sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
  sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
  sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
  if (HAL_TIMEx_ConfigBreakDeadTime(&htim1, &sBreakDeadTimeConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */
  HAL_TIM_MspPostInit(&htim1);

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_Encoder_InitTypeDef sConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 0;
  htim2.Init.CounterMode = TIM_COUNTERMODE_DOWN;
  htim2.Init.Period = 65535;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  sConfig.EncoderMode = TIM_ENCODERMODE_TI1;
  sConfig.IC1Polarity = TIM_ICPOLARITY_RISING;
  sConfig.IC1Selection = TIM_ICSELECTION_DIRECTTI;
  sConfig.IC1Prescaler = TIM_ICPSC_DIV1;
  sConfig.IC1Filter = 2;
  sConfig.IC2Polarity = TIM_ICPOLARITY_RISING;
  sConfig.IC2Selection = TIM_ICSELECTION_DIRECTTI;
  sConfig.IC2Prescaler = TIM_ICPSC_DIV1;
  sConfig.IC2Filter = 2;
  if (HAL_TIM_Encoder_Init(&htim2, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_Encoder_InitTypeDef sConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 0;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 65535;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  sConfig.EncoderMode = TIM_ENCODERMODE_TI1;
  sConfig.IC1Polarity = TIM_ICPOLARITY_RISING;
  sConfig.IC1Selection = TIM_ICSELECTION_DIRECTTI;
  sConfig.IC1Prescaler = TIM_ICPSC_DIV1;
  sConfig.IC1Filter = 2;
  sConfig.IC2Polarity = TIM_ICPOLARITY_RISING;
  sConfig.IC2Selection = TIM_ICSELECTION_DIRECTTI;
  sConfig.IC2Prescaler = TIM_ICPSC_DIV1;
  sConfig.IC2Filter = 2;
  if (HAL_TIM_Encoder_Init(&htim3, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */

}

/**
  * @brief TIM10 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM10_Init(void)
{

  /* USER CODE BEGIN TIM10_Init 0 */

  /* USER CODE END TIM10_Init 0 */

  /* USER CODE BEGIN TIM10_Init 1 */

  /* USER CODE END TIM10_Init 1 */
  htim10.Instance = TIM10;
  htim10.Init.Prescaler = 1999;
  htim10.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim10.Init.Period = 999;
  htim10.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim10.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim10) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM10_Init 2 */

  /* USER CODE END TIM10_Init 2 */

}

/**
  * @brief TIM11 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM11_Init(void)
{

  /* USER CODE BEGIN TIM11_Init 0 */

  /* USER CODE END TIM11_Init 0 */

  /* USER CODE BEGIN TIM11_Init 1 */

  /* USER CODE END TIM11_Init 1 */
  htim11.Instance = TIM11;
  htim11.Init.Prescaler = 4799;
  htim11.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim11.Init.Period = 9999;
  htim11.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim11.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim11) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM11_Init 2 */

  /* USER CODE END TIM11_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 9600;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief USART6 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART6_UART_Init(void)
{

  /* USER CODE BEGIN USART6_Init 0 */

  /* USER CODE END USART6_Init 0 */

  /* USER CODE BEGIN USART6_Init 1 */

  /* USER CODE END USART6_Init 1 */
  huart6.Instance = USART6;
  huart6.Init.BaudRate = 115200;
  huart6.Init.WordLength = UART_WORDLENGTH_8B;
  huart6.Init.StopBits = UART_STOPBITS_1;
  huart6.Init.Parity = UART_PARITY_NONE;
  huart6.Init.Mode = UART_MODE_TX_RX;
  huart6.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart6.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart6) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART6_Init 2 */

  /* USER CODE END USART6_Init 2 */

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA2_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA2_Stream0_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA2_Stream0_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA2_Stream0_IRQn);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, PT_A_Pin|PT_B_Pin|PT_C_Pin|VL_XSHUT_R_Pin
                          |L_IN1_Pin|L_IN2_Pin|VL_XSHUT_L_Pin|VL_XSHUT_F_Pin
                          |IMU_CS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LED_3_Pin|LED_2_Pin|LED_1_Pin|IR_C_Pin
                          |IR_B_Pin|IR_A_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, R_IN2_Pin|R_IN1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : PT_A_Pin PT_B_Pin PT_C_Pin */
  GPIO_InitStruct.Pin = PT_A_Pin|PT_B_Pin|PT_C_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : BUT_1_Pin */
  GPIO_InitStruct.Pin = BUT_1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(BUT_1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : VL_INT_R_Pin VL_INT_F_Pin VL_INT_L_Pin */
  GPIO_InitStruct.Pin = VL_INT_R_Pin|VL_INT_F_Pin|VL_INT_L_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : VL_XSHUT_R_Pin L_IN1_Pin L_IN2_Pin VL_XSHUT_L_Pin
                           VL_XSHUT_F_Pin IMU_CS_Pin */
  GPIO_InitStruct.Pin = VL_XSHUT_R_Pin|L_IN1_Pin|L_IN2_Pin|VL_XSHUT_L_Pin
                          |VL_XSHUT_F_Pin|IMU_CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : LED_3_Pin LED_2_Pin LED_1_Pin */
  GPIO_InitStruct.Pin = LED_3_Pin|LED_2_Pin|LED_1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : IR_C_Pin IR_B_Pin IR_A_Pin */
  GPIO_InitStruct.Pin = IR_C_Pin|IR_B_Pin|IR_A_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : R_IN2_Pin R_IN1_Pin */
  GPIO_InitStruct.Pin = R_IN2_Pin|R_IN1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : BUT_2_Pin */
  GPIO_InitStruct.Pin = BUT_2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(BUT_2_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : IMU_INT_Pin */
  GPIO_InitStruct.Pin = IMU_INT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(IMU_INT_GPIO_Port, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI0_IRQn);

  HAL_NVIC_SetPriority(EXTI1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI1_IRQn);

  HAL_NVIC_SetPriority(EXTI2_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI2_IRQn);

  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
