#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    while(n--){

        int x, y;
        cin >> x >> y;

        if(x <= 200 && x >=-200 && y<=100 && y>=-100){

            //QUADRADO 1
            if (x >= 100 && x<=200 && y>0 && y<=100){
                cout << "N" << endl;
            } 
            
            //QUADRADO 2
            else if (x >= -200 && x<=-100 && y>=-100 && y<0){
                cout << "N" << endl;
            } 
            
            //TRIANGULO 1
            else if(x<=100 && x>=0 && y<=100 && y>=0 && y>-x+100){
                cout << "N" << endl;
            } 
            
            //TRIANGULO 2
            else if(x<=-100 && x>=-200 && y<=100 && y>=0 && y>x+200){
                cout << "N" << endl;
            } 
            
            //TRIANGULO 3
            else if(x<=0 && x>=-100 && y<=0 && y>=-100 && y<-x-100){
                cout << "N" << endl;
            }
            
            //TRIANGULO 4
            else if(x<=200 && x>=100 && y<=0 && y>=-100 && y<x-200){
                cout << "N" << endl;
            } 
            
            else {
                cout << "S" << endl;
            }
            
        } else {
            cout << "N" << endl;
        }


    }

    return 0;

}