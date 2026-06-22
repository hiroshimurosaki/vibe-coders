/*
 * Helmets in Night Light — Codeforces 1876A  (rating 1000)
 * https://codeforces.com/problemset/problem/1876/A
 * Tags: greedy, sortings
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool comparar(pair<int,int> a, pair<int,int>b){
    if(a.first != b.first) return a.first < b.first;
    return a.second > b.second; 
}

int main(){

    int t;

    cin >> t;

    while(t--){

        ll n, p;
        vector<pair<ll,ll>> vet;

        cin >> n >> p;

        vet.resize(n);

        for(int i=0;i<n;i++) cin >> vet[i].second;
        for(int i=0;i<n;i++) cin >> vet[i].first;
        
        sort(vet.begin(),vet.end(), comparar);

        ll to_be_notified = n-1, cost = p;

        for(auto x: vet){
            if(to_be_notified == 0) break;
            if(x.first>=p) break;

            ll aux = min(to_be_notified, x.second);
            to_be_notified -= aux;
            cost += aux*x.first;
        }
        
        cost += p*to_be_notified;

        cout << cost << endl;

    }

    return 0;
    
}