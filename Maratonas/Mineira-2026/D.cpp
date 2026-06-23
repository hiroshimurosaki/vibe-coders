#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, m;

    cin >> n >> m;
    if(n == m){
        cout << "DATA SEGURA" << endl;
    }else if(n<=12){
        cout << "DATA INCERTA" << endl;
    } else {
        cout << "DATA SEGURA" << endl;
    }

    return 0;


}