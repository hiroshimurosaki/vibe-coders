/*
 * Equal Values — Codeforces 2111C  (rating 1100)
 * https://codeforces.com/problemset/problem/2111/C
 * Tags: brute force, greedy, two pointers
 */
#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){

        int n;
        cin >> n;
        vector<long long> numeros(n);

        for(auto &x:numeros) cin >> x;
        
        long i = 0;
        long long anti = 0;
        long long menor = LLONG_MAX;
        while(i<n){
            if(i+1<n && numeros[i+1] == numeros[i]){
                i++;
            } else {
                menor = min(((anti-1)*numeros[i] +(n-i)*numeros[i]), menor);
                i++;
                anti = i;
            }
        }

        cout << menor << endl;

    }
    return 0;
}