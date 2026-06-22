/*
 * Grasshopper on a Line — Codeforces 1837A  (rating 800)
 * https://codeforces.com/problemset/problem/1837/A
 * Tags: constructive algorithms, math
 */
#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    int a, b;

    cin >> t;

    for(int i = 0; i<t; i++){

        cin >> a >> b;

        if(a%b != 0){
            cout << "1" << endl;
            cout << a << endl;
        } else {
            cout << "2" << endl;
            cout << "1" << " " << a-1 << endl;
        }

    }

    return 0;

}