#include <bits/stdc++.h>

using namespace std;

int main(){

    int a, b, c;

    cin >> a >> b >> c;

    if(a != b && a != c){
        cout << 'A' << endl;
    } else if(b != a && b != c){
        cout << 'B' << endl;
    } else if(c != b && a != c){
        cout << 'C' << endl;
    } else {
        cout << '*' << endl;
    }

    return 0;

}