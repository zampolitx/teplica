#include <xc.h>
#include "teplica_main.h"
#include <stdio.h>
#include <stdlib.h>
#include "LCD.h"
#include "onewire.h"
#include <math.h>
#include <float.h>

int nastr = 0;
int temp = 0;
unsigned char ml_byte;
unsigned char st_byte;
unsigned int result=0;
char rejim1[] = "proverka";
int temp_drob;
int sign;
int temp2;

int one_wire(void){
    ow_reset();
    ow_write_byte(0xCC);
    ow_write_byte(0x44);
    __delay_ms(100);
    ow_reset();
    ow_write_byte(0xCC);
    ow_write_byte(0xBE);
    ml_byte = ow_read_byte();
    st_byte = ow_read_byte();
    temp_drob = ml_byte & 0b00001111;           //Записываем дробную часть в отдельную переменную
    temp_drob = ((temp_drob*6)+2)/10;         //Переводим в нужное дробное число
    ml_byte >>= 4;
    sign = st_byte & 0x80;                      //определяем знак температуры
    st_byte <<= 4;
    st_byte &= 0b01110000;
    st_byte |= ml_byte;                           //помещаем все в одну переменную

    if (sign) {                               //если минус
                result = 127-st_byte;      //глобальная переменная
                temp_drob = 10 - temp_drob;   //глобальная переменная
              }   
    else result = st_byte;
    return result;
}

void my_lcd(result, temp) {
    char s[20];
    char b[20];
    Lcd_Set_Cursor(1,1);
    Lcd_Write_String(b);
    sprintf(b, "N: %d", temp);
    Lcd_Set_Cursor(2,1);
    Lcd_Write_String(s);
    sprintf(s, "Temperatura: %d", result);    
    
}



void main(void) {
    TRISA = 0b00000;
    TRISC = 0b00000000; //Initialization PORTC all in out
    TRISB = 0b11111101; //Initialization PORTB RB1 OUT;
    Lcd_Init();
    Lcd_Clear();
        
    
    while(1){    
        
        result = one_wire();
        my_lcd(result, temp);
        PORTCbits.RC2=0;
        __delay_ms(200);
        PORTCbits.RC2=1;
        __delay_ms(100);
    }

    return;
}


