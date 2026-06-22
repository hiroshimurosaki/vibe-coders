/*
 * The Equalizer — Codeforces 2217A  (rating 800)
 * https://codeforces.com/problemset/problem/2217/A
 * Tags: math
 */
#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;

    cin >> t;

    while(t--){

        int n, k, sum=0;
        cin >> n >> k;

        for(int i=0;i<n;i++){
            int aux;
            cin >> aux;
            sum+=aux;
        }

        if(sum&1 || !(k*n&1)) {
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }

    }

    return 0;

}
