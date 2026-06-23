#include <bits/stdc++.h>
const long long MOD = 998244353;

using namespace std;

int main(){

    int n, k;
    cin >> n >> k;

    vector<long long> dp(n+1,0);
    dp[0]=1;

    for(int j=1;j<=n;j++){
        if(j==k) continue;
        for(int i=0;i<n+1;i++){
           if(i+j<=n) dp[i+j] = (dp[i+j] + dp[i])%MOD;
        }
    }

    cout << dp[n] << endl;

    return 0;

}