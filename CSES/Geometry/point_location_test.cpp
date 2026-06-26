/*
Para resolver esse problema, faremos o produto vetorial entre os vetores p2-p1 e p3-p1.
*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        ll x1,y1,x2,y2,x3,y3;        
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;        

        ll x = x2-x1;
        ll y = y2-y1;
        ll xlinha = x3-x1;
        ll ylinha = y3-y1;

        ll cross = x*ylinha - xlinha*y;
        if(cross == 0) cout << "TOUCH" << endl;
        else if(cross < 0 ) cout << "RIGHT" << endl; 
        else cout << "LEFT" << endl;  

    }

    return 0;

}