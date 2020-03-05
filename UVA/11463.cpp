#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> grafo;
int v, e;
#define INF 1000000000

vector<int> bfs(int v){
	vector<int> dist(grafo.size(), INF);
	queue<int> q;
	dist[v] = 0;
	q.push(v);
	while(!q.empty()){
		int w = q.front(); q.pop();
		for(int x: grafo[w])
			if(dist[x] == INF){
				dist[x] = 1 + dist[w];
				q.push(x);
			}
	}
	return dist;
}

int main(){

	int in;
	cin >> in;
	int count = 0;
	while(count < in){
		cin >> v >> e;
		grafo.assign(v, {});
		int a, b;
		while(e--){
			cin >> a >> b;
			grafo[a].push_back(b);
			grafo[b].push_back(a);
		}
		int o, d;
		cin >> o >> d;
		auto ida = bfs(o);
		auto vuelta = bfs(d);
		int mayor = 0;
		for(int i = 0; i < v; i++){
			mayor = max(mayor, ida[i] + vuelta[i]);
		}
		count++;
		cout<< "Case " << count << ": " << mayor << endl;
	}

	return 0;
}
