#include "transmition.h"

Transmition transmition;

void check_transfer()
{
	read_buttons();

	if ((transmition.front_button || transmition.back_button) != 0)
	{
		transmition.transfer_array_row = implication(transmition.front_button, transmition.back_button);
	}
	else
	{
		transmition.transfer_array_row = 2;
	}

	if ((transmition.left_button || transmition.right_button) != 0)
	{
		transmition.transfer_array_column = implication(transmition.left_button, transmition.right_button);
	}
	else
	{
		transmition.transfer_array_column = 2;
	}

	transmition.current_transfer = transmition.transfers_array[transmition.transfer_array_row][transmition.transfer_array_column];
}

void read_buttons()
{
	transmition.front_button = HAL_GPIO_ReadPin(GPIOD, FRONT_BUTTON_Pin);
	transmition.back_button = HAL_GPIO_ReadPin(GPIOD, BACK_BUTTON_Pin);
	transmition.left_button = HAL_GPIO_ReadPin(GPIOD, LEFT_BUTTON_Pin);
	transmition.right_button = HAL_GPIO_ReadPin(GPIOD, RIGHT_BUTTON_Pin);
}

bool implication(bool x, bool y)
{
	return !(x) || y;
}
