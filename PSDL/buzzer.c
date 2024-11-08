/*
 * File:   newmain.c
 * Author: Hp
 *
 * Created on May 3, 2024, 11:29 AM
 */


#include <xc.h>
#include<pic18f4550.h>
#define buzzer LATAbits.LATA5   //define buzzer pin
unsigned int count=0;
void __interrupt()Timer1_ISR()
{
    
    if(TMR1IF==1)
    {
        TMR1L=0x20;
        TMR1H=0xD1;
        count++;
        
        if(count>=1000)
        {
            buzzer=~buzzer; //toggles buzzer
            count=0;        //reset count
        }
        
        TMR1IF=0;           //reset timer 1 overflow flag
    }
}

void main(void)
{
    TRISB=0;                //set output PORT
    TRISAbits.TRISA5=0;     //setting buzzer pin RA5 as output
    GIE=1;                  //Enable Global Interrupt
    PEIE=1;                 //Enable Peripheral Interrupt
    TMR1IE=1;               //Enable Timer 1 overflow
    TMR1IF=0;
    
    T1CON=0x08;             //configures timer 1
    TMR1L=0x20;
    TMR1H=0xD1;
    
    while(1);
}
