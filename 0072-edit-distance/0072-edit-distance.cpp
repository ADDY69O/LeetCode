class Solution {
public:
    
    int solve(string word1,string word2,int i,int j,vector<vector<int>>&dp){
        if(i==word1.length()){
            return word2.length()-j;
        }
        
        if(j==word2.length()){
            return word1.length()-i;
        }
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        
        if(word1[i]==word2[j]){
            return dp[i][j]= solve(word1,word2,i+1,j+1,dp);
        }
        else{
            //three operations 
            
            //insert
            int insert= 1 + solve(word1,word2,i,j+1,dp);
            
            int replace=1 +solve(word1,word2,i+1,j+1,dp);
            
            int remove= 1 + solve(word1 ,word2, i+1 ,j,dp);
            
            
            return dp[i][j]= min(insert,min(replace,remove));
            
        }
        
        
    }
    
    
    int minDistance(string word1, string word2) {
        int i=0;
        int j=0;
        vector<vector<int>>dp(word1.length(),vector<int>(word2.length(),-1));
        
        
        return solve(word1,word2,i,j,dp);
        
    }
};