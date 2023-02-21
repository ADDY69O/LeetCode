class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();//row
        int maxTime=0;
        int m=grid[0].size();//col
        queue<pair<pair<int,int>,int>>q;
        
        vector<vector<int>>visited(n,vector<int>(m));
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    visited[i][j]=2;
                }
                
            }
        }
        
        
        while(!q.empty()){
            
            int row=q.front().first.first;
            int col=q.front().first.second;
            int time=q.front().second;
            q.pop();
            maxTime=max(time,maxTime);
            //check all the 4 directionally adjacency
            //check all the paths
            
            
            //-> for above path  row-1 and col
            if( row-1>=0 &&  grid[row-1][col]==1 && visited[row-1][col]!=2){
                q.push({{row-1,col},time+1});
                    visited[row-1][col]=2; 
                
            }
            //-> for above path  row+1 and col
            if(row+1<n && grid[row+1][col]==1&& visited[row+1][col]!=2){
                   q.push({{row+1,col},time+1});
                    visited[row+1][col]=2; 
                
            }
            //-> for above path  row and col-1
            if(col-1>=0 && grid[row][col-1]==1 && visited[row][col-1]!=2){
                   q.push({{row,col-1},time+1});
                    visited[row][col-1]=2; 
                
            }
            //-> for above path  row and col+1
            if(col+1 <m &&  grid[row][col+1]==1 && visited[row][col+1]!=2){
                
                   q.push({{row,col+1},time+1});
                    visited[row][col+1]=2; 
            }
            
            
            
        }
        
        
        for( int i =0;i<n;i++ ){
            
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && visited[i][j]==0){
                    return -1;
                }
                
            }
        } 
        
        
        return maxTime;
        
        
        
        
        
    }
};