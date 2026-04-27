#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
private:
    vector<long long> tree;
    int n;
    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) {
            // Leaf node
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;
      
            build(arr, leftChild, start, mid);
            build(arr, rightChild, mid + 1, end);
            
            tree[node] = tree[leftChild] + tree[rightChild];
        }
    }
    

    long long query(int node, int start, int end, int left, int right) {

        if (right < start || left > end) {
            return 0;
        }
        
 
        if (left <= start && end <= right) {
            return tree[node];
        }
        
        int mid = (start + end) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;
        
        long long leftSum = query(leftChild, start, mid, left, right);
        long long rightSum = query(rightChild, mid + 1, end, left, right);
        
        return leftSum + rightSum;
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {

            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;
            
        
            if (idx <= mid) {
                update(leftChild, start, mid, idx, val);
            } else {
                update(rightChild, mid + 1, end, idx, val);
            }
            

            tree[node] = tree[leftChild] + tree[rightChild];
        }
    }

public:

    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n, 0);
        if (n > 0) {
            build(arr, 0, 0, n - 1);
        }
    }
    
  
    long long rangeSum(int left, int right) {
        if (n == 0 || left > right || left < 0 || right >= n) {
            return 0;
        }
        return query(0, 0, n - 1, left, right);
    }
    

    void updateElement(int idx, int val) {
        if (idx < 0 || idx >= n) {
            return;
        }
        update(0, 0, n - 1, idx, val);
    }
};

int main() {

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    SegmentTree sg(arr);
    
    cout << "=== Range Sum Query using Segment Tree ===" << endl;
    cout << "\nOriginal Array: ";
    for (int x : arr) cout << x << " ";
    cout << "\n" << endl;

    cout << "Query 1: Sum of elements [0, 3]: " << sg.rangeSum(0, 3) << " (Expected: 10)" << endl;
    cout << "Query 2: Sum of elements [2, 5]: " << sg.rangeSum(2, 5) << " (Expected: 18)" << endl;
    cout << "Query 3: Sum of elements [0, 7]: " << sg.rangeSum(0, 7) << " (Expected: 36)" << endl;
    

    cout << "\nUpdating arr[2] = 10 (was 3)" << endl;
    sg.updateElement(2, 10);
    
    cout << "Query 4: Sum of elements [0, 3]: " << sg.rangeSum(0, 3) << " (Expected: 17)" << endl;
    cout << "Query 5: Sum of elements [2, 5]: " << sg.rangeSum(2, 5) << " (Expected: 25)" << endl;
    
  
    cout << "\nUpdating arr[5] = 20 (was 6)" << endl;
    sg.updateElement(5, 20);
    
    cout << "Query 6: Sum of elements [2, 5]: " << sg.rangeSum(2, 5) << " (Expected: 39)" << endl;
    
    return 0;
}
