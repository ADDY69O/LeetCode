class Solution {
public:
    //Approach 1 :  O(n^2)
    int BruteForce(vector<int>arr,int n){
        int maxi=0;
        
        for(int i=1;i<n-1;i++){
            
            int left=arr[i];
            int right=arr[i];
            
            for(int k=i-1;k>=0;k--){
                left=max(left,arr[k]);
            }
            
            for(int j=i+1;j<n;j++){
                right=max(right,arr[j]);
            }
            
            maxi+=min(left,right) - arr[i];
            
            
        }
        return maxi;
        
        
        
    }
    
    int suffPrefix(vector<int>arr,int n){
        
        
        vector<int>pre(n,0);
        vector<int>suff(n,0);
        pre[0]=arr[0];
        suff[n-1]=arr[n-1];
        int maxi=0;
        
        for(int i=1;i<n;i++){
            pre[i]=max(pre[i-1],arr[i]);
        }
        
        
        for(int j=n-2;j>=0;j--){
            suff[j]=max(suff[j+1],arr[j]);
        }

        
        for(int i=0;i<n;i++){
            int left = pre[i];
            int right=suff[i];
            
            maxi+=min(left,right) - arr[i];
        }
        
        return maxi;
    }
    
    
    int trap(vector<int>& height) {
        //Approach 1:
        
        // return BruteForce(height,height.size());   
        
        //Approach 2
        
        return suffPrefix(height,height.size());
    }
};