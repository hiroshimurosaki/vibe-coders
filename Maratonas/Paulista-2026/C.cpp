/*
PROBLEMA C - Capital Mundial da Pizza
Link do enunciado do Problema: https://codeforces.com/gym/106598/problem/C

Abordagem: 
Calcular quantos pedaços de 'n' pizzas de 8 pedaços podem ser divididos para 'm' pessoas.
*/

#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, m;
    cin >> n >> m;

    cout << (8*n)/m << endl;

    return 0;

}