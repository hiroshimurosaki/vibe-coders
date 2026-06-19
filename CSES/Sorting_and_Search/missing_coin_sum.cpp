#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;

    vector<long long> values(n);
    for(auto &x: values) cin >> x;

    sort(values.begin(),values.end());

    long long sum=1;
    for(int i=0;i<n;i++){
        if(values[i] > sum) break;
        sum+=values[i];
    }

    cout << sum << endl;

    return 0;

}