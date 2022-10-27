class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>count;
        
        for(int i=0;i<nums.size();i++){
            int x=nums[i];
            int y=target-nums[i];
            
            
            if(count.find(y)!=count.end()){
                return {count[y],i+1};
            }
            else{
                count[x]=i+1;
            }
            
        }
        return{-1,-1};
    }
};