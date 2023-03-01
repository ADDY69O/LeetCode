class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int maxi=0;
        int n=heights.size();
        int m=heights[0].size();
        
         priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
       
        vector<vector<int>>distance(n,vector<int>(m,INT_MAX));
        
        
        q.push({0,{0,0}});
        distance[0][0]=0;
        while(!q.empty()){
            int diff=q.top().first;
            int row=q.top().second.first;
            int col=q.top().second.second;
          
            q.pop();
            
            
            
            int drow[]={1,0,-1,0};
            int dcol[]={0,1,0,-1};
            
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m  ){
                  int newEffort=max(abs(heights[row][col]-heights[nrow][ncol]),diff);
                    
                    if(newEffort<distance[nrow][ncol]){
                        distance[nrow][ncol]=newEffort;
                        q.push({newEffort,{nrow,ncol}});
                    }
                   
                }
                
            }
            
            
            
            
            
        }
        
        
        return distance[n-1][m-1];
        
        
        
    }
};