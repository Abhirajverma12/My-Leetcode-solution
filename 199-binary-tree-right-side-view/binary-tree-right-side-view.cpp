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
    vector<int> rightSideView(TreeNode* root) {
        
        if(root == NULL ) return {};
        queue<TreeNode*>q;
        stack<int>st;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            int lastrightval ;
            for(int i=0;i<n;i++){
                TreeNode* node = q.front();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                lastrightval = node->val;
                q.pop();
            }         
            st.push(lastrightval);  
        }
        int sizee = st.size();
        vector<int>ans(sizee);
        while(!st.empty()){
            ans[sizee-1] = st.top();
            sizee--;
            st.pop();
        }
        return ans;
    }
};