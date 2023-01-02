class Solution {
public:
    bool detectCapitalUse(string s) {
        for(int i=0;i<s.length();i++){
            if(s[i]>=65 && s[i]<=90 && i!=0 && s[i-1]>=97 && s[i-1]<=122){
                return false;
            }
            else if(i>1 && s[i]>=97 && s[i-1]<=122 && s[i-1]>=65 && s[i-1]<=90 ){
                return false;
            }
            
            
            
        }
        return true;
    }
};