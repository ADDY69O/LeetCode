class Solution {
    private:
    bool isVowel(char s){
        
       if (s=='a' || s=='e' || s=='i' ||s=='o' || s=='u' || s=='A' || s=='E' || s=='I' ||s=='O' || s=='U'){
           return true;
       }
        else{
            return false;
        }
        
    }
    
public:
    string reverseVowels(string s) {
        int i=0;
        int e=s.length()-1;
        
        while(i<e){
            
            if(isVowel(s[i]) && isVowel(s[e]) ){
                cout<<"op1"<<endl;
            swap(s[i],s[e]);
                i++;
                e--;
            }
            else if(isVowel(s[i])){
                  cout<<"op2"<<endl;
                e--;
            }
            else if(isVowel(s[e])){
                  cout<<"op3"<<endl;
                i++;
            }
            else{
                  cout<<"op4"<<endl;
                i++;
                e--;
            }
         
            
            
        }
        return s;
    }
};