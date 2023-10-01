#include<bits/stdc++.h>
using namespace std;

void int_to_led(char n, char s[]){
    if(n == '0')
        strcpy(s, "ABCDEF");
    if(n == '1')
        strcpy(s, "BC");
    if(n == '2')
        strcpy(s, "ABDEG");
    if(n == '3')
        strcpy(s, "ABCDG");
    if(n == '4')
        strcpy(s, "BCFG");
    if(n == '5')
        strcpy(s, "ACDFG");
    if(n == '6')
        strcpy(s, "ACDEFG");
    if(n == '7')
        strcpy(s, "ABC");
    if(n == '8')
        strcpy(s, "ABCDEFG");
    if(n == '9')
        strcpy(s, "ABCDFG");
    if(n == 'A')
        strcpy(s, "ABCEFG");
    if(n == 'B')
        strcpy(s, "CDEFG");
    if(n == 'C')
        strcpy(s, "ADEF");
    if(n == 'D')
        strcpy(s, "BCDEG");
    if(n == 'E')
        strcpy(s, "ADEFG");
    if(n == 'F')
        strcpy(s, "AEFG");
}

string dec_to_hex(int n){
    string ans = "";
    while (n != 0){
        int r = 0;
        char ch;
        r = n % 16;
        if (r < 10) {
            ch = r + 48;
        }
        else {
            ch = r + 55;
        }
        ans += ch;
        n = n / 16;
    }
    int i = 0, j = ans.size() - 1;
    while(i <= j){
      swap(ans[i], ans[j]);
      i++;
      j--;
    }
    return ans;
}

int main(){
    char s[100];
    char flag[] = "miniCTF{7-segment_display_is_fun}";
    
    // đoạn code sinh ra ciphertext
    for(int i = 0; i < strlen(flag); i++){
        string str = dec_to_hex((int)(flag[i]));
        for(int j = 0; j < str.size(); j++){
            int_to_led(str[j], s);
            cout << s << " ";
        }
        cout << endl;
    }

    // đoạn code để sinh xâu s cho file "decrypt.cpp"
    // for(int i = 0; i < strlen(flag); i++){
    //     string str = dec_to_hex((int)(flag[i]));
    //     cout << "\"";
    //     for(int j = 0; j < str.size(); j++){
    //         int_to_led(str[j], s);
    //         if(j == str.size()-1){
    //             cout << s;
    //             continue;
    //         }
    //         cout << s << " ";
    //     }
    //     if(i == strlen(flag)-1){
    //         cout << "\"";
    //         continue;
    //     }
    //     cout << "\"" << ", ";
    // }
    // cout << "\nlength = " << strlen(flag);

    return 0;
}