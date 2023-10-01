#include <bits/stdc++.h>
using namespace std;

void reverse(char s[]){
    int len = strlen(s);
    for(int i = 0; i < len/2; i++){
        swap(s[i], s[len-i-1]);
    }
}

// xâu nhị phân của từng ký tự bị đảo ngược
void chr_to_bin(int n, char bin[]){
    int i = 0;
    while(n != 0){
        bin[i++] = (char)(n%2 + '0');
        n /= 2;
    }
    while(i < 8){
        bin[i++] = '0';
    }
    bin[i] = '\0';
}

void str_to_bin(char str[], char bin[]){
    for(int i = 0; i < strlen(str); i++){
        char s[10];

        // chuyển từng ký tự sang hệ nhị phân
        chr_to_bin((int)str[i], s);

        // ghép 8 bit nhị phân của từng ký tự vào xâu bin
        strcat(bin, s);
    }
}

int main()
{
    char flag[] = "miniCTF{B1n4ry_4ga1n_R19ht?}";

    // reverse flag để đảo ngược toàn bộ bit nhị phân
    reverse(flag);

    // chuyển chuỗi flag đã đảo ngược sang hệ nhị phân
    char s[1000] = "";
    str_to_bin(flag, s);
    cout << s << endl;

    // sinh ngẫu nhiên 2 số nguyên lớn sao cho mỗi chữ số của num1 cộng chữ số tương ứng của num2 có kết quả số dư đúng với dãy nhị phân bị đảo ngược
    srand((int)time(0));
    int len = strlen(s);
    int num1[1000], num2[1000];
    for(int i = 0; i < len; i++){
        num1[i] = 1 + rand()%9;
        if(s[i] == '0'){
            num2[i] = rand()%(10 - num1[i]);
        }
        if(s[i] == '1'){
            num2[i] = 10 - num1[i] + rand()%num1[i];
        }
    }
    cout << "n1 = ";
    for(int i = 0; i < len; i++)
        cout << num1[i];
    cout << endl << "n2 = ";
    for(int i = 0; i < len; i++)
        cout << num2[i];
    cout << endl;
    return 0;
}