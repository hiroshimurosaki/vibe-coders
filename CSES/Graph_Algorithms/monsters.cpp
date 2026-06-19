#include <bits/stdc++.h> 

using namespace std;

vector<pair<int,int>> passos = {{-1,0},{0,-1},{1,0},{0,1}};
vector<char> direcoes = {'U','L','D','R'};

string reconstruir(vector<vector<pair<int,int>>>& pais, int x, int y){

    string ans = "";

    while(pais[x][y] != make_pair(-2,-2)){

        pair<int,int> dir = {x - pais[x][y].first, y - pais[x][y].second};
        
        for(int i=0;i<passos.size();i++){
            if(dir == passos[i]) ans+= direcoes[i];
        }

        int px = pais[x][y].first;
        int py = pais[x][y].second;
        x = px;
        y = py;
        
    }

    reverse(ans.begin(),ans.end());
    return ans;

}

int main(){

    int n,m;
    vector<vector<char>> matriz;
    vector<vector<int>> aux;
    vector<vector<pair<int,int>>> pais;
    queue<pair<int,int>> monstros;
    queue<tuple<int,int,int>> me;

    cin >> n >> m;

    matriz.resize(n,vector<char>(m));
    aux.resize(n,vector<int>(m, INT_MAX));
    pais.resize(n,vector<pair<int,int>>(m, {-1,-1}));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> matriz[i][j];
            if(matriz[i][j] == 'M'){
                monstros.push({i,j});
                aux[i][j] = 0;
            }
            else if(matriz[i][j] == 'A'){
                me.push({i,j,1});
                pais[i][j] = {-2,-2};
            }
        }
    }

    
    while(!monstros.empty()){
        
        pair<int,int> curr = monstros.front();
        monstros.pop();
        
        for(auto p : passos){
            int x = curr.first + p.first;
            int y = curr.second + p.second;
            
            if(x<0 || x>=n || y<0 || y>=m || matriz[x][y] == '#' || aux[x][y] <= aux[curr.first][curr.second]+1) continue;
            
            aux[x][y] = aux[curr.first][curr.second] + 1;
            monstros.push({x,y});
        }
        
    }

    while(!me.empty()){

        auto [x_curr,y_curr,andou] = me.front();
        me.pop();

        for(auto p : passos){
            int x = x_curr + p.first;
            int y = y_curr + p.second;
            
            if(x<0 || x>=n || y<0 || y>=m){
                string caminho = reconstruir(pais, x_curr,y_curr);
                cout << "YES" << endl;
                cout << caminho.length() << endl;
                cout << caminho << endl;
                return 0;
            }
            else if(matriz[x][y] == '#' || andou >= aux[x][y] || pais[x][y] != make_pair(-1,-1)) continue;

            pais[x][y] = {x_curr,y_curr};
            me.push({x,y,andou+1});
        }

    }

    cout << "NO" << endl;
    
    return 0;

}