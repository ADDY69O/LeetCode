class Solution {
public:
    void reverse (vector<int>&arr,int i ,int j ,int n){
        
        while(i<=j){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
        
    }
    
    
    void rotate(vector<int>& arr, int k) {
  
        // Optimized Approach
        
        // Step 1 :   Reverse (0,n-1)
        // Step 2 :   Reverse (0,k-1)
        // Step 3 :   Reverse (k,n-1)
        int n=arr.size();
        k = k % n;
        reverse(arr,0,n-1,n);
        reverse(arr,0,k-1,n);
        reverse(arr,k,n-1,n);
        
        
    }
};