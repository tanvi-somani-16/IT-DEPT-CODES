/*
 * File:   newmain.c
 * Author: Hp
 *
 * Created on May 2, 2024, 11:47 PM
 */


#include <xc.h>
#include<pic18f4550.h>

void delay(unsigned int time){
    unsigned int i,j;
    for(i=0;i<time;i++){
        for(j=0;j<5000;j++);
    }
}
void main(void) {
    TRISB=0x00; //setting PORTB as output port
    LATB=0xFF;  //setting all pins of PORTB as HIGH
    
    while(1){
        LATB=~LATB; //toggle LATB 
        delay(200);
    }
    return;
}
