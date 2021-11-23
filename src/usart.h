#ifndef USART_H
#define USART_H

#include "mock_stm32f4xx_hal.h"
#include "usart.h"

void USART_write_string(char* charString);
char USART_read(void);
void USART_write(int ch);


#define RXNE 0x0020
#define TXE  0x0080

#endif // USART_H
