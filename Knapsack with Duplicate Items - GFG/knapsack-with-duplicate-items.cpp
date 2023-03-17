//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
//using recurrsion
    int solve(int wt[],int val[],int W,int n,int i){
        
        if(i==0){
            if(W%wt[0]==0)return W/wt[0]*val[0];
            else return -1e9;
        }
        
        int nonPick=solve(wt,val,W,n,i-1);
        
        int pick=-1e9;
        if(wt[i]<=W)pick=val[i] + solve(wt,val,W-wt[i],n,i);
        
        return max(pick,nonPick);
        
        
        
    }


    int knapSack(int N, int W, int val[], int wt[])
    {
    //   return solve(wt,val,W,N,N-1);
    vector<vector<int>>dp(N,vector<int>(W+1,0));
    for(int j=0;j<=W;j++){
       dp[0][j]=((int)j/wt[0])*val[0];
    }
    
    
    for(int i=1;i<N;i++){
        for(int j=0;j<=W;j++){
          int nonPick=dp[i-1][j];
        
        int pick=0;
        if(wt[i]<=j)pick=val[i] + dp[i][j-wt[i]];
        
        dp[i][j]= max(pick,nonPick);
        
         
            
            
        }
    }
    
    return dp[N-1][W];
    
    
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends