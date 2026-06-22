/*
 * Plus or Minus — Codeforces 1807A  (rating 800)
 * https://codeforces.com/problemset/problem/1807/A
 * Tags: implementation
 */
#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    int a, b ,c;

    cin >> t;

    for(int i = 0; i<t; i++){

        cin >> a >> b >> c;

        if(c == a + b){
            cout << "+" << endl;
        } else {
            cout << "-" << endl;
        }
    }

    return 0;


}