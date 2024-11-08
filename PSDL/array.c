/*
 * File:   newmain.c
 * Author: Hp
 *
 * Created on April 29, 2024, 4:30 PM
 */


#include <xc.h>
#include<pic18f458.h>

void main(void) {
    int a[]={2,4,6,8,10,12,14,16,18};
    unsigned int sum=0;
    for(int i=0;i<9;i++){
        sum=sum+a[i];
    }
    TRISD=0x00;
    PORTD=sum;
    
    return;
}
