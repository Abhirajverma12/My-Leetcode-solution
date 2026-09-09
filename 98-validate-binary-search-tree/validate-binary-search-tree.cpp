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
    bool checkValid(TreeNode* root , long long mini,long long maxi){
        if(root == NULL) return true ;
        if(root->val  <= mini || root->val >= maxi){
            return false ;
        }
        if(!checkValid(root->left,mini,root->val) || !checkValid(root->right ,root->val,maxi)  ){
            return false;
        }
        return true;
    }
    bool isValidBST(TreeNode* root) {
        return checkValid(root,LLONG_MIN,LLONG_MAX);
    }
};