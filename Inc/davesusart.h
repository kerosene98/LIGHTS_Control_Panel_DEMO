#ifndef USART_H
#define USART_H

//#include "stm32f4xx_hal.h"

void USART_write_string(char* charString);
char USART_read(void);
void USART_write(int ch);


#define RXNE 0x0020
#define TXE  0x0080

#define USART3EN (1 << 18)
#define USART4EN (1 << 19)
#define USART5EN (1 << 20)

#endif // USART_H
