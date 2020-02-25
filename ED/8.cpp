
#include <iostream>
#include "queue.h"

using namespace std;

int main(){

	int in;
	while(cin >> in ){
		if(in != 0){
			queue<int> q;
			q.push(in);
			while(cin >> in && in!= 0) q.push(in);
			q.duplicar();
			q.print();
		}
		cout << endl;
	}

	return 0;
}
