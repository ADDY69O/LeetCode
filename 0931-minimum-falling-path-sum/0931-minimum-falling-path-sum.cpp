class Solution {
public:
    int solve(vector<vector<int>>matrix,int i,int j){
        if(i<0 || j<0 || j>=matrix.size())return 0;
     
     
        
        int con1=101;
            if(j>0)
         con1=min(con1,matrix[i][j-1]+solve(matrix,i-1,j-1));
        
        con1=min(con1,matrix[i][j]+solve(matrix,i-1,j));
        
        if(j+1<matrix.size())
        con1=min(con1,matrix[i][j+1]+solve(matrix,i-1,j+1));
        
        
        return con1;

        
        
        
        
        
        
    }
    
    
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
//         int maxi=INT_MAX;
//         for(int i=0;i<n;i++){
//             maxi=min(maxi, matrix[n-1][i]+solve(matrix,n-2,i));
            
//         }
//         return maxi;
        
        //tabulated solution
        int dp[n][n];
        
        for(int j=0;j<n;j++){
            dp[0][j]=matrix[0][j];
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                
                
                int leftEle=matrix[i][j];
                if(j>0)leftEle+=dp[i-1][j-1];
                else leftEle+=10000;
                
                int ele=matrix[i][j] + dp[i-1][j];
                
                int rightEle=matrix[i][j];
                if(j+1<n)rightEle+=dp[i-1][j+1];
                else rightEle+=10000;
                
                dp[i][j]=min(leftEle,min(ele,rightEle));
                
                
                
                
                
                
            }
        }
           
        
        int maxi=INT_MAX;
        for(int j=0;j<n;j++){
            maxi=min(maxi,dp[n-1][j]);
        }
        return maxi;
        
        
        
        
    }
};