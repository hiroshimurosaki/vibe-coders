#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;

    int inicio = 300;
    int ans = 0;

    for(int i=0;i<n;i++){

        int aux;
        cin >> aux;
        
        ans+=aux;
        inicio+=aux;

        if((420 < inicio && inicio < 600) || (1020 < inicio && inicio < 1200)){
            ans+=180;
            inicio+=180;
            inicio%=1440;
        }

    }

    cout << ans << endl;

    return 0;

}