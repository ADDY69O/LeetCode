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
    void solve(ListNode*prev,ListNode*curr,ListNode*next){
        if(next==NULL )return;
        
        if(curr->val==next->val){
            while(curr->val==next->val && curr!=NULL){
                if(curr->next==NULL){
                    prev->next=NULL;
                    return;
                    
                }
                
                curr=curr->next;
            }
            prev->next=curr;
            
             solve(prev,curr,curr->next);
        }
        else{
            solve(curr,next,next->next);
        }
        
       
        
        
    }
    ListNode* deleteDuplicates(ListNode* head) {
         if(head==NULL){
            return NULL;
        }
        ListNode*curr=head;
        ListNode*prev=new ListNode(0);
        prev->next=head;
        ListNode*next=head->next;
       solve(prev,curr,next);
        return prev->next;
    }
};