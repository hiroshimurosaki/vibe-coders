#include <bits/stdc++.h>
typedef long long ll;
 
const ll MOD = 1e9+7;
 
using namespace std;
 
int main(){
 
    int n;
    ll ans=1;
 
    cin >> n;
 
    while(n){
        ans = (ans << 1)%MOD;
        n--;
    }
    cout << ans << endl;
 
    return 0;
 
}