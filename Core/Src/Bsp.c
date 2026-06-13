#include "Bsp.h"

#include "adc.h"
#include "tim.h"

Bsp_t bsp;

void Bsp_Init(void)
{
	bsp.timerFlag = false;
}

void Bsp_StartTimerInterrupt(void)
{
	HAL_TIM_Base_Start_IT(&htim6);
}

bool Bsp_GetTimerFlag(void)
{
	return bsp.timerFlag;
}

void Bsp_ClearTimerFlag(void)
{
	bsp.timerFlag = false;
}

uint16_t Bsp_ReadAdcPolling(void)
{
	uint16_t value;

	HAL_ADC_Start(&hadc1);

	HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);

	value = HAL_ADC_GetValue(&hadc1);

	HAL_ADC_Stop(&hadc1);

	return value;
}
