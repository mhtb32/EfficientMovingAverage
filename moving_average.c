/**
  ******************************************************************************
  * @file    moving_average.c
  * @author  Mohammad Hussein Tavakoli Bina, Sepehr Hashtroudi
  * @brief   This file contains an efficient implementation of 
	*					 moving average filter.
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "moving_average.h"

/**
  * @brief  This function initializes filter's data structure.
	* @param  filter_struct : Data structure
  * @retval None.
  */
void Moving_Average_Init(FilterTypeDef* filter_struct)
{
	filter_struct->Sum = 0;
	filter_struct->WindowPointer = 0;
	
	for(uint32_t i=0; i<WindowLength; i++)
	{
		filter_struct->History[i] = 0;
	}
}

/**
  * @brief  This function filters data with moving average filter.
	* @param  raw_data : input raw sensor data.
	* @param  filter_struct : Data structure
  * @retval Filtered value.
  */
uint32_t Moving_Average_Compute(uint32_t raw_data, FilterTypeDef* filter_struct)
{
	filter_struct->Sum += raw_data;
	filter_struct->Sum -= filter_struct->History[filter_struct->WindowPointer];
	filter_struct->History[filter_struct->WindowPointer] = raw_data;
	if(filter_struct->WindowPointer < WindowLength)
	{
		filter_struct->WindowPointer += 1;
	}
	else
	{
		filter_struct->WindowPointer = 0;
	}
	return filter_struct->Sum/WindowLength;
}
