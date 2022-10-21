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
     int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
            
            
        }
        
        
        int left= maxDepth(root->left);
        int right=maxDepth(root->right);
        
        
        return max(left,right)+1;
        
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        
        bool left=isBalanced(root->left);
        bool right=isBalanced(root->right);
        
        int l=maxDepth(root->left);
        
        int r=maxDepth(root->right);
        
        if(abs(l-r)<=1 && left && right){
            return true;
        }
        else{
            return false;
        }
        
    }
};