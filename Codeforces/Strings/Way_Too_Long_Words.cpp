/*
 * Way Too Long Words — Codeforces 71A  (rating 800)
 * https://codeforces.com/problemset/problem/71/A
 * Tags: strings
 */
#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    string palavra;

    cin >> n;
    

    while(n--){

        cin >> palavra;

        if(palavra.length() <= 10){
            cout << palavra << endl;
        }
        else{
            cout << palavra[0] << palavra.length() - 2 << palavra[palavra.length()-1] << endl;
        }

    }

    return 0;
    
}