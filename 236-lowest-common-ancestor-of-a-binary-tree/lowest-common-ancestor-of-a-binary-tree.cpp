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
// TC - O(N) , SC - O(1) 
// without any extra space 

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return nullptr; // basecase 

        if(p == root || q == root) return root; // if any of p or q is root than we have to return root 

        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        if(left && right) return root; // if from both left & right side p , q is found so we have to return that current root 

        if(left)return left; // if any of p,q is found at the left so we return left

        if(right)return right;// if any of p,q is found at right so we return right

        return nullptr; // if any of p,q is not found at the left or at the right so we have to return the 'nullptr'
    }
};