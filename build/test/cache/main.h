#include "Drivers/STM32F4xx_HAL_Driver/Inc/stm32f4xx_hal.h"
typedef struct LEDlamp LEDlamp;



void USART_init(void);

void statusLED(int onoff);

void GPIO_init(void);

void USART_write(int ch);

char USART_read(void);

char* printMenu(void);

void USART_write_string(char* charString);



typedef enum {

    LEDOnFULL,

    LEDOFFFULL,

    NoOfIlluminationStates

}illuminationState;



typedef enum {

    emptyLED,

    LD1,

    noOfLED

} ledID;



typedef struct LEDlamp{

    char *location;

    ledID GPIO;

    illuminationState ledstate;

} LEDlamp;

void Error_Handler(void);
