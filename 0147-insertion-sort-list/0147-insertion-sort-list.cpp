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
    
    ListNode* insert(ListNode* head, ListNode* node){
        //Now this will have atleast 1 element
        //case 1: insertion before head
        if(node->val < head->val){
            node->next=head;
            return node;
        }
        //case 2:insertion in between or end
        ListNode *before=head;
        while(before!=NULL){
            //If reached end
            if(before->next==NULL){
                before->next=node;
                break;
            }
            //otherwise
            if(node->val < before->next->val){
                node->next=before->next;
                before->next=node;
                break;
            }
            before=before->next;
        }
        return head;
    }
    
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        //Now all cases will be of size >=2
        ListNode* travel=head->next;
        ListNode* sortedList=head;
        sortedList->next=NULL;
        while(travel!=NULL){
            ListNode* curr=travel;
            travel=travel->next;
            curr->next=NULL;
            sortedList=insert(sortedList, curr);
        }
        return sortedList;
    }
};