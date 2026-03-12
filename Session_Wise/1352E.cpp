#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // freq[x] = how many times x appears in array
        vector<int> freq(n + 1, 0);
        for (int x : a) {
            freq[x]++;
        }

        // prefix sum array
        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + a[i];
        }
        // mark sums that are valid "special"
        vector<bool> isSpecial(n + 1, false);
        // generate all subarrays of length >= 2
        for (int i = 0; i < n; i++) {
            for (int j = i + 2; j <= n; j++) {
                int sum = pref[j] - pref[i];
                if (sum > n) break;   // optimization
                if (freq[sum] > 0) {
                    isSpecial[sum] = true;
                }
            }
        }
        // count special elements
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (isSpecial[i]) {
                ans += freq[i];
        }
        }
        cout << ans << "\n";
    }

    return 0;
}