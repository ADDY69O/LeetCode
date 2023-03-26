class Solution {
public:
    int solve(string s,int i,vector<int>&dp){
        
        if(i==s.length())return 1;
        if(dp[i]!=-1)return dp[i];
        
        
        int op1=s[i]-'0';
        int op2=0;
        if(i<s.length()-1){
            op2= 10*op1 + s[i+1] - '0';
        }
        
        
        
        
        int onePick=0;
        if(op1>0)onePick=solve(s,i+1,dp);

        int twoPick=0;
        if ( op1>0 && op2>0 &&  op2 <=26)twoPick=solve(s,i+2,dp);
        
        return dp[i]= onePick+twoPick;
        
        
    }
    
    
    int numDecodings(string s) {
        int n=s.length();
        // vector<int>dp(n,-1);
        // return solve(s,0,dp);
        
        int dp[102];
        dp[n]=1;
        dp[n+1]=1;
        
        for(int i=n-1;i>=0;i--){
            
            
        int op1=s[i]-'0';
        int op2=0;
        if(i<s.length()-1){
            op2= 10*op1 + s[i+1] - '0';
        }
        
        
        
        
        int onePick=0;
        if(op1>0)onePick=dp[i+1];

        int twoPick=0;
        if ( op1>0 && op2>0 &&  op2 <=26)twoPick=dp[i+2];
        
         dp[i]= onePick+twoPick; 
            
        }
        return dp[0];
        
        
    }   
};