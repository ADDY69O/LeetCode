class Solution {
public:
    int majorityElement(vector<int>& nums) {
    map<int,int>count;
        
        for(int i=0;i<nums.size();i++){
            
            count[nums[i]]++;
        }
        
        
        int maxi=INT_MIN;
        
        
        for(auto i:count){
            if(maxi<i.second){
                maxi=i.second;
            }
        }
        int num=-1;
        for(auto i:count){
            if(i.second==maxi){
                num=i.first;
            }
        }
        
        return num;
        
        
        
        
        
        
        
        
    }
};