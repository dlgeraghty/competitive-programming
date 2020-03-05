#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> grafo;
int v, e;
vector<bool> vis;

int dfs(int v){
	int res = 1;
	vis[v] = true;
	for(int w: grafo[v]){
		if(!vis[w])
			res += dfs(w);
	}
	return res;
}

int main(){

	int in;
	cin >> in;
	while(in--){
		cin >> v >> e;
		grafo.assign(v, {});
		int a, b;
		while(e--){
			cin >> a >> b;
			grafo[a-1].push_back(b-1);
			grafo[b-1].push_back(a-1);
		}
		vis.assign(v, false);

		int mayor = 0;
		for(int i = 0; i < v; i++)
			if(!vis[i])
				mayor = max(mayor, dfs(i));
		cout << mayor << endl;
	}

	return 0;
}
