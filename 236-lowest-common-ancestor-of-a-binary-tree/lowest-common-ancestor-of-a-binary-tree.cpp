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
        if(root == node) {return true;}
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
        int n = min(res1.size(),res2.size());
        if(res1[0] != res2[0]) return nullptr;
        
        for(int i = 1 ; i < n ;i++){
            if(res1[i] != res2[i]) return res1[i-1];
        }

        return res1[n-1];
    }
};