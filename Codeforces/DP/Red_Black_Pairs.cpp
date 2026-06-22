/*
 * Red-Black Pairs — Codeforces 2225C  (rating 1100)
 * https://codeforces.com/problemset/problem/2225/C
 * Tags: dp, greedy
 */
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){

    
    int t;
    cin >> t;

    for(int i=0; i<t; i++){
        int n;
        cin >> n;
        int cont = n;

        vector<vector<char>> table(2,vector<char>(n));

        for(int j=0; j<n; j++){
            cin >> table[0][j];
        }
        for(int j=0; j<n; j++){
            cin >> table[1][j];
        }

        for(int j=0; j<n; j++){
            if(table[0][j] == table[1][j]){
                table[0][j] = '*';
                table[1][j] = '*';
                cont--;
            } else if(j+1 < n && table[0][j] == table[0][j+1]){
                table[0][j] = '*';
                table[0][j+1] = '*';
                cont--;
            } 
        }
        for(int j=0; j<n; j++){
            if(j+1 < n && table[1][j] == table[1][j+1] && table[1][j] != '*'){
                table[1][j] = '*';
                table[1][j+1] = '*';
                cont--;
            } 
        }

        cout << cont << endl;

    }

    return 0;

}