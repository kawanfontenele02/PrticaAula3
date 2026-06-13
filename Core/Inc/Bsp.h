/*
 * Bsp.h
 *
 *  Created on: 13 de jun. de 2026
 *      Author: kawan
 */

#ifndef INC_BSP_H_
#define INC_BSP_H_



#endif /* INC_BSP_H_ */
#ifndef BSP_H
#define BSP_H

#include "main.h"
#include <stdbool.h>

typedef struct
{
	volatile bool timerFlag;
} Bsp_t;

extern Bsp_t bsp;

//Inicializa o módulo BSP.

void Bsp_Init(void);

  //Inicia o TIM6 em modo interrupção.
void Bsp_StartTimerInterrupt(void);
/**
 Retorna o estado da flag do timer.
 Retorna true se o timer gerou interrupção.
 Retorna false caso contrário.
 **/

bool Bsp_GetTimerFlag(void);
// Limpa a flag gerada pela interrupção do timer.
void Bsp_ClearTimerFlag(void);
/*
 Realiza uma leitura do ADC utilizando polling.
 Return Valor bruto do ADC (0 a 4095).
 */
uint16_t Bsp_ReadAdcPolling(void);

#endif
