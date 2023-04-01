class Solution {
public:
    int solve(vector<int>prices,int i,int buy){
        if(i==prices.size())return 0;
        int profit =0;
        if(buy){
            
            profit= max( -prices[i] + solve(prices,i+1,0),0 +  solve(prices,i+1,1));
        }
        else{
            profit= max(prices[i],0 + solve(prices,i+1,0));
        }
        
        return profit;
        
        
    }
    
    
    int maxProfit(vector<int>& prices) {
        // return solve(prices,0,1);
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        
        dp[n][0]=0;
        dp[n][1]=0;
        
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                if(buy){
            
            profit= max( -prices[ind] + dp[ind+1][0],0 + dp[ind+1][1]);
        }
        else{
            profit= max(prices[ind],0 +  dp[ind+1][0]);
        }       
        
            dp[ind][buy]= profit;
                
            }
            
            
        }
        
        return dp[0][1];
        
        
    }
};