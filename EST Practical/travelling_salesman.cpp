#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cstring>
using namespace std;


class TSP_BruteForce {
private:
    int n;
    vector<vector<int>> dist;
    int minCost;
    
public:
    TSP_BruteForce(vector<vector<int>>& distance) {
        dist = distance;
        n = distance.size();
        minCost = INT_MAX;
    }

    int solve() {
        vector<int> path;
        for (int i = 1; i < n; i++) {
            path.push_back(i);
        }
    
        do {
            int cost = dist[0][path[0]];
            for (int i = 1; i < n - 1; i++) {
                cost += dist[path[i - 1]][path[i]];
            }
            cost += dist[path[n - 2]][0];
            
            minCost = min(minCost, cost);
        } while (next_permutation(path.begin(), path.end()));
        
        return minCost;
    }
};


class TSP_DynamicProgramming {
private:
    int n;
    vector<vector<int>> dist;
    vector<vector<int>> dp;
    vector<vector<int>> parent;
    
public:
    TSP_DynamicProgramming(vector<vector<int>>& distance) {
        dist = distance;
        n = distance.size();
        dp.assign(n, vector<int>(1 << n, INT_MAX));
        parent.assign(n, vector<int>(1 << n, -1));
    }
    

    
    int solve() {

        dp[0][1] = 0; 
        
        for (int mask = 1; mask < (1 << n); mask++) {
        
            if (!(mask & 1)) continue;
            
            for (int i = 0; i < n; i++) {
                if (!(mask & (1 << i))) continue;
                if (dp[i][mask] == INT_MAX) continue;
                
             
                for (int j = 0; j < n; j++) {
                    if (mask & (1 << j)) continue; 
                    
                    int newMask = mask | (1 << j);
                    dp[j][newMask] = min(dp[j][newMask], 
                                        dp[i][mask] + dist[i][j]);
                }
            }
        }
        
    
        int fullMask = (1 << n) - 1;
        int minCost = INT_MAX;
        
        for (int i = 1; i < n; i++) {
            if (dp[i][fullMask] != INT_MAX) {
                minCost = min(minCost, dp[i][fullMask] + dist[i][0]);
            }
        }
        
        return minCost;
    }
};



class TSP_NearestNeighbor {
private:
    int n;
    vector<vector<int>> dist;
    
public:
    TSP_NearestNeighbor(vector<vector<int>>& distance) {
        dist = distance;
        n = distance.size();
    }
    
  
    
    int solve() {
        vector<bool> visited(n, false);
        int currentCity = 0;
        int totalCost = 0;
        visited[0] = true;
        
     
        for (int count = 1; count < n; count++) {
            int nearestCity = -1;
            int minDist = INT_MAX;
            
            for (int city = 0; city < n; city++) {
                if (!visited[city] && dist[currentCity][city] < minDist) {
                    minDist = dist[currentCity][city];
                    nearestCity = city;
                }
            }
            
            totalCost += minDist;
            visited[nearestCity] = true;
            currentCity = nearestCity;
        }
        
        totalCost += dist[currentCity][0];
        
        return totalCost;
    }
};

int main() {
    vector<vector<int>> dist = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    
    cout << "====== TRAVELLING SALESMAN PROBLEM ======\n\n";
    
    cout << "Distance Matrix:\n";
    for (auto& row : dist) {
        for (int d : row) {
            cout << d << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
    
    cout << "1. BRUTE FORCE (Permutation-based)\n";
    cout << "   Time: O(n!) | Space: O(n)\n";
    TSP_BruteForce bf(dist);
    cout << "   Minimum Cost: " << bf.solve() << "\n\n";
    
    cout << "2. DYNAMIC PROGRAMMING (Held-Karp)\n";
    cout << "   Time: O(n^2 * 2^n) | Space: O(n * 2^n)\n";
    TSP_DynamicProgramming dp(dist);
    cout << "   Minimum Cost: " << dp.solve() << "\n\n";
    
    cout << "3. NEAREST NEIGHBOR (Greedy Heuristic)\n";
    cout << "   Time: O(n^2) | Space: O(n)\n";
    cout << "   Note: Not always optimal, but very fast\n";
    TSP_NearestNeighbor nn(dist);
    cout << "   Approximate Cost: " << nn.solve() << "\n\n";
    cout << "\n====== LARGER EXAMPLE (6 cities) ======\n";
    vector<vector<int>> dist2 = {
        {0, 29, 20, 15, 17, 28},
        {29, 0, 24, 2, 20, 22},
        {20, 24, 0, 16, 14, 23},
        {15, 2, 16, 0, 28, 23},
        {17, 20, 14, 28, 0, 25},
        {28, 22, 23, 23, 25, 0}
    };
    
    cout << "DP Solution (optimal): ";
    TSP_DynamicProgramming dp2(dist2);
    cout << dp2.solve() << "\n";
    
    cout << "Nearest Neighbor (fast approximation): ";
    TSP_NearestNeighbor nn2(dist2);
    cout << nn2.solve() << "\n";
    
    return 0;
}
