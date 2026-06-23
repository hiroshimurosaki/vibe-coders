#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;  // FIX 1: read n before using it

    int soma = 0;
    vector<int> arcs(2*n);
    vector<pair<int,int>> intervalos;

    for(int i = 0; i < n; i++){
        cin >> arcs[i];
        arcs[n+i] = arcs[i];
        soma += arcs[i];
    }

    if(soma % 3 != 0){
        cout << 0 << endl;
        return 0;
    }

    int target = soma / 3;
    int aux = 0;
    int l = 0, r = 0;

    // FIX 2: bound r to 2*n to avoid out-of-bounds
    while(l < n && r < 2*n){
        if(aux < target){
            aux += arcs[r++];
        } else if(aux > target){
            aux -= arcs[l++];
        } else {
            intervalos.push_back({l, r-1});
            aux -= arcs[l++];
        }
    }

    int ans = 0;

    for(int i = 0; i < (int)intervalos.size(); i++){
        int lim = intervalos[i].first + n - 1;  // FIX 3: end limit for circular constraint
        int t = intervalos[i].second;

        int j;  // FIX 4: declare j outside the loop so it's visible after
        for(j = 1; j < 3; j++){  // FIX 5: start at 1 (we already have the i-th interval)
            // FIX 6: use a lambda comparator — find first interval with .first > t
            auto it = upper_bound(
                intervalos.begin() + i + 1,
                intervalos.end(),
                t,
                [](int val, const pair<int,int>& p){ return val < p.first; }
            );

            if(it == intervalos.end()) break;
            if(it->first != t + 1) break;   // must be contiguous
            if(it->second > lim) break;      // must stay within circular bounds

            t = it->second;
        }

        if(j == 3) ans++;
    }

    cout << ans << endl;
    return 0;
}