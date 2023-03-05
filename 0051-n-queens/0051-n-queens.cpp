class Solution {
public:
    bool isSafe(int row,int col,vector<string>board,int n){
        int orignalRow=row;
        int orignalCol=col;
        
        //check row
        while(col>=0){
            if(board[row][col]=='Q')return false;
            col=col-1;
            
        }
        
        col=orignalCol;
        
        
        
        
        
        while(row>=0 && col>=0){
             if(board[row][col]=='Q')return false;
            row=row-1;
            col=col-1;
        }
        row=orignalRow;
        col=orignalCol;
        
        while(row<n && col>=0){
             if(board[row][col]=='Q')return false;
            row=row+1;
            col=col-1;
        }
        
        
        
        
        
        
        
        
        return true;
        
    }
    
    
   void solve(int col,vector<vector<string>>&chess,vector<string>&board,int n){
        if(col==n){
            chess.push_back(board);
            return;
        }
       
       for(int row =0 ;row<n;row++){
           
           if(isSafe(row,col,board,n)){
               board[row][col]='Q';
               solve(col+1,chess,board,n);
               board[row][col]='.';
               
               
               
           }
           
           
           
       }
       
       
       
       
   }
    
    
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>chess;
      vector<string>board(n);
        string temp(n,'.');
        
        for(int i=0;i<n;i++){
            board[i]=temp;
         
        }
        // chess.push_back(board);
        
        
        
        
       solve(0,chess,board,n);
      return chess;  
        
        
        
    }
};