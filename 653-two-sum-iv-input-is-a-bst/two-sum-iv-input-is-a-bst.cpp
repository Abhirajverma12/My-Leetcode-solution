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
    void inorderc(TreeNode* root, vector<int>& vec) {
        if (root == nullptr) return;

        inorderc(root->left, vec);
        vec.push_back(root->val);
        inorderc(root->right, vec);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> vec;
        inorderc(root, vec);

        int n = vec.size();

        for (int i = 0; i < n - 1; i++) {
            int l = i;
            int r = n - 1;

            while (l < r) {
                if (vec[l] + vec[r] == k) return true;
                r--;
            }
        }

        return false;
    }
};