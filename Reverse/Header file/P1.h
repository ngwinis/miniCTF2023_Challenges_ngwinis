#include<stdio.h>
void sub3(int a[]){
    for(int i = 0; i < 15; i++){
        printf("%c", a[i] + (i+1)*(i+1));
    }
}