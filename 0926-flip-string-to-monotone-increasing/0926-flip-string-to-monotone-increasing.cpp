class Solution {
public:
    int minFlipsMonoIncr(string s) {
    int ans=0;
    int one=0;
        
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){
                one++;
            }
            if(s[i]=='0'){
                ans=min(ans+1,one);
            }
        }
        return ans;
        
    }
};