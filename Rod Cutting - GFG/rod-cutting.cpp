//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
  int solve(int price[],int sum,int i){
      
      if(i==0){
          
              if( sum%(i+1)==0  )return sum/(i+1) * price[i];
              else return 0;
              
      }
      
      
      
      int nonPick=0 + solve(price,sum,i-1);
      
      int pick=0;
      if(i+1<=sum){
          pick= price[i] + solve(price,sum-(i+1),i);
      }
      return max(pick,nonPick);
      
  }
  
  
    int cutRod(int price[], int n) {
        int sum=n;
        
        
    //   return solve(price,n,n-1);
      vector<vector<int>>dp(n,vector<int>(sum+1,0));
      
      for(int j=0;j<=sum;j++){
          dp[0][j]=j/1 * price[0];
      }
      
      
      for(int ind =1;ind<n;ind++){
          for(int target=0;target<=sum;target++){
                  
             int nonPick=dp[ind-1][target];
      
      int pick=0;
      if(ind+1<=target){
          pick= price[ind] + dp[ind][target-(ind+1)];
      }
      dp[ind][target]= max(pick,nonPick);
              
              
          }
      }
      
      return dp[n-1][sum];
      
      
      
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends