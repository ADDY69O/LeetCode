class Solution {
public:
    
    void solve(vector<vector<int>>rooms,vector<bool>&visited,
              int index){
            
        if(index>=rooms.size()){
            return ;
        }
        
        
        for(int i=0;i<rooms[index].size();i++){
            if(visited[rooms[index][i]]==false){
                visited[rooms[index][i]]=true;
                solve(rooms,visited,rooms[index][i]);
            }
        }
      
        
        
    }
    
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool>visited(rooms.size(),false);
       if( rooms.size()==0){
        return false;   
       }
        int index=0;
        visited[0]=true;
         solve(rooms,visited,index);
        
        for(int i=0;i<rooms.size();i++){
            if(visited[i]==false){
                return false;
            }
        }
        return true;
    }
};