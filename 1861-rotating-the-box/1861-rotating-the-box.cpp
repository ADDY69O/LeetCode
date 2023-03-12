class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n=box.size();
        int m=box[0].size();
        
               vector<vector<char>>ans(m,vector<char>(n));

        for(int i=0;i<n;i++){
            int j=box[i].size()-1;
            int pos=j;
            while(j>=0){
                
                if(box[i][j]=='*'){
                    pos=j-1;
                    
                    
                }
                else if(box[i][j]=='#'){
                    box[i][j]='.';
                    box[i][pos]='#';
                    
                    ans[pos][ans[pos].size()-i-1]='#';
                    pos--;
                    
                }
           
                ans[j][n-i-1]=box[i][j];
                
                j--;
                
                
                
                
                
            }
            
            
            
            
        }
        
       
        
        
        
        

        
        return ans;
        
        
        
        
    }
};