class Solution {
public:
     void  solve(vector<int>&candidate,int ind,set<vector<int>>&res,vector<int>&ans,int target){
      
      
          
      if(target==0){
          res.insert(ans);
          return;
      }
        
        
      for(int i=ind;i<candidate.size();i++){
          if(i>ind && candidate[i]==candidate[i-1])continue;
          
          if(candidate[i]>target)break;
            ans.push_back(candidate[i]);
          
          solve(candidate,i+1,res,ans,target-candidate[i]);
          
             ans.pop_back();
          
      }
     
      
     
      
      
        
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      set<vector<int>>res;
                
        
      sort(candidates.begin(),candidates.end());
            vector<int>debug;
     
          solve(candidates,0,res,debug,target);
      
        vector<vector<int>>ans;
        
        for(auto i:res){
            vector<int>d;
            for(auto j:i){
                d.push_back(j);
            }
            ans.push_back(d);
        }
            return ans;
    }
};