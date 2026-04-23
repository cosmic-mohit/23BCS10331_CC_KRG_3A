#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
    vector<int> bit;
    int n;

public:
    FenwickTree(int n) {
        this->n = n;
        bit.resize(n + 1, 0); 
    }

    void update(int i, int val) {
        while (i <= n) {
            bit[i] += val;
            i += (i & -i);
        }
    }

    // Get prefix sum from 1 to i
    int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += bit[i];
            i -= (i & -i);
        }
        return sum;
    }
};

int main() {
    int n = 5;
    FenwickTree ft(n);

    int arr[] = {0, 2, 4, 5, 7, 8}; // 1-based

    // Build tree
    for (int i = 1; i <= n; i++) {
        ft.update(i, arr[i]);
    }

    cout << "Prefix sum up to 3: " << ft.query(3) << endl; // 2+4+5 = 11
    cout << "Prefix sum up to 5: " << ft.query(5) << endl; // total sum

    return 0;
}