class Solution {
    
    void solve(string tiles,set<string>&res,string &s,map<int,int>&flag){
      for(int i=0;i<tiles.size();i++){
        
        if(flag[i]!=1){
            s.push_back(tiles[i]);
            flag[i]=1;
            res.insert(s);
            solve(tiles,res,s,flag);
             flag[i]=0;
            s.pop_back();
           
            
            
        }
      }
        
        
        
        
    }
    
public:
    int numTilePossibilities(string tiles) {
        set<string>res;
        string s;
        int i=0;
        map<int,int>flag;
        solve(tiles,res,s,flag);
        return res.size();
    }
};