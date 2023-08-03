class Solution {
public:
    void solve(vector<int>&nums,int i,int n,vector<vector<int>>&res){
        if(i==n-1){
           res.push_back(nums);
            return;
        }
        
        for(int idx = i;idx<n;idx++){
            swap(nums[i],nums[idx]);
           
            solve(nums,i+1,n,res);
            swap(nums[i],nums[idx]);
            
            
        }
        
        
        
        
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        int n=nums.size();
        solve(nums,0,n,res);
        return res;
    }
};