#include <bits/stdc++.h>

using namespace std;

vector<int> subs;

int dfs(vector<vector<int>>& t, int x){

    int acc=0;
    for(auto y: t[x]){
        acc += dfs(t,y);
    }
    subs[x] = acc;
    return subs[x] + 1;

}

int main(){

    int n;
    vector<vector<int>> tree;

    cin >> n;

    tree.resize(n);
    subs.resize(n,0);
    
    for(int i=0;i<n-1;i++){
        int a;
        cin >> a;
        tree[a-1].push_back(i+1);
    }

    dfs(tree,0);

    for(auto v: subs){
        cout << v << " ";
    }
    cout << endl;

    return 0;

}