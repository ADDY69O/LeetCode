class Solution {
public:
    int solve(vector<vector<int>>grid,int row,int col){
        if(row<0 || col<0) return 1e9;
        if(row==0 && col==0)return grid[row][col];
        
        
        int up =1e9;
        if(row-1>=0){
            up = grid[row][col] + solve(grid,row-1,col);
        }
        
        
        
        int left=1e9;
        if(col-1>=0){
            left = grid[row][col] + solve(grid,row,col-1);
        }
      
            return min(left,up);
        
        
    }
    
    
    
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m= grid[0].size();
        
//         int row=n-1;
//         int col=m-1;
        
//         return solve(grid,row,col);
        int dp[n][m];
        
        
    
        
        
        
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                
                    if(row==0 && col==0){
                            dp[0][0]=grid[0][0];
                            
                    }
                else{
                   int up =1e9;
                        if(row-1>=0){
                            up = grid[row][col] + dp[row-1][col];
                        }



                        int left=1e9;
                        if(col-1>=0){
                            left = grid[row][col] + dp[row][col-1];
                        }

                            dp[row][col]= min(left,up);
            
                }
                    
            }
        }
        return dp[n-1][m-1];
        
        
        
        
    }
};