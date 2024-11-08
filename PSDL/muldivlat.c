/*
 * File:   newmain.c
 * Author: Hp
 *
 * Created on April 30, 2024, 7:35 AM
 */


#include <xc.h>
#include<pic18f458.h>
void main(void) {
    unsigned int mul,div;
    TRISAbits.TRISA1=1;
    int choice=LATAbits.LATA1;
    
    if(choice==0){
        mul=0x08*0x02;
        TRISB=0x00;
        PORTB=mul;
    }
    else{
        div=0x08/0x02;
        TRISD=0x00;
        PORTD=div;
    }
}
