#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int,int>a , pair<int,int> b){
    return a.second < b.second;
}

int main() {

    int n;
    vector<pair<int,int>> movies;

    cin >> n;

    movies.resize(n);

    for(int i=0;i<n;i++) {
        cin >> movies[i].first >> movies[i].second;
    }

    sort(movies.begin(),movies.end(), comp);

    int watch=1, last=0;
    for(int i=1;i<n;i++){
        if(movies[i].first >= movies[last].second) {
            watch++;
            last = i;
        }
    }

    cout << watch << endl;

    return 0;

}
