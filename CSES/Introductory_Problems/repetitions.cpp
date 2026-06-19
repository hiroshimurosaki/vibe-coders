#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
 
    int maior = 1,aux=1;
    string a;
 
    cin >> a;
 
    for(int i=1;i<a.length();i++){
        if(a[i]==a[i-1]) aux++;
        else{
            if(maior<aux) maior = aux;
            aux=1;
        }
    }
    if(maior<aux) maior = aux;
            
    cout << maior << endl;
 
    return 0;
 
}