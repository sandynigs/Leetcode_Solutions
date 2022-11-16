/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(cloned==NULL && original==NULL){
            return NULL;
        }
        
        if(cloned->val==target->val){
            return cloned;
        }
        else{
            TreeNode* ansLeft = getTargetCopy(original->left, cloned->left, target);
            TreeNode* ansRight = getTargetCopy(original->right, cloned->right, target) ;
            if(ansLeft==NULL){return ansRight;}
            return ansLeft;
            
        }
    }
};