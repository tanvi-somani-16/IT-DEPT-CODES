/*
 * File:   newmain.c
 * Author: Hp
 *
 * Created on April 30, 2024, 9:39 AM
 */


#include <xc.h>
#include<pic18f458.h>
void main(void) {
    int arr[6]={10,25,4,14,1,8};
    int choice=1;
    
    if(choice==0){
            for(int i=0;i<5;i++){
                for(int j=0;j<5-i;j++){
                    if(arr[j]>arr[j+1]){
                        int temp=arr[j];
                        arr[j]=arr[j+1];
                        arr[j+1]=temp;
                    }
                }
            }
    }
    else{
            for(int i=0;i<5;i++){
                for(int j=0;j<5-i;j++){
                    if(arr[j]<arr[j+1]){
                        int temp=arr[j];
                        arr[j]=arr[j+1];
                        arr[j+1]=temp;
                    }
                }
            }
    }
}
    
