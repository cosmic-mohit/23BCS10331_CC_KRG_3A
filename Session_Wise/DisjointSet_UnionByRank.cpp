// DSU - Union by Rank

#include <bits/stdc++.h>
using namespace std;

vector<int> parent(1e3);
vector<int> rankArr(1e3);

void make(int node) {
    parent[node] = node;
    rankArr[node] = 0; 
}

int find(int node) {
    if (parent[node] == node) return node;
    return parent[node] = find(parent[node]); // path compression
}

void unite(int u, int v) {
    int p1 = find(u);
    int p2 = find(v);

    if (p1 != p2) {
        if (rankArr[p1] < rankArr[p2]) {
            parent[p1] = p2;
        }
        else if (rankArr[p1] > rankArr[p2]) {
            parent[p2] = p1;
        }
        else {
            parent[p2] = p1;
            rankArr[p1]++; 
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        make(i);
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        unite(u, v);
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (find(i) == i) {
            cnt++;
        }
    }

    cout << "Total Number of components are : " << cnt << endl;
}