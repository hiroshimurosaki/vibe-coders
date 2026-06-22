/*
 * Seating Arrangement (Easy Version) — Codeforces 2232C1  (rating 1300)
 * https://codeforces.com/problemset/problem/2232/C1
 * Tags: binary search, dp, greedy, two pointers
 */
#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--){
        
        int n, x, s;
        cin >> n >> x >> s;
        
        vector<int> avaiable(3,0);
        avaiable[0] = x; // Disponíveis para introvertidos 'I'
        avaiable[1] = 0; // Disponíveis para extrovertidos 'E'
        avaiable[2] = x*s; // Disponíveis para ambivertidos 'A'

        string ordem;
        cin >> ordem;
        
        int extroverts_remaing=0;
        int introverts_remaing=0;
        for(auto pessoa:ordem){
            if(pessoa == 'E') extroverts_remaing++;
            else if(pessoa == 'I') introverts_remaing++;
        }

        int count=0;
        for(char l: ordem){

            switch (l)
            {
            case 'I':
                if(avaiable[0]){
                    introverts_remaing--;
                    avaiable[0]--;
                    avaiable[1]+=s-1;
                    avaiable[2]--;    
                    count++;
                }
                break;
            case 'E':
                if(avaiable[1]){
                    extroverts_remaing--;
                    avaiable[1]--;
                    avaiable[2]--;
                    count++;
                }
                break;
            default:
                if(avaiable[2]){
                    if((avaiable[1]==0 || introverts_remaing-avaiable[0]+1 < extroverts_remaing-avaiable[1] ) && avaiable[0]>0){
                        avaiable[0]--;
                        avaiable[1]+=s-1;
                        avaiable[2]-=s;
                        count++;
                    }
                    else{
                        avaiable[1]--;
                        avaiable[2]--;
                        count++;
                    }
                }
                break;
            }

        }

        cout << count << endl;

    }
        

    return 0;

}