#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<ll> vet(n+2);
    for(auto &x: vet) cin >> x;

    sort(vet.rbegin(),vet.rend());

    ll original_sum = vet[0];
    ll sum = 0;
    for(int i=1;i<vet.size();i++){
        sum+=vet[i];
    }
    ll maior = sum - (n-1)*(original_sum);

    vector<ll> ans;
    bool flag = true;
    for(int i=1;i<vet.size();i++){
        if(vet[i]==maior && flag) flag = false;
        else ans.push_back(original_sum-vet[i]);
    }

    cout << original_sum << " " << maior << endl;
    for(auto x: ans) cout << x << " ";
    cout << endl;

    return 0;

}