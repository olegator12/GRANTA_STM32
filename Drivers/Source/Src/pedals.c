#include "pedals.h"

Clutch clutch;

void handler_selector(bool is_pressed)
{
	if(is_pressed == true)
	{
		clutch.is_pressed = 1;
		move_along(MOVE_FORWARD);
	}
	else
	{
		move_along(MOVE_BACK);
	}

	HAL_Delay(100);
}

void move_along(char direction)
{
	if(direction == MOVE_FORWARD)
	{
		while(clutch.is_pressed == 1 && clutch.direction == MOVE_FORWARD)
		{
			move_motor(PEDAL_CLUTCH, 1.0);

			if(HAL_GPIO_ReadPin(GPIOC, PEDAL_BUTTON_CLUTCH_FINISH_Pin) == true)
			{
				move_motor(PEDAL_CLUTCH, 0.0);
				clutch.direction = MOVE_BACK;
			}
		}
	}
	else
	{
		while(clutch.is_pressed == 1 && clutch.direction == MOVE_BACK)
		{
			move_motor(PEDAL_CLUTCH, -0.5);

			if(HAL_GPIO_ReadPin(GPIOB, PEDAL_BUTTON_CLUTCH_START_Pin) == true)
			{
				move_motor(PEDAL_CLUTCH, 0.0);
				clutch.is_pressed = 0;
				clutch.direction = MOVE_FORWARD;
			}
		}
	}
}

void handler_potentiometer()
{
	clutch.potentiometer_value = read_potentiometer();
	clutch.different = clutch.potentiometer_value - clutch.previous_potentiometer_value;

	if(abs(clutch.different) > 5)
	{
		clutch.direction = determine_direction(clutch.different);
		clutch.is_move = 1;
	}

	if(clutch.is_move == true)
	{
		move_under_control(clutch.direction);
	}

	clutch.previous_potentiometer_value = clutch.potentiometer_value;
}

void move_under_control(char direction)
{
	clutch.target = map(clutch.potentiometer_value, clutch.ncoder_min, clutch.ncoder_max, clutch.ncoder_min, clutch.ncoder_max);
	clutch.target = constrain(clutch.target, clutch.ncoder_min, clutch.ncoder_max);

	if((clutch.direction == MOVE_BACK && clutch.target - 1 >= clutch.ncoder_value) ||
	   (clutch.direction == MOVE_FORWARD && clutch.target + 1 <= clutch.ncoder_value))
	{
		clutch.is_move = 0;
		move_motor(PEDAL_CLUTCH, 0.0);
		return;
	}

	switch(clutch.direction)
	{
		case MOVE_FORWARD:
			move_motor(PEDAL_CLUTCH, 0.3);
			break;
		case MOVE_BACK:
			move_motor(PEDAL_CLUTCH, -0.3);
			break;
		default:
			break;
	}
}

void move_motor(uint8_t motor_number, float duty)
{
	switch(motor_number)
	{
		case PEDAL_CLUTCH:

			if(duty >= 0)
			{
				TIM4->CCR1 = ((int32_t) (duty * TIM4->ARR));
				TIM4->CCR2 = 0;
			}
			else
			{
				TIM4->CCR1 = 0;
				TIM4->CCR2 = ((int32_t) (duty * TIM4->ARR));
			}
			break;

		case PEDAL_BRAKE:

			if(duty >= 0)
			{
				TIM4->CCR3 = ((int32_t) (duty * TIM4->ARR));
				TIM4->CCR4 = 0;
			}
			else
			{
				TIM4->CCR3 = 0;
				TIM4->CCR4 = ((int32_t) (duty * TIM4->ARR));
			}
			break;

		case PEDAL_GAS:

			if(duty >= 0)
			{
				TIM9->CCR1 = ((int32_t) (duty * TIM9->ARR));
				TIM9->CCR2 = 0;
			}
			else
			{
				TIM9->CCR1 = 0;
				TIM9->CCR2 = ((int32_t) (duty * TIM9->ARR));
			}
			break;

		default:
			break;
	}
}

char determine_direction(int16_t different)
{
	if(clutch.is_move == false) return clutch.direction;

	if (different < 0) return MOVE_BACK;
	else if (different > 0) return MOVE_FORWARD;

	return clutch.direction;
}

int16_t read_potentiometer()
{
	uint8_t counter = 0;
	uint8_t limit = 30;
	int16_t sum_value = 0;

	while (counter < limit)
	{
		sum_value += HAL_ADC_GetValue(&hadc1);
		counter++;
	}

	return sum_value / limit;
}

int16_t map(int16_t value, int16_t in_min, int16_t in_max, int16_t out_min, int16_t out_max)
{
	return (value - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int16_t constrain(int16_t value, int16_t min, int16_t max)
{
	if(value <= min) return min;
	else if(value >= max) return max;

	return value;
}



