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

void LevelSensor_Init(void)
{
	levelSensor.accumulator = 0;
	levelSensor.sampleCount = 0;
}

void LevelSensor_NewSample(uint16_t rawValue)
{
	levelSensor.accumulator += rawValue;
	levelSensor.sampleCount++;
}
bool LevelSensor_IsReady(void)
{
	return (levelSensor.sampleCount >= dLEVEL_SENSOR_NUMBER);
}

float LevelSensor_GetVoltage(void)
{
	float media;

	media =
		(float)levelSensor.accumulator /
		dLEVEL_SENSOR_NUMBER;

	return (3.3f * media) /
		   dLEVEL_SENSOR_ADC_MAX;
}
float LevelSensor_GetPercent(void)
{
	float media;

	media =
		(float)levelSensor.accumulator /
		dLEVEL_SENSOR_NUMBER;

	return (media * 100.0f) /
		   dLEVEL_SENSOR_ADC_MAX;
}




