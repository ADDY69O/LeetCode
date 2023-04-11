class Solution {
public:
    
    void reverse(string &res,int i,int n){
            
        if(i==n/2)return;
        
        swap(res[i],res[n-1-i]);
        
        reverse(res,i+1,n);
        
        
        
    }
    
    
    string removeStars(string s) {
        int stars=0;
        
        string res="";
        
        for(int i=s.length()-1;i>=0;i--){
            if(stars>0 && s[i]!='*'){
                stars--;
                
            }
            else if(s[i]=='*'){
                stars++;
            }
            else{
                res+=s[i];
            }
        }
        
        reverse(res,0,res.length());
        
        
        return res;
        
       
        
    }
};