#include <bits/stdc++.h>

using namespace std;

int main(){


    int n;
    cin >> n;

    int soma = 0;

    for(int i=1; i<=n; i++){
        soma += i+2;
    }

    cout << soma << endl;

    return 0;


}