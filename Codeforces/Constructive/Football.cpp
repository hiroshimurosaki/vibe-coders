/*
 * Football — Codeforces 1773F  (rating 800)
 * https://codeforces.com/problemset/problem/1773/F
 * Tags: constructive algorithms
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    if (!(cin >> n >> a >> b)) return 0;

    if (n == 1) {
        if (a == b) cout << "1\n";
        else cout << "0\n";
        cout << a << ":" << b << "\n";
        return 0;
    }

    if (a + b < n) {
        cout << n - (a + b) << "\n";
        for (int i = 0; i < a; i++) cout << "1:0\n";
        for (int i = 0; i < b; i++) cout << "0:1\n";
        for (int i = 0; i < n - (a + b); i++) cout << "0:0\n";
        return 0;
    }

    cout << "0\n"; 

    vector<pair<int, int>> ans(n);
    
    if (a == 0) {
        for(int i=0; i<n; i++) {
            ans[i] = {0, 1}; b--;
        }
        ans[n-1].second += b;
    } 
    else if (b == 0) {
        for(int i=0; i<n; i++) {
            ans[i] = {1, 0}; a--;
        }
        ans[n-1].first += a;
    } 
    else {
        ans[0] = {1, 0}; a--;
        ans[1] = {0, 1}; b--;
        
        for (int i = 2; i < n; i++) {
            if (a > 0) {
                ans[i] = {1, 0}; a--;
            } else {
                ans[i] = {0, 1}; b--;
            }
        }
        
        ans[0].first += a;
        ans[1].second += b; 
    }

    for (auto &p : ans) {
        cout << p.first << ":" << p.second << "\n";
    }

    return 0;
}