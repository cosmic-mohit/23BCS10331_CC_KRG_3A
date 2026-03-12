#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin >> t;
    while (t--) {
        int n;cin >> n;

        vector<long long> a(n);
        for (auto &x : a) cin >> x;

        vector<bool> used(n, false);
        vector<long long> ans;

        long long cur = 0, total_or = 0;
        for (auto x : a) total_or |= x;

        while (cur != total_or) {
            long long best = -1;
            int idx = -1;

            for (int i = 0; i < n; i++) {
                if (!used[i]) {
                    long long val = cur | a[i];
                    if (val > best) {
                        best = val;
                        idx = i;
                    }}}

            used[idx] = true;
            cur |= a[idx];
            ans.push_back(a[idx]);
        }

        for (int i = 0; i < n; i++) {
            if (!used[i]) ans.push_back(a[i]);}

        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}