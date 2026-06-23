#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;


int verify(ll r, vector<ll> & dists) {
    
    int last_r = r,curr_r;
    for(int i=0;i<dists.size();i++){
        curr_r = dists[i] - last_r;
        if(curr_r <= 0){
            if(i&1) return -1;
            return 0;
        }
        last_r = curr_r;
    }
    return 1;
}

int main() {

    
    ll n, last_x,last_y,x,y;
    vector<ll> dists;

    cin >> n;
    dists.resize(n-1); 

    cin >> last_x >> last_y;
    
    for(int i=1;i<n;i++){
        cin >> x >> y;
        dists[i-1] = abs(x-last_x) + abs(y-last_y);
        last_x = x;
        last_y = y;
    }
    ll l=1, r=dists[0];
    
    while(l<r){

        int mid = (l+r+1)/2;
        int aux = verify(mid, dists);
        if(aux == 0){
            r = mid-1;
        }
        else if(aux == -1){
            l = mid+1;
        }
        else{
            l=mid;
        }
    
    }
    
    if(verify(l,dists)==1) cout << l << endl;
    else cout << -1 << endl;

    return 0;


}
    

