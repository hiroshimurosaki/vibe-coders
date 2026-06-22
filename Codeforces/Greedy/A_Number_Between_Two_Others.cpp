/*
 * A Number Between Two Others — Codeforces 2225A  (rating 800)
 * https://codeforces.com/problemset/problem/2225/A
 * Tags: greedy, math
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){

    int t;
    cin >> t;

    ll x, y;
    for(int i = 0; i<t; i++){

        cin >> x >> y;
        
        ll k = y/x;
        k--;
        if(k!=1){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }

    return 0;



}