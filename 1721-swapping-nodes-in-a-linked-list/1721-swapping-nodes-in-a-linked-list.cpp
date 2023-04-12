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
class Solution {
public:
    int getSize(ListNode*head){
        ListNode*temp=head;
        int cnt=0;
        
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
            
        }
        
        return cnt;
        
        
        
        
    }
    
    
    
    ListNode* swapNodes(ListNode* head, int k) {
     int vall, val2, n, n2; 
        ListNode *ptr =head;
            for(int i=1; i<k; i++)
            { ptr = ptr->next; } 
        vall= ptr-> val;
        ptr = head;
    n =getSize(head);
    n2= n - k + 1;
        for (int i=1;i<n2; i++) 
        {
            ptr=ptr->next;
            
        }
        val2 =ptr-> val;
         ptr->val=vall;
    ptr = head; 
    for(int i=1; i<k; i++) { 
          ptr=ptr->next;  
    }
        ptr->val= val2;
    return head;
   
    }
};