class Solution {
public:
    bool checkPossibility(vector<int>& arr) {
        int n =arr.size();
        int count =0;
        
        for(int i=1;i<arr.size();i++){
           
            if(arr[i-1] > arr[i]){
                 cout<<arr[i]<<" "<<i<<endl;
                //increase the count for non-decreasing
                count++;
                
                if(count>1)return false;
                
                if( i==1 ||  arr[i-2] <= arr[i]){arr[i-1] = arr[i];}
                else{
                    arr[i] = arr[i-1];
                }
                
            }
        }
        return true;
        
        
        
        
    }
};