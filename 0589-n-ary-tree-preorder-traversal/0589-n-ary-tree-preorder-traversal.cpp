/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    
    stack<int> helper(Node* root, stack<int> s) {
        // cout<<"size is:"<<root->children.size()<<endl;
        if(root->children.size()==0){
            s.push(root->val);    
            return s;
        }
        // cout<<"inserting-->"<<root->val<<endl;
        for(int i=root->children.size()-1;i>=0;i--){
            s=helper(root->children[i], s);
        }
        s.push(root->val);
        return s;
    }
    
    vector<int> preorder(Node* root) {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        stack<int> hold;
        hold = helper(root,hold);
        while(hold.size()!=0){
            ans.push_back(hold.top());
            hold.pop();
        }
        
        return ans;
    }

};