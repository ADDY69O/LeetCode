class Solution {
public:
    
    void merge(vector<int>&ans,int s,int mid,int e)
    {
        
        //store the value 
        // from  start to mid in a;
        // from mid+1 to end in b;
        int len1=mid -s +1;
        int len2=e-mid;
        int i=0;
        vector<int>a(len1);
        for(int index=s;index<=mid;index++){
            a[i++]=ans[index];
        }
        
        
         int j=0;
        vector<int>b(len2);
        for(int index=mid+1;index<=e;index++){
            b[j++]=ans[index];
        }
    
        
    
        int index=s;
        i=0,j=0;
        while(i<len1 && j<len2){
            
            if(a[i]<b[j]){
                ans[index++]=a[i++];
            }
            else{
                ans[index++]=b[j++];
            }
            
            
        }
        
        
        while(i<len1){
            ans[index++]=a[i++];
        }
        while(j<len2){
            ans[index++]=b[j++];
        }
        
        
        
        
        
    }
    
    void mergeSort(vector<int>&ans,int s,int e){
        if(s>=e)return ;
        int mid = s + (e-s)/2;
        
        mergeSort(ans,s,mid);
        mergeSort(ans,mid+1,e);
        merge(ans,s,mid,e);
        
        
        
        
    }
    
    
    vector<int> sortArray(vector<int>& nums) {
        //sort using merge sort
        int s=0;
        int e=nums.size()-1;
        
        mergeSort(nums,s,e);
        
        return nums;
        
    }
};