#include<stdio.h>
void sub1(int a[]){
    for(int i = 0; i < 12; i+=3){
        printf("%c", a[i]/3 - i - 1);
        printf("%c", a[i+1]/5 - i + 3);
        printf("%c", a[i+2] + i*i);
    }
}