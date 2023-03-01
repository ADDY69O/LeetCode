//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
      
          
      vector<pair<int,int>>adj[N];
      
      int n=edges.size();
     
      
      
      for(int i=0;i<n;i++){
         
              adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
          
      }
      vector<int>distance(N,INT_MAX);
      
      queue<pair<int,int>>q;
      q.push({0,0});
      distance[0]=0;
      
      while(!q.empty()){
          int node=q.front().first;
          int dis=q.front().second;
          q.pop();
          
          
          for(auto i:adj[node]){
              int adjNode=i.first;
              int d=i.second;
              
              
              if(dis + d <distance[adjNode]){
                  distance[adjNode]=dis+d;
                  q.push({adjNode,dis+d});
              }
          }
          
          
          
          
      }
      
      
      
        for(int i=0;i<distance.size();i++){
            
            if(distance[i]==INT_MAX){
                distance[i]=-1;
            }
            
        }
      
      
      return distance;
      
      
      
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends