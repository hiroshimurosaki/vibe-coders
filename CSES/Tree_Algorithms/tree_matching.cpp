#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,add=0;
    
    vector<int> arestas;
    vector<vector<int>> tree;
    queue<int> fila;

    cin >> n;

    tree.resize(n);
    arestas.resize(n,0);

    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        arestas[a]++;
        arestas[b]++;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    for(int i=0;i<n;i++){
        if(arestas[i] == 1) fila.push(i);
    }

    while(!fila.empty()){

        int no = fila.front();
        fila.pop();
        int f = 1;

        arestas[no] = -1;

        for(auto v: tree[no]){
            if(f && arestas[v] > 0){
                arestas[v] = -1;
                for(auto x: tree[v]) if(--arestas[x] == 1) fila.push(x);
                f = 0;
                add++;
            }
            if(--arestas[v] == 1) fila.push(v);
        }

    }

    cout << add << endl;

    return 0;

}