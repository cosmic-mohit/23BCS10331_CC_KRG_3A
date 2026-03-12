
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9; // Representing infinity (no edge)

void floydWarshall(vector<vector<int>> &dist, int V)
{
  for (int k = 0; k < V; ++k)
  {
    for (int i = 0; i < V; ++i)
    {
      for (int j = 0; j < V; ++j)
      {
        // If vertex k is on the shortest path from i to j, update dist[i][j]
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  // Check for negative cycles
  for (int i = 0; i < V; ++i)
  {
    if (dist[i][i] < 0)
    {
      cout << "Negative cycle detected!" << endl;
      return;
    }
  }

  // Print the shortest distance matrix
  cout << "Shortest distances between all pairs of vertices:\n";
  for (int i = 0; i < V; ++i)
  {
    for (int j = 0; j < V; ++j)
    {
      if (dist[i][j] == INF)
        cout << "INF ";
      else
        cout << dist[i][j] << " ";
    }
    cout << endl;
  }
}

int main()
{
  int V = 4;
  vector<vector<int>> dist = {
      {0, 3, INF, 5},
      {2, 0, INF, 4},
      {INF, 1, 0, INF},
      {INF, INF, 2, 0}};

  floydWarshall(dist, V);
  return 0;
}
