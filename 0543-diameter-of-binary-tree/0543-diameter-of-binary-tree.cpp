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
        if(root==NULL)return 0;
        
        int left = height(root->left);
        int right= height(root->right);
        return 1 + max(left,right);
        
        
        
    }
    int solve(TreeNode*root){
        if(root==NULL)return 0;
        
        int h1 = height(root->left);
        int h2 = height(root->right);
        
        int left = solve(root->left);
        int right = solve(root->right);
        
        return max(h1 + h2 ,max(left,right));
        
        
        
    }
    
    pair<int,int>optM(TreeNode*root){
        // height , diameter;
        
        if(root==NULL){
            pair<int,int>p=make_pair(0,0);
            return p;
        }
        pair<int,int>left = optM(root->left);
        pair<int,int>right= optM(root->right);
        
        int height = max(left.first ,  right.first)+  1;
        int diameter = max(left.first + right.first ,max(left.second,right.second));
        pair<int,int>ans;
        ans.first=height;
        ans.second=diameter;
        return ans;
        
        
        
        
    }
    
    
    
    int diameterOfBinaryTree(TreeNode* root) {
        // return solve(root);
        return optM(root).second;
    }
};