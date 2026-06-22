/*
 * The Man who became a God  — Codeforces 1847A  (rating 800)
 * https://codeforces.com/problemset/problem/1847/A
 * Tags: greedy, sortings
 */
#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;

    cin >> t;

    while(t--){

        int n, k;
        cin >> n >> k;
        vector<int> numeros(n);
        vector<int> f(n-1);
        int forca = 0;

        for(int i = 0; i<n; i++){

            cin >> numeros[i];
            if(i>0){
                f[i-1] = abs(numeros[i] - numeros[i-1]);
            }
        }

        sort(f.begin(), f.end());

        for(int i=0; i<n-k; i++){
            forca += f[i];
        }

        cout << forca << endl;


    }

    return 0;



}