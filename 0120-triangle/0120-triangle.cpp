class Solution {
public:
    int solve(vector<vector<int>>triangle,int n,int m,int i,int j){
        if(i>n || j>m  || i<0 || j<0)return 0;
        int sum1=0,sum2=0;
        if(i>0){
        sum1= solve(triangle,n,triangle[i-1].size(),i-1,j);
        sum2= solve(triangle,n,triangle[i-1].size(),i-1,j-1);
        }
        return triangle[i][j]+min(sum1,sum2);
        
        
    }
    
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int dp[n][n];
        
        
        for(int i=0;i<n;i++){
            dp[n-1][i]=triangle[n-1][i];
        }
        
        
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
               int sum1=0,sum2=0;
                if(i+1<n)
                 sum1= triangle[i][j] + dp[i+1][j];
                if(i+1<n && j+1<n)
                 sum2=triangle[i][j] + dp[i+1][j+1];
                
                dp[i][j]=min(sum1,sum2);
                
            }
            
        }
        
        
       
        
        return dp[0][0];
        
        
        

        
        
    }
};