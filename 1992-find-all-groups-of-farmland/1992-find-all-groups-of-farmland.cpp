class Solution {
public:
    
    void dfs(vector<vector<int>>land,int row,int col,vector<vector<bool>>&visited,vector<int>&endP){
         int n=land.size();
        int m=land[0].size();
        visited[row][col]=1;
          cout<<row<< " "<< col<< " "<<endl;
        endP[0]=row;
        endP[1]=col;
       

        int drow[]={0,1,0,-1};
        int dcol[]={1,0,-1,0};
        
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow<n && nrow>=0 && ncol>=0 && ncol<m && land[nrow][ncol]==1 && !visited[nrow][ncol]){
                visited[nrow][ncol]=1;
                dfs(land,nrow,ncol,visited,endP);
            }
            
            
        }
        
        
    }
    
    
   void bfs(vector<vector<int>>&land,int i,int j,int &ei,int &ej){
          int n=land.size();
        int m=land[0].size();
       land[i][j]=2;
       queue<pair<int,int>>q;
       q.push({i,j});
       
       while(!q.empty()){
            int row=q.front().first;
           int col=q.front().second;
           q.pop();
           
          int drow[]={0,1,0,-1};
        int dcol[]={1,0,-1,0};
        
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow<n && nrow>=0 && ncol>=0 && ncol<m && land[nrow][ncol]==1){
                land[nrow][ncol]=2;
                ei=nrow;
                ej=ncol;
                q.push({nrow,ncol});
            }
            
            
        } 
           
           
           
       }
       
       
       
   }
    
    
    
    
    
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n=land.size();
        int m=land[0].size();
       
        vector<vector<int>>res;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( land[i][j]==1){
                    vector<int>ans;
                  
                    ans.push_back(i);
                    ans.push_back(j);
                 
                    int ei=i;
                    int ej=j;
                    bfs(land,i,j,ei,ej);
                    ans.push_back(ei);
                    ans.push_back(ej);
                    res.push_back(ans);
                }
            }
        }
        
        return res;
        
        
        
        
    }
};