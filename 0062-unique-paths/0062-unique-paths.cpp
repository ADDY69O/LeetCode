class Solution {
public:
    
    
    int solve(int m,int n,int i,int j,vector<vector<int>>&dp){
        if(i>=m || j>=n || i<0 || j<0 )return dp[i][j]= 0;
        if(m-1==i && n-1==j)return dp[i][j]=1;
        if(dp[i][j]!=-1)return dp[i][j];
        
       int right= solve(m,n,i,j+1,dp);
       int down= solve(m,n,i+1,j,dp);
        return dp[i][j]= right + down;
        
    }
    
    
    
    int uniquePaths(int m, int n) {
        //movment either right or down
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(m,n,0,0,dp);
        
    }
};