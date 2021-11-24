#include "menu.h"

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