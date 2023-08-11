class Solution {
public:
  int findMin(vector<int>& nums) {
        int n = nums.size();
        int s=0;
        int e=nums.size()-1;
        int mid = s + (e-s)/2;
        int mini =1e9;
        
        while(s<e){
            
            int prev = (mid + n -1)%n;
            int next = (mid + n +1)%n;
            if(nums[s]>nums[e]){
                if(mini==1e9)mini=e;
                else if(nums[mini]>nums[e]){
                     mini=e;   
                    }
                }
            
            else{
                 if(mini==1e9)mini=s;
                else if(nums[mini]>nums[s]){
                     mini=s;   
                    }
            }
            
            
            
         
            if(nums[prev]> nums[mid] && nums[mid]<nums[next]){
                return mid;
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
    
    int solve(vector<int>nums,int key,int s,int e){
       
        int mid = s + (e-s)/2;
        
        while(s<e){
            if(nums[mid]==key){
                return mid;
            }
            else if(nums[mid] < key){
                s = mid +1;
            }
            else if(nums[mid]>key){
                e =mid-1;
            }
            
            mid = s + (e-s)/2;
        }
        if(nums[s]==key)return s;
        return -1;
        
        
        
    }
    
    
    
    int search(vector<int>& nums, int target) {
        //approach 1 : using linear search
        
        
        //approach2 :using binary search
        
        if(nums.size()==1){
            if(nums[0]==target)return 0;
            else return -1;
        }
        
        
        //step 1 : find postion from the array is sorted
        int midP = findMin(nums);
        cout<<midP<<endl;
        if(nums[midP]==target)return midP;
       int FirstHalf = solve(nums,target,0,midP-1);
        int SecondHalf=solve(nums,target,midP,nums.size()-1);
        if(FirstHalf!=-1)return FirstHalf;
        else if(SecondHalf!=-1)return SecondHalf;
        else return -1;
        
        
        
        
    }
};