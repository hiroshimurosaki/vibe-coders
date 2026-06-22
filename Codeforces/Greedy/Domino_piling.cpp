/*
 * Domino piling — Codeforces 50A  (rating 800)
 * https://codeforces.com/problemset/problem/50/A
 * Tags: greedy, math
 */
#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,m;

    cin >> n >> m;

    if(n < m) swap(n,m);

    int ans = n/2 * m + (n%2)*(m/2) ;
    
    cout << ans << endl;

    return 0;
    
}