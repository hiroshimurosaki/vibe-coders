/*
 * Next Round — Codeforces 158A  (rating 800)
 * https://codeforces.com/problemset/problem/158/A
 * Tags: *special, implementation
 */
#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, k;
    vector<int> finishers;

    cin >> n >> k;

    finishers.resize(n);

    for(int i=0;i<n;i++) cin >> finishers[i];

    int corte = finishers[k-1];
    
    int i;
    for(i=0;i<n && finishers[i]>=corte && finishers[i]; i++);

    cout << i << endl;


    return 0;
    
}