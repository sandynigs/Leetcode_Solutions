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
        ListNode* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp=temp->next;
        }
        cout<<endl;
    }
    ListNode* reverse(ListNode* head){
        cout<<"reversing list:";
        print(head);
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
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        //A special case arise if left=1, because head will change in that case;
        if(left==1){
            // cout<<"left is:"<<left<<" and right is:"<<right<<endl;
            // print(head);
            ListNode* temp=head;
            for(int i=1;i<right;i++){
                temp=temp->next;
            }
            ListNode* addLater=temp->next;
            temp->next=NULL;
            head=reverse(head);
            // cout<<"reverse secttions is:";
            // print(head);
            ListNode* aux=head;
            while(aux->next!=NULL){
                aux=aux->next;
            }
            aux->next=addLater;
        }
        else{
            // cout<<"left is:"<<left<<" and right is:"<<right<<endl;
            // print(head);
            ListNode* temp1=head;
            for(int i=1;i<left-1;i++){
                temp1=temp1->next;
            }
            ListNode* temp2=head;
            for(int i=1;i<right;i++){
                temp2=temp2->next;
            }
            ListNode* addLater=temp2->next;
            temp2->next=NULL;
            ListNode* rev=reverse(temp1->next);
            // cout<<"reverse secttions is:";
            // print(rev);
            temp1->next=rev;
            ListNode* aux=rev;
            while(aux->next!=NULL){
                aux=aux->next;
            }
            aux->next=addLater;
        }
        return head;
        
    }
};