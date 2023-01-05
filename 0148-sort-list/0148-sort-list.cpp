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
    ListNode*middle(ListNode*head){
         if(head==NULL || head->next==NULL){
            return head;
        }
        
        ListNode*slow=head;
        ListNode*fast=head->next;
        
        while(fast->next!=NULL && fast!=NULL){
            
            
            slow=slow->next;
            
            fast=fast->next;
            if(fast->next!=NULL){
                fast=fast->next;
            }
            
            
        }
        return slow;
        
        
        
    }
    
    ListNode*mergeSort(ListNode*f,ListNode*s){
        if(f==NULL || s==NULL){
            return (f==NULL)?s:f;
        }
        
        
        ListNode*curr=new ListNode(0);
        ListNode*temp;
      
            if(f->val<=s->val){
                    temp=f;
                temp->next=mergeSort(f->next,s);
            }
            else{
                temp=s;
                temp->next=mergeSort(f,s->next);
                
            }

            
            
        
        
     
            return temp;
    }
    
    ListNode* sortList(ListNode* head) {
        //using merger sort 
        if(head==NULL || head->next==NULL){
            return head;
        }
        //Step 1: finding the mid node of the head
        
        ListNode*mid=middle(head);
        ListNode*f=head;
        ListNode*s=mid->next;
        mid->next=NULL;
        //step 2: divide the linked list in two phases 
                //first phase head to mid
                    f=sortList(f);
                //second phase mid+1 to end
                    s=sortList(s);
        
        
        //step 3: last and final to merge the first and second phase linked list
               return  mergeSort(f,s);
        
        
    }
};