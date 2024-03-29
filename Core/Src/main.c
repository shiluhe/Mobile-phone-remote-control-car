/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <string.h>
#include "My_esp8266.h"
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
#define RXBUFFERSIZE  256     //最大接收字节数
char RxBuffer[RXBUFFERSIZE];   //接收数据
uint8_t aRxBuffer;			//接收中断缓冲
uint8_t Uart2_Rx_Cnt = 0;		//接收缓冲计数
uint8_t my_test_v = 0 ;
char my_order[15]={0};
char receive_flag=0;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
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
  MX_TIM2_Init();
  MX_TIM1_Init();
  MX_TIM3_Init();
  MX_USART3_UART_Init();//各种初始化
  /* USER CODE BEGIN 2 */
    //HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_RESET );

    HAL_UART_Receive_IT(&huart3, (uint8_t *)&aRxBuffer, 1);//在第一次接收到数据的时候才会触发中断
    esp8266_start_trans();//wifi初始化
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

      if(receive_flag)
      {
          receive_flag=0;
          if(strstr((const char*)my_order,(const char*)"1"))
          {
              Uart2_Rx_Cnt=0;
              memset(RxBuffer,0x00,sizeof(RxBuffer)); //清空数组
              memset(RxBuffer,0x00,sizeof(my_order)); //清空数组
              my_test_v=1;
          }
          else if(strstr((const char*)my_order,(const char*)"2"))
          {
              Uart2_Rx_Cnt=0;
              memset(RxBuffer,0x00,sizeof(RxBuffer)); //清空数组
              memset(RxBuffer,0x00,sizeof(my_order)); //清空数组
              my_test_v=2;
          }
          else if(strstr((const char*)my_order,(const char*)"3"))
          {
              Uart2_Rx_Cnt=0;
              memset(RxBuffer,0x00,sizeof(RxBuffer)); //清空数组
              memset(RxBuffer,0x00,sizeof(my_order)); //清空数组
              my_test_v=3;
          }
          else if(strstr((const char*)my_order,(const char*)"4"))
          {
              Uart2_Rx_Cnt=0;
              memset(RxBuffer,0x00,sizeof(RxBuffer)); //清空数组
              memset(RxBuffer,0x00,sizeof(my_order)); //清空数组
              my_test_v=4;
          }
          else if(strstr((const char*)my_order,(const char*)"5"))
          {
              Uart2_Rx_Cnt=0;
              memset(RxBuffer,0x00,sizeof(RxBuffer)); //清空数组
              memset(RxBuffer,0x00,sizeof(my_order)); //清空数组
              my_test_v=5;
          }


      }
      if(my_test_v==1)
      {
              HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
              HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);
              HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
              HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
              HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);
              HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);
              HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_SET);
              HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_RESET);

      }
      else if(my_test_v==2)
      {

              HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_SET);
              HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
              HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
              HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
              HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET);
              HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);
              HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_SET);
              HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET);
              HAL_Delay(100);
      }
      else if(my_test_v==3)
      {

              HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
              HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);
              HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
              HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
              HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET);
              HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);
              HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_SET);
              HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_RESET);
          HAL_Delay(100);

      }
      else if(my_test_v==4)
      {

          HAL_GPIO_WritePin(GPIOA,GPIO_PIN_3,GPIO_PIN_SET);
          HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,GPIO_PIN_RESET);
          HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,GPIO_PIN_SET);
          HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_RESET);
          HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,GPIO_PIN_SET);
          HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_RESET);
          HAL_GPIO_WritePin(GPIOA,GPIO_PIN_12,GPIO_PIN_SET);
          HAL_GPIO_WritePin(GPIOA,GPIO_PIN_11,GPIO_PIN_RESET);
          HAL_Delay(100);
      }
      else if(my_test_v==5)
      {

              HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, GPIO_PIN_RESET);
              HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
              HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
              HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
              HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);
              HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);
              HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_RESET);
              HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET);
          HAL_Delay(100);
      }


    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
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

/* USER CODE BEGIN 4 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(huart);
    /* NOTE: This function Should not be modified, when the callback is needed,
             the HAL_UART_TxCpltCallback could be implemented in the user file
     */

    if(Uart2_Rx_Cnt >= 255)  //溢出判断
    {
        Uart2_Rx_Cnt = 0;
        memset(RxBuffer,0x00,sizeof(RxBuffer));
    }
    else
    {
        static uint8_t Uart2_count=0;

        RxBuffer[Uart2_Rx_Cnt] = aRxBuffer;   //接收数据转存
        if(receive_flag==0)
        {
            if(RxBuffer[Uart2_Rx_Cnt-Uart2_count]=='<')
            {
                Uart2_count++;
                if((RxBuffer[Uart2_Rx_Cnt]=='>')||Uart2_count>=14)
                {
                    uint8_t My_i=0;
                    for(int i=Uart2_Rx_Cnt-Uart2_count+1;i<Uart2_Rx_Cnt+1;i++)
                    {
                        my_order[My_i++]=RxBuffer[i];
                        receive_flag=1;
                        Uart2_count=0;
                    }
                }
            }
        }
        Uart2_Rx_Cnt++;
    }

    HAL_UART_Receive_IT(&huart3, (uint8_t *)&aRxBuffer, 1);   //再开启接收中???
}

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
