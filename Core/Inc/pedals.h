#pragma once

#include "main.h"
#include "adc.h"
#include "stdbool.h"
#include "stdlib.h"


typedef struct
{
	int16_t potentiometer_value;
	int16_t previous_potentiometer_value;
	int16_t potentiometer_min;
	int16_t potentiometer_max;
	int16_t ncoder_value;
	int16_t ncoder_min;
	int16_t ncoder_max;
	int16_t different;
	int16_t target;
	char is_pressed;
	char is_move;
	char is_control;
	char direction;
}Clutch;

extern Clutch clutch;

enum Pedals
{
	PEDAL_CLUTCH,
	PEDAL_BRAKE,
	PEDAL_GAS
};

enum Direction
{
	MOVE_FORWARD,
	MOVE_BACK
};

extern void clutch_initialize(void);

extern void handler_selector(char is_pressed);

void move_along(char direction);

extern void handler_potentiometer(char is_control);

void move_under_control(char direction);

void move_motor(uint8_t motor_number, float duty);

char determine_direction(int16_t different);

int16_t read_potentiometer(void);

int16_t map(int16_t value, int16_t in_min, int16_t in_max, int16_t out_min, int16_t out_max);

int16_t constrain(int16_t value, int16_t min, int16_t max);

