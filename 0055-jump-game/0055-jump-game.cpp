class Solution {
public:
    bool solve(vector<int>nums,int i,vector<int>&dp){
      if(i>=nums.size()-1){
          return true;
      }
        if(nums[i]==0){
            return false;
        }
        
        if(dp[i]!=-1){
            return dp[i];
        }
        
        int maxi=i+nums[i];
        
        for(int idx=i+1;idx<=maxi;idx++){
            
            if(idx<nums.size() && solve(nums,idx,dp)){
         return  dp[i]=true;
            }
        }
       
        
        
     return dp[i]=false;   
        
    }
    
    
    bool canJump(vector<int>& nums) {
        // vector<int>dp(nums.size(),-1);
        // return solve(nums,0,dp);
       
        
        int n=nums.size();
        
        vector<int>dp(n,-1);
        dp[n-1]=1;
        
        for(int i= n-2;i>=0;i--){
            if(nums[i]==0){
                dp[i]=false;
             continue;   
            }
            
            int flag=0;
              int maxi=i+nums[i];
        
        for(int idx=i+1;idx<=maxi;idx++){
            
            if(idx<nums.size() && dp[idx]){
           dp[i]=true;
                flag=1;
                break;
            }
        }
            if(flag==1){
                continue;
            }
                
      dp[i]=false;  
       
            
        }
        return dp[0];
        
        
        
        
        
        
    } 
};