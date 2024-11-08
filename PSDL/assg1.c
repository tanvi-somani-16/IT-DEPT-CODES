/*
 * File:   newmain.c
 * Author: Hp
 *
 * Created on April 26, 2024, 12:10 AM
 */


#include <xc.h>
#include<pic18f458.h>

void main(void) {
    unsigned int add,sub;
    int choice=1;
    
    switch(choice){
        case 0:
            add=0x06+0x03;
            TRISD=0x00;
            PORTD=add;
            break;
        case 1:
            sub=0x09-0x06;
            TRISB=0x00;
            PORTB=sub;
            break;
    }
    return;
}
