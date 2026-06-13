#ifndef BSP_H
#define BSP_H

#include "main.h"
#include <stdbool.h>

typedef struct
{
	volatile bool timerFlag;
} Bsp_t;

extern Bsp_t bsp;

void Bsp_Init(void);

void Bsp_StartTimerInterrupt(void);

bool Bsp_GetTimerFlag(void);

void Bsp_ClearTimerFlag(void);

uint16_t Bsp_ReadAdcPolling(void);

#endif
