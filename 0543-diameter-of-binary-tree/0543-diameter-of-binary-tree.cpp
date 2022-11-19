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
    int height(TreeNode*root){
        if(root==NULL){
            return 0;
        }
        int left = height(root->left);
        int right= height(root->right);
        return 1+ max(left,right);
        
        
    }
    
    pair<int,int>solve(TreeNode*root){
        if(root==NULL){
            pair<int,int>p=make_pair(0,0);
            return p;
        }
        
        pair<int,int>left=solve(root->left);
        pair<int,int>right=solve(root->right);
        
        int op1=left.first;
        int op2=right.first;
        int op3=left.second+right.second;
        
        pair<int,int>ans;
        ans.first=max(op1,max(op2,op3));
        ans.second=max(left.second,right.second)+1;
        
        return ans;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        
//         if(root==NULL){
//             return 0;
//         }
        
//         int left=diameterOfBinaryTree(root->left);
//         int right=diameterOfBinaryTree(root->right);
//         int cond=height(root->left)+height(root->right);
        
        
//         return max(left,max(right,cond));
        
        return solve(root).first;
        
    }
};