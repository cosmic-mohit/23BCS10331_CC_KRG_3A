#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    vector<int> seg;
    int n;

public:
    SegmentTree(int n) {
        this->n = n;
        seg.resize(4 * n); 
    }

    // Build the tree
    void build(int ind, int low, int high, vector<int>& arr) {
        if (low == high) {
            seg[ind] = arr[low];
            return;
        }

        int mid = (low + high) / 2;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);

        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    // Query sum in range [l, r]
    int query(int ind, int low, int high, int l, int r) {
        // No overlap
        if (high < l || low > r) return 0;

        // Complete overlap
        if (low >= l && high <= r) return seg[ind];

        // Partial overlap
        int mid = (low + high) / 2;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);

        return left + right;
    }

    // Update value at index i
    void update(int ind, int low, int high, int i, int val) {
        if (low == high) {
            seg[ind] = val;
            return;
        }

        int mid = (low + high) / 2;
        if (i <= mid)
            update(2 * ind + 1, low, mid, i, val);
        else
            update(2 * ind + 2, mid + 1, high, i, val);

        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    int n = arr.size();

    SegmentTree st(n);
    st.build(0, 0, n - 1, arr);
    cout << "Sum [1,3]: " << st.query(0, 0, n - 1, 1, 3) << endl;

    st.update(0, 0, n - 1, 1, 10); 
    cout << "After update, Sum [1,3]: " << st.query(0, 0, n - 1, 1, 3) << endl;

    return 0;
}