#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> tree;

void bfs(int origem, vector<int> &distancias){

    queue<int> fila;

    distancias[origem] = 0;
    fila.push(origem);

    while(!fila.empty()){

        int temp = fila.front();
        fila.pop();

        for(auto v: tree[temp]){
            if(distancias[v]==-1){
                distancias[v] = distancias[temp] + 1;
                fila.push(v);
            }
        }
    }


}

int main(){

    int n;
    cin >> n;

    tree.resize(n);

    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    vector<int> distsA(n,-1);
    vector<int> distsB(n,-1);
    
    bfs(0,distsA);
    
    int maior = 0;
    for(int i=1;i<distsA.size();i++){
        if(distsA[maior] < distsA[i]) maior = i;
    }
    
    distsA.assign(n,-1);
    bfs(maior,distsA);
    
    maior = 0;
    for(int i=1;i<distsA.size();i++){
        if(distsA[maior] < distsA[i]) maior = i;
    }
    
    bfs(maior,distsB);

    for(int i=0;i<n;i++){
        cout << max(distsA[i],distsB[i]) << " ";
    }
    cout << endl;

    return 0;

}