class Solution {
public:
    string maximumOddBinaryNumber(string s) {
    
        string res="";
        //bits are in the form  ( 8, 4 2, 1)
        
        //it contain One bit -> 1
        
        //so simply count the number of ones 
        
        int count =0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1')count++;
        }
        count-=1;
        
        for(int i=0;i<s.length();i++){
            if(i==s.length()-1){
                res+='1';
            }
            else if(count>0){
                res+='1';
                count--;
            }
            else{
                res+='0';
            }
        }
        
        return res;
        
        
        
        
    }
    
};