#ifndef LEVEL_SENSOR_H
#define LEVEL_SENSOR_H

#include "main.h"
#include <stdbool.h>

#define dLEVEL_SENSOR_NUMBER 20
#define dLEVEL_SENSOR_ADC_MAX 4095

void LevelSensor_Init(void);

void LevelSensor_NewSample(uint16_t rawValue);

bool LevelSensor_IsReady(void);

float LevelSensor_GetVoltage(void);

float LevelSensor_GetPercent(void);

#endif
