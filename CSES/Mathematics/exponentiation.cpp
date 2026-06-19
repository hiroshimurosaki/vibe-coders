#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;


ll exponenciar(ll a, ll b){

    ll ans = 1;
    while(b){
        if(b%2){
            ans = (ans*a)%MOD;
            b--;
        }
        else{
            a = (a*a)%MOD;
            b/=2;
        }
    }

    return ans;

}

int main(){

    int n;

    cin >> n;

    while(n--){

        ll a,b;
        cin >> a >> b;

        cout << exponenciar(a,b) << endl;

    }

    return 0;

}