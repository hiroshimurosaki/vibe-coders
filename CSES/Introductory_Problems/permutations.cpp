#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
 
    int n;
    vector<int> vet;
    cin >> n;
 
    if(n == 1){
        cout << "1" << endl;
        return 0;
    }
    if(n<=3){
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    else if(n == 4){
        cout << "2 4 1 3" << endl;
        return 0;
    }
 
    vet.resize(n);
    int a = 1;
    for(int i=0;i<n;i+=2) vet[i] = a++;
    for(int i=1;i<n;i+=2) vet[i] = a++;
 
    for(auto x: vet) cout << x << " ";
    cout << endl;
 
    return 0;
 
}
