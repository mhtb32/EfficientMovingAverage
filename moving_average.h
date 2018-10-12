/**
  ******************************************************************************
  * @file    moving_average.h
  * @author  Mohammad Hussein Tavakoli Bina, Sepehr Hashtroudi.
  * @brief   This file contains function prototype of moving average filter.
  ******************************************************************************
  */

#ifndef MOVING_AVERAGE_H
#define MOVING_AVERAGE_H

/* Includes ------------------------------------------------------------------*/
#include "stdint.h"

/* Definitions ---------------------------------------------------------------*/
#define WindowLength 10

/* TypeDefs ------------------------------------------------------------------*/
typedef struct{
	uint32_t History[WindowLength]; /*Array to store values of filter window*/
	uint32_t Sum;	/* Sum of filter window's elements*/
	uint32_t WindowPointer; /* Pointer to the first element of window*/
}FilterTypeDef;

/* Function prototypes -------------------------------------------------------*/
void Moving_Average_Init(FilterTypeDef* filter_struct);
uint32_t Moving_Average_Compute(uint32_t raw_data, FilterTypeDef* filter_struct);

#endif
