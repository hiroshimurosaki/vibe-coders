/*
PROBLEMA I - Inserção de Dígitos
Link do enunciado do Problema: https://codeforces.com/gym/106598/problem/I

Abordagem: 

Realizamos backtracking para formar todas as possibilidades de números de telefone válidos.
*/
#include <bits/stdc++.h>

using namespace std;

string ans; // Váriável auxiliar em que montaremos o número de telefone durante o backtracking
vector<string> final; // Vetor com os resultados finais, já que temos que falar primeiro a quantidade de núemero de telefones válidos

void backtracking(int pos, int pos_pal, string &s){

    // Se é inválido o número retornamos da recursão
    if(pos > 0 && ans[0] != '1') return;
    if( pos > 1 && ans[1] == '0') return;
    if(pos > 2 && ans[2] != '9') return;

    // Se a string atingiu tamanho 11 armazena ela
    if(pos == 11){    
        final.push_back(ans);
        return;
    }

    // Quantidade de números que faltam para 's' ter 11 dígitos
    int numeros_a_adicionar = 11 - pos - (s.size() - pos_pal);
    
    // Se não tem como adicionar novos números então adicionamos apenas os valores de 's'
    if(numeros_a_adicionar <= 0 ){ 
        ans+=s[pos_pal];
        backtracking(pos+1,pos_pal+1,s);
        ans.pop_back();
        return;
    }

    //Se tem como adicionar números
    else{
        /// Insere s[pos_pal] caso seja == 0
        if(pos_pal < s.size() && s[pos_pal] == '0'){
            ans+=s[pos_pal];
            backtracking(pos+1,pos_pal+1,s);
            ans.pop_back();
        }
        
        // Insere 1
        ans+='1';
        if(s[pos_pal] == '1') backtracking(pos+1,pos_pal+1,s);
        else backtracking(pos+1,pos_pal,s);
        ans.pop_back();

        // Insere s[pos_pal]
        if(pos_pal < s.size() && s[pos_pal] > '1'  && s[pos_pal] != '9'){
            ans+=s[pos_pal];
            backtracking(pos+1,pos_pal+1,s);
            ans.pop_back();
        }

        // Insere 9
        ans+='9';
        if(s[pos_pal] == '9') backtracking(pos+1,pos_pal+1,s);
        else backtracking(pos+1,pos_pal,s);
        ans.pop_back();
    }


}

int main(){

    string s;

    cin >> s;

    if(s.size() > 11) { // Se 's' tiver mais de 11 dígitos, não é possível formar número válido
        cout << 0 << endl;
        return 0;
    }
    else if(s.size() == 11) { // Se já tiver 11 dígitos só há a possibilidade de ser o valor recebido, só temos que ver se ele é válido
        if(s[0] == '1' && s[1] != '0' && s[2] == '9'){
            cout << 1 << endl;
            cout << s << endl;
            return 0;
        }
        else{
            cout << 0 << endl; 
            return 0;
        }
    }

    // Criamos todas as possibilidades de numeros que contenham 's' nele
    backtracking(0,0,s);

    cout << final.size() << endl;
    for(auto f: final){
        cout << f  << endl;            
    }
    
    return 0;

}