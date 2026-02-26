#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

long long totalPairs(vector<int>& A) {
    long long n = A.size();
    long long ans = 0;

    for (int bit = 0; bit < 32; bit++) {
        long long cnt1 = 0;

        for (int i = 0; i < n; i++) {
            if (A[i] & (1 << bit))
                cnt1++;
        }

        long long cnt0 = n - cnt1;

        long long contribution = (cnt1 * cnt0) % MOD;
        contribution = (2 * contribution) % MOD; 

        ans = (ans + contribution) % MOD;
    }

    return ans;
}

int main() {
    vector<int> A = {2, 7};
    cout << totaPairs(A) << endl;
}
