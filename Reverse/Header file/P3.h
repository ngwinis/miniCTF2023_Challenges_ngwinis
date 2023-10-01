#include<stdio.h>
void sub2(int a[], char key[]){
    for(int i = 0; i < 20; i++){
        printf("%c", a[i]/((int)key[i%7]));
    }
}