// Using BFS , we use the concept of indegree to find topo sort
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> indegree(V,0);
        queue<int> p;
        vector<int> ans;
        vector<vector<int>> adj(V);
        
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        for(int i=0;i<V;i++){
            if(indegree[i] == 0){
                p.push(i);
            }
        }
        
        while(!p.empty()){
            int curr=p.front();
            p.pop();
            
            for(auto it:adj[curr]){
                indegree[it]--;
                if(indegree[it]==0){
                    p.push(it);
                }
            }
            ans.push_back(curr);
        }
        
        return ans;
        
    }
};

