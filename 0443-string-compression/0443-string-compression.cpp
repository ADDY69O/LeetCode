class Solution {
public:
    int compress(vector<char>& chars) {
     
        vector<char>ans;
        int i=0;
        while(i<chars.size()){
            int count=0;
            char ch=chars[i];
            
            while( i<chars.size() && chars[i]==ch ){
                i++;
                count++;
            }
            if(count==1){
                 ans.push_back(ch);
           
              
            }
            else if(count>9){
                  ans.push_back(ch);
                string s;
                int num=count;
                while(num!=0){
                    s+=(num%10 + 48);         
                    num=num/10;
                }
                for(int k=s.length()-1;k>=0;k--){
                     ans.push_back(s[k]); 
                }
                
                
            }
            else{
                         
            ans.push_back(ch);
             ans.push_back(48  + count);  
            }
   
           
            
            
        }
        chars.clear();
       for(auto i:ans)chars.push_back(i);
        return ans.size();
        
    }
};