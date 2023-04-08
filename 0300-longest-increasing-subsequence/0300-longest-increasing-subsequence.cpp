class Solution {
public:
    
    
    int solve(vector<int>nums,int i,int pick){
        if(i==nums.size())return 0;
        int take=0;
        if(i==0 || pick==-1|| nums[i]>nums[pick]){
             
                take = 1 + solve(nums,i+1,i);
        }
        int notTake = 0 + solve(nums,i+1,pick);
        
        return max(take,notTake);        
        
    }
    
    int memoize(vector<int>nums,int i,int pick,vector<vector<int>>&dp){
          if(i==nums.size())return 0;
            if(dp[i][pick+1]!=-1)return dp[i][pick+1];
        
        int take=0;
        if(pick==0|| nums[i]>pick){
             
                take = 1 + solve(nums,i+1,nums[i]);
        }
        int notTake = 0 + solve(nums,i+1,pick);
        
        return dp[i][pick+1]= max(take,notTake);        
        
        
        
        
    }
    int find(vector<int>arr, int ele)
{
    int n = arr.size();
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;

    while (s < e)
    {

        if (arr[mid] == ele)
        {
            return mid;
        }
        else if (arr[mid] < ele)
        {
            s = mid;
        }
        else
        {
            e = mid - 1;
        }

        mid = s + (e - s) / 2;
    }

    return s;
}
    
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // return solve(nums,0,-1);
        // vector<vector<int>>dp(n+1,vector<int>(n+2,-1));
        // return memoize(nums,0,0,dp);
        //using tabulation
//        vector<vector<int>>dp(n+1,vector<int>(n+2,0));
        
        
//         for(int i=n-1;i>=0;i--){
//             for(int pick=i-1;pick>=-1;pick--){
//                 int take=0;
//            if(pick==-1 ||  nums[i]>nums[pick]){
             
//                 take = 1 + dp[i+1][i+1];
//         }
//         int notTake = 0 + dp[i+1][pick+1];
        
//         dp[i][pick+1]= max(take,notTake);    
//             }
            
            
//         }
      
        
//         return dp[0][0];
        
        //using space optimization
            
//             vector<int>next(n+1,0);
        
        
//         for(int i=n-1;i>=0;i--){
//             vector<int>curr(n+1,0);
//             for(int pick=i-1;pick>=-1;pick--){
//                 int take=0;
//            if(pick==-1 ||  nums[i]>nums[pick]){
             
//                 take = 1 + next[i+1];
//         }
//         int notTake = 0 + next[pick+1];
        
//         curr[pick+1]= max(take,notTake);    
//             }
//             next=curr;
            
            
//         }
      
        
//         return next[0];
        
        //using 2nd tabulation approach
        
//         vector<int>dp(n,1);
//         int maxi=1;
//         for(int i=0;i<n;i++){
//             for(int prev=0;prev<i;prev++){
                
//                 if(nums[prev]<nums[i]){
//                     dp[i] = max(dp[i], 1 + dp[prev]);
//                 }
//             }
//             maxi=max(maxi,dp[i]);
//         }
        
//         return maxi;

        
        
    
        //using binary search
//         vector<int>ans;
//         ans.push_back(nums[0]);
//         for(int i=1;i<nums.size();i++){
//             if(ans.back()<nums[i]){
//                 ans.push_back(nums[i]);
//             }
//             else{
                  
//   vector<int>::iterator idx;
//                 int ele = nums[i];
//                 // int idx = find(ans,ele);
//                  idx = lower_bound(ans.begin(),ans.end(),ele);
//                 ans[idx - ans.begin()] = nums[i];
//             }
//         }
        
//         return ans.size();
        
            //printing  longest increasing subsequence
        vector<int>dp(n,1),hash(n);
     
        int last=0;
        int maxi=0;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if( nums[i]>nums[j] && dp[i]< 1 + dp[j] ){
                    dp[i] = 1  + dp[j];
                    hash[i]=j;
              
                }
            }
            if(maxi<dp[i]){
                maxi=dp[i];
                last = i;
            }
        }
   
        int count=0;
        for(int i=0;i<hash.size();i++){
            cout<<hash[i]<<" ";
        }
        cout<<"last element "<<endl;
        cout<<last<<endl;
        
        vector<int>ans;
        while(hash[last]!=last){
            ans.push_back(nums[last]);
            last = hash[last];
            count++;
            
            
        }
        
        for(int i=ans.size()-1;i>=0;i--){
            cout<<ans[i]<<" ";
        }
        
        
        return maxi;
         
        
    }
};