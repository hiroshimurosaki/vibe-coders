#include <bits/stdc++.h>

using namespace std;

vector<int> bob;
int ans = 0;

int encontrar_combinacao_soma(vector<pair<int,bool>>& numeros, int alvo) {
    int n = numeros.size();
    
    // Tabela DP: (n+1) x (alvo+1) inicializada com false
    vector<vector<bool>> dp(n + 1, vector<bool>(alvo + 1, false));

    // Uma soma 0 é sempre possível
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;
    }

    // Preenchendo a tabela
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= alvo; ++j) {
            if (numeros[i - 1].first <= j) {
                // Inclui ou exclui o número atual
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - numeros[i - 1].first];
            } else {
                // Exclui o número atual
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // Se o alvo não for alcançável
    if (!dp[n][alvo]) {
        return 0; // Retorna vetor vazio
    }

    // Backtracking para reconstruir a combinação
    std::vector<int> combinacao;
    int i = n, j = alvo;
    while (i > 0 && j > 0) {
        // Se o valor veio da inclusão do número atual (ou seja, não era possível sem ele)
        if (!dp[i - 1][j]) {
            numeros[i-1].second=true;
            // combinacao.push_back(numeros[i - 1]);
            j -= numeros[i - 1].first;
        } 
        i--;
    }

    return 1;
}


int  main() {
    
    int n;
    vector<pair<int,bool>> bags;
    vector<int> ana,bob;

    cin >> n;

    bags.resize(n);
    
    int sum=0;
    for(auto &x : bags){
        cin >> x.first;
        sum += x.first;
    }

    if(sum&1) {
        cout<< -1 << endl;
        return 0;
    }
    else{
        if(encontrar_combinacao_soma(bags,sum/2)){

            for(auto x: bags){
                if(x.second) ana.push_back(x.first);
                else bob.push_back(x.first);
            }
    
            int sum_ana=0, sum_bob=0, i=0, j=0;
            while(i<ana.size() && j<bob.size()){
                if(sum_ana <=  sum_bob){   
                    cout << ana[i] << " ";
                    sum_ana += ana[i++];
                }
                else{
                    cout << bob[j] << " ";
                    sum_bob += bob[j++];
                }
            }
            while(i<ana.size()){
                if(sum_ana <=  sum_bob){   
                    cout << ana[i++] << " ";
                }
            }
            while(j<bob.size()){
                if(sum_bob <=  sum_bob){   
                    cout << bob[j++] << " ";
                }
            }
            cout << endl;
        }
        else cout << -1 << endl;

    } 
    

    return 0;
}
