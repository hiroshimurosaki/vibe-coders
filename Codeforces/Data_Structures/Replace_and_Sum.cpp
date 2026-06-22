/*
 * Replace and Sum — Codeforces 2193C  (rating 1000)
 * https://codeforces.com/problemset/problem/2193/C
 * Tags: data structures, greedy
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){

    int t;

    cin >> t;

    while(t--){

        int n, q;

        cin >> n >> q;

        vector<ll> vet(n);

        for(int i=0;i<n;i++) cin >> vet[i];
        ll aux;
        for(int i=0;i<n;i++){
            cin >> aux; 
            vet[i] = max(aux,vet[i]);
        }

        ll ml = vet[n-1];
        for(int i=n-2;i>=0;i--){
            if(vet[i] < ml) vet[i] = ml;
            else ml = vet[i];
        }

        vector<ll> presum(n+1);
        presum[0] = 0;
        for(int i=1;i<n+1;i++) presum[i] = presum[i-1] + vet[i-1];

        while(q--){
            int a, b;
            cin >> a >> b;
            cout << presum[b] - presum[a-1] << " "; 
        }
        cout << endl;

    }

    return 0;
    
}