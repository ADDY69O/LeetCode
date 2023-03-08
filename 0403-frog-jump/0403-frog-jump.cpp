class Solution {
public:
   
    int jump(unordered_set<int> &sett,int k,int i,int n, map<pair<int,int>,int>& dp){
        if(i==n)return 1;
        if(dp.find({i,k})!=dp.end())return dp[{i,k}];
        int l=0;
        if(i+k-1<=n and i+k-1>i and sett.find(i+k-1)!=sett.end()){
         l|=jump(sett,k-1,i+k-1,n,dp);
        }
        if(i+k<=n and i+k>i and sett.find(i+k)!=sett.end()){
            l|=jump(sett,k,i+k,n,dp);
        }
        if(i+k+1<=n  and i+k+1>i and sett.find(i+k+1)!=sett.end()){
            l|=jump(sett,k+1,i+k+1,n,dp);
        }
        return dp[{i,k}]=l;
    }
    
    bool canCross(vector<int>& stones)
    {if(stones[1]!=1)return false;
         unordered_set<int> sett;
         map<pair<int,int>,int> dp;
         for(int i:stones)sett.insert(i);
         int n=stones.size();
         return jump(sett,1,1,stones[n-1],dp);
    }
};