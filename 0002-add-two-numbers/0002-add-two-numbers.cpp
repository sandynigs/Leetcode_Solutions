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
    //Follow up
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *sumHead=NULL, *sumTail=NULL;
        int carry=0;
        ListNode *t1=l1,*t2=l2;
        while(t1!=NULL && t2!=NULL){
            int nodeval;
            int n1=t1->val;
            int n2=t2->val;
            if(n1+n2+carry>9){
                nodeval=(n1+n2+carry)%10;
                carry=(n1+n2+carry)/10;
            }
            else{
                nodeval=(n1+n2+carry);
                carry=0;
            }
            ListNode* newNode = new ListNode(nodeval);
            if(sumHead==NULL){
                sumHead=newNode;
                sumTail=newNode;
            }
            else{
                sumTail->next=newNode;
                sumTail=sumTail->next;
            }
            t1=t1->next;
            t2=t2->next;
        }
        if(t1!=NULL){
            if(carry==0){
                sumTail->next=t1;
            }
            else{
                while(t1!=NULL){
                    int nodeval;
                    int n1=t1->val;
                    if(n1+carry>9){
                        nodeval=(n1+carry)%10;
                        carry=(n1+carry)/10;
                    }
                    else{
                        nodeval=(n1+carry);
                        carry=0;
                    }
                    ListNode* newNode = new ListNode(nodeval);
                    if(sumHead==NULL){
                        sumHead=newNode;
                        sumTail=newNode;
                    }
                    else{
                        sumTail->next=newNode;
                        sumTail=sumTail->next;
                    }
                    t1=t1->next;
                }
            }
        }
        
        else if(t2!=NULL){
            if(carry==0){
                sumTail->next=t2;
            }
            else{
                while(t2!=NULL){
                    int nodeval;
                    int n2=t2->val;
                    if(n2+carry>9){
                        nodeval=(n2+carry)%10;
                        carry=(n2+carry)/10;
                    }
                    else{
                        nodeval=(n2+carry);
                        carry=0;
                    }
                    ListNode* newNode = new ListNode(nodeval);
                    if(sumHead==NULL){
                        sumHead=newNode;
                        sumTail=newNode;
                    }
                    else{
                        sumTail->next=newNode;
                        sumTail=sumTail->next;
                    }
                    t2=t2->next;
                    
                }
            }
        }
        if(carry==1){
            ListNode *endTail = new ListNode(carry);
            sumTail->next=endTail;
        }
        
        return sumHead;
    }
};