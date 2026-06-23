#include <bits/stdc++.h>

using namespace std;

int main(){


    int n;

    cin >> n;

    vector<int> presentes(2000000,-1), mesa(n);
    priority_queue<pair<int,int>> maiores_gerais;

    int inicio=0;
    int curr_pos=0;
    int maior=INT_MIN;
    
    for(int i=0; i<n;i++){

        int aux;
        cin >> aux;

        mesa[curr_pos++] = aux;

        if(!(presentes[aux] == -1 || presentes[aux] < inicio)) inicio = presentes[aux];
        presentes[aux] = curr_pos;
        maiores_gerais.push({aux,curr_pos});
                
        while(maiores_gerais.top().second < inicio) maiores_gerais.pop();
        
        cout <<  maiores_gerais.top().first << " " << maiores_gerais.top().second << endl;


    }


}