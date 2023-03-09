class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
            if(nums.size()<3){
                if(nums.size()==1){
                return nums[nums.size()-1];    
                    }
                else{
                    return max(nums[n-1],nums[n-2]);
                }
            
        }
        int dp[n+1];
        dp[0]=nums[0];
        dp[1]=nums[1];
        
        
        dp[2]=dp[0]+nums[2];
        
        for(int i=3;i<n;i++){
            dp[i]=max(dp[i-2],dp[i-3]) +nums[i];
        }
    
        
        
        return max(dp[n-1],dp[n-2]);
        
        
        
    }
};