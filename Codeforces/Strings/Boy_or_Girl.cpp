/*
 * Boy or Girl — Codeforces 236A  (rating 800)
 * https://codeforces.com/problemset/problem/236/A
 * Tags: brute force, implementation, strings
 */
#include <bits/stdc++.h>

using namespace std;

int main(){

    string word;
    vector<bool> letras(26,0);

    cin >> word;

    for(auto l:word) letras[l-'a']=true;

    int aux = 0;
    for(auto p:letras) if(p) aux++;

    cout << ((aux&1) ?  "IGNORE HIM!" : "CHAT WITH HER!") << endl;

    return 0;
    
}