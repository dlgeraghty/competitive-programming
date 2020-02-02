# competitive-programming

## This readme file will only contain algorithms.

### Graphs:
1. Shortest distances between every pair of vertices in a given edge weighted directed Graph:

```
//Floyd warshall
//AdjacencyMatrix
for(int k = 0; k < V; k++)
  for(int i = 0; i < V; i++)
    for(int j = 0; j < V; j++)
      AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);
      
