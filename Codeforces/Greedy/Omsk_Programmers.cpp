/*
 * Omsk Programmers — Codeforces 2236C  (rating 1000)
 * https://codeforces.com/problemset/problem/2236/C
 * Tags: brute force, greedy, math
 */
#include <bits/stdc++.h>

using ll = long long;

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
        
        long long  a,b,x;
        cin >> a >> b >> x;

        int divs=0;
        long long minimo=abs(a-b);

        while(a!=b){

            if(b>a) swap(a,b);
            minimo = min(minimo,(a-b)+divs);
            a/=x;
            divs++;
            
        }
        
        minimo = min(minimo,(a-b)+divs);

        cout << minimo << endl;

    }

    return 0;

}