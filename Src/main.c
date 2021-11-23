/*
 * This is a USART app that receives a cmd via the users keyboard to toggle on/off an LED.
 * @author David Gelkin <david.gelkin@gmail.com>
 */

#include "stm32f4xx.h"
#include "main.h"
#include "string.h"
#include "stdlib.h"

// Global
LEDlamp led1;
LEDlamp led2;
LEDlamp led3;

char* CLEARDISPLAY = "\n\n\n\n\n\n\n\n\n\n";
char* APPHELP = "\n -APP HELP- \r\nThis is a demo app using USART to illuminate an LED.\r\n"
                "The LED can also be toggled by pressing the onboard default Button.\r\n";

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
    // gpio AF PA2
    GPIOA->AFR[0] &= ~0x0F00;    // clear
    GPIOA->AFR[0] |= 0x7700;     // set AF7 function

    GPIOA->MODER &= ~0x0CF0;     // clear
    GPIOA->MODER |= 0x04A0;      // set to AF mode 10b PA2(Tx) PA3(Rx) & PA5(LED) as output 01b
}

int setBaud(int baud){
    float baudResult = 16000000/16*baud;
}

/*
 * Initialise the USART
 */
void USART_init(void){
    // Configure USART Baud
    USART2->BRR = 0x0683;        // set baud 9600
    USART2->CR1 = TE | RE;       // set TE & RE
    USART2->CR2 = 0x0000;
    USART2->CR3 = 0x0000;
    USART2->CR1 |= UE;       // Enable USART2
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
 * write to USART a single character
 */
void USART_write(int ch){
    while(!(USART2->SR & TXE)){}
        USART2->DR = (ch & 0xFF);
}

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
 * Hard coded menu of options to control app
 */
char* printMenu(void){
    char *menu = "\r\n------------------------------\r\n"
                 "*           MENU             *\r\n"
                 "------------------------------\r\n"
                 "    1    - \tLED ON in Kitchen\r\n"
                 "    0    - \tLED OFF in Kitchen\r\n"
                 "spacebar - \tDisplay this menu\r\n"
                 " h or H  - \tDisplay app help\r\n"
                 " s or S  - \tPrint status of LED\r\n"
                 "   c     - \tClear display with 10* line feeds\r\n"
                 "\r\n"
                 " esc, q 0r Q  - \tQuit\r\n"
                 "\r\n"
                 "\r\n";
    return menu;
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