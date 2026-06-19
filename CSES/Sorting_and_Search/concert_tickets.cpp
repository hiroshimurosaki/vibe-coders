#include <bits/stdc++.h>

using namespace std;

int main(){

	int n,m;
	multiset<int> tickets;
	cin >> n >> m;

	int temp;
	for(int i=0;i<n;i++){
		cin >> temp;
		tickets.insert(temp);
	}

	int q;
	for(int i=0;i<m;i++){
		cin >> q;
		
		auto iterador = tickets.upper_bound(q);

		if(iterador == tickets.begin()) cout << -1 << endl;
		else{
			iterador--;
			cout << *iterador << endl;
			tickets.erase(iterador);
		}
		
	}

	return 0;
}

