#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    int n,q;
    vector<ll> pre_sum;

    cin >> n >> q;

    pre_sum.resize(n);
    cin >> pre_sum[0];

    for(int i=1;i<n;i++){
        ll temp;
        cin >> temp;
        pre_sum[i] = temp + pre_sum[i-1]; 
    }

    while(q--){
        int a,b;
        cin >> a >> b;
        if(a-2>=0) cout << pre_sum[b-1] - pre_sum[a-2] << endl;
        else cout << pre_sum[b-1] << endl;

    }

    return 0;

}