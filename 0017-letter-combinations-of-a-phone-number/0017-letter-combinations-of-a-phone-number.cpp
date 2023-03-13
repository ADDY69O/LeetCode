class Solution {
public:
    
    void solve(string digits,int i,vector<string>&ans,map<int,string>&Phone,string &output){
        if(i>=digits.size() && output.length()>0){
            ans.push_back(output);
            return;
        }
        int num =digits[i] - '0';
        string a=Phone[num];
        
        
        for(int ind=0;ind<a.length();ind++){
            output.push_back(a[ind]);
            solve(digits,i+1,ans,Phone,output);
            output.pop_back();
            
        }
        
        
        
        
        
    }
    
    
    
    vector<string> letterCombinations(string digits) {
    
       std::map<int, std::string> Phone = {
    {2, "abc"},
    {3, "def"},
    {4, "ghi"},
    {5, "jkl"},
    {6, "mno"},
    {7, "pqrs"},
    {8, "tuv"},
    {9, "wxyz"}
};
        
        vector<string>ans;
        string output="";
          solve(digits,0,ans,Phone,output);
        return ans;
   
        
        
    }
};