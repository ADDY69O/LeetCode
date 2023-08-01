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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long int>>q;
        q.push({root,0});
        long long int  maxi=0;
        
        while(!q.empty()){
            int size =q.size();
            long long int left,right;
            long long int curr = q.front().second;
            for(int i=0;i<size;i++){
                
                TreeNode*top = q.front().first;
               long long  int index = q.front().second - curr;
                q.pop();
                if(i==0)left=index;
                if(i==size-1)right=index;
                
                if(top->left){
                    q.push({top->left,2 *index + 1});
                }
                if(top->right){
                    q.push({top->right,2*index+2});
                }
                
                
                
            }
            maxi= max(maxi,right - left +1);
       
        }
        
        return maxi;
        
    }
};