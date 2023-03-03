class Solution {
public:
  void  solve(vector<int>&candidate,int i,vector<vector<int>>&res,vector<int>&ans,int target){
      
      
      
        if(target<=0 || i==candidate.size() ){
            if(target==0){
                res.push_back(ans);
                return;
            }
            return;
        }
        
        
      //pick or non - pick
      int ele =  candidate[i];
      
      //pick 
        ans.push_back(ele);
        solve(candidate,i,res,ans,target-ele);
        ans.pop_back();
      
      //non - pick
      
      solve(candidate,i+1,res,ans,target);
      
      
     
      
      
        
        
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      
        vector<vector<int>>res;
        
            vector<int>debug;
        int sum=0;
        int i=0;
            solve(candidates,i ,res,debug,target);
            
        
        
//          vector<vector<int>>ans;
        
//         for(auto i:res){
//             vector<int>d;
//             for(auto j:i){
//                 d.push_back(j);
//             }
//             ans.push_back(d);
//         }
        
        return res;
        
        
    }
};