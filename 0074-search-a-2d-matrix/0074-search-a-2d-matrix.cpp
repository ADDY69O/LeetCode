class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int n=matrix.size();
        int m=matrix[0].size();
        int s=0;
        int e=matrix[0].size()-1;
        if(s==e && matrix.size()==1){
            if(matrix[0][s]==target)return true;
            else return false;
        }
        int i=0;
        int  j=0;
        while(target>matrix[j][e]){
       
            j++;
            i++;
 if(j>n-1)return false;
        }
        
        //abb yha par binary search lagana hai
        
        int mid=s+(e-s)/2;
        
        while(s<=e){
            
            if(matrix[i][mid]==target){
                return true;
            }
            else if(matrix[i][mid] <target){
                s=mid+1;                   }
            else{
                e=mid-1;
            }
            
           mid=s + (e-s)/2; 
        }
        
       return false;
        
        
        
        
    }
};