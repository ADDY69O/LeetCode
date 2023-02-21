class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc, int color) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        int pre=grid[sr][sc];
         vector<vector<int>>visited(n,vector<int>(m));
        q.push({sr,sc});
        visited[sr][sc]=1;
        
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            grid[row][col]=color;
              //check all the 4 directionally adjacency
            //check all the paths
            
            
            //-> for above path  row-1 and col
            if( row-1>=0 &&  grid[row-1][col]== pre && visited[row-1][col]!=1 ){
                q.push({row-1,col});
                visited[row-1][col]=1;
                 
            }
            //-> for above path  row+1 and col
            if(row+1<n && grid[row+1][col]==pre && visited[row+1][col]!=1){
                   q.push({row+1,col});
                  visited[row+1][col]=1;
                
            }
            //-> for above path  row and col-1
            if(col-1>=0 && grid[row][col-1]==pre && visited[row][col-1]!=1){
                   q.push({row,col-1});
               visited[row][col-1]=1;
                
            }
            //-> for above path  row and col+1
            if(col+1 <m &&  grid[row][col+1]==pre && visited[row][col+1]!=1){
                
                   q.push({row,col+1});
                   visited[row][col+1]=1;
            }
            
        }
        
        return grid;
        
        
        
        
        
        
    }
};