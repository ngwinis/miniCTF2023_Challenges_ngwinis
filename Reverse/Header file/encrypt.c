#include<stdio.h>
#include<string.h>
#include"P1.h"
#include"P2.h"
#include"P3.h"

int main(){
    char subflag1[] = "miniCTF{N0w_U_K";
    char subflag2[] = "n0w_H0w_T0_W";
    char subflag3[] = "r1t3_Ur_0wn_L1Br4ry}";
    char key[] = "ISPCLUB";
    printf("a3[] = {");
    for(int i = 0; i < 15; i++){
        printf("%d", (int)subflag1[i] - (i+1)*(i+1));
        if(i < 14)
            printf(", ");
    }
    printf("}\n");

    printf("a2[] = {");
    for(int i = 0; i < 12; i+=3){
        printf("%d, ", ((int)subflag2[i]+i+1)*3);
        printf("%d, ", ((int)subflag2[i+1]+i-3)*5);
        printf("%d", (int)subflag2[i+2] - i*i);
        if(i+2 < 11)
            printf(", ");
    }
    printf("}\n");

    printf("a1[] = {");
    for(int i = 0; i < 20; i++){
        printf("%d", (int)subflag3[i]*((int)key[i%7]));
        if(i < 19)
            printf(", ");
    }
    printf("}\n");
    return 0;
}