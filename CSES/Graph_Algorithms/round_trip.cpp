#include <bits/stdc++.h>
 
using namespace std;
 
vector<vector<int>> graph;
vector<int> vis;
bool flag=false;
 
int dfs(int curr, int dist){
 
    if(vis[curr]){
        if(dist-vis[curr]>2){
            cout << dist-vis[curr] + 1 << endl;
            cout << curr+1<< " ";
            flag = true;
            return vis[curr]; 
        }
        return 0;
    }
    vis[curr] = dist;
    for(auto v: graph[curr]){
        int temp = dfs(v,dist+1);
        if(temp==-1) return -1;
        else if(temp){
            cout << curr+1 << " ";
            if(temp == vis[curr]) return -1;
            return temp;
        }
    }
    return 0;
}
 
int main(){
 
    int n, m;
    cin >> n >> m;
 
    graph.resize(n);
    vis.resize(n,0);
 
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        a--;b--;    
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
 
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,1);
            if(flag) break;
        }
    }
    if(flag) cout << endl;
    else cout << "IMPOSSIBLE" << endl;
 
    return 0;
 
}
