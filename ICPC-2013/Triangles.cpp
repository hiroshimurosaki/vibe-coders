#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;

    cin >> n;
    int soma = 0;
    vector<int> arcs(2*n);
    vector<pair<int,int>> intervalos;

    for(int i = 0; i<n; i++){

        cin >> arcs[i];
        arcs[n+i] = arcs[i];
        soma += arcs[i];
    }

    if(soma%3 != 0){
        cout << "0" << endl;
        return 0;
    }
    int target = soma/3;
    int aux = 0;

    int l = 0;
    int r = 0;
    while(l<n && r < 2*n){
        if(aux<target){
            aux += arcs[r++];
        } else if(aux>target){
            aux-= arcs[l++];
        } else if(aux == target){
            intervalos.push_back({l,r-1});
            aux-= arcs[l++];
        }
    }

    int ans =0;
    for(int i=0; i<intervalos.size(); i++){

        int lim = intervalos[i].first + n - 1;
        int t = intervalos[i].second;

        int j;
        for(int j = 0; j<2; j++){
            auto it = upper_bound(intervalos.begin()+i, intervalos.end(), t, [](int val, const pair<int,int>& p){ return val < p.first; });
            if((*it).first != t+1 || (*it) .second > lim) break;
            if(it == intervalos.end()) break;
            t = (*it).second;
        }

        if(j==2) ans++;

    }

    cout << ans << endl;

    return 0;

}