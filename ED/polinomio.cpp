#include <bits/stdc++.h>

#include "polinomio.h"

using namespace std;

int main(){

	int n;
	int x;
	while(cin && !cin.eof()){
		polinomio p;
		cin >> p ;
		if(!cin) break;
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> x;
			cout << p.evaluate(x) << " ";
		}
		cout << endl;
	}

	return 0;
}
