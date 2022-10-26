class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
                //rem //count
            map<int,int>count;
            count[0]=0;
            int sum=0;
            for(int i=0;i<nums.size();i++){
                    
                sum+=nums[i];
                if(count.find(sum%k)==count.end()){
                    count[sum%k]=i+1;
                }
                else if(count[sum%k]<i){
                  return true;
                   
                }
                
                
            }
        return false;
        
    }
};