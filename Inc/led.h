#ifndef LED_H
#define LED_H

//#include "stm32f4xx_hal.h"

typedef struct LEDlamp LEDlamp;

void statusLED(LEDlamp *led1, int onoff);
void placeLED(LEDlamp *led1, char* location);


#define ON  1
#define OFF 0

typedef enum {
    LEDOFFFULL,
    LEDONFULL,
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


#endif // LED_H
