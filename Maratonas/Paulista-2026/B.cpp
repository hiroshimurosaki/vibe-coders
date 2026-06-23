/*
PROBLEMA B - Metro ticket 
Link do enunciado do Problema: https://codeforces.com/gym/106598/problem/B

Abordagem:
Basicamente só compensa a gente extender a duração do ticket enquanto:

    -> intervalo*c < k+c

por outro lado, compensa mais comprar outro ticket.

*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){

    ll n, c ,k;
    cin >> n >> c >> k;

    vector<ll> tickets(n);
    for(auto &x: tickets) cin >> x;

    ll inicio=0; // Posição do útimo dia em que se comprou o ticket
    ll custo=k+c; // Custo de comprar o primeiro ticket ( já que N é pelomenos 1)

    for(int i=1;i<n;i++){
        ll intervalo = tickets[i] - tickets[inicio]; // Calcula tamanho do intervalo atual
        if(intervalo * c < k+c) { 
            custo += (tickets[i]-tickets[inicio]) *c;
            inicio = i;
        }
        else {
            custo += (k+c);
            inicio = i;
        }
    }

    cout << custo << endl;

    return 0;

}
