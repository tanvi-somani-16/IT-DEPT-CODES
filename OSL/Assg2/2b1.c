#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[]){
    printf("\nIn child file\n");
    printf("Array in reverse order\n");
    for(int i = argc - 1; i > 0; i--){ // Start from argc - 1, skip argv[0]
        printf("%s\n", argv[i]);
    }
    return 0;
}

