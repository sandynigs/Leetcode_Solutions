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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL||head->next==NULL){return head;}
        ListNode* temp=head;
        ListNode* p1=NULL;
        ListNode* p2=NULL;
        ListNode* t1=NULL;
        ListNode* t2=NULL;
        while(temp!=NULL){
            ListNode* curr = temp;
            temp=temp->next;
            curr->next=NULL;
            if(curr->val<x){
                //add to first list
                if(p1==NULL){
                    p1=curr;
                    t1=curr;
                }
                else{
                    t1->next=curr;
                    t1=t1->next;
                }
            }
            else{
                //add to second list
                if(p2==NULL){
                    p2=curr;
                    t2=curr;
                }
                else{
                    t2->next=curr;
                    t2=t2->next;
                }
            }
        }
        if(t1==NULL){
            return p2;
        }
        t1->next=p2;
        return p1;
    }
};