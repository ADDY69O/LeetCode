class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
     
        //steps for finding the safe nodes
        
        
        int n=graph.size();
        
        vector<int>adj[n];
        
        
        // Step 1 : - first reverse the direction of the edges

        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[graph[i][j]].push_back(i);
                
                
            }
            
        }
        
        
        //Step 2 find the indegree of all the nodes
        
        
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
            for(auto j:adj[i]){
                indegree[j]++;
            }
            
            
        }
        
        
        queue<int>q;
        for(int i=0;i<n;i++){
            
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        set<int>ans;
        
        
        while(!q.empty()){
            int top=q.front();
            q.pop();
            ans.insert(top);
            
            for(auto i:adj[top]){
                indegree[i]--;
                if(indegree[i]==0)
                    q.push(i);
                
            }
            
            
            
        }
        
        
        vector<int>res;
        for(auto i:ans){
            res.push_back(i);
        }
        
        return res;
        
        
        
        
        
        
        
    }
};