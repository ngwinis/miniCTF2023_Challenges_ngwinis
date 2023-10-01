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
    // In ra bảng chữ cái để dễ đối chiếu
    cout << "==============================\n";
    cout << "Bang chu cai:\n";
    for(int i = 0; i < 26; i++){
        if(i % 10 == 0)
            cout << " ";
        cout << alphabeta[i];
    }
    cout << endl;
    for(int i = 0; i < 26; i++){
        if(i % 10 == 0)
            cout << " ";
        cout << i%10;
    }
    cout << endl;
    for(int i = 0; i < 26; i++){
        if(i % 10 == 0)
            cout << " ";
        cout << alphabetA[i];
    }
    cout << endl;
    cout << "==============================\n";
    cout << "\necrypted flag: ";
    
    // Mã hóa flag
    char flag[100] = "miniCTF{C4n_Y0u_Wr1t3_My_C0rr3ct_M3ss493?}";
    int j = 0;
    for(int i = 0; i < strlen(flag); i++){
        if(flag[i] >= 'a' && flag[i] <= 'z'){
            if(j % 3 == 0){
                flag[i] = alphabeta[idxa[flag[i]] % 10]; // kí tự flag[i] được mã hóa bằng kí tự tại vị trí [vị trí của nó trong bảng chữ cái % 10]
            }
            j++;
        }
        if(flag[i] >= 'A' && flag[i] <= 'Z'){
            if(j % 3 == 0){
                flag[i] = alphabetA[idxA[flag[i]] % 10];
            }
            j++;
        }
    }
    cout << flag << endl;
    return 0;
}