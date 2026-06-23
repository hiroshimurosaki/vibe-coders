#include <bits/stdc++.h>

using namespace std;

int main(){

    int c;
    int soma = 100;
    int maior = 100;

    cin >> c;
    
    while(c--){
        int aux;
        cin >> aux;
        soma += aux;
        if(maior<soma){
            maior = soma;
        }
    }

    cout << maior << endl;
    return 0;


}