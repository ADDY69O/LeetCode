class Solution {
public:
    
    
    int solve(vector<int>nums,int i,int pick){
        if(i==nums.size())return 0;
        int take=0;
        if(i==0 || pick==-1|| nums[i]>nums[pick]){
             
                take = 1 + solve(nums,i+1,i);
        }
        int notTake = 0 + solve(nums,i+1,pick);
        
        return max(take,notTake);        
        
    }
    
    int memoize(vector<int>nums,int i,int pick,vector<vector<int>>&dp){
          if(i==nums.size())return 0;
            if(dp[i][pick+1]!=-1)return dp[i][pick+1];
        
        int take=0;
        if(pick==0|| nums[i]>pick){
             
                take = 1 + solve(nums,i+1,nums[i]);
        }
        int notTake = 0 + solve(nums,i+1,pick);
        
        return dp[i][pick+1]= max(take,notTake);        
        
        
        
        
    }
    
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // return solve(nums,0,-1);
        // vector<vector<int>>dp(n+1,vector<int>(n+2,-1));
        // return memoize(nums,0,0,dp);
        
       vector<vector<int>>dp(n+1,vector<int>(n+2,0));
        
        
        for(int i=n-1;i>=0;i--){
            for(int pick=i-1;pick>=-1;pick--){
                int take=0;
           if(pick==-1 ||  nums[i]>nums[pick]){
             
                take = 1 + dp[i+1][i+1];
        }
        int notTake = 0 + dp[i+1][pick+1];
        
        dp[i][pick+1]= max(take,notTake);    
            }
            
            
        }
      
        
        return dp[0][0];
        
            
        
        
    }
};