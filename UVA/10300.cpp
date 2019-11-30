#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){


	int in;
	cin >> in;
	while(in--){
		int farmers;
		cin >> farmers;
		long sum = 0;
		while(farmers--){
			int s, a, f;
			cin >> s >> a >> f;
			sum += s * f;
		}
		cout << sum << endl;
	}

	return 0;
}
