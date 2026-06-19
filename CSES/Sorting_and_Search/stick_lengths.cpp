#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {

    int n;
    vector<ll> p;
    
    cin >> n;
    p.resize(n);

    for(int i=0;i<n;i++){
        cin >> p[i];
    }

    sort(p.begin(),p.end());

    ll mediana = p[p.size()/2];

    ll ans=0;
    for(int j=0;j<n;j++){
        ans+=abs(p[j]-mediana);
    }

    cout << ans << endl;

    return 0;

}