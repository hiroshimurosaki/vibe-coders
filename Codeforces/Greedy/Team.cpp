/*
 * Team — Codeforces 231A  (rating 800)
 * https://codeforces.com/problemset/problem/231/A
 * Tags: brute force, greedy
 */
#include <bits/stdc++.h>

using namespace std;

int main(){

    int n,acc,temp,problems=0;

    cin >> n;

    while(n--){

        acc=0;
        for(int i=0;i<3;i++){
            cin >> temp;
            acc+=temp;
        }
        if(acc>=2) problems++;
    }

    cout << problems << endl;

    return 0;
    
}