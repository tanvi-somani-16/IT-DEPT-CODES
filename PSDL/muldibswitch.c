/*
 * File:   newmain.c
 * Author: Hp
 *
 * Created on April 29, 2024, 10:50 PM
 */


#include <xc.h>
#include<pic18f458.h>
void main(void) {
    unsigned int mul,div;
    int choice=1;
    
    switch(choice){
        case 0:
            mul=0x05*0x03;
            TRISD=0x00;
            PORTD=mul;
            break;
        case 1:
            div=0x0A/0x02;
            TRISB=0x00;
            PORTB=div;
            break;
    }
    return;
}
