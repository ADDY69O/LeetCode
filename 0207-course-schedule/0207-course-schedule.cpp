class Solution {
public:
    
     bool dfs(int node,vector<bool>&visited,vector<bool>&pre,vector<int>adj[]){
        
        
        visited[node]=1;
        pre[node]=1;
        
        
        for(auto i:adj[node]){
            if(!visited[i]){
            dfs(node,visited,pre,adj);
            }
            else if(visited[i] && pre[i]){
                return true;
            }
            
        }
        
        return false;
        
    }
    
    
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        
   
        vector<int>adj[V];
      
      for (auto e : prerequisites) {
		adj[e[1]].push_back(e[0]);
	}
        
        vector<int>ind(V);
	    
	    
	    //first initialize the indegree for the graph with the hekp of the adj list
	    
	    //suppose for example 1
	    
	    
	    // 1 ->  0
	    // 2 ->  0
	    // 3 ->  0
	    //                 0 , 1, 2, 3
	    //indegree array  [3 , 0, 0, 0  ]
	    
	    
	    
	    for(int i=0;i<V;i++){
	        
	        for( auto j:adj[i]){
	            ind[j]++;
	        }
	        
	        
	    }
	    
	    
	    queue<int>q;
	    
	    
	    //check if the indegree is 0 push it into the queue
	    for(int i=0;i<V;i++){
	        if(ind[i]==0)
	            q.push(i);
	        
	    }
	    
	    
	    int cnt=0;
	    
	    while(!q.empty()){
	        int top=q.front();
	        q.pop();
	        cnt++;
	        
	        for(auto i : adj[top]){
	            ind[i]--;
	            if(ind[i]==0)
	                q.push(i);
	            
	        }      
	        
	        
	        
	    }
	    
	    
        return cnt==V;
        
    }
};