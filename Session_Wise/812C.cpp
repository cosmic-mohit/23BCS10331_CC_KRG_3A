#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;              // number of items
    long long S;        // total money available
    cin >> n >> S;
    vector<long long> a(n);  // base prices
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // Binary search on number of items we want to buy (k)
    int left = 0, right = n;
    int best_k = 0;           // maximum items we can buy
    long long best_cost = 0;  // minimum cost for that k



    while(left <= right) {
        int mid = (left + right) / 2;   // try buying mid items

        vector<long long> cost(n);

        // Calculate modified cost for each item
        // cost[i] = base price + (index * k)
        // index is (i + 1) because problem uses 1-based indexing
        for(int i = 0; i < n; i++) {
            cost[i] = a[i] + (long long)(i + 1) * mid;
        }


        // Sort to choose cheapest 'mid' items
        sort(cost.begin(), cost.end());


        // Calculate total cost of buying 'mid' cheapest items
        long long total = 0;
        for(int i = 0; i < mid; i++) {
            total += cost[i];
        }


        // If total cost is within budget
        if(total <= S) {
            best_k = mid;       // update answer
            best_cost = total;
            left = mid + 1;     // try to buy more items
        }
        else {
            right = mid - 1;    // try smaller k
        }
    }


    // Output result:
    // maximum items and minimum cost
    cout << best_k << " " << best_cost << endl;

    return 0;
}