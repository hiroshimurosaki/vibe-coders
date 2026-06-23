#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<vector<int>> pontos;
vector<vector<char>> matriz;
int n;
int maior = 0;

vector<pair<int, int>> passos = { {-1, -1}, {-1, 1}, {1, 1}, {1, -1} };

ll pass_sup = 0;
ll pass_inf = 0;

vector<vector<int>> calcular_matriz(int size){
    vector<vector<int>> p(size, vector<int>(size, 0));
    int count_sup = 1;
    int count_inf = 1;

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if((i + j) % 2){
                if(i < j) p[i][j] = count_sup++;
                else p[i][j] = count_inf++;   
            }
        }
    }
    return p;
}

bool verifica_ponto(int i, int j){
    if(i < j) return (pass_sup & (1LL << pontos[i][j])) != 0;
    return (pass_inf & (1LL << pontos[i][j])) != 0;
}

void marcar_ponto(int i, int j) {
    if(i < j) pass_sup |= (1LL << pontos[i][j]);
    else pass_inf |= (1LL << pontos[i][j]);
}

void desmarcar_ponto(int i, int j) {
    if(i < j) pass_sup &= ~(1LL << pontos[i][j]);
    else pass_inf &= ~(1LL << pontos[i][j]);
}

void dfs(int x, int y, int total_comidas) {
    maior = max(maior, total_comidas);

    for(auto p: passos){
        int x_curr = x + p.first;
        int y_curr = y + p.second;
        int x_next = x + 2 * p.first;
        int y_next = y + 2 * p.second;

        if(0 <= x_curr && x_curr < n && 0 <= y_curr && y_curr < n && matriz[x_curr][y_curr] == 'P' && !verifica_ponto(x_curr, y_curr)){
            
            // Vê se a casa de pouso está livre
            if(0 <= x_next && x_next < n && 0 <= y_next && y_next < n && matriz[x_next][y_next] == '.'){ 
                
                marcar_ponto(x_curr, y_curr);
                
                dfs(x_next, y_next, total_comidas + 1);
                    
                desmarcar_ponto(x_curr, y_curr);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n)) return 0;

    matriz.assign(n, vector<char>(n));
    pontos = calcular_matriz(n);

    vector<pair<int, int>> brancas;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> matriz[i][j];
            if(matriz[i][j] == 'B'){
                brancas.push_back({i, j});
            }
        }
    }

    // Testamos a DFS para cada peça branca encontrada no tabuleiro de forma independente
    for(auto b : brancas) {
        int start_x = b.first;
        int start_y = b.second;

        // Transformamos a casa original em '.' para que a própria peça 
        // possa fazer um "loop" e voltar para onde começou se precisar pousar lá
        matriz[start_x][start_y] = '.'; 
        
        dfs(start_x, start_y, 0);
        
        // Restaura a peça branca original para não quebrar o teste das outras brancas
        matriz[start_x][start_y] = 'B'; 
    }

    cout << maior << "\n";

    return 0;
}