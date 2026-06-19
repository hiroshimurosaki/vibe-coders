#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    int t;
    cin >> t;
 
    while(t--){
        long long n;
        cin >> n;
 
        long long digs = 1;
        long long teto = 9;
        long long start = 1;
 
        while(n > digs*teto){
            n -= digs*teto;
            digs++;
            teto *= 10;
            start *= 10;
        }
 
        long long number = start+(n-1)/digs;
        int aux = (n-1)%digs;
 
        long long temp = 1;
        for(int i=0;i<digs-aux-1;i++){
            temp *= 10;
        }
 
        cout << (number/temp)%10 << '\n';
    }
 
    return 0;
}