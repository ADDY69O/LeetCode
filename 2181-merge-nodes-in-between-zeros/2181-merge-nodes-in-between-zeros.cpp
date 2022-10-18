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
    ListNode* mergeNodes(ListNode* head) {
        ListNode*ansH=NULL;
        ListNode*ansT=NULL;
        if(head==NULL){
            return NULL;
        }
        
        ListNode*curr=head;
        int sum=0;
        while(curr!=NULL){
            sum+=curr->val;
            if(curr->val==0){
                
                if(ansH==NULL){
                ListNode*temp= new ListNode(sum);
                  ansH=temp;
                    ansT=temp;
                }
                else{
                    ListNode*temp=new ListNode(sum);
                    ansT->next=temp;
                    ansT=temp;
                }
                sum=0;
            }
            curr=curr->next;
            
        }
        
        return ansH->next;
    }
};