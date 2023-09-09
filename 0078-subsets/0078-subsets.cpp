class Solution {
public:
    void solve(vector<int>nums,int i,vector<int>&ans,vector<vector<int>>&res){
        if(i==nums.size()){
            res.push_back(ans);
            return;
        }
        
        //pick 
        ans.push_back(nums[i]);
        solve(nums,i+1,ans,res);
        ans.pop_back();
        
        
        //nonPick
        solve(nums,i+1,ans,res);
        
        
        
        
    }
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>ans;
        int i=0;
        solve(nums,i,ans,res);
        return res;
    }
};