//Brilliantly bad solution , damn when will I improve.

class Node{
    public:
    int val;
    Node* next=NULL;
    Node(int x){
        val=x;
    }
};

class MyLinkedList {
public:
    Node* head=NULL;
    int size=0;
    MyLinkedList() {
        
    }
    
    void print(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<"->";
            temp=temp->next;
        }
        cout<<endl;
    }
    
    int get(int index) {
        // cout<<"called get at index:"<<index<<"on :";
        // print();
        if(index>=size){
            return -1;
        }
        Node* temp=head;
        for(int i=0;i<index;i++){
            temp=temp->next;
        }
        // cout<<"value is:"<<temp->val<<endl;
        return temp->val;
    }
    
    void addAtHead(int val) {
        Node* n = new Node(val);
        n->next=head;
        head=n;
        size+=1;
        // cout<<"head added---->";
        // print();
    }
    
    void addAtTail(int val) {
        Node* n = new Node(val);
        if(head==NULL){
            head=n;
            size+=1;
            return;
        }
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=n;
        size+=1;
        // cout<<"tail added---->";
        // print();
    }
    
    void addAtIndex(int index, int val) {
        // cout<<"adding called on"<<endl;
        // print();
        // cout<<"at index"<<index<<endl;
        if(index>size){
            return;
        }
        if(index==0){
            addAtHead(val);
            return;
        }
        if(index==size){
            addAtTail(val);
            return;
        }
        Node* temp=head;
        for(int i=0;i<index-1;i++){
            temp=temp->next;
        }
        Node* n = new Node(val);
        n->next=temp->next;
        temp->next=n;
        size+=1;
        // print();
        return;
    }
    
    void deleteAtIndex(int index) {
        // cout<<"deleting called on"<<endl;
        // print();
        // cout<<"at index"<<index<<endl;
        if(index>=size){
            return;
        }
        if(index==0){
            head=head->next;
            size-=1;
            // print();
            return;
        }
        if(index==size-1){
            Node* temp=head;
            while(temp->next->next!=NULL){
                temp=temp->next;
            }
            temp->next=NULL;
            size-=1;
            // print();
            return;
        }
        Node* temp=head;
        for(int i=0;i<index-1;i++){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        size-=1;
        // print();
        return;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */