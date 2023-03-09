class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
    
        
        int prev1=0;
        int prev=nums[0];
        
        
        for(int i=1;i<n;i++){
            
            int pick = nums[i];
            if(i>1)pick+=prev1;
            
            int notPick=prev;
            prev1=prev;
            prev=max(pick,notPick);
            
            
        }
        
        return prev;
        
        
        
        
    }
};