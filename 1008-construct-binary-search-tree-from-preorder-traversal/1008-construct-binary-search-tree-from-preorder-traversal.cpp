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
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==0){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        vector<int> small;
        vector<int> large;
        for(int i=1;i<preorder.size();i++){
            if(preorder[i] < root->val){
                small.push_back(preorder[i]);
            }
            else{
                large.push_back(preorder[i]);
            }
        }
        root->left=bstFromPreorder(small);
        root->right=bstFromPreorder(large);
        return root;
    }
};