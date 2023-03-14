class Solution {
public:
    int sum(vector<int>nums){
        int s=0;
        for(auto i:nums)s+=i;
        
        return s;
        
    }
    
    bool solve(vector<int>nums,int i,int target){
        if(target==0)return true;
        if(i==0)return (target==nums[i]);
        
        
        int pick= solve(nums,i-1,target-nums[i]);
        int nonPick=solve(nums,i-1,target);
        
        return pick+nonPick;
        
        
        
        
        
    }
    
    
    
    bool canPartition(vector<int>& nums) {
        // int i=nums.size()-1;
        int n=nums.size();
        int  totalSum=sum(nums);
        cout<<totalSum<<endl; 
        int half=totalSum/2;
        
        if(totalSum%2==1 || nums.size()==1)return false;
        
        
//         return solve(nums,i,target);
        
        vector<vector<bool>>dp(n,vector<bool>(half+1,0));
        
        
      
        
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        
        if(nums[0]<=half)
      dp[0][nums[0]]=true;
       
    
        
        for(int i=1;i<n;i++){
            
            for(int target=1;target<=half;target++){
            
          
               
                bool nonPick= dp[i-1][target];
            
                bool pick=false;
                if(nums[i]<=target){
                    pick=dp[i-1][target-nums[i]];
                }
               
                dp[i][target]=pick||nonPick;        
        
        
                
                
            }
            
        }
        
        return dp[n-1][half];
        
        
        
        
        
    }
};