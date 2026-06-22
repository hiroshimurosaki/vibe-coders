/*
 * Convergence — Codeforces 2232A  (rating 800)
 * https://codeforces.com/problemset/problem/2232/A
 * Tags: greedy, sortings
 */
#include <bits/stdc++.h>

using namespace std; 

int main() {

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;
        vector<long long> amigos(n);
        for(auto &a: amigos) cin >> a;

        sort(amigos.begin(),amigos.end());

        int l=0, r=n-1;
        int count=0;
        while(l<r){
            if(amigos[l++]!=amigos[r--]) count++;
            else break;
        }

        cout << count << endl;

    }

    return 0;

}