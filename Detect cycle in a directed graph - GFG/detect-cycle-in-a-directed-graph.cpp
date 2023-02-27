//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    bool dfs(int node,vector<bool>&visited,vector<bool>&pre,vector<int>adj[]){
        
        
        visited[node]=1;
        pre[node]=1;
        
        
        for(auto i:adj[node]){
            if(!visited[i]){
           if(dfs(i,visited,pre,adj)){
               return true;
           }
            }
            else if(visited[i] && pre[i]==1){
                return true;  
            }
            
        }
        pre[node]=0;
        return false;
        
    }
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
      //using  the approach of storing the visited and previsited of the node
      
      
      vector<bool>visited(V);
      vector<bool>pre(V);
      
      
      
      for(int i=0;i<V;i++){
          
          if(!visited[i]){
              if(dfs(i,visited,pre,adj))
                return true;
          }
          
      }
      
      return false;
      
      
      
      
      
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends