class Solution {
public:
    string ans;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        ans=longUrl;
        for(int i=0;i<ans.size();i++){
            ans[i]+=4;
        }
        return ans;
        
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        cout<<ans<<endl;
         for(int i=0;i<ans.size();i++){
            ans[i]-=4;
             
        }
        cout<<ans<<endl;
        return ans;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));