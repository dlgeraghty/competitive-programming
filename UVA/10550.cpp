#include <iostream>
using namespace std;

int main(){
	int f = 9;
	int i, a, b, c;
	while(cin >> i >> a >> b >> c && !(i == 0 && a == 0 && b == 0 && c == 0)){
		int initial = 80;
		int first = 0;
		if(i < a) first = i + (40 - a);
		else if(i > a) first = i-a;
		int second = 0;
		if(a > b) second = b + (40 - a);
		else if(a < b) second = b-a;
		int third = 0;
		if(b < c) third = b + (40 - c);// das toa la vuelta 
		else if(b > c)third = b-c;
		int sum = first + 40 + second + third + initial;
		//cout << "[DEBUG][sum] "<< initial<< " " << first << " 40 " << second << " " << third << " ";
		cout << sum * f << endl;

	}

	return 0;
}
