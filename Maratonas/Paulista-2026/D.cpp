/*
PROBLEMA D - Desenhando SP 
Link do enunciado do Problema: https://codeforces.com/gym/106598/problem/D

Abordagem: 
Encontrar padrões matemáticos para descrever o desenho do estado de São Paulo
*/

#include <bits/stdc++.h>

using namespace std;
int main(){

    int n;
    cin >> n;

    int linha_size= 6+4*(n-1);

    // Primeira linha
    for(int i=0;i<2*n+1;i++) {
        if(i > n-1 && i <= 2*n) cout << '_';
        else cout << ' ';
    }
    cout << endl;
   
    // Padrão da parte superior
    for(int j=1;j<=n;j++){
        for(int i=0;i<linha_size;i++) {
            if(i == n-j) cout << '/';
            else if(i == 2*n+j) { 
                cout << '\\';
                if(j!=n) break;
            }
            else if(j==n && (0 < i && i <= n || i > 2*n+j)) cout << '_';
            else cout << ' ';
        }
        cout << endl;
    }

    // Padrão do restante
    for(int j=1;j<=n;j++){
        for(int i=0;i<linha_size;i++) {
            if(i == n+j) cout << '\\';
            else if(i == linha_size-j){
                cout << '/';
                break;
            }
            else if(j==n && (n+j < i && i < linha_size-j)) cout << '_';
            else cout << ' ';
        }
        cout << endl;
    }
        
    return 0;
}