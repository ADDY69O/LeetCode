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
    vector<int> largestValues(TreeNode* root) {
     vector<int>ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            int ele=INT_MIN;
                int size=q.size();
            for(int i=0;i<size;i++){
            TreeNode*toop=q.front();
            q.pop();
                ele=max(toop->val,ele);
             if(toop->left){
                 q.push(toop->left);
             }   
             if(toop->right){
                 q.push(toop->right);
             }   
            }
            ans.push_back(ele);
            
            
            
        }
        return ans;
    }
};