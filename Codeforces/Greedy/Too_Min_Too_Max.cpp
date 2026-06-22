/*
 * Too Min Too Max — Codeforces 1934A  (rating 800)
 * https://codeforces.com/problemset/problem/1934/A
 * Tags: greedy, math
 */
#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;
    
    while(t--){

        int n;
        cin >> n;

        vector<int> vet(n);
        for(auto &x:vet) cin >> x;

        sort(vet.begin(),vet.end());

        vector<int> ans = {vet[n-1],vet[0],vet[n-2],vet[1]};

        int i=0;
        int sum=0;
        for(int j=0;j<4;j++){
            sum += abs(ans[i] - ans[(i+1)%4]);
            i=(i+1)%4;
        }

        cout << sum << endl;

    }

    return 0;

}