/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    int len(ListNode*head){
        if(head==NULL){
            return 0;
        }
        int count=0;
        ListNode*temp=head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        
        
      return count;  
    }
    int getEle(ListNode*head,int start,int end,int mid){
        int cross=0;
        ListNode*temp=head;
        while(cross!=mid && temp!=NULL){
            cross++;
            temp=temp->next;
            
            
        }
        
        if(temp==NULL){
            return 0;
        }
        else{
            return temp->val;
        }
        
        
        
    }
    
    
    TreeNode*solve(ListNode*head,int start,int end,TreeNode*ans){
        if(start>end){
            return NULL;
        }
        int mid= (start +end)/2;
        int ele=getEle(head,start,end,mid);
        TreeNode*temp=new TreeNode(ele);
        ans=temp;
        
        ans->left=solve(head,start,mid-1,ans);
        ans->right=solve(head,mid+1,end,ans);
        return ans;
        
        
        
        
        
        
    }
    
    
    
    TreeNode* sortedListToBST(ListNode* head) {
        //find the length of the linked list
            int length=len(head);
        cout<<len(head)<<endl;
        if(head==NULL){
            return NULL;
        }
        
        
        //than we manipulate the linklist along with the start and the end pointers
        int start=0;
        int end=length-1;
        
        TreeNode*ans=NULL;
       
        return     solve(head,start,end,ans);
   
        
        
        
        
    }
};