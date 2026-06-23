#include <bits/stdc++.h>
typedef long long ll;
const ll INF = 1e18;

using namespace std;

int main(){

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<pair<int,ll>>> graph(n);

    for(int i=0;i<m;i++){

        int u, v;
        ll w;

        cin >> u >> v >> w;

        u--;v--;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});

    }

    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
    vector<ll> tempo_pessoas(n, INF);

    for(int i=0;i<k;i++) {
        int aux;
        cin >> aux;
        tempo_pessoas[--aux] = 0;
        pq.push({0,aux});
    }

    while(!pq.empty()){

        auto [irr, u] = pq.top();
        pq.pop();
        
        if (irr > tempo_pessoas[u]) continue;

        for(auto [v, w]: graph[u]){
            if(tempo_pessoas[u] +  2*w < tempo_pessoas[v]){
                tempo_pessoas[v] = tempo_pessoas[u] + 2*w;
                pq.push({tempo_pessoas[v],v});
            }
        }

    }

    vector<ll> bike(n,INF);
    bike[0] = 0;
    pq.push({0,0});

    while(!pq.empty()){

        auto [irr, u] = pq.top();
        pq.pop();

        if (irr > bike[u]) continue;

        for(auto [v, w]: graph[u]){
            if(bike[u] + w < bike[v]){
                bike[v] = bike[u] + w;
                pq.push({bike[v],v});
            }
        }

    }

    vector<ll> adiantar(n,INF);
    adiantar[0] = 0;
    pq.push({0,0});

    while(!pq.empty()){

        auto [irr, u] = pq.top();
        pq.pop();
        if (irr > adiantar[u]) continue;

        for(auto [v, w]: graph[u]){
            ll peso = (bike[v] - tempo_pessoas[v] <= 0 ) ? 0 : bike[v] - tempo_pessoas[v];
            if(adiantar[u] + peso < adiantar[v]){
                adiantar[v] = adiantar[u] + peso;
                pq.push({adiantar[v],v});
            }
        }

    }

    cout << adiantar[n-1] << endl;

    return 0;

}