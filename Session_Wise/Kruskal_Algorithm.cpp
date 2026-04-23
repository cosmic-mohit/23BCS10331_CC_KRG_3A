#include <bits/stdc++.h>
using namespace std;

vector<int> parent(1e5), sz(1e5);

void make(int v) {
    parent[v] = v;
    sz[v] = 1;
}

int find(int v) {
    if (v == parent[v]) return v;
    return parent[v] = find(parent[v]); // Path Compression
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges;

    for (int i = 0; i < m; i++) { 
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w}); 
    }

    // Step 1: Initialize DSU
    for (int i = 1; i <= n; i++) {
        make(i);
    }

    // Step 2: Sort edges by weight
    sort(edges.begin(), edges.end(), [](auto &a, auto &b) {
        return a[2] < b[2];
    });

    int mstCost = 0;

    // Step 3: Kruskal's Algorithm
    for (auto &e : edges) {
        int u = e[0];
        int v = e[1];
        int w = e[2];

        if (find(u) != find(v)) {
            mstCost += w;
            unite(u, v);
        }
    }

    cout << "Minimum Cost Spanning Tree : " << mstCost << endl;

    return 0;
}