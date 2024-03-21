#pragma once

#include "main.h"
#include "stdbool.h"

typedef struct{
	bool front_button;
	bool back_button;
	bool left_button;
	bool right_button;
	uint8_t current_transfer;
	uint8_t transfer_array_row;
	uint8_t transfer_array_column;
	uint8_t transfers_array[][3];
} Transmition;

extern Transmition transmition;

extern void check_transfer(void);

void read_buttons(void);

bool implication(bool x, bool y);
