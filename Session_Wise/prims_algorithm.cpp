// For finding MST

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// TC - O(E logE)
// SC - O(E)

int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<int> visited(V,0);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0,0});
        int sum=0;
        
        while(!pq.empty()){
            pair<int,int> curr = pq.top();
            int currSum=curr.first;
            int currNode=curr.second;
            pq.pop();
            
            if(!visited[currNode]){
              // Only mark visited when we are removing from priority queue(Not while adding)
                visited[currNode]=1;
                sum+=currSum;
                for(auto it:adj[currNode]){
                    if(!visited[it[0]]){
                      pq.push({it[1],it[0]});
                    }
                }
            }
            
        }
        return sum;

    }