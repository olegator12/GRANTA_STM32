/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define PEDAL_BUTTON_BRAKE_FINISH_Pin GPIO_PIN_4
#define PEDAL_BUTTON_BRAKE_FINISH_GPIO_Port GPIOE
#define PEDAL_BUTTON_BRAKE_FINISH_EXTI_IRQn EXTI4_IRQn
#define MOTOR_GAS_LEFT_PWM_Pin GPIO_PIN_5
#define MOTOR_GAS_LEFT_PWM_GPIO_Port GPIOE
#define MOTOR_GAS_RIGHT_PWM_Pin GPIO_PIN_6
#define MOTOR_GAS_RIGHT_PWM_GPIO_Port GPIOE
#define PEDAL_BUTTON_CLUTCH_FINISH_Pin GPIO_PIN_1
#define PEDAL_BUTTON_CLUTCH_FINISH_GPIO_Port GPIOC
#define PEDAL_BUTTON_BRAKE_START_Pin GPIO_PIN_2
#define PEDAL_BUTTON_BRAKE_START_GPIO_Port GPIOC
#define POTENTIOMETER_Pin GPIO_PIN_0
#define POTENTIOMETER_GPIO_Port GPIOA
#define PEDAL_BUTTON_GAS_START_Pin GPIO_PIN_4
#define PEDAL_BUTTON_GAS_START_GPIO_Port GPIOC
#define PEDAL_BUTTON_GAS_FINISH_Pin GPIO_PIN_5
#define PEDAL_BUTTON_GAS_FINISH_GPIO_Port GPIOC
#define PEDAL_BUTTON_CLUTCH_START_Pin GPIO_PIN_1
#define PEDAL_BUTTON_CLUTCH_START_GPIO_Port GPIOB
#define ECCODER_GAS_A_Pin GPIO_PIN_9
#define ECCODER_GAS_A_GPIO_Port GPIOE
#define ECCODER_GAS_B_Pin GPIO_PIN_11
#define ECCODER_GAS_B_GPIO_Port GPIOE
#define MOTOR_CLUTCH_LEFT_PWM_Pin GPIO_PIN_12
#define MOTOR_CLUTCH_LEFT_PWM_GPIO_Port GPIOD
#define MOTOR_CLUTCH_RIGHT_PWM_Pin GPIO_PIN_13
#define MOTOR_CLUTCH_RIGHT_PWM_GPIO_Port GPIOD
#define MOTOR_BRAKE_LEFT_PWM_Pin GPIO_PIN_14
#define MOTOR_BRAKE_LEFT_PWM_GPIO_Port GPIOD
#define MOTOR_BRAKE_RIGHT_PWM_Pin GPIO_PIN_15
#define MOTOR_BRAKE_RIGHT_PWM_GPIO_Port GPIOD
#define ECCODER_CLUTCH_A_Pin GPIO_PIN_6
#define ECCODER_CLUTCH_A_GPIO_Port GPIOC
#define ECCODER_CLUTCH_B_Pin GPIO_PIN_7
#define ECCODER_CLUTCH_B_GPIO_Port GPIOC
#define ECCODER_BRAKE_A_Pin GPIO_PIN_15
#define ECCODER_BRAKE_A_GPIO_Port GPIOA
#define FRONT_CONTACT_Pin GPIO_PIN_0
#define FRONT_CONTACT_GPIO_Port GPIOD
#define FRONT_CONTACT_EXTI_IRQn EXTI0_IRQn
#define BACK_CONTACT_Pin GPIO_PIN_1
#define BACK_CONTACT_GPIO_Port GPIOD
#define BACK_CONTACT_EXTI_IRQn EXTI1_IRQn
#define SELECTOR_BUTTON_CLUTCH_Pin GPIO_PIN_2
#define SELECTOR_BUTTON_CLUTCH_GPIO_Port GPIOD
#define SELECTOR_BUTTON_CLUTCH_EXTI_IRQn EXTI2_IRQn
#define SELECTOR_CONC_CLUTCH_Pin GPIO_PIN_3
#define SELECTOR_CONC_CLUTCH_GPIO_Port GPIOD
#define SELECTOR_CONC_CLUTCH_EXTI_IRQn EXTI3_IRQn
#define LEFT_CONTACT_Pin GPIO_PIN_6
#define LEFT_CONTACT_GPIO_Port GPIOD
#define RIGHT_CONTACT_Pin GPIO_PIN_7
#define RIGHT_CONTACT_GPIO_Port GPIOD
#define ECCODER_BRAKE_B_Pin GPIO_PIN_3
#define ECCODER_BRAKE_B_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
