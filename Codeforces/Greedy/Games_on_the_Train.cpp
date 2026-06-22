/*
 * Games on the Train — Codeforces 2236A  (rating 800)
 * https://codeforces.com/problemset/problem/2236/A
 * Tags: greedy, math
 */
#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;
        int maiortorre = 0;
        int menortorre = 8;
        for(int i =0; i<n; i++){
            int aux;
            cin >> aux;

            if(aux < menortorre){
                menortorre = aux;
            }
            if(aux > maiortorre){
                maiortorre = aux;
            }
        }

        cout << (maiortorre - menortorre) + 1 << endl;

    }

    return 0;

}