#include <bits/stdc++.h>

using namespace std;

int main(){

	long long n;
	long long i=1,acc=0;
	
	cin >> n;
	
	while(n>=i){
		long long tam_bloco = 2*i;

		acc += i*((n+1)/(tam_bloco));

		long long rest = (n+1)%tam_bloco;

		if(rest>0 && rest - i >0) acc += rest - i;	
		
		i<<=1;
	
	}
	
	cout << acc << endl;


	return 0;

}
