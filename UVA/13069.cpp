#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define INF 1000000000

int main(){

	int a, b;
	while(cin >> a >> b){
		int v[32767] = {};
		queue<int> q;
		q.push(a); v[a] = 1;
		while(!q.empty()){
			int u = q.front(); q.pop();
			if(v[b]) break;
			int x = ( u + 1 ) % 10000;
			if(v[x] == 0){
				v[x] = v[u] + 1;
				q.push(x);
			}
			x = ( u * 2 + 10000) % 10000;
			if(v[x] == 0){
				v[x] = v[u] + 1;
				q.push(x);
			}
			x = (u / 3);
			if(v[x] == 0){
				v[x] = v[u] + 1;
				q.push(x);
			}
		}
		cout << v[b] -1 << endl;
	}

	return 0;
}
