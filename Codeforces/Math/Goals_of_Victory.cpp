/*
 * Goals of Victory — Codeforces 1877A  (rating 800)
 * https://codeforces.com/problemset/problem/1877/A
 * Tags: math
 */
#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;

    cin >> t;

    while(t--){

        int n,temp, acc =0;
        cin >> n;

        for(int i=0;i<n-1;i++){ 
            cin >> temp;
            acc += temp;
        }

        cout << -acc << endl;

    }

    return 0;
    
}