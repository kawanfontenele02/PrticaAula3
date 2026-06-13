/*
 * LevelSensor.c
 *
 *  Created on: 13 de jun. de 2026
 *      Author: kawan
 */

#include "LevelSensor.h"

typedef struct
{
	uint32_t accumulator;
	uint8_t sampleCount;
} LevelSensor_t;

static LevelSensor_t levelSensor;

//Inicializa os acumuladores do módulo.
void LevelSensor_Init(void)
{
	levelSensor.accumulator = 0;
	levelSensor.sampleCount = 0;
}
/*Armazena uma nova amostra do ADC.
  rawValue Valor bruto lido do ADC. */
void LevelSensor_NewSample(uint16_t rawValue)
{
	levelSensor.accumulator += rawValue;
	levelSensor.sampleCount++;
}
/**
 * Indica se já existem amostras suficientes para realizar os cálculos e retorna o Estado da coleta.
 */
bool LevelSensor_IsReady(void)
{
	return (levelSensor.sampleCount >= dLEVEL_SENSOR_NUMBER);
}

//Calcula a tensão média das amostra e retorna a Tensão média em volts.
float LevelSensor_GetVoltage(void)
{
	float media;

	media =
		(float)levelSensor.accumulator /
		dLEVEL_SENSOR_NUMBER;

	return (3.3f * media) /
		   dLEVEL_SENSOR_ADC_MAX;
}
//Calcula o nível do tanque em porcentageme e retorna Nível médio em porcentagem.
float LevelSensor_GetPercent(void)
{
	float media;

	media =
		(float)levelSensor.accumulator /
		dLEVEL_SENSOR_NUMBER;

	return (media * 100.0f) /
		   dLEVEL_SENSOR_ADC_MAX;
}




