# competitive-programming

## This readme file will only contain algorithms.

### Include the whole std:

```
#include <bits/sdtc++.h>
```

### Graphs:
1. Representation of a graph:

```
//Adjacency list:

vector<list<pair<int,int>>> adjList(vertices+1);

for(int i = 0; i < entries; i++){
  cin >> a >> b >> w;
  adjList[a].push_back(make_pair(b, w));
}

```

2. Shortest distances between every pair of vertices in a given edge weighted directed Graph:

```
//Floyd warshall
//AdjacencyMatrix
for(int k = 0; k < V; k++)
  for(int i = 0; i < V; i++)
    for(int j = 0; j < V; j++)
      AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);
      
