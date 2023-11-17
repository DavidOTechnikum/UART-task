/*
 * frame.c
 *
 *  Created on: Nov 17, 2023
 *      Author: David Oberleitner
 */

#include "frame.h"
char return_string[RETSTRINGLEN];
//uint32_t random_number = 0;

bool frame_check(char* frame) {
	char first_part[strlen(frame)];
	strcpy(first_part, frame);
	char *second_part;
	char *third_part;
	int interval_low;
	int interval_high;
	char *ptr;

	if (frame[0] != '#') {
		return false;
	}
	if (frame[1] != 'r') {
		return false;
	}
	if (frame[2] != ',') {
		return false;
	}
	if ((strtok(first_part, ",")) == NULL) {
		return false;
	}

	if ((second_part = strtok(NULL, ":")) == NULL) {
		return false;
	}
	if ((third_part = strtok(NULL, "\n")) == NULL) {
		return false;
	}
	interval_low = strtol(second_part, &ptr, 10);
	if (ptr == second_part) {
		return false;
	}
	interval_high = strtol(third_part, &ptr, 10);
	if (ptr == third_part) {
		return false;
	}
	if (frame[strlen(frame)-1] != '\n') {
		return false;
	}
	if (interval_low > interval_high) {
		return false;
	}

	return true;
}


char* frame_number_gen(char* frame, RNG_HandleTypeDef hrng) {
	char first_part[strlen(frame)];
	strcpy(first_part, frame);
	char *second_part;
	char *third_part;
	int interval_low;
	int interval_high;
	char *ptr;
//	char return_string[RETSTRINGLEN];
	uint32_t random_number = 0;

	if (frame[0] != '#') {
		return false;
	}
	if (frame[1] != 'r') {
		return false;
	}
	if (frame[2] != ',') {
		return false;
	}
	if ((strtok(first_part, ",")) == NULL) {
		return false;
	}

	if ((second_part = strtok(NULL, ":")) == NULL) {
		return false;
	}
	if ((third_part = strtok(NULL, "\n")) == NULL) {
		return false;
	}
	interval_low = strtol(second_part, &ptr, 10);
	if (ptr == second_part) {
		return false;
	}
	interval_high = strtol(third_part, &ptr, 10);
	if (ptr == third_part) {
		return false;
	}
	if (frame[strlen(frame)-1] != '\n') {
		return false;
	}
	if (interval_low > interval_high) {
		return false;
	}

	HAL_RNG_GenerateRandomNumber(&hrng, &random_number);
	random_number = (random_number % (1 + interval_high - interval_low)) + interval_low;


	if ((snprintf(return_string, RETSTRINGLEN-1, "#a,%d\n", (int)random_number)) < 0) {
		Error_Handler();
	}

	return return_string;
}
