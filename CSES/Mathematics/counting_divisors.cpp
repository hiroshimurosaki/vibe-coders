#include <bits/stdc++.h>

using namespace std;

// Função que calcula os divisores primos de um número (usado o crivo do menor divisor primo)
void calcular_divs(vector<int>&divs){

    int lim = sqrt(divs.size());

    // Inicializa o vetor com os seus valore sendo os próprios índices. Isso indica que cada número tem como seu menor divisor ele mensmo (por enquanto).
    for(int i=0;i<divs.size();i++) divs[i] = i;

    // Agora vamos iterar sobre o vetor, comma seguinte lógica. Se o menor valor que divide o número na posição 'i' é ele mesmo (ou seja, 'i'), sabemos que esse valor é primo, assim podemos marcar todos seus múltiplos como tendo o 'i' como menor divisor primo.
    for(int i=2;i<=lim;i++){
        if(divs[i]!=i) continue;
        for(int j=i*i;j<divs.size();j+=i){
            if(divs[j] == j) divs[j] = i;
        }
    }
}

int main(){

    int n;
    vector<int> divs(1000001);

    calcular_divs(divs);

    cin >> n;

    while(n--){

        int x,ans=1;
        cin >> x;

        while(x!=1){
            int count=0;
            int divisor = divs[x];
            
            // Verifica quantas vezes o divisor 'divisor' divide o valor 'x'
            while(!(x%divisor)){
                x/=divisor;
                count++;
            }
            ans *= count+1; // 'ans' é a combinatória de todos fatores primos do número 'x', o que faz com que tenhamos todos os divisores de 'x' 
        }

        cout << ans << endl;

    }

    return 0;

}