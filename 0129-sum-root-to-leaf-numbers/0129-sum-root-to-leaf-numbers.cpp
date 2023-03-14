/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode*root,int &ans,vector<int>&sum){
        if(root->left==NULL && root->right==NULL){
            sum.push_back(ans);
            return;   
        }
        
        if(root->left){
            int ele=root->left->val;
            int orignal=ans;
          ans=10*ans+ele;
            solve(root->left,ans,sum);
            ans=orignal;
            
            
        }  
        
        if(root->right){
            int ele=root->right->val;
            int orignal=ans;
          ans=10*ans+ele;
            solve(root->right,ans,sum);
            ans=orignal;
            
        }
        
        
        
    }
    
    
    int sumNumbers(TreeNode* root) {
        if(root==NULL)return 0;
        int ans=root->val;
        vector<int>sum;
        solve(root,ans,sum);
    
        
        int total=0;
        for(int i=0;i<sum.size();i++){
            cout<<sum[i]<<" ";
        }
        
        for(auto i:sum)total+=i;
        return total;
        
    }
};