#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
 
    int t,a,b, pihadois_a, pilhadois_b;
    cin >> t;
    
    while(t--){
        
        cin >> a >> b;
        
        int x = 2*a-b;
        int y = 2*b-a;
 
        if(x >=0 && !(x%3) && y>=0 && !(y%3)) cout << "YES" << endl;
        else cout << "NO" << endl;
 
    }
 
    return 0;
 
}