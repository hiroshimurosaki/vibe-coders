/*
 * Petya and Strings — Codeforces 112A  (rating 800)
 * https://codeforces.com/problemset/problem/112/A
 * Tags: implementation, strings
 */
#include <bits/stdc++.h>

using namespace std;

int main(){

    string word1,word2;

    cin >> word1;
    cin >> word2;

    for(int i=0;i<(int)word1.size();i++){
        int temp = tolower(word1[i]) - tolower(word2[i]);
        if(temp == 0) continue;
        else if(temp < 0){
            cout << -1 << endl;
            return 0;
        }
        else{
            cout << 1 << endl;
            return 0;
        }
    }
    cout << 0 << endl;

    
    return 0;
    
}