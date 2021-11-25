/*
 * This is a USART app that receives a cmd via the users keyboard to toggle on/off an LED.
 * @author David Gelkin <david.gelkin@gmail.com>
 */

#include "main.h"
#include "string.h"
#include "stdlib.h"
#include "init.h"
#include "menu.h"
#include "led.h"

// Global
LEDlamp led1;
LEDlamp led2;
LEDlamp led3;

// Ensure compiler does not optimize out variable
volatile int APPisOn = ON;

/*
 * Main function
 */
int main(void){
    RCC_init();
    GPIO_init();
    USART_init();
    char c;

    // Position LEDs in rooms
    placeLED(&led1, "Kitchen");
    placeLED(&led2, "Bedroom");
    placeLED(&led3, "Porch");



    //print initial menu as app starts
    USART_write_string(printMenu());

    // Super loop
    while(APPisOn){
        c = USART_read();
        //USART_write(c); // loopback for debugging

        // turn LED1 ON
        if(c == '7') {
            statusLED(&led1, ON);
        }

        // turn LED1 OFF
        if(c =='1') {
            statusLED(&led1, OFF);
        }

        // turn LED2 ON
        if(c == '8') {
            statusLED(&led2, ON);
        }

        // turn LED2 OFF
        if(c =='2') {
            statusLED(&led2, OFF);
        }

        // turn LED2 ON
        if(c == '9') {
            statusLED(&led3, ON);
        }

        // turn LED2 OFF
        if(c =='3') {
            statusLED(&led3, OFF);
        }

        // turn ALL LED OFF
        if(c =='5') {
            statusLED(&led1, OFF);
            statusLED(&led2, OFF);
            statusLED(&led3, OFF);
        }

        // turn ALL LED ON
        if(c =='0') {
            statusLED(&led1, ON);
            statusLED(&led2, ON);
            statusLED(&led3, ON);
        }

        // Spacebar, q or h displays the menu!
        if(c == 32) {
            // turn LED off as default
            statusLED(&led1, OFF);
            USART_write_string(printMenu());
        }

        // h displays the app help
        if((c == 'h')||(c=='H')) {
            // turn LED off as default
            statusLED(&led1, OFF);
            USART_write_string(APPHELP());
        }

        // LED status
        if((c == 's')||(c=='S')) {
            // turn LED off as default
            char *status = malloc(20*sizeof(char));
            strcpy(status,"[STATUS CHECK] \r\n");
            USART_write_string(status);
            USART_write_string(led1.location);
            USART_write_string(led1.ledstate==0?"\tOFF\r\n":"\tON\r\n");
            USART_write_string(led2.location);
            USART_write_string(led2.ledstate==0?"\tOFF\r\n":"\tON\r\n");
            USART_write_string(led3.location);
            USART_write_string(led3.ledstate==0?"\tOFF\r\n":"\tON\r\n");

            USART_write_string("\r\n");
            free(status);
        }

        //TODO clear display with 10x new lines!
        if(c == 'c') {
            // turn LED off as default
            statusLED(&led1, OFF);
            USART_write_string(CLEARDISPLAY);
        }

        // quit app, press esc button
        if((c == 27) || ((c == 'q')||(c=='Q'))){
            APPisOn = OFF;
            USART_write_string("\nAPP SHUTDOWN\n\n");
        }
    }
}