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
    void reorderList(ListNode* head) {
        deque<ListNode*>q;
        ListNode*temp=head;
    
        while(temp!=NULL){
            q.push_back(temp);
            temp=temp->next;
            q.back()->next=NULL;
        }
        q.pop_front();
        bool check=1;
        
        while(!q.empty()){
            if(check){
                head->next=q.back();
                q.pop_back();
              
            }
            else{
                head->next=q.front();
                q.pop_front();
                
            }
            head=head->next;
            check=!check;
            
        }
        
        
        
        
    }
};