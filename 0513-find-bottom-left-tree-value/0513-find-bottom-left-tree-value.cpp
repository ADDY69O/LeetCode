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
    int findBottomLeftValue(TreeNode* root) {
        
        //Approach 1 : lvl order traversal and find the highest lvl left element
        
        if(root==NULL)return 0;
        //storing in <lvl,value>
        int ResultH=-1;
        int ResultV=0;
        queue<pair<int,TreeNode*>>q;
        q.push({0,root});
        
        while(!q.empty()){
            pair<int,TreeNode*>top = q.front();
            q.pop();
            int lvl = top.first;
            TreeNode* ele = top.second;
            
            if(lvl > ResultH){
                ResultH=lvl;
                ResultV=ele->val;
            }
            
            if(ele->left){
                q.push({lvl+1,ele->left});
            }
            
             if(ele->right){
                q.push({lvl+1,ele->right});
            }
            
        }
        
        return ResultV;
        
        
        
    }
};