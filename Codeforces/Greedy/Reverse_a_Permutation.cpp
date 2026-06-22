/*
 * Reverse a Permutation — Codeforces 2193B  (rating 800)
 * https://codeforces.com/problemset/problem/2193/B
 * Tags: greedy
 */
#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;

    cin >> t;

    while(t--){

        int n;
        cin >> n;

        vector<int> vet(n);

        for(int i=0;i<n;i++) cin >> vet[i];

        int i;
        for(i=0;i<n && vet[i] == n-i;i++);
        
        if(i==n){
            for(auto x:vet) cout << x << " ";
            cout << endl;
            continue;
        }

        int j;
        for(j=i;j<n && vet[j] != n-i;j++);

        for(int x=0; x<i;x++) cout << vet[x] << " ";
        for(int x=j;x>=i;x--) cout << vet[x] << " ";
        for(int x=j+1;x<n;x++) cout << vet[x] << " ";
        cout << endl;

    }

    return 0;
    
}