class Solution {
public:
    
    void bfs(vector<int>adj[],int node,int &count,vector<bool>&check){
        
        check[node]=1;
        count++;
        cout<<node<<" ";
        queue<int>q;
        q.push(node);
        
        while(!q.empty()){
            int ele=q.front();
            q.pop();
            
            for(auto i:adj[ele]){
                
                if(!check[i]){
                    q.push(i);
                    count++;
                    check[i]=1;
                }
                
            }
            
        }
        
        
        
        
    }
    
    
    long long countPairs(int n, vector<vector<int>>& edges) {
    
     vector<int>adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
     
        }
        
        //count the number of nodes in each component 
        //and store them in array
        
        long long count=0;
        vector<int>all;
        vector<bool>visited(n,0);
        for(int i=0;i<n;i++){
            
            if(!visited[i]){
            
                int ans=0;
                bfs(adj,i,ans,visited);
                all.push_back(ans);
                
                
            }
            
            
        }
    //find the suffix
        vector<int>suf(all.size());
        int s=0;
        for(int i=all.size()-1;i>=0;i--){
            s+=all[i];
            suf[i]=s;
        }
        
        
        for(int i=0;i<suf.size();i++){
            long long int ele=suf[i]-all[i];
            count+=all[i]*ele;
            
            
            
        }
        return count;
        
    }
};