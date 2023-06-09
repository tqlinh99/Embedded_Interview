/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

#define SCL GPIO_PIN_3
#define SDA GPIO_PIN_4

uint8_t RxBuffer[16];



void SetSDA_Output(){
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = SDA;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}

void SetSDA_Input(){
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = SDA;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}

void I2C_Software_Master_init(){
	HAL_GPIO_WritePin(GPIOB, SCL, 1);
	HAL_GPIO_WritePin(GPIOB, SDA, 1);
}

void I2C_Software_Master_Start(){
	SetSDA_Output();
	HAL_GPIO_WritePin(GPIOB, SCL, 1);
	HAL_GPIO_WritePin(GPIOB, SDA, 1);
	HAL_Delay(5);
	HAL_GPIO_WritePin(GPIOB, SDA, 0);
	HAL_Delay(5);
	HAL_GPIO_WritePin(GPIOB, SCL, 0);
}

void I2C_Software_Master_Stop(){
	SetSDA_Output();
	HAL_GPIO_WritePin(GPIOB, SCL, 0);
	HAL_GPIO_WritePin(GPIOB, SDA, 0);
	HAL_Delay(1);
	HAL_GPIO_WritePin(GPIOB, SCL, 1);
	HAL_GPIO_WritePin(GPIOB, SDA, 1);
}

void Clock_Signal(){
	HAL_GPIO_WritePin(GPIOB, SCL, 1);
	HAL_Delay(8);
	HAL_GPIO_WritePin(GPIOB, SCL, 0);
	HAL_Delay(8);
}

void I2C_Software_Master_Send_Byte(uint8_t mData){
	SetSDA_Output();
	
	for(uint8_t i = 0; i < 8; i++){
		if ((mData&0x80) == 0){
			HAL_GPIO_WritePin(GPIOB, SDA, 0);
		}
		else{
			HAL_GPIO_WritePin(GPIOB, SDA, 1);
		}
		Clock_Signal();
		mData = mData << 1;
	}
	HAL_GPIO_WritePin(GPIOB, SDA, 0);
}
	
uint8_t I2C_Software_Master_Read_Byte(){
	uint8_t receivedByte = 0;
	SetSDA_Input();

	for(uint8_t i = 0; i < 8; i++){
		receivedByte = receivedByte << 1;
		receivedByte = receivedByte | HAL_GPIO_ReadPin(GPIOB, SDA);
		Clock_Signal();
	}
	return receivedByte;
}

void I2C_Ack(){
	SetSDA_Output();
	HAL_GPIO_WritePin(GPIOB, SDA, 0);
	Clock_Signal();
}

void I2C_NAck(){
	SetSDA_Output();
	HAL_GPIO_WritePin(GPIOB, SDA, 1);
	Clock_Signal();
}

uint8_t I2C_Wait_Ack(){
	uint8_t time = 0;
	SetSDA_Input();
	HAL_GPIO_WritePin(GPIOB, SCL, 1);
	HAL_Delay(8);

	while(HAL_GPIO_ReadPin(GPIOB, SDA)){
		time++;
		if(time>250){
			I2C_Software_Master_Stop();
			return 1;
		}
	}
	HAL_GPIO_WritePin(GPIOB, SCL, 0);
	HAL_Delay(8);

	return 0;
}

void I2C_Software_Master_Transmit(uint8_t address ,char data[]){
	I2C_Software_Master_Start();

	I2C_Software_Master_Send_Byte(address<<1);
	if (I2C_Wait_Ack() == 1){
		return;
	}
	
	for(uint8_t i=0;; i++){
		I2C_Software_Master_Send_Byte(data[i]);
		if (I2C_Wait_Ack() == 1){
			return;
		}
		if(data[i] == '\0'){
			break;
		}
	}
	I2C_Software_Master_Stop();
}

void I2C_Software_Master_Receive(uint8_t address){
	I2C_Software_Master_Start();

	I2C_Software_Master_Send_Byte((address<<1)+1);
	if (I2C_Wait_Ack() == 1){
		return;
	}
	for(uint8_t i=0; ; i++){
		RxBuffer[i] = I2C_Software_Master_Read_Byte();
		I2C_Ack();
		
		if(RxBuffer[i] == 0){
			break;
		}
	}
	I2C_Software_Master_Stop();
}


/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

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
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	I2C_Software_Master_init();

  while (1)
  {
		if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_12) == 0){
			HAL_Delay(20);
			if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_12) == 0){
				I2C_Software_Master_Transmit(0x02, "abcdef");
			}
		}
	}
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_7, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA0 PA1 PA2 PA3
                           PA4 PA5 PA6 PA7 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3
                          |GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PB12 */
  GPIO_InitStruct.Pin = GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PB3 PB4 */
  GPIO_InitStruct.Pin = GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
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
  __disable_irq();
  while (1)
  {
  }
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
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
