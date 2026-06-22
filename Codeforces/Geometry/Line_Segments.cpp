/*
 * Line Segments — Codeforces 2119B  (rating 1200)
 * https://codeforces.com/problemset/problem/2119/B
 * Tags: geometry, greedy, math
 */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    int t;

    cin >> t; 
    while(t--){

        ll len_a,px,py,qx,qy,sum=0, maior=0;
        
        cin >> len_a;
        
        cin >> px >> py >> qx >> qy;

        for(int i=0;i<len_a;i++){
            ll a;
            cin >> a;
            sum+=a;
            maior = max(maior,a);
        }

        long double dist = sqrt((long double)((px-qx)*(px-qx)) + (long double)((py-qy)*(py-qy)));

        if(dist >= maior - (sum - maior) && dist <= sum) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
    
}