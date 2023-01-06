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
    int findPos(vector<int>inorder,int ele){
        
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==ele){
                return i;
            }
            
        }
        return -1;
        
        
    }
    TreeNode*solve(vector<int>& preorder, vector<int>& inorder,int &index,int start,int end){
        if(index>=preorder.size() || start>end){
            return NULL;
        }
        int ele=preorder[index];
        TreeNode*root= new TreeNode(ele);
        int pos=findPos(inorder,preorder[index++]);
        root->left=solve(preorder,inorder,index,start,pos-1);
        root->right=solve(preorder,inorder,index,pos+1,end);
        
        return root;
        
        
        
        
        
        
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index=0;
        
        
        return solve(preorder,inorder,index,0,preorder.size()-1);
        
    }
};