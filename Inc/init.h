#ifndef INIT_H
#define INIT_H

//#include "stm32f4xx_hal.h"

#define GPIOAEN (1 << 0)
#define USART2EN (1 << 17)
#define GPIOBEN (1 << 1)
#define GPIOCEN (1 << 2)
#define GPIODEN (1 << 3)
#define GPIOEEN (1 << 4)
#define GPIOFEN (1 << 5)
#define GPIOGEN (1 << 6)
#define GPIOHEN (1 << 7)

#define TE 0x0008
#define RE 0x0004
#define UE 0x2000

#define PA2_AF7 0x0700
#define PA3_AF7 0x7000
#define MODER2_AF 0x0020
#define MODER3_AF 0x0080
#define MODER5_OUTPUT 0x0400

#define baud_9600 0x0683

#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB

void RCC_init(void);
void GPIO_init(void);
void USART_init(void);

#endif // INIT_H
