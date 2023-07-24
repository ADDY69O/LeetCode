/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode*BruteForce(ListNode *headA,ListNode*headB){
        //Approach O(n^2)
        ListNode*curr=headA;
        
        
        while(curr!=NULL){
            ListNode * curr2=headB;
            
            while(curr2!=NULL){
                if(curr==curr2)return curr;
                else curr2=curr2->next;
            }
            curr=curr->next;
        }
        
        
        return NULL;
        
        
        
    }
    
    
    ListNode*Approach2(ListNode*headA,ListNode*headB){
        // using Map 
        
        map<ListNode*,bool>count;
        
        ListNode*curr1=headA;
        ListNode*curr2=headB;
        
        while(curr1!=NULL){
            count[curr1]=true;
            curr1=curr1->next;
        }
        
        while(curr2!=NULL){
            if(count[curr2]==true){
                return curr2;
            }
            else count[curr2]=true;
            curr2=curr2->next;
        }
        return NULL;
        
        
        
    }
    
    int length(ListNode*head){
        ListNode*curr=head;
        
        int len=0;
        while(curr!=NULL){
            curr=curr->next;
            len++;
        }
        return len;
    }
    
    
    ListNode * Approach3(ListNode*headA,ListNode*headB){
        int size1 = length(headA);
        
        int size2 = length(headB);
              
        int inc = abs(size1-size2);
   
        
        
        ListNode*curr1=headA;
        ListNode*curr2=headB;
        
        if(size1>size2){
           
            while(inc!=0){
                curr1=curr1->next;
                inc--;
            }
            
        }
        else{
            
             while(inc!=0){
                curr2=curr2->next;
                 inc--;
            }
        }
        
        while(curr1!=NULL ||curr2==NULL){
            if(curr1==curr2){
                return curr1;
            }
            else{
                curr1=curr1->next;
                curr2=curr2->next;
            }
        }
        return NULL;
        
        
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //Approach 1 - T.C - O(n^2)
        // return BruteForce(headA,headB);
        
        //Approach 2 - T.C - O(N + M) S.C-> O(N + M)
        // return Approach2(headA,headB);
        
        
        //Approach 3 - T.c  - O(N)
        return Approach3(headA,headB);
    }
};