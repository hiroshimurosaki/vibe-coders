#include <bits/stdc++.h>
typedef unsigned long long ll;
const ll MOD = 998244353;
using namespace std;


int main() {

    ll n,k;
    cin >> n >> k;

    n%=MOD;
    
    ll aux=n;
    for(int i=1; i<=k; i++){
       cout << aux << " ";
       aux = (aux*((n-i+MOD)%MOD))%MOD;
    }
    cout << endl;

    cout << (1ULL * 1755647 * (999999999))%MOD << endl;
    cout << (1ULL * 1755647 * (1755646))%MOD << endl;

    return 0;

}

