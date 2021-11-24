#include "led.h"
#include "stm32f4xx_hal.h"

/*
 * LED ON PA5
 */
void statusLED(LEDlamp *led1, int onoff){
    if(onoff==LEDONFULL) {
        // Devboard example has ONLY 1 test LED but imagine more LEDs can be tied to an LED object...
        GPIOA->BSRR |= 0x0020;       // LED on
        led1->ledstate = ON;
    }else{
        GPIOA->BSRR |= 0x0020 << 16; // LED off
        led1->ledstate = OFF;
    }
}

void placeLED(LEDlamp *led1, char* location){
    led1->location = malloc(8*sizeof(char));
    strcpy(led1->location, location);
}