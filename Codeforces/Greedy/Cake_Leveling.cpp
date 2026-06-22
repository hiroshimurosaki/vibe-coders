/*
 * Cake Leveling — Codeforces 2232B  (rating 900)
 * https://codeforces.com/problemset/problem/2232/B
 * Tags: binary search, greedy, math
 */
#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;

    cin >> t;

    while(t--){
    
        int n;
        cin >> n;
        vector<long long> vet(n),ans(n);
        for(auto &x: vet) cin >> x;
  
        ans[0] = vet[0];
        long long  acc=0, sum=vet[0];
        for(int i=1;i<n;i++){
            sum+=vet[i];
            if(vet[i] < ans[i-1]){
                if(acc+vet[i] >=  ans[i-1]){
                    ans[i] = ans[i-1];
                    acc = sum-(ans[i]*(i+1));
                }
                else{
                    ans[i] = sum/(i+1);
                    acc = sum-(ans[i]*(i+1));
                }
                    
            }
            else{
                ans[i] = ans[i-1];
                acc = sum-(ans[i]*(i+1));
            }
        }
        
        for(auto x: ans) cout << x << " ";
        cout << endl;

    }

    return 0;
}
