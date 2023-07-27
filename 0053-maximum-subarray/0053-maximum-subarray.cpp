class Solution {
public:
    int Brute(vector<int>nums){
        
        int maxi=-1e7;
        
        for(int i=0;i<nums.size();i++){
            int sum=0;
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                maxi=max(maxi,sum);
            }
        }
        
        return maxi;
        
    }
    
    int Approach1(vector<int>nums){
        int sum=-1e7;
        int currSum=0;
        
        
        for(int i=0;i<nums.size();i++){
            
            currSum+=nums[i];
            sum=max(sum,currSum);
            
            if(currSum<0){
                currSum=0;
            }
            
            
            
        }
        
        return sum;
        
        
        
    }
    
    int maxSubArray(vector<int>& nums) {
     
        //BrruteForce
        // return Brute(nums);
        
//         Optimised O(n)
        return Approach1(nums);
    }
};