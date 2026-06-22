#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

int main() {

    int n;
    string s, t;

    cin >> n;
    cin >> s;
    cin >> t;

    float aux=0,temp=0;
    for(int i=0;i<n;i++){
        if(s[i] == '*') temp++; 
        if(s[i] != t[i]) aux++;
    }

    cout << fixed << setprecision(2) << aux/temp << endl;

    return 0;

}
