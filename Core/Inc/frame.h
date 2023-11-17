/*
 * frame.h
 *
 *  Created on: Nov 17, 2023
 *      Author: David Oberleitner
 */

#ifndef INC_FRAME_H_
#define INC_FRAME_H_

#include "main.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define RETSTRINGLEN 20

bool frame_check(char* frame);
char* frame_number_gen(char* frame, RNG_HandleTypeDef hrng);



#endif /* INC_FRAME_H_ */
