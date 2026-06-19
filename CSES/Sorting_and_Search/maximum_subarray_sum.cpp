#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {

    int n;
    vector<int> vet;

    cin >> n;

    ll sum = 0, ans = LLONG_MIN;
    for(int i=0;i<n;i++) {
        int temp;
        cin >> temp;
        sum += temp;
        ans = max(ans, sum);
        if(sum<0) sum=0;
    }

    cout << ans << endl;
    

    return 0;
    
}
