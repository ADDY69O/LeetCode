class Solution {
public:
    void dfs(int node,vector<int>adj[],int& count,vector<bool>&visited)
    {
       
        for(auto i:adj[node]){
            if(!visited[i]){
                visited[i]=1;
                count++;
                dfs(i,adj,count,visited);
            }
        }
        
        
    }    
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
   //markk the restricted elements
        vector<bool>visited(n,0);
      
        
        for(auto i:restricted){
            visited[i]=1;
        }
        
        
        vector<int>adj[n];
        
        for(int i=0;i<edges.size();i++){
        
            int ele1=edges[i][0];
            int ele2=edges[i][1];
        
          
            adj[ele1].push_back(ele2);                                                       adj[ele2].push_back(ele1);
       
            
            
            
        }
        int count=0;
       
                 visited[0]=1;
            
                 count++;
                dfs(0,adj,count,visited);
           
        return count;
        
        
        
    }
};