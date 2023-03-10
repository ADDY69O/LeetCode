class Solution {
public:
    int solve(vector<vector<int>>grid,int n,int m,int i,int j){
        if(i<0 || j<0)return 201;
        if(i==0 && j==0)return grid[i][j];
        
        
        int left=solve(grid,n,m,i,j-1);
            cout<<left<<" ";
        int up  =solve(grid,n,m,i-1,j); 
            cout<<right<<" ";
        cout<<endl;
        
        return grid[i][j]+ min(left,up);
        
        
        
    }
    
    
    int minPathSum(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        int dp[n][m];
       
        
        for(int i=0;i<n;i++ ){
            for(int j=0;j<m;j++){
                if(i==0 && j==0)dp[0][0]=grid[0][0];
                else{
                int l=201,u=201;
                if(j>0)l=dp[i][j-1];
                if(i>0)u=dp[i-1][j];
                
                dp[i][j]=grid[i][j]+ min(l,u);
                }
                
            }
        }
        
        
        
        return dp[n-1][m-1];
        
    }
};