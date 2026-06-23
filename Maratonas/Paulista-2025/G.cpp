#include <bits/stdc++.h>

using namespace std;

int main(){

    string s;

    cin >> s;

    // int cont = 0;
    //     if((s[0] == 'B' && s[1] == 'R') || (s[0] == '?' || s[1] == '?')){
    //         if((s[0] == '?' || s[1] == '?') && (s[3] == 'S' && s[4] == 'P')){
    //             cout << "S" << endl;
    //             return 0;
    //     } else {
    //         if(s[3] == '?' && s[4] == 'P'){
    //             cout << 'T' << endl;
    //             return 0;
    //         } else if(s[3] == 'S' && s[4] == '?'){
    //             cout << 'T' << endl;
    //             return 0;
    //         }
    //         }
    //     }
    //     cout << 'N' << endl;
    //     return 0;

    if(s[2] == '?'){
        if(s[3] == 'S' && s[4] == 'P'){
            cout << 'S' << endl;
            return 0;
        }
    } else {
        if(s[0] == 'B' && s[1] == 'R'){
    
            if(s[3] == '?' && s[4] == 'P'){
                cout << 'T' << endl;
                return 0;
            } else if((s[3] == 'S' && s[4] == '?')){
                cout << 'T' << endl;
                return 0;
            } 
    
    
        }else{
            if(s[3] == 'S' && s[4] == 'P'){
                cout << 'S' << endl;
                return 0;
            }
        }

    }


    cout << 'N' << endl;

    return 0;


}