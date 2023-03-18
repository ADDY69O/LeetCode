class Solution {
public:
    int solve(string text1,string text2,int i,int j){
        if(i<0 || j<0)return 0;
        if(i==0 && j==0){
           
            return (text1[i]==text2[j]);
           
        }
        
       int nonPick=max(solve(text1,text2,i-1,j),solve(text1,text2,i,j-1));
        int pick=0;
        if(text1[i]==text2[j])pick=1+solve(text1,text2,i-1,j-1);
        
        return max(pick,nonPick);
        
    }
    
    
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        // return solve(text1,text2,i,j);
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        
        
        for(int j=0;j<=m;j++){
            dp[0][j]=0;
        }
        
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
             dp[i][j]=1+dp[i-1][j-1];
   
                }
                else{
                     dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
                    
                }
        
        
                
            }
        }
        return dp[n][m];
        
        
    }
};