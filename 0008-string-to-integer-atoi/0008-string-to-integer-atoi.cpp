class Solution {
public:
    double solve(string s,int i,double num,bool get){
        
        if(i==s.length())return num;
        if(s[i]=='-' && s[i+1]=='+' || s[i]=='-' && s[i+1]=='-' ||s[i]=='+' && s[i+1]=='+' ||s[i]=='+' && s[i+1]=='-' )return num;
        else if(s[i]=='-'){
            if(i-1>=0 && s[i-1]>='0' && s[i-1]<='9'  )return num;
            return (-1)*solve(s,i+1,num,get);
        }
        else if(s[i]== '+') {
             if(i-1>=0 && s[i-1]>='0' && s[i-1]<='9' || s[i+1]==' ')return num;
            return (+1)*solve(s,i+1,num,get);
        }
        else if(s[i]>='0' && s[i]<='9'){
            get =true;
            if(num==0){
                
                num = s[i] -'0';
                 return  solve(s,i+1,num,get);

            }
            else{
                num = num*10 + s[i]-'0';
                return solve(s,i+1,num,get);
            }
            
                
            
           
            
        }
        else if(s[i]==' '){
                if(i+1<s.length() && get==true &&  s[i+1]>='0' && s[i+1]<='9')return num;
            return solve(s,i+1,num,get);
        }
        
        else{
            return num;
        }
        
        
        
    }
    
    
    int myAtoi(string s) {
       double num=0;
        bool get=false;
         double ans=  solve(s,0,num,get);
        if(ans>=INT_MAX)return INT_MAX;
        else if(ans<=INT_MIN)return INT_MIN;
        else return ans;
        
    }
};