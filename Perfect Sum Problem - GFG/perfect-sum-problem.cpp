//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod = (int)(1e9+7);
	//using recursion
	int solve(int arr[],int n,int target,int i){
	    if(i==0){
	        if(target==0 && arr[0]==0)return 2;
	        else if(target==0 || arr[0]==target)return 1;
	        else return 0;
	    }
	    
	    
	    int nonPick=0 +solve(arr,n,target,i-1);
	    
	    int pick=0;
	    if(arr[i]<=target){
	        pick=solve(arr,n,target-arr[i],i-1);
	
	    }
	    
	    return pick + nonPick;
	    
	    
	    
	}
	
	
	int perfectSum(int arr[], int n, int sum)
	{
            // return solve(arr,n,sum,n-1);
            
            //{using tabulated approach}
            
            vector<vector<int>>dp(n,vector<int>(sum+1,0));
            
            if(arr[0]==0)dp[0][0]=2;
            else dp[0][0]=1;
            
            if(arr[0]!=0 && arr[0]<=sum)dp[0][arr[0]]=1;
            
            
            for(int i=1;i<n;i++){
                for(int j=0;j<=sum;j++){
                 
                 int nonPick=0 +dp[i-1][j];
	    
	             int pick=0;
	             if(arr[i]<=j){
	                pick=dp[i-1][j-arr[i]];
	
	                         }
	    
	            dp[i][j]= (pick + nonPick)%mod;
	    
	    
	       
                }
            }
            
            return dp[n-1][sum] % mod;
            
            
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends