class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& graph) {
        
        vector<int>adj[V];
        
        for(auto e:graph){
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
	    
	    
	    vector<int>ans;
	    
	    while(!q.empty()){
	        int top=q.front();
	        q.pop();
	        ans.push_back(top);
	        
	        for(auto i : adj[top]){
	            ind[i]--;
	            if(ind[i]==0)
	                q.push(i);
	            
	        }      
	        
	        
	        
	    }
	    
	    
	    if(ans.size()==V){
            return ans;
        }
        else{
            return {};
        }
	    
    }
};