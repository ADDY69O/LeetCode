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
    void solve(ListNode*curr,ListNode*next){
        if(next==NULL )return;
        
        if(curr->val==next->val){
            if(next->next==NULL){
                curr->next=NULL;
                return;
            }
            else{
                curr->next=next->next;
            }
             solve(curr,next->next);
        }
        else{
            solve(next,next->next);
        }
        
       
        
        
    }
    
    ListNode* deleteDuplicates(ListNode* head) {
         if(head==NULL){
            return NULL;
        }
        ListNode*curr=head;
        ListNode*next=head->next;
       solve(curr,next);
        return head;
        
    }
};