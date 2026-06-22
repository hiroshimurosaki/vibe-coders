/*
 * Bit++ — Codeforces 282A  (rating 800)
 * https://codeforces.com/problemset/problem/282/A
 * Tags: implementation
 */
#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,x=0;
    string op;

    cin >> n;

    while(n--){

        cin >> op;

        if(op[1] == '+') x++;
        else x--;

    }
    cout << x << endl;

    return 0;
    
}