class Solution {
    int solve(vector<int>nums,int i,vector<int>&dp){
        if(i>=nums.size()){
            return 0;
        }
        
        if(dp[i]!=-1){
            return dp[i];
        }
        
        int pick= nums[i] + solve(nums,i+2,dp);
        int nonpick=solve(nums,i+1,dp);
        
        return dp[i]=max(pick,nonpick);
    }
    
    
public:
    int rob(vector<int>& nums) {
        int i=0;
        vector<int>dp(nums.size()+1,-1);
        return solve(nums,i,dp);
    }
};