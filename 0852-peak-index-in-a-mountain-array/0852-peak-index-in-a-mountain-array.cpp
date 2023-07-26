class Solution {
public:
    int Approach1(vector<int>arr){
        
        for(int i=1;i<arr.size()-1;i++){
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
                return i;
            }
        }
        return -1;
    }
    
    int Approach2(vector<int>arr){
        int s=0;
        int e = arr.size()-1;
        int mid = s + (e-s)/2;
        
        while(s<=e){
            if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1]){
               return mid; 
            }
            else if(arr[mid-1]>arr[mid] && arr[mid]>arr[mid+1])
            {
                e = mid;
            }         
            else if(arr[mid-1]<arr[mid] && arr[mid]<arr[mid+1]){
                s = mid ;
            }
            mid = s + (e-s)/2;
        }
     return -1;   
    }
    
    
    int peakIndexInMountainArray(vector<int>& arr) {
        //BruteForce O(n);
        // return Approach1(arr);
        //BinarySearch O(logn)
        return Approach2(arr);
        
    }
};