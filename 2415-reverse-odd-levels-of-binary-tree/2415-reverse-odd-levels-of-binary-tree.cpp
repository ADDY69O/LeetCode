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
    void solve(TreeNode*left,TreeNode*right,int lvl){
        if(left==NULL || right==NULL){
            return;
        }
        
        if(lvl%2==0){
            swap(left->val,right->val);
        }
        solve(left->left,right->right,lvl+1);
        solve(left->right,right->left,lvl+1);
        
        
    }
    
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        int lvl=0;
       
        TreeNode*left=root->left;
        TreeNode*right=root->right;
        solve(left,right,lvl);
        return root;
        
    }
};