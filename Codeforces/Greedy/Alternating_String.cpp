/*
 * Alternating String — Codeforces 2225B  (rating 900)
 * https://codeforces.com/problemset/problem/2225/B
 * Tags: brute force, greedy
 */
#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;

    cin >> t;

    for(int i=0; i<t; i++){

        string s;
        cin >> s;
        vector<int> aux(s.size());
        for(int j=0;j<s.size();j++) aux[j] = s[j] - 'a'; 
        
        // for (auto v : aux) cout << v << " ";
        // cout << endl; 

        int correto = aux[0]^1;
        int problemas = 0;
        bool flag = 0;
        for(int j = 1; j<aux.size(); j++){
            
            if(aux[j] != correto && !flag){
                flag = 1;
            } 
            else if (aux[j] == correto && flag){
                flag = 0;
                problemas++;
            }
            
            correto = !correto;

        }

        if(flag) problemas++;

        if(problemas == 1 || problemas == 0){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }


    }

    return 0;

}