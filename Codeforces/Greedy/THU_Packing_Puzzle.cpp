/*
 * THU Packing Puzzle — Codeforces 2216B  (rating 1300)
 * https://codeforces.com/problemset/problem/2216/B
 * Tags: greedy
 */
#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main(){

    ll teste;
    cin >> teste;
    for(ll i = 0; i< teste; i++){
        ll h, u ,t;
        ll ans = 0;
        cin >> t >> h >> u;
        ll menor;
        if(t>0 && u>0){
            menor = min(t,u);
            t -= menor;
            u -= menor;
            ans += menor * 4;
        }
        if(t>=2 && h>=1){
            menor = min(t/2, h);
            t -= menor*2;
            h -= menor;
            ans += menor * 7;
        }
        if(t>=1 && h>=1){
            menor = min(t, h);
            t -= menor;
            h -= menor;         
            ans += menor * 5;
        }
        if(t>=1){
            ans += t*2+1;
            t = 0;
        }
        ans += h * 3;
        ans += u * 3;
        
        cout << ans << endl;

    }
    

}