#include <iostream>
using namespace std;

long long int sumDigits(long long int n){
	long long int sum = 0;
	while(n > 0){
		sum += n%10;
		n /= 10;
	}
	if(sum / 10 == 0) return sum;
	else return sumDigits(sum);
}

int main(){

	long long int in;
	while(cin >> in && in != 0){
		cout << sumDigits(in) << endl;
	}

	return 0;
}
