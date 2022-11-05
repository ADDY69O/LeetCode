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
    private:
    void solve(TreeNode*root,vector<string>&ans,string op){
        
        
        if(root==NULL){
            op.pop_back();
            return;
        }
        
        if(root->left==NULL && root->right==NULL){
         string a= to_string(root->val);
              op+=a;
        
            ans.push_back(op);
            return;
        }
        string a= to_string(root->val);
        op+=a + "->";
        if(root->left){
        solve(root->left,ans,op);
         
   
        }
        if(root->right){
            solve(root->right,ans,op);
        
         
        }
            
        
        
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        
        string op="";
        
        solve(root,ans,op);
        return ans;
    }
};