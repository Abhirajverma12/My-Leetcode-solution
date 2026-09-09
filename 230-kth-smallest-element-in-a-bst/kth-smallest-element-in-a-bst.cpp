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
    void inOrder(TreeNode*root,vector<int>& inorderv){
        TreeNode* curr = root;
        // vector<int>inorderv ;
        while(curr!= NULL){

            if(curr->left == NULL ){
                inorderv.push_back(curr->val);
                curr = curr->right ;
            }
            else{
                TreeNode* prev = curr->left ;
                while(prev->right && prev->right != curr){prev = prev->right ;}
                if(prev->right == NULL){
                    prev->right = curr ;
                    curr = curr->left ;
                }else{
                    prev->right = NULL ;
                    inorderv.push_back(curr->val);
                    curr = curr->right ;
                }
            }
        }
        // return inorderv;
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>inorderv ;
        inOrder(root,inorderv);

        return inorderv[k-1];
    }
};