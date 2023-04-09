class Solution {
public:
    string reverseWords(string s) {
        stack<string>ans;
        string temp="";
        for(int i=0;i<s.length();i++){
            if(s[i]==' ' && temp.length()>0 ){
                cout<<"space"<<endl;
                ans.push(temp);
                temp.clear();
            }
            else if( s[i]!=' '){
                temp+=s[i];
            }
            
            
        }
        if(temp.length()>0)
        ans.push(temp);
        
        
        
        
        string res;
        
        while(!ans.empty()){
            
            cout<<ans.top()<<endl;
            res+=ans.top();
             ans.pop();
            if(ans.size()!=0)
            res+=' ';
           
            
        }
        return res;
    }
};