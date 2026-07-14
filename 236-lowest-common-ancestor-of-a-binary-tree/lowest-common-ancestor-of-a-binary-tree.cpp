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
    bool ancestorofnode(TreeNode* root, TreeNode* node,vector<TreeNode*>& vec){
        if(root == NULL) return false;
        vec.push_back(root);
        if(root->val == node->val) {return true;}
        int left = ancestorofnode(root->left,node,vec);
        int right = ancestorofnode(root->right,node,vec);
        if(left || right ){
            return true;
        }
        vec.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>res1 ;
        vector<TreeNode*>res2;
        ancestorofnode(root,p,res1);
        ancestorofnode(root,q,res2);

        // cout<<res1<<endl;
        // cout<<res2<<endl;
        map<TreeNode*,int>mpp ;

        int n1 = res1.size() , n2 = res2.size();
        TreeNode* ans;
        for(int i=0;i<n1;i++){
            mpp[res1[i]]++;
        }
        for(int i=0;i<n2;i++){
            mpp[res2[i]]++;
        }
        for(auto it:mpp){
            if(it.second==2) ans = it.first;
        }
        return ans;

    }
};