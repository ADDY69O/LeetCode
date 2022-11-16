class Solution {
public:
    int solve(int n,vector<int>&dp){
        
        if(n==0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
            
        int ans=INT_MAX;
        for(int i=1;i*i<=n;i++){
            ans=min(ans,1+solve(n-i*i,dp));
            
        }
        return dp[n]=ans;
            
        
        
    }
   int solveTab(int n){
        vector<int>dp(n+1,0);
        
        
        for(int target =1;target<=n;target++){
               int ans=INT_MAX;
          for(int i=1;i*i<=target;i++){
            ans=min(ans,1+dp[target-(i*i)]);
            
        }
         dp[target]=ans;
         
            
            
        }
        return dp[n];
        
        
    }
    
    int numSquares(int n) {
  return solveTab(n);
        
    }
};