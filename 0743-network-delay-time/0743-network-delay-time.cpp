class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<pair<int,int>>adj[n+1];
        
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        // node and the time
        queue<pair<int,int>>q;
        vector<int>distance(n+1,INT_MAX);
        vector<bool>visited(n+1,0);
        visited[0]=1;
        q.push({k,0});
        visited[k]=1;
        distance[k]=0;
        distance[0]=0;
        int maxi=0;
        
        while(!q.empty()){
            int node =q.front().first;
            int t=q.front().second;
           
            q.pop();
            
            for(auto i:adj[node]){
                int adjNode=i.first;
                int edw=i.second;
                
                if(!visited[adjNode] || distance[adjNode]>t + edw){
                   
                    distance[adjNode]=t+edw;
                    visited[adjNode]=1;
                    q.push({adjNode,t+edw});
                    
                }
                    
                    
                }
                
                
                
            }
            
            
         for(auto i:visited){
            if(!i)return -1;
        }
       
        for(auto i:distance){
            if(i>maxi)maxi=i;
        }
        return maxi;
           
            
        }
        
        
        
        
        
        
       
        
        
        
        
    
};