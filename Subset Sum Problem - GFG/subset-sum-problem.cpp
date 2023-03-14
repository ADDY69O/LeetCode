//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool solve(vector<int>arr,int i,int target){
        if(target==0)return true;
        if(i==0)return (arr[i]==target);
        
        
        int nonPick=solve(arr,i-1,target);
        int pick=0;
        if(arr[i]<=target)pick=solve(arr,i-1,target-arr[i]);
   
        return pick+nonPick;    
        
        
    }


    bool isSubsetSum(vector<int>arr, int sum){
    //   int i=arr.size()-1;
    //   return solve(arr,i,sum);
    int n=arr.size();
    int m=sum+1;
    vector<vector<bool>>dp(n,vector<bool>(m,0));
    
     
     
     for(int i=0;i<n;i++)dp[i][0]=true;
     
     if(arr[0]<=sum)dp[0][arr[0]]=true;
     
     for(int i=1;i<n;i++){
         for(int target=1;target<m;target++){
              bool nonPick=dp[i-1][target];
             bool pick=0;
            if(arr[i]<=target)pick=dp[i-1][target-arr[i]];
    
        dp[i][target]= pick||nonPick;    
             
         }
     }
    return dp[n-1][m-1];
    
    
    
    
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends