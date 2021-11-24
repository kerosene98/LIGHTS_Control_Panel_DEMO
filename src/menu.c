/*
 * MENU text
 */

#include "menu.h"

/*
 * Hard coded main menu of options to control app
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
                 " esc, q or Q  - \tQuit\r\n"
                 "\r\n"
                 "\r\n";
    return menu;
}

char* CLEARDISPLAY(void){
    char *output = "\n\n\n\n\n\n\n\n\n\n";
    return output;
}

char* APPHELP(void){
    char *output = "\n -APP HELP- \r\nThis is a demo app using USART to illuminate an LED.\r\n"
                   "The LED can also be toggled by pressing the onboard default Button.\r\n";
    return output;
}