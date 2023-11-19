/*
  ******************************************************************************
  * @file           : frame_func.c
  * @brief          : Source file for frame functions
  ******************************************************************************
  *
  *  Created on: Nov 17, 2023
  *      Author: David Oberleitner
  *
  ******************************************************************************
 */
#include "frame_func.h"

/**
  * @brief Function checks if a string is a frame of the format "#r,<int1>:<int2>\n",
  * 		if int1 < int2 and if the numbers are within the boundaries of system integers.
  * @param frame: String to be checked.
  * @retval True in case of correct frame.
 */
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
	if (interval_low > interval_high || interval_low < INT_MIN || interval_low > INT_MAX || interval_high < INT_MIN || interval_high > INT_MAX) {
		return false;
	}

	return true;
}

/**
 * @brief	Function generates a reply frame which contains a random number
 * 			between the two values of the request frame.
 * @param 	frame: 			Request frame containing the min. and max. values.
 * @param	reply_frame:	Pointer to the string which is to be filled with the reply frame.
 * @param 	hrng:			Typedef for random function.
 * @retval 	True in case of success.
 */
bool frame_number_gen(char* frame, char* reply_frame, RNG_HandleTypeDef hrng) {
	char first_part[strlen(frame)];
	strcpy(first_part, frame);
	char *second_part;
	char *third_part;
	int interval_low;
	int interval_high;
	char *ptr;
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


	if ((snprintf(reply_frame, FRAMELEN-1, "#a,%d\n", (int)random_number)) < 0) {
		Error_Handler();
	}

	return true;
}

/**
 * @brief: 	Wrapper function for checking a string for "ACK"-message.
 * @param 	frame: 	String to be checked.
 * @retval	True in case of matching string.
 */
bool ack_check(char* frame) {
	if (strcmp(frame, "ACK\n") == 0) {
		return true;
	} else {
		return false;
	}
}
