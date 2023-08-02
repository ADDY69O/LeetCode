class Solution {
public:
    bool isValid(string s) {
       
        stack<char>st;
        
        int i=0;
        
        while(i<s.length()){
            if(!st.empty() && ( s[i] == ')' || s[i]=='}' || s[i]==']' )){
                if(s[i]==')'  && st.top() == '('){
                    i++;
                    st.pop();
                }
                else if(s[i]=='}'  && st.top() == '{'){
                    i++;
                    st.pop();
                }
                else if(s[i]==']'  && st.top() == '['){
                    i++;
                    st.pop();
                }
                else{
                    return false;
                }
                
                
                
            }
            else{
                st.push(s[i]);
                i++;
            }
            
        }
       return (!st.empty() ? false: true ); 
      
        
        
        
    }
};