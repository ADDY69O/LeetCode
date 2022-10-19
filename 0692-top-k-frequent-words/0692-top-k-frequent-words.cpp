class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>count;
        
        for(int i=0;i<words.size();i++){
            count[words[i]]++;
            
        }
        vector<string>ans;
        
        for(int i=0;i<k;i++){
        int maxVal=INT_MIN;
        string maxi="";    
        for(auto i:count){
            if(i.second>maxVal){
                maxVal=i.second;
                maxi=i.first;
            }
        }
            ans.push_back(maxi);
            count[maxi]=0;
            maxi="";
            maxVal=INT_MIN;
            
        }
        
        
        return ans;
    }
};