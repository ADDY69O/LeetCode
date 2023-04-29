class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxi=1;
        int maxCnt=0;
        vector<int>dp(n,1);
        vector<int>cnt(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                    
                if(nums[i]>nums[j] && 1 + dp[j]>dp[i]){
                 dp[i] = 1 + dp[j];
                    cnt[i]=cnt[j];
                }
                else if(nums[i]>nums[j] && 1 + dp[j]==dp[i]){
                    cnt[i]+=cnt[j];
                }
                
            }
            maxi=max(maxi,dp[i]);
          
        }
        
        for(int i=0;i<n;i++){
            if(dp[i]==maxi)maxCnt+=cnt[i];
        }
    
        return maxCnt;
        
    }
};