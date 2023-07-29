class Solution {
public:
    
    void reverse(vector<int>&ans){
        int s=0;
        int e = ans.size()-1;
        
        while(s<e){
            swap(ans[s],ans[e]);
            s++;
            e--;
            
        }
        
        
        
        
    }
    
    
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int>s;
        
        for(int i=0;i<nums.size();i++){
              
            if( s.size()>0 && nums[i]<0 && s.top() >0){
             
                if(s.top() > abs(nums[i])){
                    continue;
                }
                else if(s.top()==abs(nums[i])){
                    s.pop();
                }
                else{
                    
                    while( !s.empty() && s.top()>0 && s.top() < abs(nums[i])){
                        s.pop();
                    }
                    if(s.empty()){
                        s.push(nums[i]);
                    }
                    else if(s.top()<0 && nums[i]<0){
                        s.push(nums[i]);
                    }
                    else if(abs(nums[i])==s.top()){
                        s.pop();
                    }
                    
                    
                    
                }
                
                }
                
            
            else{
                s.push(nums[i]);
            }
        }
        
        vector<int>ans;
        
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        
        reverse(ans);
        
        return ans;
    }
};