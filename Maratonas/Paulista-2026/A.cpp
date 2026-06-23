/*
PROBLEMA A - After em Campinas
Link do enunciado do Problema: https://codeforces.com/gym/106598/problem/A

Abordagem: 
A ideia é pré-processar todas as proximas baladas validas para cada posição para uma busca em O(1).
E depois realizar uma busca binária pelo primeiro custo <= ao valor disponóivel para o grupo.
*/


#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,q;

    cin >> n >> q;

    vector<int> custos(n); // Vetor com os custos em ordem decrescente
    vector<int> estilos(n); // Vetor com os estilos de cada custo
    for(int i=0;i<n;i++) cin >> custos[i] >> estilos[i];
    
    // Esse vetor armazena para cada balada 'i' a próxima balada válida caso ela não seja válida
    vector<int> proximo_valido(n,-2);
    for(int i=n-2;i>=0;i--){
        if(estilos[i] != estilos[i+1]) proximo_valido[i] = i+1; // Se os estilos forem diferentes então atualiza idx
        else proximo_valido[i] = proximo_valido[i+1]; // Se forem iguais propaga o mesmo próximo
    }

    for(int i=0;i<q;i++){

        int d, o;
        cin >> d >> o;

        int pos = lower_bound(custos.begin(),custos.end(), d, greater<int>()) - custos.begin();
        if(pos == n){
            cout << -1 << endl;
            continue;
        }
        else if(estilos[pos] != o) cout << pos+1 << endl;
        else cout << proximo_valido[pos] + 1 << endl;
        
    }    

    return 0;

}