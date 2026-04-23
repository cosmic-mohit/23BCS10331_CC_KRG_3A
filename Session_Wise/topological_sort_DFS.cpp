// Topological sorting only works on 'Directed Acyclic Graph'
// It is linear ordering of vertices such that if there is an edge between u and v , u appears before v in that 
// Stack is used
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
  public:
      void dfs(int node, vector<vector<int>>& graph, vector<int>& visited, stack<int>& st) {
          visited[node] = 1;
          for (auto it : graph[node]) {
              if (!visited[it]) {
                  dfs(it, graph, visited, st);
              }
          }
          // Push the node to the stack after all its neighbors are processed
          st.push(node);
      }
  
      vector<int> topoSort(vector<vector<int>>& graph) { 
          int n = graph.size();
          vector<int> visited(n, 0);
          stack<int> st;
          vector<int> ans;
  
          for (int i = 0; i < n; i++) {
              if (!visited[i]) {
                  dfs(i, graph, visited, st);
              }
          }
  
          while(!st.empty()) {
              ans.push_back(st.top());
              st.pop();        
          }
  
          return ans;
      }
  };
  