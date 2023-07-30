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
    
     ListNode * solve(ListNode*head){
 ListNode*curr=head;
        ListNode*next=head->next;
            
        
        while(next!=NULL){
            if(curr->val!=next->val){
                cout<<curr->val<<" "<<next->val<<endl;
                curr=next;
                next=next->next;
                
            }
            else if(curr->val==next->val){
                cout<<curr->val<<" "<<next->val<<endl;
                while(next!=NULL && curr->val==next->val){
                next=next->next;
                }
                curr->next=next;
                curr=next;
                if(next!=NULL)
                next=next->next;
                
            }
            
            
            
        }
        return head;
        
        
        
        
        
        
    }
    
    
    
    ListNode* deleteDuplicates(ListNode* head) {
         //BruteForce
        //Approach 1 :-- push all elements in array than remove duplicates in array
        
        
        //Approach 2
        if(head==NULL || head->next==NULL)return head;
        
       
        return solve(head);
        
    }
};