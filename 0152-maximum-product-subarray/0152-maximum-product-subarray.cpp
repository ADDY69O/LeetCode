class Solution {
public:
     int Approach1(vector<int>nums){

         int pre=1;
         int suff=1;
         int maxi=-1e7;
         for(int i=0;i<nums.size();i++){
             
             if(pre==0)pre=1;
             if(suff==0)suff=1;
             
             pre=pre * nums[i];
             suff= suff * nums[nums.size()-i-1];
             
             maxi = max(maxi,max(pre,suff));
             
             
         }
         return maxi;
         
        
    }
    int maxProduct(vector<int>& nums) {
        return Approach1(nums);
    }
};