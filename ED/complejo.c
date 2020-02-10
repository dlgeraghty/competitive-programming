#include <iostream>

using namespace std;

#include "complejo.h"

int main(){

	int in;
	cin >> in;
	while(in--){
		float a;
		float b;
		int c;
		cin >> a >> b >> c;
		complejo<float> z(a, b);
		bool m = true;
		complejo<float> y(0,0);
		for(int i = 1; i <= c && m; i++){
			if(y.mod() > 2) m = false;
			else y = (y*y) + z;
		}
		if(m)
			cout << "SI";
		else
			cout << "NO";
		cout << endl;
	}
	return 0;
}
