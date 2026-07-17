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
    int widthOfBinaryTree(TreeNode* root) {
        long long  maxwidth = 0;

        queue<pair<TreeNode*,long long>>q;
        q.push({root,0}); // we have push the root node have 0 index 

        while(!q.empty()){
            
            int n = q.size();// we have to only compute the width of the current level by ((rindx-lindx)+1)

            long long lindx ,rindx; // for keep track of left & right most node of the current level 
            long long minIndx = q.front().second;
            for(int i=0;i<n;i++){
                auto it = q.front();
                q.pop();
                long long indx = it.second-minIndx;
                if(i==0){ // we have to use this because if any level has only one node so we assign the left & right indx at a time 
                    lindx = indx ;
                    rindx = indx;
                }
                rindx = indx ;
                TreeNode* node = it.first;
                if(node->left) q.push({node->left,((indx*2)+1)}); // push the left child in queue by assign the indx if exists
                if(node->right) q.push({node->right,((indx*2)+2)}); // push the right child in queue by assign the indx if exists
            }

            long long currwidth = (rindx-lindx)+1; // compute the width of current level 
            maxwidth = max(maxwidth,currwidth);

        }
        return maxwidth;
    }
};