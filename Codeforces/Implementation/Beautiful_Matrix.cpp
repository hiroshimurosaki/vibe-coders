/*
 * Beautiful Matrix — Codeforces 263A  (rating 800)
 * https://codeforces.com/problemset/problem/263/A
 * Tags: implementation
 */
#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int linha, coluna, val;

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin >> val;
            if(val){
                linha = i;
                coluna = j;
            }
        }
    }

    cout << abs(coluna-2) + abs(linha-2) << endl;

    return 0;
    
}