#include<bits/stdc++.h>
using namespace std;

void reverse(char s[]){
    int len = strlen(s);
    for(int i = 0; i < len/2; i++){
        swap(s[i], s[len-i-1]);
    }
}

void bin_carry(char n1[], char n2[], char bin[]){
    int i = strlen(n1) - 1;
    int j = 0;
    for(; i >= 0; i--){
        bin[j++] = (char)((int)(n1[i]-'0' + n2[i]-'0') / 10 + '0');
    }
    bin[j] = '\0';
}

void bin_to_str(char bin[], char str[]){
    int n = 7, j = 0;
    int ascii = 0;
    for(int i = 0; i < strlen(bin); i++){
        if(n == -1){
            n = 7;
            str[j++] = (char)ascii;
            ascii = 0;
        }
        ascii += pow(2,n) * (int)(bin[i] - '0');
        n--;
    }
    str[j++] = (char)ascii;
    str[j] = '\0';
}

int main(){
    // xâu n1 và n2 được sinh ngẫu nhiên bởi file encrypt.cpp
    char n1[] = "39981494423198321557627355135585942112296963619788171836271727721825588247685336782986746484212291785812517752282772323989463758314744218414394135622281967121696598423913399424937265468681141884166513913821948397441682249143";
    char n2[] = "70779730688983068091988004880740340999307036690018029093889380372988078380305721306006426885298306717832698360818108899019419661438069701899167193308910041573607902789019900282025273718414649091372992097669548005389397960965";
    int len = strlen(n1);

    // xâu chứa số nhớ (ở hệ nhị phân)
    char bin[len+5];
    bin_carry(n1, n2, bin);
    cout << bin << endl;

    // flag được chuyển từ hệ nhị phân sang xâu ký tự (cứ 8 bit nhị phân sinh ra 1 ký tự)
    char flag[1000];
    bin_to_str(bin, flag);
    cout << flag << endl;
    return 0;
}