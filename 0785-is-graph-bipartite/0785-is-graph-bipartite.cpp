class Solution {
public:
    bool bfs(vector<vector<int>>graph,vector<int>color,int node)
    {
        
        queue<int>q;
        
        
        q.push(node);
        color[node]=0;
        
        while(!q.empty()){
            int top=q.front();
           
            q.pop();
            
            for(auto i:graph[top]){
                if(color[i]==-1){
                    q.push(i);
                       color[i]=!color[top];
                    }
                else if(color[top]==color[i]){
                    return false;
                }
            }
            
        }
        
        return true;
        
        
    }    
    
    bool isBipartite(vector<vector<int>>& graph) {
       
        int n=graph.size();
                
        vector<int>color(graph.size(),-1);
        
        for(int i=0;i<n;i++){
            if(!bfs(graph,color,i)){
                return false;
            }
        }
        
        
        

        //hame do hi color dena hai yaa tho 0 yaa 1
          
        
        
        return true;
        
        
        
        
    }
};