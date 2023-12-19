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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include "TM1638.h"
#include "TM1638_platform.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
//#define toggle(a) {a=a^1;}
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
  TM1638_Handler_t Handler;

  	  TM1638_Platform_Init(&Handler);
  	 TM1638_Init(&Handler, TM1638DisplayTypeComCathode);
  	//TM1638_Init(&Handler,TM1638DisplayTypeComAnode);
  	  TM1638_ConfigDisplay(&Handler, 1, TM1638DisplayStateOFF);
  	  HAL_Delay(100);
  	TM1638_ConfigDisplay(&Handler, 7, TM1638DisplayStateON);
 //uint8_t d=112;
  	 uint8_t i=0;
  	uint32_t keys = 0;
  	int status =0;
//const uint8_t test[]={0x06,  0x5B, 0X3F,0x4F,  0x66, 0x6D,  0x7D,  0x07,  0x7F,  0x6F,0x77, 0x7c, 0x39, 0x5E, 0x79, 0x71};
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  // Display the number 8 and Decimal Point in the SEG1
	  //TM1638_SetMultipleDigit(&Handler, test , 0,15);
	  //TM1638_SetSingleDigit_HEX(&Handler, 0, 1);
	   for (i = 0; i < 9; i++) {
		  // TM1638_ConfigDisplay(&Handler, 7, TM1638DisplayStateON);
		  // HAL_Delay(1000);
	     TM1638_SetSingleDigit_HEX(&Handler, i, 0);
	     HAL_Delay(100);
	     TM1638_SetSingleDigit_HEX(&Handler, i, 2);
	     HAL_Delay(100);
	     TM1638_SetSingleDigit_HEX(&Handler, i, 4);

	     status = TM1638_ScanKeys(&Handler,&keys);
	     if (status == 0) {
	            // Display or use the scanned keys
	            printf("Scanned keys: %u\n", keys);
	        } else {
	            printf("Error scanning keys!\n");
	        }
	     /*HAL_Delay(100);
	     TM1638_SetSingleDigit_HEX(&Handler, ' ', 6);
	     	     HAL_Delay(100);
	     TM1638_SetSingleDigit_HEX(&Handler, ' ', 1);
	     HAL_Delay(100);
	     TM1638_SetSingleDigit_HEX(&Handler, ' ', 3);
	     HAL_Delay(100);
	     TM1638_SetSingleDigit_HEX(&Handler, ' ', 7);
	     HAL_Delay(100);
	     TM1638_SetSingleDigit_HEX(&Handler, ' ', 8);
	     HAL_Delay(100);
	     TM1638_SetSingleDigit_HEX(&Handler, ' ', 9);
	     HAL_Delay(100);
	     TM1638_SetSingleDigit_HEX(&Handler, ' ', 10);
	     HAL_Delay(100);
	     TM1638_SetSingleDigit_HEX(&Handler, ' ', 11);
	     HAL_Delay(100);
	     TM1638_SetSingleDigit_HEX(&Handler, ' ' , 12);
	     HAL_Delay(100);
	     TM1638_SetSingleDigit_HEX(&Handler, ' ' , 13);
	     HAL_Delay(100);
	     TM1638_SetSingleDigit_HEX(&Handler, ' ', 14);
	     HAL_Delay(100);

	     TM1638_SetSingleDigit_HEX(&Handler, ' ', 15);
	     	     HAL_Delay(100);
	     	    TM1638_SetSingleDigit_HEX(&Handler, ' ', 16);
	     	    	     HAL_Delay(100);*/
	     /* TM1638_SetSingleDigit_HEX(&Handler, i+1, 2);
	     HAL_Delay(100);
	     TM1638_SetSingleDigit_HEX(&Handler,  i, 3);
	     HAL_Delay(100);
	     TM1638_SetSingleDigit_HEX(&Handler, i+2 , 4);
	     HAL_Delay(100);
	     TM1638_SetSingleDigit_HEX(&Handler, i+3 , 6);
	     HAL_Delay(100);
	     TM1638_SetSingleDigit_HEX(&Handler, i+4 , 8);
	     HAL_Delay(100);
	     TM1638_SetSingleDigit_HEX(&Handler, i+5 , 10);
	     HAL_Delay(100);
	     TM1638_SetSingleDigit_HEX(&Handler, i+6 , 12);
	     HAL_Delay(100);
	  	 TM1638_SetSingleDigit_HEX(&Handler, i+7, 14);*/

	  	HAL_Delay(100);
	     //TM1638_ConfigDisplay(&Handler, 7, TM1638DisplayStateOFF);
	     HAL_GPIO_TogglePin(GPIOC, LED_PIN);
	       	//  HAL_Delay(1000);



	    // HAL_Delay(100);
	  }





  }
  TM1638_DeInit(&Handler);
    return 0;


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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL8;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
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
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);

  /*Configure GPIO pin : PC13 */
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : PA6 */
  GPIO_InitStruct.Pin = GPIO_PIN_6;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PB14 */
  GPIO_InitStruct.Pin = GPIO_PIN_14;
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
