#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct pt {
    ll x, y;

    friend istream& operator>>(istream& input, pt& ponto) {
        input >> ponto.x >> ponto.y;
        return input;
    }

    pt operator-(pt opt) const {
        return {this->x - opt.x, this->y - opt.y };
    }

    // Produto vetorial (Cross Product)
    ll operator^(pt ponto) const {
        return this->x * ponto.y - this->y * ponto.x;
    }

    // Produto interno (Dot Product)
    ll operator*(pt ponto) const {
        return this->x * ponto.x + this->y * ponto.y;
    }
};

int main(){
    
    int n;
    cin >> n;

    vector<pt> poligono(n);
    for(auto &p:poligono) cin >> p;

    ll area=0;
    for(int i=0;i<poligono.size();i++){
        area+= poligono[i] ^ poligono[(i+1)%poligono.size()];
    }

    cout << abs(area) << endl;

    return 0;

}