class Solution
{
    bool solve(vector<int> nums, int val,int n,vector<vector<int>>&dp)
    {
        if( val==0){
            return 1;
        }
    
        if(n<=0 ){
            return 0;
        }
        if(dp[val][n]!=-1){
            return dp[val][n];
        }
            
        if(nums[n-1]<=val){  
            return dp[val][n]=(solve(nums,val-nums[n-1],n-1,dp) || solve(nums,val,n-1,dp));
        }
        else{
            return dp[val][n]= (solve(nums,val,n-1,dp)); 
        }

    }
    public:
        bool canPartition(vector<int> &nums)
        {

            int sum = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                sum += nums[i];
            }

            if (sum % 2 != 0)
            {
                return false;
            }
            else
            {
                int target = sum / 2;
               vector<vector<int>>dp(target+1,vector<int>( nums.size()+1,-1));    
                return solve(nums, target,nums.size(),dp);
            }
        }
};