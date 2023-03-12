class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succ, int start, int end) {
        
        
        // Step 1: create adjacency list
        vector<pair<int,double>>adj[n];
        
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succ[i]});
            adj[edges[i][1]].push_back({edges[i][0],succ[i]});

        }
        
        
        //step 2 create queue and distance 
             vector<double>distance(n,0);
        
        
        queue<pair<int,double>>q;
        
        q.push({start,1});
       
        distance[start]=1;
        
        
        while(!q.empty()){
            int node=q.front().first;
            double nodeProb=q.front().second;
            q.pop();
            
            
            for(auto i:adj[node]){
                int adjNode=i.first;
                double adjProb=i.second;
                if(distance[adjNode]<nodeProb*adjProb){
                  
                    distance[adjNode]=nodeProb*adjProb;
                    q.push({adjNode,distance[adjNode]});
                    
                }
              
                
                
            }
            
            
            
            
            
                
        }
       if(distance[end]==-1)return 0;
        return distance[end];
        
        
        
        
        
        
        
        
    }
};