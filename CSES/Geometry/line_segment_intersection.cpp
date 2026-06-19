#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

typedef struct{
    ll x;
    ll y;
} Ponto;

ll area_paralelogramo(Ponto &a, Ponto &b, Ponto &c){
    return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}

bool no_segmento(Ponto &A,Ponto &B, Ponto &C){
    return min(A.x,B.x) <= C.x && C.x <= max(A.x,B.x)  && min(A.y,B.y) <= C.y && C.y <= max(A.y,B.y);
}

int main(){

    int t;
    Ponto A,B,C,D;

    cin >> t;

    while(t--){

        cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;

        ll a1 = area_paralelogramo(A,B,C);
        ll a2 = area_paralelogramo(A,B,D);
        ll a3 = area_paralelogramo(C,D,A);
        ll a4 = area_paralelogramo(C,D,B);

        if(((a1 < 0 && a2 > 0) || (a1 > 0 && a2 < 0)) && ((a3 < 0 && a4 > 0) || (a3 > 0 && a4 < 0))){
            cout << "YES" << endl;
            continue;
        }

        if(!a1 && no_segmento(A, B, C)){
            cout << "YES" << endl; 
            continue; 
        }
        if(!a2 && no_segmento(A, B, D)){
            cout << "YES" << endl; 
            continue;
        } 
        if(!a3 && no_segmento(C, D, A)){
            cout << "YES" << endl;
            continue;
        } 
        if(!a4 && no_segmento(C, D, B)){
            cout << "YES" << endl; 
            continue; 
        }
        cout << "NO" << endl;

    }

    return 0;

}