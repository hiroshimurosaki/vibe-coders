/*
 * Raspberries — Codeforces 1883C  (rating 1000)
 * https://codeforces.com/problemset/problem/1883/C
 * Tags: dp, math
 */
#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){

        int n, k;
        cin >> n >> k;

        vector<int> modulo(k,0);

        for(int i=0; i<n; i++){
            int aux;
            cin >> aux;
            modulo[aux%k]++; 
        }

        if(modulo[0] || (modulo[2]>=2 && k == 4)){
            cout << 0 << endl;
            continue;
        } else {
            for(int i=k-1; i>0; i--){
                if(modulo[i] > 0){
                    if ((k == 4 && i == 1) && modulo[2]){
                        cout << 1 << endl;
                        break;
                    } else if((k == 4 && i == 1) && modulo[1] >= 2){
                        cout << 2 << endl;
                        break;
                    } else if(k!= 4 || i == 3){
                        cout << k-i << endl;
                        break;
                    }
                
                }
            }
        }
    }
    return 0;
}