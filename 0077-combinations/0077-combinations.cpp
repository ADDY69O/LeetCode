class Solution {
public:
    void solve(set<set<int>>&res,set<int>&s,int &n,int &k,int i){
        if(s.size()==k){
            res.insert(s);
            return;
        }
        
    
        
        for(int j=i+1;j<=n;j++){
            if(j!=i){
                s.insert(j);
                solve(res,s,n,k,j);
                s.erase(j);
                
            }
        }
        
        
        
        
    }
    
    
    vector<vector<int>> combine(int n, int k) {
        set<set<int>>res;
        
        for(int i=1;i<=n;i++){
            set<int>s;
                s.insert(i);
            solve(res,s,n,k,i);
            
        }
        
    vector<vector<int>>ans;
        
        for(auto i:res){
            vector<int>d;
            for(auto j:i){
                d.push_back(j);
            }
            ans.push_back(d);
        }
        
        return ans;
        
    }
};