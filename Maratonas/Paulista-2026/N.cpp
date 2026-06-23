/*
PROBLEMA N - Níveis de Reatividade 
Link do enunciado do Problema: https://codeforces.com/gym/106598/problem/N

Abordagem: 

Vamos considerar os valores das amostrar originais

    x1, x2, x3, x4, ..., xn

sendo x1 <= x2 <= x3 <= x4 <= ... <= xn.

Assim podemos concluir que:

S = x1 + x2 + x3 + x4 + ... + xn
M = xn

No vetor da entrada temos que os valores xi se transformariam nos seguintes valores:

x1 -> x2 + x3 + x4 + ... + xn    ( <= S )
x2 -> x1 + x3 + x4 + ... + xn    ( <= S )
x3 -> x1 + x2 + x4 + ... + xn    ( <= S  )
x4 -> x1 + x2 + x3 + x5 + ... + xn  ( <= S )
...
xn -> x1 + x2 + x3 + x5 + ... + x(n-1)  ( <= S )

ou seja, todos os valores seriam <= S.

Como S e M estariam nesse vetor final, se ordenarmos de forma decrescente S estaria na posição 0 do vetor.
Para encontrar M, basta somarmos todos os valores desse vetor (com exceção de S) que teríamos:

    Soma_final = (n-1)*x1 + (n-1)*x2 + (n-1)*x3 + (n-1)*x4  + ... + (n-1)*xn + M

Se colocarmos n-1 em evidência, temos:

    Soma_final = (n-1)*(x1 + x2 + x3 + x4 + ... + xn) + M => Soma_final = (n-1)*S + M

ou seja, se subtrairmos (n-1)*S da Soma_final, encontramos M.
Conhecendo S e M sabemos que não estarão na resposta das amostras iniciais.
Para encontrar os valores iniciais, basta subtrair cada elemento do vetor final (que não seja S e M), de S.
*/
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<ll> vet(n+2);
    for(auto &x: vet) cin >> x;

    sort(vet.rbegin(),vet.rend()); // Ordenamos em ordem decrescente

    ll original_sum = vet[0]; // Encontramos S
    ll sum = 0;
    for(int i=1;i<vet.size();i++){
        sum+=vet[i];
    }
    ll maior = sum - (n-1)*(original_sum); // Encontramos M

    vector<ll> ans;
    bool flag = true;
    for(int i=1;i<vet.size();i++){
        if(vet[i]==maior && flag) flag = false; // Se for M a gente não usa e considera M como já tendo sido coletado
        else ans.push_back(original_sum-vet[i]);
    }

    cout << original_sum << " " << maior << endl;
    for(auto x: ans) cout << x << " ";
    cout << endl;

    return 0;

}