class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
   map<int,int>count;
        priority_queue<int, vector<int>> pq;
        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;
            
        }
        map<int,bool>visited;
        vector<int>ans;
        
        for(auto it:count){
            pq.push(it.second);
        }
      
       while(k!=0){
           int front=pq.top();
           pq.pop();
           
           for(auto i:count){
               if(i.second==front && visited[i.first]==false){
                   ans.push_back(i.first);
                   visited[i.first]=true;
                   break;
               }
           }
           k--;
           
       } 
        
        return ans;
        
        
        
    }
};