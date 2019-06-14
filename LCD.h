// Прототипы функций, указанных в файле LCD.c
#ifndef LCD_H
#define LCD_H
#include <xc.h>
#include "teplica_main.h"
void Lcd_Port(char a);
void Lcd_Cmd(char a);
Lcd_Clear();
void Lcd_Set_Cursor(char a, char b);
void Lcd_Init();
void Lcd_Write_Char(char a);
void Lcd_Write_String(char *a);
void Lcd_Shift_Right();
void Lcd_Shift_Left();


#endif /* UV_SPOTLIGHT_MAIN_H */
