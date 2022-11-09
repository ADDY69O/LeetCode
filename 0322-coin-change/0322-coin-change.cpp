class Solution {
    int solve(int n , vector<int>coins){
    
          vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
     
      
        
        for(int target=1;target<=n;target++){
        
        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++){
            if(target-coins[i]>=0){
            int ans=dp[target-coins[i]];
            if(ans!=INT_MAX)
            {
                mini=min(ans+1,mini);
                
            }
            }
            
        }
            dp[target]=mini;
        }
     return dp[n];
    }
    
    
public:
    int coinChange(vector<int>& coins, int amount) {
      
       int ans= solve(amount,coins);
        if(ans==INT_MAX){
            return -1;
        }
        else{
            return ans;
        }
    }
};