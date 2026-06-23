#include <bits/stdc++.h>

typedef long long ll;

const ll MOD = 1e9+7;

using namespace std;

int main(){

    ll n;
    cin >> n;
    vector<pair<char,ll>> op;
    char operacao;
    ll numero;

    ll multiplicacao = 1;
    ll soma = 0;

    ll res = 0;

    for(ll i=0;i<n;i++){
        cin >> operacao >> numero;
        if(operacao == '?'){
            cout << ((numero*multiplicacao)%MOD+soma)%MOD << endl;
        } else {
            if(operacao == '+'){
                soma = (soma+numero)%MOD;
            } else {
                soma = (soma*numero)%MOD;
                multiplicacao = (multiplicacao*numero)%MOD;
            }
        }


    }

    return 0;


}