#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        ll maximo=0;    
        vector<int> vet(n);
        set<int> elementos;    
        for(auto &x: vet){
            cin >> x; 
            elementos.insert(x);
            maximo = max(maximo,(ll)x);
        }

        ll mex = 0;
        while (elementos.count(mex)) {
            mex++;
        }


        ll sum=0;
        if(maximo >= mex){
            sort(vet.rbegin(),vet.rend());

            sum = vet.size()*vet[0];
            
            int i;
            for(i=0;i<vet.size() && vet[i]!=0;i++);
            sum+= mex*(vet.size()-i);

        }
        else{
            sort(vet.begin(),vet.end());

            int i;
            for(i=0;i<vet.size() && mex > vet[i]+1;i++){
                sum+=2*(vet[i])+1;
            }
            sum+= mex*(vet.size()-i);
            for(;i<vet.size();i++){
                sum+=vet[i];
            }
        }
        
        cout << sum << endl;

    }


}