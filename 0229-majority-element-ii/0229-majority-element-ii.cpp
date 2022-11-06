class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int>count;
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;
        }
        
        for(auto i:count){
            if(i.second>n/3){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};