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
    void inorder(TreeNode*root,vector<int>&ans){
        if(root==NULL){
            return ;
        }
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
        
        
    }
    
    void changeValue(TreeNode*root,map<int,int>count){
        if(root==NULL){
            return;
        }
        changeValue(root->left,count);
        int ele=root->val;
        root->val=count[ele];
        changeValue(root->right,count);
        
        
    }
    
    
    TreeNode* bstToGst(TreeNode* root) {
        vector<int>ans;
            inorder(root,ans);
        map<int,int>count;
        int sum=0;
        for(int i=ans.size()-1;i>=0;i--){
            sum+=ans[i];
            count[ans[i]]=sum;
                
            
        }
        
        changeValue(root,count);
        return root;
        
    }
};