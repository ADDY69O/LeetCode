class Solution {
public:
    int solve(vector<int>coins,int target,int i){
   
        if(i==0){
           return (target%coins[0]==0);
  }
            
            
          int nonPick= 0 + solve(coins,target,i-1);
          int pick=0;
            if(coins[i]<=target){
                pick=solve(coins,target-coins[i],i);
            }
        
        return pick+nonPick;
        
        
    }
    
    
    
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        // int count=0;
        // return solve(coins,amount,n-1);
       vector<vector<int>>dp(n,vector<int>(amount+1));
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0){
                dp[0][i]=1;
            }
            else{
                dp[0][i]=0;
            }
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=amount;j++){
             int nonPick= 0 + dp[i-1][j];
          int pick=0;
            if(coins[i]<=j){
                pick=dp[i][j-coins[i]];
            }
        
        dp[i][j]= pick+nonPick;
         
                
            }
        }
        
        return dp[n-1][amount];
        
        
        
    }
};