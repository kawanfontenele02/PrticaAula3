/*
 * LevelSensor.h
 *
 *  Created on: 13 de jun. de 2026
 *      Author: kawan
 */

#ifndef INC_LEVELSENSOR_H_
#define INC_LEVELSENSOR_H_



#endif /* INC_LEVELSENSOR_H_ */
#ifndef LEVEL_SENSOR_H
#define LEVEL_SENSOR_H

#include "main.h"
#include <stdbool.h>

#define dLEVEL_SENSOR_NUMBER 20
#define dLEVEL_SENSOR_ADC_MAX 4095

// Inicializa o módulo de medição de nível.
void LevelSensor_Init(void);
/* Adiciona uma nova amostra ao cálculo.
   param rawValue Valor bruto obtido do ADC. */
void LevelSensor_NewSample(uint16_t rawValue);
/**
 * @brief Verifica se já existem amostras suficientes.
 * @return true quando 20 amostras forem coletadas.
 * @return false caso contrário.
 */
bool LevelSensor_IsReady(void);
/**
 * @brief Retorna a tensão média medida.
 * @return Tensão em volts.
 */
float LevelSensor_GetVoltage(void);
/**
 * @brief Retorna o nível do tanque em porcentagem.
 * @return Nível entre 0 e 100%.
 */
float LevelSensor_GetPercent(void);

#endif
