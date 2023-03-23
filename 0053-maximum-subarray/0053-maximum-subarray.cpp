class Solution {
public:
    int maxSubArray(vector<int>& nums) {
     
        //using kadane's algorithm
        
        //if the sum gets less than zero initialized with zero 
    
        int maxi=INT_MIN;
        
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
              maxi=max(maxi,sum);
            if(sum<0)sum=0;
            cout<<sum<<endl;
            
           
            
            
        }
        
        
        return maxi;
        
        
        
        
        
        
    }
};