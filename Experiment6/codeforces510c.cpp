#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj(26);
vector<int> vis(26, 0);
string ans;
bool cycle = false;

void dfs(int u) {
    vis[u] = 1;
    for (int v : adj[u]) {
        if (vis[v] == 0) dfs(v);
        else if (vis[v] == 1) cycle = true;
    }
    vis[u] = 2;
    ans.push_back(char(u + 'a'));
}

int main() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n - 1; i++) {
        string s = a[i], t = a[i + 1];
        int len = min(s.size(), t.size());
        bool found = false;

        for (int j = 0; j < len; j++) {
            if (s[j] != t[j]) {
                adj[s[j] - 'a'].push_back(t[j] - 'a');
                found = true;
                break;
            }
        }

        if (!found && s.size() > t.size()) {
            cout << "Impossible\n";
            return 0;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (vis[i] == 0) dfs(i);
    }

    if (cycle) {
        cout << "Impossible\n";
        return 0;
    }

    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
}