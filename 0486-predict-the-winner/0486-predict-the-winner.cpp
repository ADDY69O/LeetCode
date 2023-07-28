class Solution {
public:

    
   vector<vector<vector<int>>>dp; 
    Solution(){
        dp=vector<vector<vector<int>>>(22,vector<vector<int>>(22,vector<int>(2,-1)));
    }
    int solve(vector<int>nums,int s,int e,bool p1Turn){
        if(s>e)return 0;
       
        if(s==e)  return dp[s][e][p1Turn]= nums[s];
        if(dp[s][e][p1Turn]!=-1)return dp[s][e][p1Turn];
        
        if(p1Turn){
            return dp[s][e][p1Turn]= max( nums[s] + solve(nums,s+1,e,false) , nums[e] + solve(nums,s,e-1,false));
            
        }
        else{
            return dp[s][e][p1Turn]= min(solve(nums,s+1,e,true),solve(nums,s,e-1,true));
        }
        
        
        
        
    }
    
    
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        
        int p1Scr=  solve(nums,0,nums.size()-1,true);
        int total=0;
        for(auto i:nums)total+=i;
        int p2Scr= total - p1Scr;
        
        return (p1Scr>=p2Scr);
    }
};