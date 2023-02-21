class Solution {
public:
    
    void dfs(vector<int>adj[],unordered_map<int,bool>&visited,int node){
        
        visited[node]=1;
        queue<int>q;
        q.push(node);
        
        while(!q.empty()){
            int top=q.front();
            q.pop();
            
            for(auto it:adj[top]){
                if(!visited[it]){
                    q.push(it);
                    visited[it]=1;
                }
            }
        }
        
    }
    
    
    
    int solve(int V,vector<int>adj[]){
        unordered_map<int,bool>visited;
        
        
        int count=0;
        for(int i=1;i<V;i++){
            if(!visited[i]){
                dfs(adj,visited,i);
                count++;
            }
            
        }
        
        
    return count;
        
        
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V=isConnected.size()+1;
        //make the adjacency list
            vector<int>adj[isConnected.size()+1];
        for(int i=0;i<isConnected.size();i++)
        {
            
            for(int j=0;j<isConnected[i].size();j++){
                if(isConnected[i][j]==1  && i!=j){
                    adj[i+1].push_back(j+1);
                }
                
            }
            
        }
        
       return  solve(V,adj);
        
        
        
        
        
    }
};