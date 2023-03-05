class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
         sort(intervals.begin(),intervals.end());
        vector<int>temp=intervals[0];
 
        
        vector<vector<int>>res;
        
        for(auto i:intervals){
            
            if(i[0]<=temp[1]){
                temp[1]=max(i[1],temp[1]);
            }
            else{
                res.push_back(temp);
                temp=i;
                
            }
            
            
            
        }
        
        res.push_back(temp);
        return res;
    }
};