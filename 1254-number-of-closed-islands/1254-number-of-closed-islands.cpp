class Solution {
public:
    void dfs(vector<vector<int>>&grid,int row,int col,vector<vector<bool>>&visited){
        visited[row][col]=1;
        
           int n=grid.size();
        int m=grid[0].size();
        
        int drow[]={1,0,-1,0};
        int dcol[]={0,1,0,-1};
        
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && grid[nrow][ncol]==0 && !visited[nrow][ncol]){
                dfs(grid,nrow,ncol,visited);
            }
            
            
        }
        
        
        
        
    }
    
    int closedIsland(vector<vector<int>>& grid) {
         int n=grid.size();
        int m=grid[0].size();
        
        
        //mark the visited element that are 0 because it required to cover water from alll the directions 
            
        vector<vector<bool>>visited(n,vector<bool>(m,0));
        
        
        //check the upper row
        
        for(int j=0;j<m;j++){
            if(grid[0][j]==0){
                dfs(grid,0,j,visited);
                
            }
        }
        
          //check the last row
        
        for(int j=0;j<m;j++){
            if(grid[n-1][j]==0){
                dfs(grid,n-1,j,visited);
                
            }
        }
        
        
          //check the left row
        
        for(int i=0;i<n;i++){
            if(grid[i][0]==0){
                  dfs(grid,i,0,visited);
                
            }
        }
        
         //check the Right row
        
        for(int i=0;i<n;i++){
            if(grid[i][m-1]==0){
                   dfs(grid,i,m-1,visited);
                
            }
        }
        
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==0){
                    dfs(grid,i,j,visited);
                    count++;
                    
                }
                
                
            }
        }
        
        
        
        
        
        
        return count;
        
    }
};