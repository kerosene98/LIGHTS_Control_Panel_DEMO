#include "init.h"

/*
 * Initialise the RCC clocks
 */
void RCC_init(void){
    // clocks
    RCC->AHB1ENR |= GPIOAEN;     // GPIOA clock enable PA2 = Tx
    RCC->APB1ENR |= USART2EN;    // USART2 clock enable 0x20000
}

/*
 * GPIO Init
 */
void GPIO_init(void){
    // gpio AF PA2 & PA3
    GPIOA->AFR[0] &= ~0xFF00;               // clear PA2 & PA3 AF
    GPIOA->AFR[0] |= PA2_AF7 | PA3_AF7;     // set AF7 function

    GPIOA->MODER &= ~0x0CF0;                // clear
    GPIOA->MODER |= MODER2_AF | MODER3_AF | MODER5_OUTPUT;      // set to AF mode 10b PA2(Tx) PA3(Rx) & PA5(LED) as output 01b
}

/*
 * Initialise the USART
 */
void USART_init(void){
    // Configure USART Baud
    USART2->BRR = baud_9600;     // set baud 9600
    USART2->CR1 = TE | RE;       // set TE & RE
    USART2->CR2 = 0x0000;
    USART2->CR3 = 0x0000;
    USART2->CR1 |= UE;          // Enable USART2
}