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
    bool solve(TreeNode*root,int targetSum,int& sum){
       cout<<sum<<endl;
        if(sum==targetSum && root->left==NULL && root->right==NULL)return true;
        
        if(root->left==NULL && root->right==NULL)return false;
        
  
        bool left=0,right=0;
        if(root->left){
                            cout<<"cond1"<<endl;

            sum+=root->left->val;
           left= solve(root->left,targetSum,sum);
            sum-=root->left->val;
        }
          if(root->right){
                cout<<"cond2"<<endl;
              sum+=root->right->val;
           right= solve(root->right,targetSum,sum);
            sum-=root->right->val;
        }
        
        return left or right;
        
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        if(root==NULL){
         
             return false;
        }
        sum+=root->val;
        return solve(root,targetSum,sum);
        
    }
};