class Solution {
public:
    void dfs(vector<vector<char>> &board,int row,int col,vector<vector<bool>>& visited,int n,int m){
        // visited[i][j]=1;
        // board[i][j]='O';
        board[row][col]='#';
        int drow[]={1,0,-1,0};
        int dcol[]={0,1,0,-1};
        for(int l=0;l<4;l++){
            int nrow=row+drow[l];
            int ncol=col+dcol[l];
            
            if(nrow<n && nrow>=0 && ncol<m && ncol>=0 &&  board[nrow][ncol]=='O' && !visited[nrow][ncol] ){
               visited[nrow][ncol]=1;
                dfs(board,nrow,ncol,visited,n,m);
            
            }
            
        }
        
        
    }
    
    
    void solve(vector<vector<char>>& board) {
     
        int n=board.size();
        int m=board[0].size();
        // vector<vector<char>>d(n,vector<char>(m,'X'));
        vector<vector<bool>>visited(n,vector<bool>(m));
        
        //first row
        
        for(int i=0 ;i<m;i++){
            if(board[0][i]=='O' && !visited[0][i]){
               visited[0][i]=1;
                dfs(board,0,i,visited,n,m);
                  
            }
        }
        
        //first column
        
        for(int i=0;i<n;i++){
            if(board[i][0]=='O' && !visited[i][0]){
                 visited[i][0]=1;
                dfs(board,i,0,visited,n,m);
            }
        }
        //last row
        
        for(int i=0 ;i<m;i++){
            if(board[n-1][i]=='O' && !visited[n-1][i]){
                 visited[n-1][i]=1;
                dfs(board,n-1,i,visited,n,m);
            }
        }
        
        //Last column
        
        for(int i=0;i<n;i++){
            if(board[i][m-1]=='O' && !visited[i][m-1]){
                 visited[i][m-1]=1;
                dfs(board,i,m-1,visited,n,m);
            }
        }
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' ){
                    board[i][j]='X';
                }
                  if(board[i][j]=='#' ){
                    board[i][j]='O';
                }
            }
        }
        cout<<endl;
          for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<board[i][j]<<" ";
            }
              cout<<endl;
        }
    
        
    
        
        
        
    }
};