class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        map<int,bool>count;
        for(auto i:arr){
            count[i]=1;
        }
        
        int s=1;
        
        while(k >0){
            if(count[s]!=0){
                s++;
            }
            else{
                
                k--;
                s++;
            }
        }
        return s-1;
        
        
    }
};