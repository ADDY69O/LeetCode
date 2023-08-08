class Solution {
public:
    int solve(vector<int>nums,int s,int e){
        if(s>e)return -1;
    
        int mid = s +(e-s)/2;
        
        while(s<=e){
            if(s==e)return s; 
            else if(mid-1>=s &&  nums[mid-1] > nums[mid] && nums[mid+1]>nums[mid] && mid+1 <=e){
                return mid;
            }
            else if(mid-1>=s && mid+1<=e && nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1]){
                return mid+1;
            }
           
            else{
                int ans1 = -1;
               
                    
                ans1=solve(nums,s,mid);
                
                int ans2=-1;
                if(mid+1<=e)ans2=solve(nums,mid+1,e);
                
                if(ans1==-1 && ans2!=-1)return ans2;
                else if(ans1!=-1&& ans2==-1)return ans1;
                else if(ans1!=-1 && ans2!=-1){
                    if(nums[ans1]<nums[ans2]){
                        return ans1;
                    }
                    return ans2;
                }
                return -1;
                
            }
            
            
            
            
            
            mid = s + (e-s)/2;
            
        }
        
        
     return -1;   
    }
    int findMin(vector<int>& nums) {
        // if(nums.size()==2)return min(nums[1],nums[0]);
        
       int index=  solve(nums,0,nums.size()-1);
        
        if(index!=-1)return nums[index];
        return nums[0];
    }
};