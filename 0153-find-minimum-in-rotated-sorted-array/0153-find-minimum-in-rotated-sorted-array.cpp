class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int s=0;
        int e=nums.size()-1;
        int mid = s + (e-s)/2;
        int mini =nums[0];
        
        while(s<e){
            
            int prev = (mid + n -1)%n;
            int next = (mid + n +1)%n;
            mini = min(nums[s],min(mini,nums[e]));
         
            if(nums[prev]> nums[mid] && nums[mid]<nums[next]){
                return nums[mid];
            }
            else if(nums[s]<=nums[mid]){
                s = mid +1;
            }
            else if(nums[e]>=nums[mid]){
                e = mid -1;
            }
            mid  = s + (e-s)/2;
        }
        return mini;
        
        
        
    }
};