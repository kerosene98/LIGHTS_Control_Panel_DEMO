#ifndef INIT_H
#define INIT_H

#include "stm32f4xx_hal.h"

#define GPIOAEN (1 << 0)
#define USART2EN (1 << 17)

#define TE 0x0008
#define RE 0x0004
#define UE 0x2000

#define PA2_AF7 0x0700
#define PA3_AF7 0x7000
#define MODER2_AF 0x0020
#define MODER3_AF 0x0080
#define MODER5_OUTPUT 0x0400

#define baud_9600 0x0683

void RCC_init(void);
void GPIO_init(void);
void USART_init(void);

#endif // INIT_H
