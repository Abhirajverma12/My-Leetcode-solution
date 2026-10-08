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
    void storeinorder(TreeNode* root, vector<int>&arr){
        if(root == NULL){return ;}

        storeinorder(root->left,arr);
        arr.push_back(root->val);
        storeinorder(root->right,arr);
    }

    void recover(TreeNode* root, vector<int>& arr, int& index) {
        if (root == NULL) {
            return;
        }

        recover(root->left, arr, index);

        root->val = arr[index];
        index++;

        recover(root->right, arr, index);
    }

    void recoverTree(TreeNode* root) {
        vector<int>arr;
        storeinorder(root,arr);
        sort(arr.begin(),arr.end());

        int index = 0;
        recover(root, arr, index);
    }
};