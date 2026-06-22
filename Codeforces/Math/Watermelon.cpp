/*
 * Watermelon — Codeforces 4A  (rating 800)
 * https://codeforces.com/problemset/problem/4/A
 * Tags: brute force, math
 */
#include <bits/stdc++.h>

using namespace std;

int main(){

    int w;

    cin >> w;

    if(!(w&1) && w > 2) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;

}