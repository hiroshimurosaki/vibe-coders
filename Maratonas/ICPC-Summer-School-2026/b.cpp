#include <bits/stdc++.h>
typedef long long ll;
const ll MOD = 998244353;
using namespace std;

ll power(ll base, ll exp, ll mod) {
    ll result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

ll inv(ll a) { return power(a, MOD - 2, MOD); }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k;
    cin >> n >> k;

    // Precompute factorials and inverse factorials up to k
    vector<ll> fact(k + 1), inv_fact(k + 1);
    fact[0] = 1;
    for (int i = 1; i <= k; i++) fact[i] = fact[i-1] * i % MOD;
    inv_fact[k] = inv(fact[k]);
    for (int i = k - 1; i >= 0; i--) inv_fact[i] = inv_fact[i+1] * (i+1) % MOD;

    // Precompute surj[i] = number of surjections from k elements onto i elements
    // surj[i] = sum_{j=0}^{i} (-1)^j * C(i,j) * (i-j)^k
    vector<ll> surj(k + 1, 0);
    // Also precompute powers: pw[j] = j^k mod MOD for j = 0..k
    vector<ll> pw(k + 1);
    for (int j = 0; j <= k; j++) pw[j] = power(j, k, MOD);

    for (int i = 1; i <= k; i++) {
        ll val = 0;
        for (int j = 0; j <= i; j++) {
            ll term = inv_fact[j] % MOD * inv_fact[i-j] % MOD * pw[i-j] % MOD;
            if (j % 2 == 0) val = (val + term) % MOD;
            else            val = (val - term + MOD) % MOD;
        }
        surj[i] = val % MOD * fact[i] % MOD; // multiply by i! to get surj count
    }

    // Compute answers: r[i] = C(n, i) * surj[i]
    // C(n, i) computed incrementally: C(n,i) = C(n,i-1) * (n-i+1) / i
    ll comb = 1; // C(n, 0) = 1
    ll n_mod = n % MOD;
    for (int i = 1; i <= k; i++) {
        // comb = C(n, i) = C(n, i-1) * (n - i + 1) / i
        comb = comb % MOD * ((n_mod - i + 1 + MOD) % MOD) % MOD * inv(i) % MOD;
        ll ans = comb * surj[i] % MOD;
        cout << ans;
        if (i < k) cout << " ";
    }
    cout << "\n";

    return 0;
}
