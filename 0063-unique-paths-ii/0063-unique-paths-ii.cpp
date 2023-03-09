class Solution {
public:
    int solve(vector<vector<int>>grid, int row,int col,int i,int j){
        
        if(i<0 || j<0 || grid[i][j]==1)return 0;
        
        if(i==row && j==col)return 1;
        
        int left=solve(grid,row,col,i,j-1);
                int up=solve(grid,row,col,i-1,j);
    return left +up;
        
    }
    
    
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        // return solve(grid,0,0,n-1,m-1);
        int dp[n][m];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    dp[i][j]=0;
                }
                else if(i==0 && j==0){
                    dp[0][0]=1;
                }
                else{
                    int left=0,up=0;
                   if(j>0)
                    left=dp[i][j-1];
                    if(i>0)
                    up=dp[i-1][j];
                  dp[i][j]= left +up;
                    
                    
                }
                
                  
            }
        }
        
        return dp[n-1][m-1];
        
        
        
    }
};