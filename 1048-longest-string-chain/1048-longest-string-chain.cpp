class Solution {
public:
    
    bool pred(string op1 ,string op2){
        if(op2.length()+1!=op1.length())return false;
        int i=0;
        int j =0;
        int n1 =op1.length();
        int n2 = op2.length();
        
        int count =0;
        
        while(i<n1 ){
            if(op1[i] == op2[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        
       if(i==n1 && j==n2 )return true;
    return false;
        
    }
    
    
    
    
    int solve(vector<string>words,int i,int pick,int n){
        if(n==i)return 0;
        
        int take=0;
        if(pick!=-1){
            cout<<words[i]<<" " << words[pick]<<" ";
            cout<<pred(words[i],words[pick]);
            cout<<endl;
            
        }
        if(pick ==-1 || pred(words[i],words[pick])){
            
            take = 1 + solve(words,i+1,i,n);
        }
        int nonTake = 0 + solve(words,i+1,pick,n);
        
        return max(take ,nonTake);
        
        
        
    }
    
    static bool comp (string &s1 ,string &s2){
        return s1.size()<s2.size();
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int n =words.size();
        // return solve(words,0,-1,n);
        vector<int>dp(n,1);
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(pred(words[i],words[j]) && dp[i] <dp[j] + 1){
                    dp[i] = dp[j] + 1;
                }
            }
            maxi = max(maxi,dp[i]);
        }
        return maxi;
        
    }
};