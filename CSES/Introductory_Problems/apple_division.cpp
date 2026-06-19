#include <bits/stdc++.h>
typedef unsigned long long ull;
typedef long long ll;
using namespace std;


int main() {
    
    int n;
    vector<ll> vet;
    
    cin >> n;
    
    vet.resize(n);
    for(int i=0;i<n;i++) cin >> vet[i];
    
    ll min_diff = LLONG_MAX;
    for(ull mask=0; mask<(1<<n);mask++){

        ll conj_1=0,conj_2=0;
        for(int j=1,i=0;j<(1<<n);j<<=1,i++){
            if(mask&j) conj_1+= vet[i];
            else conj_2+= vet[i];
        }
        min_diff = min(min_diff,abs(conj_1-conj_2));

    }

    cout << min_diff << endl;

    return 0;

}
