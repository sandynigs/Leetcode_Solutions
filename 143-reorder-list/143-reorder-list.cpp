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
    void print(ListNode* head){
        cout<<"Cur list is: "<<endl;
        ListNode* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp=temp->next;
        }
    }
    
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev=curr;
            curr=nxt;
        }
        return prev;
    }
    
    void helper(ListNode* head, ListNode* tail){
        if(tail->next==NULL){return;}
        ListNode *reverseListHead = reverse(tail);
        head->next = reverseListHead;
        // tail=reverseListHead->next;
        // print(head);
        helper(reverseListHead,reverseListHead->next);
    }
    
    void reorderList(ListNode* head) {
        if(head->next==NULL){
            return;
        }
        helper(head, head->next);
    }
};