#ifndef USART_H
#define USART_H

#include "stm32f4xx_hal.h"

void USART_write_string(char* charString);
char USART_read(void);
void USART_write(int ch);


#define RXNE 0x0020
#define TXE  0x0080

#endif // USART_H
