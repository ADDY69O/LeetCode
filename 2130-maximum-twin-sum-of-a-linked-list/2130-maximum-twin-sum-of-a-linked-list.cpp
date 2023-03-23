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
    ListNode*find(ListNode*head){
        
        ListNode*t=head;
        while(t->next->next!=NULL){
            t=t->next;
        }
        return t;
        
        
    }
    ListNode* middleNode(ListNode* head) {
       //using slow and fast pointer 
        if(head==NULL)return NULL;
        ListNode*fast=head;
        ListNode*slow=head;
        
        while(fast->next!=NULL&&fast!=NULL){
            slow=slow->next;
            fast=fast->next;
            if(fast->next!=NULL)fast=fast->next;
        }
        return slow;
        
        
        
        
    }
    stack<int>put(ListNode*middleNode){
        stack<int>s;
        
        while(middleNode!=NULL){
            s.push(middleNode->val);
            middleNode=middleNode->next;
        }
        return s;
        
        
        
        
    }
    
    
    
    int pairSum(ListNode* head) {
    
        //aproach 1 :it can done by copying all the linkedlist elements in the array and applying two pointer 
        
        //aproach 2 : use two pointer directly into the linkedlist
        
        
        ListNode* f=head;
        ListNode*middleNode(head);
        stack<int>s;
        s=put(middleNode);
        
        int maxi=-1e9;
        while(!s.empty()){
            int total=s.top() + f->val;
            s.pop();
            f=f->next;
            maxi=max(maxi,total);
            
        }
        
        return maxi;
        
        
        
        
        
        
        
        
    }
};