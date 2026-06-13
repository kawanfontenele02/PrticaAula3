#include "Bsp.h"

#include "adc.h"
#include "tim.h"

Bsp_t bsp;

//Inicializa as variáveis do módulo BSP.
void Bsp_Init(void)
{
	bsp.timerFlag = false;
}
//Inicia o TIM6 com interrupções habilitadas.
void Bsp_StartTimerInterrupt(void)
{
	HAL_TIM_Base_Start_IT(&htim6);
}
/**
   Retorna o estado atual da flag do timer.
   Estado da flag.
 */
bool Bsp_GetTimerFlag(void)
{
	return bsp.timerFlag;
}

// Limpa a flag do timer.
void Bsp_ClearTimerFlag(void)
{
	bsp.timerFlag = false;
}
/*Executa uma conversão ADC por polling.
  Valor bruto convertido pelo ADC.*/
uint16_t Bsp_ReadAdcPolling(void)
{
	uint16_t value;

	HAL_ADC_Start(&hadc1);

	HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);

	value = HAL_ADC_GetValue(&hadc1);

	HAL_ADC_Stop(&hadc1);

	return value;
}
