/*
 * Vlad and Shapes — Codeforces 1926B  (rating 800)
 * https://codeforces.com/problemset/problem/1926/B
 * Tags: geometry, implementation
 */
#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;

    cin >> t;

    while(t--){

        int n;
        cin >> n;
        vector<string> matriz(n);
        
        for(int i=0;i<n;i++){
            cin >> matriz[i];
        }

        for(int i=0;i<n;i++){
            int flag = 0;
            for(int j=0;j<n;j++){
                if(matriz[i][j] == '1'){
                    int k;
                    for(k=j+1;k<n && matriz[i][k] == '1';k++);
            
                    int aux = k - j - 1;
                    if(aux > 0 && i+aux < n && matriz[i+aux][j] == '1') cout << "SQUARE" << endl;
                    else cout << "TRIANGLE" << endl;
                    flag=1;
                    break;
                }
            }
            if(flag) break;
        }

    }

    return 0;
    
}