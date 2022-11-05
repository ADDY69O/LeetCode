class Solution {
    private:
    void transpose(vector<vector<int>>&matrix){
        int row=matrix.size();
        int col=matrix[0].size();
        
        
        for(int i=0;i<row;i++){
            for(int j=0;j<i;j++){
                
                swap(matrix[i][j],matrix[j][i]);
                
                
            }
        }
        
        
        
    }
    
    void print(vector<vector<int>>matrix){
            int row=matrix.size();
        int col=matrix[0].size();
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                
              cout<<matrix[i][j]<<" ";
                
                
            }cout<<endl;
        }cout<<endl;
        
    }
    void swapKrdai(vector<vector<int>>&matrix){
      for(int i=0;i<matrix.size();i++){
          reverse(matrix[i].begin(),matrix[i].end());
      }
    }
    
    
public:
    void rotate(vector<vector<int>>& matrix) {
        // Step 1 : phle tho transpose krdai
        transpose(matrix);
        
        
        
      
        //step 2 coloumns swap krdai
        
        swapKrdai(matrix);
          //print(matrix);
        
        
    }
};