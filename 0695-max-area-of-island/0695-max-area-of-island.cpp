class Solution {
public:
    
    void dfs(vector<vector<int>>grid,int row,int col,vector<vector<bool>>&visited,int &count){ 
        int n=grid.size();
        int m=grid[0].size();
          
        visited[row][col]=1;
        
        int drow[]={1,0,-1,0};
        int dcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && !visited[nrow][ncol]){
                count++;
              dfs(grid,nrow,ncol,visited,count);
               
            }
        }
        
     

    }
    
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
     int n=grid.size();
        int m=grid[0].size();
        
    vector<vector<bool>>visited(n,vector<bool>(m,0));
        int maxi=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==1){
                    
                   int count=1;
                    dfs(grid,i,j,visited,count);
                    maxi=max(maxi,count);
                    
                }
            }
        }
            
        return maxi;
        
        
        
        
        
    }
};