/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<stack>
class Solution {
public:
    
    stack<TreeNode*> helper(TreeNode* root, stack<TreeNode*> s){
        if(root==NULL){
            return s;
        }
        s=helper(root->right, s);
        s.push(root);
        s=helper(root->left, s);
        return s;
    }
    
    
    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode*> s;
        s = helper(root,s);
        TreeNode* nr=s.top();
        TreeNode* front;
        while(s.size()!=0){
            front=s.top();
            s.pop();
            front->left=NULL;
            if(s.size()!=0){
                TreeNode* next=s.top();
                front->right=next;
            }
        }
        return nr;
    }
};