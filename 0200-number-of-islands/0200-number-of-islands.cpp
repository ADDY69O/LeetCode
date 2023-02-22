class Solution {
public:
    void bfs(int i,int j ,vector<vector<bool>>&visited,int n,int m,vector<vector<char>>grid){
        
        visited[i][j]=1;
        queue<pair<int,int>>q;
        q.push({i,j});
        
        
        while(!q.empty()){
            int row =q.front().first;
            int col=q.front().second;
            q.pop();
            int drow[]={1,0,-1,0};
            int dcol[]={0,1,0,-1};
            
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                
                if(  nrow>=0 && nrow<n && ncol>=0 && ncol<m &&grid[nrow][ncol]=='1' && !visited[nrow][ncol] ){
                    q.push({nrow,ncol});
                    visited[nrow][ncol]=1;
                }
                
            }
            
            
            
        }
        
        
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<bool>>visited(n,vector<bool>(m));
        int count=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
             if(grid[i][j]=='1' && !visited[i][j] ){
                  count++;
                 bfs(i,j,visited,n,m,grid);
                
             }
                
            }
        }
        
        return count;
        
        
        
    }
};