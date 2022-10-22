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
    pair<int,int>check(TreeNode*root){
        if(root==NULL){
            pair<int,int>p=make_pair(0,0);
            return p;
        }
        
        
        
        pair<int,int>left=check(root->left);
        pair<int,int>right=check(root->right);
        
        
        int p1=left.first;
        int p2=right.first;
        int p3=left.second+right.second+1;
        
        pair<int,int>ans;
        
        ans.first=max(p1,max(p2,p3));
        ans.second=max(left.second,right.second)+1;
        
        
        return ans;
        
        
        
    }
    
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        
        return check(root).first-1;
        
    }
};