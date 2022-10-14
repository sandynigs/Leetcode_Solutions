// ListNode sentinel = new ListNode(0, head); adding a sentinel node too is a popular approach
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
    
    ListNode* fixHead(ListNode* head){
        while(head->next!=NULL && head->val == head->next->val){
            head=head->next;
        }
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        head=head->next;
        return head;
    }
    
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        while(head!=NULL && head->next!=NULL && head->val==head->next->val){
            head=fixHead(head);
        }
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        ListNode* before=head;
        ListNode* after=head->next;
        while(after->next!=NULL){
            if(after->val == after->next->val){
                while(after->next!=NULL && after->val==after->next->val){
                    after=after->next;
                }
                if(after->next==NULL){
                    before->next=NULL;
                }
                else{
                    after=after->next;
                    before->next=after;
                }
            }
            else{
                before=after;
                after=after->next;
            }
        }
        return head;
    }
};