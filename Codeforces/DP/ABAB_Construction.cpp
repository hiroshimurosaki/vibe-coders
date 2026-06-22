/*
 * ABAB Construction — Codeforces 2202B  (rating 1200)
 * https://codeforces.com/problemset/problem/2202/B
 * Tags: dp, greedy, implementation
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

        // Se for impar a primeira letra semre vai ser 'a'
        if(n%2 && s[0] == 'b'){
            cout << "NO" << endl;
            continue;
        }

        int i = (n%2) ? 2 : 1;
        bool flag = true;
        for(;i<s.size();i+=2){
            if(s[i]==s[i-1] && s[i]!= '?'){
                cout << "NO" << endl;
                flag = false;
                break;
            }
        }
        if(flag) cout << "YES" << endl;
        

    }

    return 0;
}