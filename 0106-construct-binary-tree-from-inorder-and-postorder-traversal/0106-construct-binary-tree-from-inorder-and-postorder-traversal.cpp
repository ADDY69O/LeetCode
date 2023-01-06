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
    
    TreeNode*solve(vector<int>& inorder, vector<int>& postorder,int &index,int start,int end){
        
        if(index<0 || start>end){
            return NULL;
        }
                
        TreeNode*root=new TreeNode(postorder[index]);
        int pos=findPos(inorder,postorder[index]);
        index--;
        root->right=solve(inorder,postorder,index,pos+1,end);
       
        root->left=solve(inorder,postorder,index,start,pos-1);
        
        return root;
        
        
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index=postorder.size()-1;
        return solve(inorder,postorder,index,0,inorder.size()-1);
    }
};