/*
 * Two Towers — Codeforces 1795A  (rating 800)
 * https://codeforces.com/problemset/problem/1795/A
 * Tags: brute force, implementation, strings
 */
    #include <bits/stdc++.h>

    using namespace std;

    int main(){

        int t;
        cin >> t;
        while(t--){
            int n1, n2;
            cin >> n1 >> n2;
            string pilha1;
            string pilha2;

            cin >> pilha1;
            cin >> pilha2;
            reverse(pilha2.begin(), pilha2.end());
            pilha1 += pilha2;
            int cont = 0;
            int size = 1;
            int maior = 1;

            for(int i =1; i<pilha1.size(); i++){
                if(pilha1[i] == pilha1[i-1]){
                    size++;
                } else if(size>1){
                    cont++;
                    maior = max(maior,size);
                    size = 1;
                }
            }
            if(size>1){
                cont++;
                maior = max(maior,size);
                size = 1;
            }

            if(maior >= 3 || cont >= 2){
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            }

        }

        return 0;

    }