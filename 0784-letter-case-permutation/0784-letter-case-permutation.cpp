class Solution {
public:
    
       void solve(string nums,int i,string &ans,vector<string>&res){
        if(i==nums.size()){
            res.push_back(ans);
            return;
        }
        
        //pick 
           if(nums[i]>=97 && nums[i]<=122){ 
            int index = nums[i] - 'a';
            char newEle = 'A' + index;   
        ans.push_back(newEle);
                solve(nums,i+1,ans,res);
                 ans.pop_back();
        
        
        //nonPick
         ans.push_back(nums[i]);     
        solve(nums,i+1,ans,res);
               ans.pop_back();
           }
           else if(nums[i]>=65 && nums[i]<=90){
               
                int index = nums[i] - 'A';
            char newEle = 'a' + index;   
        ans.push_back(newEle);
                solve(nums,i+1,ans,res);
                 ans.pop_back();
        
        
        //nonPick
         ans.push_back(nums[i]);     
        solve(nums,i+1,ans,res);
               ans.pop_back();
           }
           else{
               ans.push_back(nums[i]);
               solve(nums,i+1,ans,res);
              ans.pop_back();
           }
            
        
        
    }
    
    vector<string> letterCasePermutation(string nums) {
     vector<string>res;
        string ans;
        int i=0;
        solve(nums,i,ans,res);
        return res;   
    }
};