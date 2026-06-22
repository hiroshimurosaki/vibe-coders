/*
 * Tatar TV Show — Codeforces 2236B  (rating 800)
 * https://codeforces.com/problemset/problem/2236/B
 * Tags: greedy, math, strings
 */
#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<bool> numeros(n);

        for(int i=0; i<n; i++){
            if(s[i] == '0'){
                numeros[i] = false;
            } else {
                numeros[i] = true;
            }
        }
        for(int i=0; i<n-k; i++){
            if(numeros[i]){
                numeros[i] = !numeros[i];
                numeros[i+k] = !numeros[i+k];
            }
        }
        bool flag = false;
        for(int i=n-k; i<n; i++){
            if(numeros[i]){
                cout << "NO" << endl;
                flag = true;
                break;
            }
        }
        if(!flag){
            cout << "YES" << endl;
        }
  


    }

    return 0;

}