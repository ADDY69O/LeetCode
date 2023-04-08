class Solution {
public:
    
    int solve(vector<int>nums,int i,int pick,vector<vector<int>>&res,vector<int>&ans){
        if(i==nums.size()){
            res.push_back(ans);
            return 0;
        }
        
        int take=0;
        if(pick==-1 || nums[pick] %nums[i] ==0 || nums[i]%nums[pick]==0 ){
            ans.push_back(nums[i]);
            take =  1 + solve(nums,i+1,i,res,ans);
            ans.pop_back();
        }
        int notTake= 0 + solve(nums,i+1,pick,res,ans);
        return max(take,notTake);
        
        
    }
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
//         vector<vector<int>>res;
//         vector<int>ans;
        
//        int maxi=  solve(nums,0,-1,res,ans);   
//         cout<<maxi<<endl;
//         for(int i=0;i<res.size();i++){
//             for(int j=0;j<res[i].size();j++){
//                 cout<<res[i][j]<<" ";
//             }
//             cout<<endl;
//         }
//         for(int i=0;i<res.size();i++){
//             if(res[i].size()==maxi){
//                 return res[i];
//             }
//         }
//         return ans;
        
                //printing  longest increasing subsequence
        int n = nums.size();
        vector<int>dp(n,1),hash(n);
     
        int last=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if( ( nums[i]% nums[j] ==0 || nums[j] %nums[i] ==0 ) && dp[i]< 1 + dp[j] ){
                    dp[i] = 1  + dp[j];
                    hash[i]=j;
              
                }
            }
            if(maxi<dp[i]){
                maxi=dp[i];
                last = i;
            }
        }
   
     
        
        vector<int>ans;
        while(hash[last]!=last){
            ans.push_back(nums[last]);
            last = hash[last];
         
            
        }
       ans.push_back(nums[last]);
        
        reverse(ans.begin(),ans.end());
        return ans;
        
        
    
    }
};