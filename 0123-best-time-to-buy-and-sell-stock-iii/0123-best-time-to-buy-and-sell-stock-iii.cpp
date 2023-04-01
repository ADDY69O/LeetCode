class Solution {
public:
     int solve(vector<int>prices,int i,int buy,int limit){
        if(i==prices.size() || limit==0)return 0;
        int profit =0;
        if(buy){
            
            profit= max( -prices[i] + solve(prices,i+1,0,limit),0 +  solve(prices,i+1,1,limit));
        }
        else{
            profit= max(prices[i] + solve(prices,i+1,1,limit-1),0 + solve(prices,i+1,0,limit));
        }
        
        return profit;
        
        
    }
    int maxProfit(vector<int>& prices) {
          // return solve(prices,0,1,2); 
            int n = prices.size();
               //using tabulated approach
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        
     
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int limit = 0 ;limit<=2 ; limit++){
                    
                int profit=0;
                if(buy){
            
            profit= max( -prices[ind] + dp[ind+1][0][limit],0 + dp[ind+1][1][limit]);
        }
        else{
            if(limit >= 1)
            profit= max(prices[ind] + dp[ind+1][1][limit-1],0 +  dp[ind+1][0][limit]);
        }       
        
            dp[ind][buy][limit]= profit;
                    
                    
                    
                }
                
                
                
            }
            
            
        }
        
        return dp[0][1][2];
    }
};