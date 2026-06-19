#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 
int main(){
 
    int n;
    ll ans=0;
    vector<int> vet;
 
    cin >> n;
    vet.resize(n);
 
    for(int i=0;i<n;i++){
        cin >> vet[i];
    }
 
    for(int i=1;i<n;i++){
        if(vet[i]<vet[i-1]){
            ans+= vet[i-1]-vet[i];
            vet[i] = vet[i-1];
        }
    }
 
    cout << ans << endl;
 
    return 0;
}
