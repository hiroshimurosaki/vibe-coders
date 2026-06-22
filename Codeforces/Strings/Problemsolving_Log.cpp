/*
 * Problemsolving Log — Codeforces 1914A  (rating 800)
 * https://codeforces.com/problemset/problem/1914/A
 * Tags: implementation, strings
 */
#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        string s;
        cin >> s;

        vector<int> occ(26,0);
        for(auto c: s) occ[c-'A']++;

        int ans=0;
        for(int i=0;i<26;i++){
            if(occ[i] >= i+1) ans++;
        }

        cout << ans << endl;

    }


    return 0;

}