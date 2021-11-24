/*
 * This is a USART app that receives a cmd via the users keyboard to toggle on/off an LED.
 * @author David Gelkin <david.gelkin@gmail.com>
 */

//#include "stm32f4xx.h"
#include "main.h"
#include "string.h"
#include "stdlib.h"
#include "init.h"
#include "menu.h"

// Global
LEDlamp led1;
LEDlamp led2;
LEDlamp led3;

char* CLEARDISPLAY = "\n\n\n\n\n\n\n\n\n\n";
char* APPHELP = "\n -APP HELP- \r\nThis is a demo app using USART to illuminate an LED.\r\n"
                "The LED can also be toggled by pressing the onboard default Button.\r\n";

/*
 * Write a string to the USART bus
 */
void USART_write_string(char* charString){
    for(int a = 0; a<strlen(charString);a++ ) {
        USART_write(charString[a]);
    }
}

/*
 * read from the USART bus
 */
char USART_read(void){
    while(!(USART2->SR & RXNE)){}
    return USART2->DR;
}

/*
 * write a character to the USART bus
 */
void USART_write(int ch){
    while(!(USART2->SR & TXE)){}
    USART2->DR = (ch & 0xFF);
}

/*
 * LED ON PA5
 */
void statusLED(int onoff){
    if(onoff==ON) {
        // Devboard example has ONLY 1 test LED but imagine more LEDs can be tied to an LED object...
        GPIOA->BSRR |= 0x0020;       // LED on
        led1.ledstate = ON;
    }else{
        GPIOA->BSRR |= 0x0020 << 16; // LED off
        led1.ledstate = OFF;
    }
}

/*
 * Main function
 */
int main(void){
    RCC_init();
    GPIO_init();
    USART_init();
    char c;

    // object to hold status of LED ~led1
    led1.GPIO = 1;  // LD1
    led1.ledstate = OFF;
    led1.location = malloc(8*sizeof(char));
    strcpy(led1.location, "Kitchen");

    // object to hold status of LED ~led2
    led2.GPIO = 2;  // LD1
    led2.ledstate = OFF;
    led2.location = malloc(8*sizeof(char));
    strcpy(led2.location, "Bedroom");

    // object to hold status of LED ~led3
    led3.GPIO = 3;  // LD1
    led3.ledstate = OFF;
    led3.location = malloc(8*sizeof(char));
    strcpy(led3.location, "Porch");


    int APPisOn = ON;

    //print initial menu as app starts
    USART_write_string(printMenu());

    // Super loop
    while(APPisOn){
        c = USART_read();
        //USART_write(c); // loopback for debugging

        // turn LED ON
        if(c == '1') {
            statusLED(ON);
        }

        // 0 turn LED OFF
        if(c =='0') {
            statusLED(OFF);
        }

        // Spacebar, q or h displays the menu!
        if(c == 32) {
            // turn LED off as default
            statusLED(OFF);
            USART_write_string(printMenu());
        }

        // h displays the app help
        if((c == 'h')||(c=='H')) {
            // turn LED off as default
            statusLED(OFF);
            USART_write_string(APPHELP);
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
            statusLED(OFF);
            USART_write_string(CLEARDISPLAY);
        }

        // quit app, press esc button
        if((c == 27) || ((c == 'q')||(c=='Q'))){
            APPisOn = OFF;
            USART_write_string("\nAPP SHUTDOWN\n\n");
        }
    }
}