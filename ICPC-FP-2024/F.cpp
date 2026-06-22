#include <bits/stdc++.h>
using namespace std;
 
int main(){
 
    int p1 = 1, p2 = 1, result;
    int n;
 
    cin >> n;
 
    if(n == 0 || n ==1){
        cout << p1 << endl;
        return 0;
    }
 
 
    for(int i = 1; i<n; i++){
 
        result = p1 + p2;
        p1 = p2;
        p2 = result;
        
    }
 
    cout << result << endl;
   
}