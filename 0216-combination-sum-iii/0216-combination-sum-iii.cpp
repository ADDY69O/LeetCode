class Solution {
public:
    
       void  solve(int k,int ind,set<vector<int>>&res,vector<int>&ans,int target){
      
      
          
      if(target==0 && ans.size()==k){
          res.insert(ans);
          return;
      }
        
        
      for(int i=ind;i<10;i++){
        
          
          if(i>target)break;
            ans.push_back(i);
          
          solve(k,i+1,res,ans,target-i);
          
             ans.pop_back();
          
      }
     
      
     
      
      
        
        
    }
    
    vector<vector<int>> combinationSum3(int k, int target) {
        
         set<vector<int>>res;
                
  
            vector<int>debug;
     
          solve(k,1,res,debug,target);
      
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