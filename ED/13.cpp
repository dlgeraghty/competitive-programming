#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){

	int in;
	while( cin >> in && in != 0){
		int x;
		priority_queue <int, vector<int>, greater<int>> p;
		for(int i = 0; i < in; i++){
			cin >> x;
			p.push(x);
		}
		while(!p.empty()){
			cout << p.top() << " ";p.pop();
		}
		cout << endl;
	}
	return 0;
}

