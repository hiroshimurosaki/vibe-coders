#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 
int main(){
 
    ll n, count_a=0,count_b=0;
    vector<int> a,b;
 
    cin >> n;
 
    if(n==1 || ((1+n)*n/2)%2){
        cout << "NO" << endl;
        return 0;
    }
    
    while(n){
        if(count_a<=count_b){
            count_a+=n;
            a.push_back(n);
        }
        else{
            count_b+=n;
            b.push_back(n);
        }
        n--;
    }
    cout << "YES" << endl;
    cout << a.size() << endl;
    for(auto x: a) cout << x << " ";
    cout << endl;
 
    cout << b.size() << endl;
    for(auto x: b) cout << x << " ";
    cout << endl;
 
    return 0;
 
}
