//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
  
    
    void bfs(vector<int> adj[],unordered_map<int,set<int>>&count,unordered_map<int,bool>&visited,
    int node,vector<int>ans){
        queue<int>q;
        q.push(node);
        visited[node]=1;
        
        while(!q.empty()){
            int top=q.front();
            q.pop();
            
            ans.push_back(top);
            
            for(auto i:adj[node]){
                if(!visited[i]){
                    q.push(i);
                    visited[i]=1;
                }
            }
        }
        
    }
    
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
       unordered_map<int,set<int>>count;
       unordered_map<int,bool>visited;
       
       vector<int>ans;
       
       queue<int>q;
       
        q.push(0);
        visited[0]=1;
        
        while(!q.empty()){
            int top=q.front();
            q.pop();
            
            ans.push_back(top);
            
            for(auto i:adj[top]){
                if(!visited[i]){
                    q.push(i);
                    visited[i]=1;
                }
            }
        }
        
      
       
       return ans;
       
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends