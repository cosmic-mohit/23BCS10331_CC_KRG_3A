#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;   

    vector<pair<int,int>> graph[n+1];

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;  
        graph[u].push_back({v, w});
    }

    vector<int> dist(n+1, INT_MAX);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[1] = 0;
    pq.push({0,1});

    while(!pq.empty()){
        int wt = pq.top().first;
        int v = pq.top().second;
        pq.pop();

        for(auto it : graph[v]){
            int adjNode = it.first;
            int currWt = it.second;

            if(dist[v] + currWt < dist[adjNode]){
                dist[adjNode] = dist[v] + currWt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    cout << "The Distance Array is: ";
    for(int i = 1; i <= n; i++){
        cout << dist[i] << " ";
    }
}