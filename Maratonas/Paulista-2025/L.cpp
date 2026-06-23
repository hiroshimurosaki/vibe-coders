#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;

    cin >> n;

    vector<int> numeros(n);

    if(n!= 2){
        cout << "S" << endl;
    } else {

        int x1, x2;

        cin >> x1;
        vector<int> v1(x1);

        for(int i=0; i<x1; i++){
            cin >> v1[i];
        }

        cin >> x2;
        vector<int> v2(x2);

        for(int i=0; i<x2; i++){
            cin >> v2[i];
        }

        reverse(v2.begin(),v2.end());

        v1.insert(v1.end(), v2.begin(), v2.end());
        

        bool flag = true;
        for(int i=0; i<v1.size(); i++){

            if(v1[i] == 1){
                if(!flag){
                    cout << 'N' << endl;
                    return 0;
                }
            } else if(v1[i] == 2){
                if(flag){
                    flag = false;
                }
            }

        }

        cout << 'S' << endl;

    }

    return 0;

}