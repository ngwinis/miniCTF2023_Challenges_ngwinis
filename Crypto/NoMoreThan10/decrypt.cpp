#include<bits/stdc++.h>
using namespace std;

char alphabeta[30], alphabetA[30];
int idxa[30], idxA[30];
void ktao(){
    char ca = 'a', cA = 'A';
    int i;
    // gán bảng chữ cái viết hoa và viết thường
    for(i = 0; i < 26; i++){
        alphabeta[i] = ca++;
        alphabetA[i] = cA++;
    }
    i = 0;

    // gán vị trí của chữ cái trong bảng chữ cái
    for(char ia = 'a', iA = 'A'; ia <= 'z', iA <= 'Z'; ia++, iA++){
        idxa[ia] = i;
        idxA[iA] = i;
        i++;
    }
}

int main(){
    ktao();
    char mess[100] = "ciniCTF{C4n_E0u_Wh1t3_Me_C0rh3ct_C3ss493?}";
    int times[] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 1, 0, 0, 2, 0, 0, 1, 0, 0, 1, 0, 0};
    int j = 0;
    cout << "flag: ";
    for(int i = 0; i < strlen(mess); i++){
        if(mess[i] >= 'a' && mess[i] <= 'z'){
            mess[i] = alphabeta[idxa[mess[i]] + 10*times[j]];
            j++;
        }
        if(mess[i] >= 'A' && mess[i] <= 'Z'){
            mess[i] = alphabetA[idxA[mess[i]] + 10*times[j]];
            j++;
        }
    }
    cout << mess << endl;
    return 0;
}