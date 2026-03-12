#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
{
  vector<int> dist(V, 1e8);
  dist[src] = 0;

  // Relax the edges for V-1 times
  for (int i = 0; i < V - 1; i++)
  {
    for (auto it : edges)
    {
      int u = it[0];
      int v = it[1];
      int wt = it[2];
      if (dist[u] != 1e8 && dist[v] > dist[u] + wt)
      {
        dist[v] = dist[u] + wt;
      }
    }
  }
  // Relax for one more time - To check for negative weight cycles
  for (auto it : edges)
  {
    int u = it[0];
    int v = it[1];
    int wt = it[2];

    if (dist[u] != 1e8 && dist[v] > dist[u] + wt)
    {
      return {-1};
    }
  }
  return dist;
}
