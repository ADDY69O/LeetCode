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
    int len(ListNode*head){
        
        ListNode*temp=head;
        int count=0;
        
        if(temp==NULL){
            return count;
        }
        
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
        
        
        return count;
        
        
    }
    
    
public:
    ListNode* middleNode(ListNode* head) {
        if(head==NULL){
            return head;
        }
        int size=len(head);
        int mid=size/2;
        cout<<size<<endl;
        ListNode*temp=head;
        while(mid>0 && temp!=NULL){
                
            temp=temp->next;
            mid--;
            
            
        }
        
        
        
     return temp;   
        
        
        
    }
};