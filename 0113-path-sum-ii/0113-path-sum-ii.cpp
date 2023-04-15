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
     void solve(TreeNode*root,int targetSum,int& sum,vector<vector<int>>&res,vector<int>&op){
       cout<<sum<<endl;
        if(sum==targetSum && root->left==NULL && root->right==NULL){
            res.push_back(op);
            return;
        }
        
        if(root->left==NULL && root->right==NULL)return ;
        
  
        bool left=0,right=0;
        if(root->left){
                            cout<<"cond1"<<endl;

            sum+=root->left->val;
           op.push_back(root->left->val);

           solve(root->left,targetSum,sum,res,op);
            sum-=root->left->val;
             op.pop_back();
        }
          if(root->right){
                cout<<"cond2"<<endl;
              sum+=root->right->val;
           op.push_back(root->right->val);
              
            solve(root->right,targetSum,sum,res,op);
            sum-=root->right->val;
              op.pop_back();
        }
        
      
        
    }
    
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>res;
        vector<int>op;
        int sum=0;
        if(root==NULL){
         
             return res;
        }
        sum+=root->val;
        op.push_back(root->val);
         solve(root,targetSum,sum,res,op);
            return res;
    }
};