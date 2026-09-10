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
public: // LCA implementation for the BST 
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       if(root == NULL ){
        return NULL ;
       } 
       // we compare the curr root by p, q if p, q  is small than we search on the left subtree other wise righsubtree

        // Both smaller -> search left
       if(p->val < root->val && q->val < root->val ){ 
        return lowestCommonAncestor(root->left , p,q);
       }

       // Both greater -> search right
       if(p->val > root->val && q->val >root->val ){
        return lowestCommonAncestor(root->right,p,q);
       }

       return root ;
    }
};