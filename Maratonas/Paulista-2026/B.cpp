#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){

    ll n, c ,k;
    cin >> n >> c >> k;

    vector<ll> tickets(n);
    for(auto &x: tickets) cin >> x;

    ll inicio=0;
    ll custo=0;

    for(int i=1;i<n;i++){
        ll intervalo = tickets[i] - tickets[inicio] + 1;
        if(intervalo*c >  k){
            custo+=(tickets[i-1]-tickets[inicio]+1)*c + k;
            inicio = i;
        }
    }
    
    custo += (tickets[n-1] - tickets[inicio]+1)*c + k;

    cout << custo << endl;


    return 0;

}
