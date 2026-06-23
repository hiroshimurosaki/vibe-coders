#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, r;

    cin >> n >> r;

    vector<bool> pessoas(n,false);


    for(int i=0; i<r; i++){

        int aux;
        cin >> aux;

        pessoas[aux-1] = true;

    }

    if(n == r){
        cout << "*";
    } else {
        for(int i=0; i<n; i++){
    
            if(!pessoas[i]){
                cout << i+1 << " ";
            }
    
        }
    }
    cout << endl;

    return 0;


}