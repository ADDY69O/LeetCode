class Solution {
public:
    
    int solve(string s1,string s2,int i){
   
        
    if(i>=s1.length())return -1;
    
        
        if(s2 == s1.substr(i,s2.length())  ){
              return i;
        }
        else{
            return solve(s1,s2,i+1);
        }
     
        
    }
    
    
    
    int strStr(string s1, string s2) {
        int i=0;
     
        return solve(s1,s2,i);
    }
};