#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
 
    string palavra;
    vector<int> freq(26,0);
    vector<char> aux_a,aux_b;
    int impares=0;
 
    cin >> palavra;
 
    for(auto l: palavra) freq[l-'A']++;
    
    
    for(auto f:freq){
        if(f%2) impares++;
    }
 
    if(impares>1){
        cout << "NO SOLUTION" << endl;
        return 0;
    }
 
    int idx = -1;
    for(int i=0;i<26;i++){
        if(freq[i]%2) idx = i;
        else{
            while(freq[i]){
                aux_a.push_back('A'+i);
                aux_b.push_back('A'+i);
                freq[i]-=2;
            }
        }
    }
 
    if(idx!=-1){
        for(int i=0;i<freq[idx];i++) aux_a.push_back('A'+idx);
        
    }
 
    for(auto x:aux_a) cout << x;
    for(vector<char>::iterator it=aux_b.end()-1; it!=aux_b.begin()-1; it--) cout << *it;
    cout << endl;
 
    return 0;
 
}