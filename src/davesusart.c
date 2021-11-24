#include "davesusart.h"
#include "string.h"
#include "stm32f4xx_hal.h"

/*
 * write to USART a string of characters
 */
void USART_write_string(char* charString){
    for(int a = 0; a<strlen(charString);a++ ) {
        USART_write(charString[a]);
    }
}

/*
 * read USART
 */
char USART_read(void){
    while(!(USART2->SR & RXNE)){}
    return USART2->DR;
}

/*
 * write to USART a single character
 */
void USART_write(int ch){
    while(!(USART2->SR & TXE)){}
    USART2->DR = (ch & 0xFF);
}