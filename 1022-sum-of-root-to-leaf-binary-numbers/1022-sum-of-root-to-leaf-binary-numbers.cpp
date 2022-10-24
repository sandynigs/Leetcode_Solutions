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
#include<cmath>
#include<vector>
class Solution {
public:
    
    int helper(TreeNode* root, int sm, vector<int> curr){
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right==NULL){
            curr.push_back(root->val);
            int n=curr.size();
            int cs=0;
            for(int i=0;i<n;i++){
                cs+=pow(2,n-1-i)*curr[i];
            }
            return cs;
        }
        curr.push_back(root->val);
        int a=helper(root->left,sm,curr);
        int b=helper(root->right,sm,curr);
        // cout<<"left is:"<<a<<endl;
        // cout<<"right is:"<<b<<endl;
        sm+=a+b;
        return sm;
    }
    
    int sumRootToLeaf(TreeNode* root) {
        int sm=0;
        vector<int> v;
        sm+=helper(root, sm, v);
        return sm;
    }
};