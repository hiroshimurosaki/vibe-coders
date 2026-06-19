#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    vector<pair<int,int>> e;

    cin >> n;

    e.resize(2*n);

    int a;
    for(int i=0;i<n;i++){
        cin >> a;
        e[2*i] = {a,1};
        cin >> a;
        e[2*i+1] = {a,-1};
    }

    sort(e.begin(),e.end());

    int maior=0, curr=0;
    for(auto x: e){
        curr += x.second;
        maior = max(maior,curr);
    }

    cout << maior << endl;

    return 0;

}