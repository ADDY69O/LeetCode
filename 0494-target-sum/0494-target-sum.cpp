class Solution {
public:
    int solve(vector<int>nums,int n,int target){
        
        
        vector<vector<int>>dp(n,vector<int>(target+1,0));
        
        if(nums[0]==0)dp[0][0]=2;
        else dp[0][0]=1;
        
        if(nums[0]!=0 && nums[0]<=target)dp[0][nums[0]]=1;
        
        
        for(int ind=1;ind<n;ind++){
            for(int sum=0;sum<=target;sum++){
                
                int nonPick= dp[ind-1][sum];
                int pick=0;
                if(nums[ind]<=sum){
                   pick= dp[ind-1][sum-nums[ind]];
                }
                
                dp[ind][sum]=pick+nonPick;
                
                
                
                
                
            }
        }
        
        return dp[n-1][target];
        
        
        
        
    }
    
    
    int findTargetSumWays(vector<int>& nums, int target) {
     
        // solving using the method sum1 - sum2 = d(target)
        int total=0;
        for(auto it:nums)total+=it;
        
        if(total-target<0 || (total-target)%2==1)return 0;
        else return solve(nums,nums.size(),(total-target)/2);
        
        
        
        
        
    }
};