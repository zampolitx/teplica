#ifndef UV_SPOTLIGHT_MAIN_H
#define UV_SPOTLIGHT_MAIN_H
#include <xc.h>

#define _XTAL_FREQ 10000000

#define buttom1 RB4             // Левая кнока Start
#define buttom2 RB5             // Правая кнопка Stop
#define RS RC7
#define EN RC6
#define D4 RC5
#define D5 RC4
#define D6 RC0
#define D7 RC1
#define relay RC2               // Выход исполнительного реле, включающего светодиоды

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#endif /* UV_SPOTLIGHT_MAIN_H */
