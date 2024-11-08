/*
 * File:   newmain.c
 * Author: Hp
 *
 * Created on May 3, 2024, 1:20 PM
 */


#include <xc.h>
#include<pic18f4550.h>

void msdelay(unsigned int time){
    unsigned int i,j;
    for(i=0;i<time;i++){
        for(j=0;j<710;j++);
    }
}

void main(void) {
    TRISCbits.TRISC2=0;         //set RC2 as output to control CCP1 module
    LATCbits.LATC2=0;           //high all pins of RC2
    TRISCbits.TRISC6=0;         //set RC6 as output to control motor
    TRISCbits.TRISC7=0;         //set RC7 as output to control motor
    
    PR2=0xBA;                   //set pwm freq to 4KHz
    CCP1CON=0x0C;               //set CCP1 module in pwm mode
    T2CON=0x07;                 //configures timer 2 
    
    PORTCbits.RC6=1;            //turn on motor
    PORTCbits.RC7=0;            //turn of motor
    
    while(1){
        //-----duty cycle 80%----
        CCP1CONbits.DC1B0=0;
        CCP1CONbits.DC1B1=0;
        CCPR1L=0x96;
        msdelay(2000);
        
        //----duty cycle 60%----
        CCP1CONbits.DC1B0=0;
        CCP1CONbits.DC1B1=1;
        CCPR1L=0x70;
        msdelay(2000);
        
        //----duty cycle 40%----
        CCP1CONbits.DC1B0=0;
        CCP1CONbits.DC1B1=0;
        CCPR1L=0x4B;
        msdelay(2000);
        
        //----duty cycle 20%----
        CCP1CONbits.DC1B0=0;
        CCP1CONbits.DC1B1=1;
        CCPR1L=0x25;
        msdelay(2000);
    }
}
