#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 
int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        vector<ll> vet(n);

        for(int i=0;i<n;i++) cin >> vet[i];

        
        for(int i=n-2; i>=0;i--){
            if(vet[i] + vet[i+1] > vet[i]){
                vet[i]+= vet[i+1]; 
            }
        }
        
        int count=0;
        for(auto x: vet){
            if(x>0) count++;
        }

        cout << count << endl;

    }


    return 0;

}