#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<int> restricoes(21,0);
void acender(int &mask, int pos){
    mask |= (1 << (pos));
}
void apagar(int &mask, int pos){
    mask &= ~(1 << (pos));
}

void escolhe_pao();
void escolhe_salsicha();
void escolhe_ingredientes(int j);

int n, m, p, s;
ll ans=0;
int conjunto=0;

void escolhe_pao(){
    for(int i=1;i<=p;i++){
        acender(conjunto,i);
        escolhe_salsicha();
        apagar(conjunto, i);
    }
}
void escolhe_salsicha(){
    for(int i=p+1;i<=p+s;i++){
        if(!(restricoes[i] & conjunto)){
            ans++;
            acender(conjunto,i);
            escolhe_ingredientes(s+p+1);
            apagar(conjunto, i);
        }
    }
}
void escolhe_ingredientes(int j){
    for(int i=j;i<=n;i++){
        if(!(restricoes[i] & conjunto)){
            ans++;
            acender(conjunto,i);
            escolhe_ingredientes(i+1);
            apagar(conjunto, i);
        }
    }
}


int main(){

    cin >> n >> m >> p >> s;
    
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        acender(restricoes[a],b);
        acender(restricoes[b],a);
    }

    escolhe_pao();

    cout << ans << endl;

    return 0;

}