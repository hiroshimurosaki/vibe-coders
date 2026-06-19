#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD_1 = 1e9+7;
const ll MOD_2 = 1e9+6;


ll exponenciar(ll a, ll b, ll MOD){

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

        ll a,b,c;
        cin >> a >> b >> c;
        
        cout << exponenciar(a,  exponenciar(b,c, MOD_2), MOD_1) << endl;

    }

    return 0;

}