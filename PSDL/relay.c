/*
 * File:   newmain.c
 * Author: Hp
 *
 * Created on May 3, 2024, 12:11 PM
 */


#include <xc.h>
#include<pic18f4550.h>
#define relay_pin LATAbits.LATA4

void __interrupt() extint_isr(){
    unsigned int i;
    if(INT1F){
        INT1F=0;
        INT1IE=0;
        
        relay_pin=~relay_pin;
        for(i=0;i<10000;i++);   //small delay for debouncing
        
        INT1E=1;
    }
}

void main(void) {
    ADCON1=0x0F;    //set all pins to digital
    TRISBbits.TRISB1=1;
    TRISAbits.TRISA4=0;
    relay_pin=1;
    
    INT1IE=1;
    INTEDG1=0;
    GIE=1;
    
    while(1);
}
