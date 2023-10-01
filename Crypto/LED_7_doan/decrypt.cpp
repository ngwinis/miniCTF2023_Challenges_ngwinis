#include<bits/stdc++.h>
using namespace std;

char led_to_int(char *s){
    if(strcmp(s, "ABCDEF") == 0)
        return '0';
    if(strcmp(s, "AB") == 0)
        return '1';
    if(strcmp(s, "ABDEG") == 0)
        return '2';
    if(strcmp(s, "ABCDG") == 0)
        return '3';
    if(strcmp(s, "BCFG") == 0)
        return '4';
    if(strcmp(s, "ACDFG") == 0)
        return '5';
    if(strcmp(s, "ACDEFG") == 0)
        return '6';
    if(strcmp(s, "ABC") == 0)
        return '7';
    if(strcmp(s, "ABCDEFG") == 0)
        return '8';
    if(strcmp(s, "ABCDFG") == 0)
        return '9';
    if(strcmp(s, "ABCEFG") == 0)
        return 'A';
    if(strcmp(s, "CDEFG") == 0)
        return 'B';
    if(strcmp(s, "ADEF") == 0)
        return 'C';
    if(strcmp(s, "BCDEG") == 0)
        return 'D';
    if(strcmp(s, "ADEFG") == 0)
        return 'E';
    if(strcmp(s, "AEFG") == 0)
        return 'F';
}

int hex_to_dec(string hex)
{
    int len = hex.size();
    int base = 1;
    int dec = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            dec += (hex[i] - '0') * base;
            base *= 16;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F') {
            dec += (int(hex[i]) - 55) * base;
            base *= 16;
        }
    }
    return dec;
}

void decrypt(string s){
    stringstream ss(s);
    char *word;
    string hex = "";
    while(ss >> word){
        hex += led_to_int(word);
    }
    cout << (char)hex_to_dec(hex);
}

int main(){
    string s[100] = {"ACDEFG BCDEG", "ACDEFG ABCDFG", "ACDEFG ADEFG", "ACDEFG ABCDFG", "BCFG ABCDG", "ACDFG BCFG", "BCFG ACDEFG", "ABC CDEFG", "ABCDG ABC", "ABDEG BCDEG", "ABC ABCDG", "ACDEFG ACDFG", "ACDEFG ABC", "ACDEFG BCDEG", "ACDEFG ACDFG", "ACDEFG ADEFG", "ABC BCFG", "ACDFG AEFG", "ACDEFG BCFG", "ACDEFG ABCDFG", "ABC ABCDG", "ABC ABCDEF", "ACDEFG ADEF", "ACDEFG AB", "ABC ABCDFG", "ACDFG AEFG", "ACDEFG ABCDFG", "ABC ABCDG", "ACDFG AEFG", "ACDEFG ACDEFG", "ABC ACDFG", "ACDEFG ADEFG", "ABC BCDEG"};
    // cout << s[0] << "\n";
    for(int i = 0; i < 33; i++){
        decrypt(s[i]);
    }
    return 0;
}