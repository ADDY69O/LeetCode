class Solution {
       private:
  void solve(vector<int>nums, set<vector<int>>&ans,int i,vector<int>output){
        
        
        //base case
        if(i==nums.size()){
            sort(output.begin(),output.end());
            ans.insert(output);
            return;
        }
         
        //include
        output.push_back(nums[i]);
         solve(nums,ans,i+1,output);
        output.pop_back();
        
        //exclude
        solve(nums,ans,i+1,output);
            
       
        
        
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
          set<vector<int>>ans;
        vector<int>output;
        solve(nums,ans,0,output);
        vector<vector<int>>res;
        
        for(auto &v:ans){
            res.push_back(v);
        }
    
       
        return res;

    }
};