#ifndef USART_H
#define USART_H

#include "stm32f4xx_hal.h"

void USART_write(int ch);
void USART_write_string(char* charString);
char USART_read(void);

#endif // USART_H
