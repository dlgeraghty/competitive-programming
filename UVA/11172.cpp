#include <iostream>
using namespace std;

int main(){

	long long int in;
	cin >> in;
	while(in--){
		long long int a;
		long long int b;
		cin >> a >> b;
		if(a < b) cout << "<";
		else if(a > b) cout << ">";
		else cout << "=";
		cout << endl;

	}

	return 0;
}
