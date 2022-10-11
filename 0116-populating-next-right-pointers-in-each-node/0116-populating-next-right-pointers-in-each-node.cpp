/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
#include<queue>
class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL){return root;}
        queue<Node*> q;
        q.push(NULL);
        q.push(root);
        while(q.size()!=0){
            Node* front = q.front();
            if(front==NULL){
                if(q.size()==1){
                    q.pop();
                }
                else{
                    q.pop();
                    q.push(NULL);
                }
            }
            else{
                q.pop();
                Node* nxt = q.front();
                front->next = nxt;
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
        }
        return root;
    }
};