#include "onewire.h"
#include <xc.h>

char ow_reset(){
    OWOUT;
    __delay_us(480);
    OWIN;
    __delay_us(70);
    short response=(OWPIN==0);
    __delay_us(410);
    return response;
}
void ow_write_bit(char b){
    OWOUT;
    if(b){
        __delay_us(6);
        OWIN;
        __delay_us(64);
    }
    else{
        __delay_us(60);
        OWIN;
        __delay_us(10);
    }
}
char ow_read_bit(){
    OWOUT;
    __delay_us(6);
    OWIN;
    __delay_us(9);
    char response=OWPIN;
    __delay_us(55);
    return response;
}
char ow_read_byte(){
    char c,r = 0;
    for(c=0; c<8;c++){
        if(ow_read_bit()){
            r |=1 << c;
        }
    }
    return r;
}

void ow_write_byte(char B){
    char c;
    for(c=0;c<8;c++){
        ow_write_bit((B>>c)&1);
    }
}