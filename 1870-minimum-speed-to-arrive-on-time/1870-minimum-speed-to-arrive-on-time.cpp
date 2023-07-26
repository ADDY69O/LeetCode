class Solution {
public:
    
    int solve(vector<int>dist,double hour){
        
       
        
        for(int speed =1;speed<=1e7;speed++ ){
            double time=0;
            // cout<<"for speed "<<speed<<endl;
            for(int i=0;i<dist.size();i++){
                
                if(time<ceil(time)){
                    time= double((int) time + 1);
                }
                time+= double(dist[i])/double(speed);
                // cout<<time<<" ";
                
                
                
            }
             cout<<endl;
            if(time<=hour)
                return speed;
            
            
            
        }
        return -1;
        
        
        
        
    }
    int Approach2(vector<int>dist,double hour){
        
       
        int s=1;
        int e=1e7;
        int mid = s + (e-s)/2;
    
        while(s<=e){
            cout<<s<<"  "<<e<<endl;
            double time=0;
            for(int i=0;i<dist.size();i++){
                 
                if(time<ceil(time)){
                    time= double((int) time + 1);
                }
                time+= double(dist[i])/double(mid);
                
            }
            
            if(time>hour){
                s = mid +1;
            }
            else{
             
                e = mid-1;
            }
            
        mid = s + (e-s)/2;    
            
        }
        
        
       
        if(s>1e7)return -1;
        return s;
        
        
        
        
    }
    
    
    
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        
        
        //bruteForce 
       // return solve(dist,hour);
        
        //binarySearch
        return Approach2(dist,hour);
        
    }
};