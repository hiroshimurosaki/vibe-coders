#include <bits/stdc++.h>

using namespace std;

vector<string> cruzada;
int n, m; // Tornando n e m globais para facilitar o uso na função

// Modificado: Agora recebe o ID da palavra para marcar na matriz de histórico
void verificaPalavra(map<char,int> letras, int num_letras, vector<vector<int>> &vis_palavra, int x, int y){
    
    map<char,int> letras_temp;

    // CORREÇÃO: Verifica se a primeira letra sequer existe no mapa
    if(letras.find(cruzada[x][y]) == letras.end()) return;

    // --- VERIFICAÇÃO VERTICAL (Para baixo) ---
    letras_temp = letras;
    int i = x;
    bool valido = true;
    while(i < x + num_letras){
        // CORREÇÃO: Garante que está dentro dos limites da matriz
        if (i >= n) { valido = false; break; }
        
        char atual = cruzada[i][y];
        // CORREÇÃO: Checa se a letra existe e se ainda há saldo dela
        if(letras_temp.find(atual) == letras_temp.end() || letras_temp[atual] <= 0) {
            valido = false;
            break;
        }
        letras_temp[atual]--;
        i++;
    }
    if(valido) {
        for(int j = x; j < x + num_letras; j++) vis_palavra[j][y] = 1;
    }

    // --- VERIFICAÇÃO HORIZONTAL (Para a direita) ---
    letras_temp = letras;
    i = y;
    valido = true;
    while(i < y + num_letras){
        // CORREÇÃO: Garante limite da coluna
        if (i >= m) { valido = false; break; }
        
        char atual = cruzada[x][i];
        if(letras_temp.find(atual) == letras_temp.end() || letras_temp[atual] <= 0) {
            valido = false;
            break;
        }
        letras_temp[atual]--;
        i++;
    }
    if(valido) {
        for(int j = y; j < y + num_letras; j++) vis_palavra[x][j] = 1;
    }

    // --- VERIFICAÇÃO DIAGONAL DIREITA (Para baixo e direita) ---
    letras_temp = letras;
    i = x;
    int j = y;
    valido = true;
    while(i < x + num_letras && j < y + num_letras){
        // CORREÇÃO: Garante limites
        if (i >= n || j >= m) { valido = false; break; }
        
        char atual = cruzada[i][j];
        if(letras_temp.find(atual) == letras_temp.end() || letras_temp[atual] <= 0) {
            valido = false;
            break;
        }
        letras_temp[atual]--;
        i++; j++;
    }
    // CORREÇÃO: Garante que andou o tamanho correto da palavra
    if(valido && i == x + num_letras) {
        for(int w = x, z = y; w < x + num_letras; w++, z++) vis_palavra[w][z] = 1;
    }

    // --- VERIFICAÇÃO DIAGONAL ESQUERDA (Para cima e direita) ---
    letras_temp = letras;
    i = x; 
    j = y;
    valido = true;
    while(j < y + num_letras){
        // CORREÇÃO: Garante limites (i diminui, j aumenta)
        if (i < 0 || j >= m) { valido = false; break; }
        
        char atual = cruzada[i][j];
        if(letras_temp.find(atual) == letras_temp.end() || letras_temp[atual] <= 0) {
            valido = false;
            break;
        }
        letras_temp[atual]--;
        i--; j++;
    }
    // CORREÇÃO: Condição e laço reestruturados para não quebrar limites
    if(valido && j == y + num_letras) {
        for(int w = x, z = y; z < y + num_letras; w--, z++) vis_palavra[w][z] = 1;
    }
}

int main(){
    // Otimização de leitura
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> m)) return 0;

    cruzada.resize(n);
    for(int i = 0; i < n; i++){
        cin >> cruzada[i];
    }

    int p;
    cin >> p;

    // MATRIZ HISTÓRICO: Guarda quantas palavras diferentes usaram cada célula
    vector<vector<int>> total_palavras_na_celula(n, vector<int>(m, 0));

    for(int i = 0; i < p; i++){
        string palavra;
        cin >> palavra;
        
        map<char,int> letras;
        for(int j = 0; j < palavra.size(); j++){
            letras[palavra[j]]++;
        }

        // Matriz temporária para marcar onde A PALAVRA ATUAL achou anagramas
        vector<vector<int>> vis_palavra(n, vector<int>(m, 0));

        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                verificaPalavra(letras, palavra.length(), vis_palavra, j, k);
            }
        }

        // Soma o resultado desta palavra no histórico geral
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++){
                if (vis_palavra[j][k] == 1) {
                    total_palavras_na_celula[j][k]++;
                }
            }
        }
    }

    // Conta quantas células foram usadas por pelo menos 2 palavras diferentes
    int especiais = 0;
    for(int j = 0; j < n; j++){
        for(int k = 0; k < m; k++){
            if (total_palavras_na_celula[j][k] >= 2) {
                especiais++;
            }
        }
    }

    cout << especiais << "\n";

    return 0;
}