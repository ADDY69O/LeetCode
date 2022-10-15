class Solution {
    private:
  void solve(vector<int>nums, vector<vector<int>>&ans,int i,vector<int>output){
        
        
        //base case
        if(i==nums.size()){
            ans.push_back(output);
            return;
        }
        
        
        //exclude
        solve(nums,ans,i+1,output);
            
        
        //include
        output.push_back(nums[i]);
         solve(nums,ans,i+1,output);
        
        
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>output;
        solve(nums,ans,0,output);
        return ans; 
        
            
        
        
    }
};