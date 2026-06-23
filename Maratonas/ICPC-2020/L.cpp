#include <bits/stdc++.h>

using namespace std;

vector<string> cruzada;

int cont = 0;

void verificaPalavra(map<char,int> letras, int num_letras, vector<vector<bool>> &vis, int n, int m, int x, int y){
    
    map<char,int> letras_temp(letras);

    cout << "x = " << x << " y = " << y << endl;

    cout << "map1: " << endl;
    for(auto w:letras_temp){
        cout << " {" << w.first << " " << w.second  << "}" << " ";
    }
    cout << endl;
    
    if(letras_temp.find(cruzada[x][y]) != letras_temp.end()){
        if(letras_temp[cruzada[x][y]]>0) letras_temp[cruzada[x][y]]--;
        else return;

        // Verifica vertical
        int i=x+1;
        while(i<x+num_letras){
            
            cout << ((letras_temp.find(cruzada[i][y]) == letras_temp.end())?1:0) << endl;
            
            if(letras_temp.find(cruzada[i][y]) == letras_temp.end() || --letras_temp[cruzada[i][y]] < 0) {
                break;
            }
            
            
            i++;
        }
        if(i == x+num_letras) {
            for(int j=x;j<x+num_letras;j++) vis[j][y] = true;
        }

        cout << "map2: " << endl;
        for(auto w:letras_temp){
        cout << " {" << w.first << " " << w.second  << "}" << " ";
    }
    cout << endl;
        
        // Verifica horizontal
        letras_temp = letras;
        letras_temp[cruzada[x][y]]--;
        i=y+1;
        while(i<y+num_letras){
            i++;
            if(letras_temp.find(cruzada[x][i]) == letras_temp.end() || --letras_temp[cruzada[x][i]] < 0) break;
        }
        if(i == y+num_letras) {
            for(int j=y;j<y+num_letras;j++) vis[x][j] = true;
        }

        cout << "map3: " << endl;
        for(auto w:letras_temp){
        cout << " {" << w.first << " " << w.second  << "}" << " ";
    }
    cout << endl;
        
        // Verifica diagonal direita
        letras_temp = letras;
        letras_temp[cruzada[x][y]]--;
        i=x+1;
        int j=y+1;
        while(i<x+num_letras && j<y+num_letras){
            if(letras_temp.find(cruzada[i][j]) == letras_temp.end() || --letras_temp[cruzada[i][j]] < 0) break;
            i++;j++;
        }
        if(i == x+num_letras && j == y+num_letras) {
            for(int w=x,z=y;w<x+num_letras && z<y+num_letras;w++,z++) vis[w][z] = true;
        }

        cout << "map4: " << endl;
        for(auto w:letras_temp){
        cout << " {" << w.first << " " << w.second  << "}" << " ";
    }
    cout << endl;


        
        
        // Verifica diagonal esquerda
        letras_temp = letras;
        letras_temp[cruzada[x][y]]--;
        i=x-1, j=y+1;
        while(i>=max(0,x-num_letras) && j<y+num_letras){
            
            if(letras_temp.find(cruzada[i][j]) == letras_temp.end() || --letras_temp[cruzada[i][j]] < 0) break;
            i--;j++;
        }
        if(i == x-num_letras-1 && j == y+num_letras) {
           
            for(int w=x,z=y;w<x+num_letras && z<y+num_letras;w--,z++) vis[w][z] = true;
        }
        
        
    }

    cout << "map5: " << endl;
    for(auto w:letras_temp){
        cout << " {" << w.first << " " << w.second  << "}" << " ";
    }
    cout << endl;
    
    cout << ++cont << endl;
    for(int q=0;q<n;q++){
        for(int g=0;g<m;g++){
            cout << vis[q][g] << " ";
        }
        cout << endl;
    }
    
}


int main(){

    int n, m;
    cin >> n >> m;

    
    vector<vector<int>> visfinal(n,vector<int>(m,0));
    cruzada.resize(n);

    for(int i=0; i<n; i++){
        cin >> cruzada[i];
    }


    int p;

    cin >> p;

    string palavra;

    for(int i=0; i<p; i++){
        cin >> palavra;
        map<char,int> letras;
        for(int j = 0; j<palavra.size() ;j++){
            letras[palavra[j]]++;
        }

        // for(auto w:letras){
        //     cout << "{" << w.first << " " << w.second  << "}" << " ";
        // }
        vector<vector<bool>> vis(n,vector<bool>(m,false));

        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                verificaPalavra(letras,palavra.length(),vis,n,m,j,k);
            }
        }

        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                cout << vis[j][k] << " ";
            }
            cout << endl;
        }
        
    }

    

}