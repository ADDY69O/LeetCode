class Solution {
public:
    
        int solveTab1(vector<int>nums){
        int n= nums.size();
    vector<int>dp(n+2,0);
        
        for(int i=n-2;i>=0;i--){
            
            
        int pick=nums[i]+dp[i+2];
            int nonPick=dp[i+1];
         dp[i]=max(pick,nonPick);
        
        }
        return dp[0];

    }
        int solveTab2(vector<int>nums){
        int n= nums.size();
    vector<int>dp(n+2,0);
        
        for(int i=n-1;i>=0;i--){
            
            
        int pick=nums[i]+dp[i+2];
            int nonPick=dp[i+1];
         dp[i]=max(pick,nonPick);
        
        }
        return dp[1];

    }
    
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
       return max(solveTab1(nums),solveTab2(nums));
    }
};