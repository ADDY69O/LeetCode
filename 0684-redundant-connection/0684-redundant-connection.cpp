class Solution {
public:
    int findParent(int element,vector<int>&parent){
        if(parent[element]==element)return element;
        return findParent(parent[element],parent);
        
    }
    
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        //implemented with the help of DSU
         int n=edges.size();
      
        //first initialize the parent as the same node
        vector<int>parent(n+1);
       
        for(int i=0;i<parent.size();i++){
            parent[i]=i;
        }
        
        
        //then check one by one pairs and add them in the same sets
        //if any set is already present in the set than we have to return that pairs
        
        for( vector<int>v:edges){
            int ele1=v[0];
            int ele2=v[1];
            
            int p1=findParent(ele1,parent);
            int p2=findParent(ele2,parent);
            
            if(p1==p2){
                return v;
            }
            else{
                parent[p2]=p1;
            }
            
            
            
        }
        
        return {};
        
        
        
    }
};