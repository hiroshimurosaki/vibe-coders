#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;

    cin >> n;

    for(int i=0;i<(1<<n);i++){
    
        int temp = i ^ (i>>1);

        for(int j=0;j<n;j++){
            cout << ((temp>>j)&1);
        }
        cout << endl;

    }

    return 0;

}
