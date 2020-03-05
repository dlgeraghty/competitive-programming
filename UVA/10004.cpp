#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define INF 99999
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main(){

	int v , e;
	while(cin >> v >> e && v != 0){
		vector<vii> grafo(v+1);
		int a, b;
		while(e--){
			cin >> a >> b;
			grafo[a].push_back(make_pair(b, 0));
			grafo[b].push_back(make_pair(a, 0));
		}
		int s = 0;
		//bfs coloring:
		queue<int> q; q.push(s);
		vi color(v, INF); color[s] = 0;
		bool isBipartite = true;
		while(!q.empty() && isBipartite){
			int u = q.front(); q.pop();
			for(int j = 0; j < (int)grafo[u].size();j++){
				ii w = grafo[u][j];
				if(color[w.first] == INF){
					color[w.first] = 1 - color[u];
					q.push(w.first);
				}else if(color[w.first] == color[u]){
					isBipartite = false;
					break;
				}
			}
		}
		if(isBipartite) cout << "BICOLORABLE." << endl;
		else cout << "NOT BICOLORABLE." << endl;
	}

	return 0;
}
