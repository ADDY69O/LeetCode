class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        if(grid[0][0]==1)return -1;
        // if(grid.size()==1 && grid[0].size()==1)return 0;   
          priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>>distance(n,vector<int>(m,INT_MAX));
        
    
        
        
        int dx=n-1;
        int dy=m-1;
    
        pq.push({1,{0,0}});
        distance[0][0]=1;
        
        
        while(!pq.empty()){
            int d=pq.top().first;
            int srx=pq.top().second.first;
            int sry=pq.top().second.second;
            pq.pop();
            
            int drow[]={1,0,-1,0,-1,-1,1,1};
            int dcol[]={0,1,0,-1,-1,1,-1,1};
            
            for(int i=0;i<8;i++){
                int nrow=srx+drow[i];
                int ncol=sry+dcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==0 &&  (d+1)<distance[nrow][ncol]){
                    distance[nrow][ncol]=d+1;
                    pq.push({d+1,{nrow,ncol}});
                }
                
                
                
            }
            
            
            
        }
        
        
        
        if(distance[dx][dy]==INT_MAX)return -1;
        else return distance[dx][dy];
        
        
        
        
        
        
        
        
    }
};