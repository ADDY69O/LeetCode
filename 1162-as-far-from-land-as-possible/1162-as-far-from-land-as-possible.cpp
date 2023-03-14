class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,0)); 
        vector<vector<int>>distance(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        
        
        
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(grid[i][j]==1){
                    q.push({{i,j},0});
                }
                
            }
        }
       
        
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int dist=q.front().second;
            q.pop();
            distance[row][col]=dist;
            
            int drow[]={1,0,-1,0};
            int dcol[]={0,1,0,-1};
            
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                
                if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && !visited[nrow][ncol] && grid[nrow][ncol]==0){
                    visited[nrow][ncol]=1;
                    q.push({{nrow,ncol},dist+1});
                    
                }
                
                
            }
            
            
        }
        int maxi=-1e9;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(distance[i][j]>maxi)maxi=distance[i][j];
            }
        }
        if(maxi==0)return -1;
        return maxi;
        
        
        
    }
};