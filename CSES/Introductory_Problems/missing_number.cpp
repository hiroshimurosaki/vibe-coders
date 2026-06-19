#include <bits/stdc++.h>
 
using namespace  std;
 
int main(){
 
    int n,aux;
    vector<bool> presence;
 
    cin >> n;
 
    presence.resize(n+1,false);
 
    for(int i=0;i<n-1;i++){
        cin >> aux;
        presence[aux]= true;
    }
 
    for(int j=1;j<=n;j++){
        if(!presence[j]){
            cout << j << endl;
            break;
        }
    }
 
    return 0;
 
}