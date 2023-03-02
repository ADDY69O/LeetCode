class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        //basically finding the lowest cost with at most k stops
        
        vector<pair<int,int>>adj[n];
        
        
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
            
            
        }
        
        vector<int>s(n,INT_MAX);
       vector<int>cost(n,INT_MAX); 
                   priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        //push in the way  {stops,node,distance}
        pq.push({0,{src,0}});
        cost[src]=0;
        s[src]=0;
        
        while(!pq.empty()){
            int stop=pq.top().first;
            int node=pq.top().second.first;
            int dis=pq.top().second.second;
            pq.pop();
            
            for(auto i:adj[node]){
                int adjNode=i.first;
                int d=i.second;
                
                if(  stop+1<=k+1 ){
                    if(cost[adjNode]>dis+d){
                    cost[adjNode]=dis+d;
                    s[adjNode]=stop+1;
                    pq.push({s[adjNode],{adjNode,cost[adjNode]}});
                    }
                    }
                
            }
            
            
        }
        if(cost[dst]==INT_MAX)return -1;
        return cost[dst];
        
        
        
    }
};