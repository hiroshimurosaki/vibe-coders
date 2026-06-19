#include <bits/stdc++.h>

using namespace std;

int ans=0;

int diametro(int x, vector<vector<int>>& tree, vector<int>& visitado){

    int maior=0, menor=0, aux;

    visitado[x] = 1;
    for(auto y: tree[x]){
        if(!visitado[y]){
            aux = diametro(y, tree, visitado);
            if(aux > maior){
                menor = maior;
                maior = aux;
            }
            else if(aux > menor) menor = aux;
        }
    }

    ans = (ans < maior + menor) ? maior+menor : ans; 
    return maior + 1;

}

int main(){

    int n;
    vector<vector<int>> tree;
    vector<int> vis;

    cin >> n;

    tree.resize(n);
    vis.resize(n,0);

    for(int i=0;i<n-1;i++){

        int a,b;
        cin >> a >> b;
        a--;b--;
        tree[a].push_back(b);
        tree[b].push_back(a);

    }

    diametro(0,tree,vis);

    cout << ans << endl;

    return 0;

}