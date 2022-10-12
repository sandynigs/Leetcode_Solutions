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
    
    ListNode* mergeTwoSortedList(ListNode* h1, ListNode* h2){
        ListNode* h=NULL;
        ListNode* t=NULL;
        ListNode* temp1=h1;
        ListNode* temp2=h2;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val<temp2->val){
                if(h==NULL){
                    h=temp1;
                    t=temp1;
                }
                else{
                    t->next=temp1;
                    t=t->next;
                }
                temp1=temp1->next;
            }
            else{
                if(h==NULL){
                    h=temp2;
                    t=temp2;
                }
                else{
                    t->next=temp2;
                    t=t->next;
                }
                temp2=temp2->next;
            }
        }
        if(temp1!=NULL){
            t->next=temp1;
        }
        if(temp2!=NULL){
            t->next=temp2;
        }
        return h;
    }
    
    ListNode* findMid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        if(head->next->next==NULL){
            ListNode* mid = head;
            ListNode* nxt = mid->next;
            mid->next=NULL;
            ListNode* h1 = sortList(head);
            ListNode* h2 = sortList(nxt);
            return mergeTwoSortedList(h1,h2);            
        }
        ListNode* mid = findMid(head);
        ListNode* nxt = mid->next;
        mid->next=NULL;
        ListNode* h1 = sortList(head);
        ListNode* h2 = sortList(nxt);
        return mergeTwoSortedList(h1,h2);
    }
};