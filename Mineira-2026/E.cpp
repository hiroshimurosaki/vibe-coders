#include <bits/stdc++.h>

using namespace std;

int n, m, t;

void fura(vector<pair<int,int>> &pos, int i, int j){
    
    if(i>=0 && j>=0 && i<n && j<m){
        pos.push_back({i,j});
    } 
    return;
}


int main(){

    cin >> n >> m >> t;
    
    vector<vector<int>> matriz(n,vector<int>(m));
    vector<pair<int,int>> a(t);
    vector<pair<int,int>> g(t);
    


    for(int i=0; i<n; i++){
        for(int j=0;j<m;j++){

            int aux;
            cin >> aux;
            matriz[i][j] = aux;

        }
    }

    for(int i=0; i<t; i++){
        int aux1, aux2;
        cin >> aux1 >> aux2;

        g[i].first = aux1 - 1;
        g[i].second = aux2 - 1;

    }


    for(int i=0; i<t; i++){
        
        cin >> a[i].first >> a[i].second;

        a[i].first = a[i].first - 1;
        a[i].second = a[i].second - 1;

    }

    

    int somag = 0;
    int somaa = 0;
    
    
    
    
    for(int i=0; i<t; i++){
        vector<pair<int,int>> gf;
        vector<pair<int,int>> af;
        map<pair<int,int>,int> cont;
        
        fura(gf,g[i].first,g[i].second);
        fura(gf,g[i].first+1,g[i].second);
        fura(gf,g[i].first-1,g[i].second);
        fura(gf,g[i].first,g[i].second+1);
        fura(gf,g[i].first,g[i].second-1);

        fura(af,a[i].first,a[i].second);
        fura(af,a[i].first+1,a[i].second);
        fura(af,a[i].first-1,a[i].second);
        fura(af,a[i].first,a[i].second+1);
        fura(af,a[i].first,a[i].second-1);

        for(int k=0; k<gf.size(); k++){
            cont[{gf[k].first,gf[k].second}]++;
        }
        for(int k=0; k<af.size(); k++){
            if(cont.find({af[k].first,af[k].second}) == cont.end()){
                cont[{af[k].first,af[k].second}]++;
            } else{
                cont[{af[k].first,af[k].second}]--;
            }
        }
    
        for(int k=0; k<gf.size(); k++){
            if(cont.find({gf[k].first,gf[k].second}) != cont.end() && cont[{gf[k].first,gf[k].second}] > 0){
                somag+=matriz[gf[k].first][gf[k].second];
                matriz[gf[k].first][gf[k].second] = 0;
            }
        }
    
        for(int k=0; k<af.size(); k++){
            if(cont.find({af[k].first,af[k].second}) != cont.end() && cont[{af[k].first,af[k].second}] > 0){
                somaa+=matriz[af[k].first][af[k].second];
                matriz[af[k].first][af[k].second] = 0;
            }
        }
    }

    cout << somag << " " << somaa << endl;


}