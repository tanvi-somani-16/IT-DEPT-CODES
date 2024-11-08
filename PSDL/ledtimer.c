/*
 * File:   newmain.c
 * Author: Hp
 *
 * Created on May 3, 2024, 10:53 AM
 */


#include <pic18f4550.h>
#include<xc.h>
void msdelay(){
    T0CON=0x03;  // Configure Timer0
    TMR0H=0x6F;  // Load Timer0 with initial value for desired delay
    TMR0L=0x82;
    T0CONbits.TMR0ON=1;  // Start Timer0
   
    // Wait until Timer0 overflows
    while(INTCONbits.TMR0IF==0);
   
    // Delay complete, clear Timer0 and interrupt flag
    T0CONbits.TMR0ON=0;
    INTCONbits.TMR0IF=0;
}

void main(void){
    TRISB=0x00;
    PORTB=0x00;
    while(1){
        PORTB=~PORTB;
        msdelay();
    }
}