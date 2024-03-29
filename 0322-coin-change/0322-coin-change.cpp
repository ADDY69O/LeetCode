class Solution {
public:
    //{using reccursion}
    int solve(vector<int>coins,int amount,int n,int i){
        
        if(i==0){
            if(amount%coins[0]==0)return amount/coins[0];
            else return 1e9;
        }
        
        
        
          int nonPick= 0 + solve(coins,amount,n,i-1);
        
      
          int pick=1e9;
        if(coins[i]<=amount){
            pick=1 + solve(coins,amount-coins[i],n,i);
        }
        
        
      
        return min(pick,nonPick);
        
        
    }
    
    
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        // int ans= solve(coins,amount,n,n-1);
        // if(ans==1e9)return -1;

        // return ans;

        //{using tabulated}
//         vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        
//        for(int i=0;i<=amount;i++){
//             if(i%coins[0]==0){
//                 dp[0][i]=i/coins[0];
//             }
//            else{
//                dp[0][i]=1e9;
//            }
//        }
        
        
//         for(int i=1;i<n;i++){
//             for(int j=0;j<=amount;j++){
            
//             int nonPick= 0 + dp[i-1][j];
        
      
//           int pick=1e9;
//         if(coins[i]<=j){
//             pick=1 + dp[i][j-coins[i]];
//         }
        
        
      
//         dp[i][j]= min(pick,nonPick);
                
//             }
//         }
        
//         int ans= dp[n-1][amount];
//         if(ans>=1e9)return -1;
//         return ans;
        
        //{using space optimization}
        
        vector<int>prev(amount+1,-1),curr(amount+1,-1);
        
        for(int T=0 ;T<=amount;T++){
            if(T%coins[0] ==0 )prev[T]=T/coins[0];
            else prev[T]=1e9;
        }
        
        
        for(int ind=1;ind<n;ind++){
            for(int target=0;target<=amount;target++){
                
                int nonPick= 0  + prev[target];
                
                int pick= 1e9;
                if(coins[ind]<=target){
                    pick = 1 + curr[target-coins[ind]];
                }
                
                
                curr[target]=min(pick,nonPick);
                    
                
                
                
                
            }
            prev=curr;
        }
        
       int ans= prev[amount];
        if(ans>=1e9)return -1;
        else return ans;
        
    }
};