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

int sinal(ll val) {
    if (val > 0) return 1;
    if (val < 0) return -1;
    return 0;
}

bool no_segmento(pt a, pt b, pt p) {
    return ((a - p) * (b - p)) <= 0;
}

int main() {

    int t;
    if (cin >> t) {
        while(t--) {
            pt P1, P2, P3, P4;
            cin >> P1 >> P2 >> P3 >> P4;

            ll cp1 = (P2 - P1) ^ (P3 - P1);
            ll cp2 = (P2 - P1) ^ (P4 - P1);
            ll cp3 = (P4 - P3) ^ (P1 - P3);
            ll cp4 = (P4 - P3) ^ (P2 - P3);

            int s1 = sinal(cp1), s2 = sinal(cp2);
            int s3 = sinal(cp3), s4 = sinal(cp4);

            if (s1 != s2 && s3 != s4) {
                cout << "YES\n";
            }
            else if (s1 == 0 && no_segmento(P1, P2, P3)) cout << "YES\n";
            else if (s2 == 0 && no_segmento(P1, P2, P4)) cout << "YES\n";
            else if (s3 == 0 && no_segmento(P3, P4, P1)) cout << "YES\n";
            else if (s4 == 0 && no_segmento(P3, P4, P2)) cout << "YES\n";
            else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}