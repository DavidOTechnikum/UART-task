/*
  ******************************************************************************
  * @file           : frame_func.h
  * @brief          : Header file for frame functions
  ******************************************************************************
  *
  *  Created on: Nov 17, 2023
  *      Author: David Oberleitner
  *
  ******************************************************************************
 */

#ifndef INC_FRAME_FUNC_H_
#define INC_FRAME_FUNC_H_

#include "main.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>

bool frame_check(char* frame);
bool frame_number_gen(char* frame, char* reply_frame, RNG_HandleTypeDef hrng);
bool ack_check(char* frame);

#endif /* INC_FRAME_FUNC_H_ */
