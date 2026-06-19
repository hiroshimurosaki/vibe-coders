#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
 
    int n, ans=0,div=5;
    cin >> n;
 
    while(n>=div){
        ans+= (n/div);
        div*=5;
    }
 
    cout << ans << endl;    
 
    return 0;
 
}