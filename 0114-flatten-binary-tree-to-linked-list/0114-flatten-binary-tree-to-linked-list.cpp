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

class Pair {
    public:
    TreeNode* first;
    TreeNode* last;
};


class Solution {
public:
    
    Pair helper(TreeNode* root){
        if(root==NULL){
            TreeNode* f=NULL;
            TreeNode* l=NULL;
            Pair p;
            p.first=f;
            p.last=l;
            return p;
        }
        else if(root->left==NULL && root->right==NULL){
            TreeNode* f=root;
            TreeNode* l=root;
            Pair p;
            p.first=f;
            p.last=l;
            return p;            
        }
        else if(root->left!=NULL && root->right==NULL){
            Pair callLeft=helper(root->left);
            root->left=NULL;
            root->right=callLeft.first;
            TreeNode* f=root;
            TreeNode* l=callLeft.last;
            Pair p;
            p.first=f;
            p.last=l;
            return p;            
        }
        
        else if(root->left==NULL && root->right!=NULL){            
            Pair callRight=helper(root->right);
            root->right=callRight.first;
            TreeNode* f=root;
            TreeNode* l=callRight.last;
            Pair p;
            p.first=f;
            p.last=l;
            return p; 
        }
        
        Pair callLeft=helper(root->left);
        Pair callRight=helper(root->right);
        root->left=NULL;
        root->right=callLeft.first;
        callLeft.last->right=callRight.first;
        Pair ans;
        ans.first=root;
        ans.last=callRight.last;
        return ans;
    }
    
    
    void flatten(TreeNode* root) {
        helper(root);
    }
};