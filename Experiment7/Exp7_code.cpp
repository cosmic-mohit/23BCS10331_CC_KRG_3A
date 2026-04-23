#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    // Relax edges K+1 times
    for (int i = 0; i <= k; i++) {
        vector<int> temp = dist;

        for (auto &flight : flights) {
            int u = flight[0];
            int v = flight[1];
            int price = flight[2];

            if (dist[u] != INT_MAX && dist[u] + price < temp[v]) {
                temp[v] = dist[u] + price;
            }
        }

        dist = temp;
    }

    return dist[dst] == INT_MAX ? -1 : dist[dst];
}

int main() {
    int n = 4;
    vector<vector<int>> flights = {
        {0,1,100}, {1,2,100}, {2,0,100}, {1,3,600}, {2,3,200}
    };
    int src = 0, dst = 3, k = 1;

    cout << findCheapestPrice(n, flights, src, dst, k);
    return 0;
}