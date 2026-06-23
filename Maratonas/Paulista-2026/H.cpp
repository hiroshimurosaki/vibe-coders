/*
PROBLEMA H - Horário de Rodízio
Link do enunciado do Problema: https://codeforces.com/gym/106598/problem/H

Abordagem: 

Como N é no máximo 12 e T é no máximo 120min podemos perceber que a gente nunca vai cair nas 7horas do segundo dia.
assim só devemos saber se o tempo final > 120 e > 720 e somar 120 no tempo final para cada caso válido.

*/

#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;

    int ans=0;
    for(int i=0;i<n;i++){
        int aux;
        cin >> aux;
        ans+=aux;
    }

    if(ans > 120) ans+=180;
    if(ans > 720) ans+=180;

    cout << ans << endl;

    return 0;

}