#include <bits/stdc++.h>
typedef long long ll;
 
using namespace std;
 
int main(){
 
    int t;
    ll l, c;
 
    cin >> t;
 
    while(t--){
        cin >> l >> c;
        ll temp = max(l,c);
        ll mid = ((temp*temp) + (temp-1)*(temp-1)+1)/2;
        if(l<=c){
            if(c&1) cout << mid+(c-l) << endl;
            else cout << mid-(c-l) << endl;
        }else{
            if(l&1) cout << mid-(l-c) << endl;
            else cout << mid+(l-c) << endl;
        }
 
    }
 
    return 0;
 
}