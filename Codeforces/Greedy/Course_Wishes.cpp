/*
 * Course Wishes — Codeforces 2216A  (rating 900)
 * https://codeforces.com/problemset/problem/2216/A
 * Tags: greedy
 */
#include <bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        
        int n, k;
        cin >> n >> k;
        vector<int> wishes(n);
        vector<int> limits(k);
        vector<pair<int,int>> initial_wishes(n);

        for(int j=0; j<k; j++){
            cin >> limits[j];
        }
        for(int j=0; j<n; j++){
            cin >> wishes[j];
        }
        for(int j=0; j<n; j++){
            initial_wishes[j] = {wishes[j], j+1};
        }
        sort(initial_wishes.rbegin(),initial_wishes.rend());
        // cout << "teste" << endl;

        vector<int> ans;
        bool flag = true;
        
        for(int j = 0; j<n; j++){
            if(initial_wishes[j].first < k+1){
                for(int x=0; x<k+1-initial_wishes[j].first; x++){
                    ans.push_back(initial_wishes[j].second);
                }
                if(ans.size() > 1000){
                    cout << -1 << endl;
                    flag = !flag;
                    break;
                }
            }
        }

        if(flag){
            cout << ans.size() << endl;
            for (auto x:ans){
                cout << x << " ";
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }


    }

    return 0;


}