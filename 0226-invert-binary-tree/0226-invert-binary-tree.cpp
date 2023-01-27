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
    TreeNode*solve(TreeNode*root,TreeNode*ans){
        if(root==NULL){
            return ans;
        }
        
        TreeNode*temp =new TreeNode(root->val);
        ans=temp;
        if(root->right!=NULL)
        ans->left=solve(root->right,ans->left);
           if(root->left!=NULL)
        ans->right=solve(root->left,ans->right);
        
        return ans;
        
        
    }
    
    TreeNode* invertTree(TreeNode* root) 
    {
        if(root==NULL){
            return NULL;
        }
       TreeNode*ans;
        return solve(root,ans);
    }
};