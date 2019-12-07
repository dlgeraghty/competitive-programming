#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

int main(){

	int in;
	cin >> in; 			       
	while(in--){
		int a;
		cin >> a;
		a = ((((a * 567 / 9) + 7492) * 235) / 47) - 498;
		cout << abs((a%100)/10) << endl;
	}

	return 0;
}
