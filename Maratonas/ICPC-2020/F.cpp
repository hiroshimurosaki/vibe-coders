#include <bits/stdc++.h>

using namespace std;

int main()
{

    string s;
    cin >> s;

    int pl = 0;
    int pr = 0;
    int saque = 0;
    bool flag = false;
    int qual;

    vector<int> pontos = {0, 0};

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'S')
        {
            pontos[saque]++;
        }
        else if (s[i] == 'R')
        {
            saque ^= 1;
            pontos[saque]++;
        }
        else
        {
            if(flag){
                if(qual == 0){
                    printf("%d (winner) - %d\n", pl, pr);
                }else{
                    printf("%d - %d (winner)\n", pl, pr);
                }
            } else {
                if(saque == 0){
                    printf("%d (%d*) - %d (%d)\n", pl, pontos[0], pr, pontos[1]);
                }else{
                    printf("%d (%d) - %d (%d*)\n", pl, pontos[0], pr, pontos[1]);
                }
            }
        }
        if(((pontos[0] >= 5 || pontos[1] >= 5) && (abs(pontos[0] - pontos[1]) >= 2) || pontos[0] == 10 || pontos[1] == 10)){
            if(pontos[0] > pontos[1]){
                pl++;
                pontos[0] = pontos[1] = 0;  
            } else {
                pr++;
                pontos[0] = pontos[1] = 0;  
            }
            if(pl==2){
                flag = true;
                qual = 0;
            } else if(pr==2){
                flag = true;
                qual = 1;
            }
        }
    }

    return 0;
}
