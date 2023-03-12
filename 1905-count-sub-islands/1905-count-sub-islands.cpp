class Solution {
public:
    void bfs(vector<vector<int>>grid1,vector<vector<int>>grid2,int i,int j,vector<vector<bool>>&visited,bool &marked){
            int n=grid2.size();
        int m=grid2[0].size();
        visited[i][j]=1;
         
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty()){
                int row=q.front().first;
            int col=q.front().second;
            q.pop();
            
            int drow[]={1,0,-1,0};
            int dcol[]={0,1,0,-1};
            for(int i=0;i<4;i++)
            {
                int nrow = row + drow[i];
                int ncol=col +dcol[i];
                if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && grid2[nrow][ncol]==1 && !visited[nrow][ncol] ){
                    
                    if(grid1[nrow][ncol]!=1)marked=false;
                  
                    visited[nrow][ncol]=1;
                    q.push({nrow,ncol});
                    
                    
                } 
                
            }
            
            
            
        }
       
        
    }
    void dfs(vector<vector<int>>&grid1,vector<vector<int>>&grid2,int row,int col,bool &marked){
            int n=grid2.size();
        int m=grid2[0].size();
        grid2[row][col]=2;
        if(grid1[row][col]!=1)marked=false;
        
        int drow[]={1,0,-1,0};
        int dcol[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && grid2[nrow][ncol]==1 ){
            
                         dfs(grid1,grid2,nrow,ncol,marked);
                
            }
            
        }
       
        
    }
    
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        int n=grid2.size();
        int m=grid2[0].size();
      
        
        
        int maxi=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1 && grid2[i][j]== grid1[i][j]){
                bool marked=true;
              
               dfs(grid1,grid2,i,j,marked);
                    // cout<<marked<<endl;
                    if(marked){
                        maxi++;
                    }
              
                   
                    
                }
                
            }
        }
        
        return maxi;
        
    }
};