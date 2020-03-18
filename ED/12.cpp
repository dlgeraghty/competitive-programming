#include <iostream>
#include <vector>

using namespace std;

int josephus(int n, int k){
	if(n == 1) return 1;
	else return (josephus(n-1, k) + k) %n+1;
}

int main(){

	int a, b;
	while( cin >> a >> b && a != 0)
		printf("%d\n", josephus(a, b));

	return 0;
}

