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
    bool checkMirror(TreeNode*r1,TreeNode*r2){
        
        
        if(r1==NULL && r2!=NULL || r1!=NULL && r2==NULL) {
            return false;
        }
        if(r1==NULL && r2==NULL ) {
            return true;
        }
        if(r1->val!=r2->val){
            return false;
        }
        
        
        
        bool o1=checkMirror(r1->left,r2->right);
        
        bool o2=checkMirror(r1->right,r2->left);
    
        if(o1&&o2){
            return true;
        }
        else{
            return false;
        }
    
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        
       return checkMirror(root->left,root->right);
        
    }
};