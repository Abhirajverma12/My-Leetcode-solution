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
    TreeNode* tree(unordered_map<int,int>& Inmpp,vector<int>& inorder,int inStart ,int inEnd ,vector<int>& preorder,int preStart,int preEnd){

      if(inStart>inEnd || preStart >preEnd) return NULL;

      TreeNode* node = new TreeNode(preorder[preStart]);

      int indx = Inmpp[preorder[preStart]];
      int numleft = indx - inStart ;

      node->left = tree(Inmpp,inorder,inStart,indx-1,preorder,preStart+1,preStart+numleft);
      node->right = tree(Inmpp,inorder,indx+1,inEnd,preorder,preStart+numleft+1,preEnd);
      return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>inmpp;
        for(int i=0;i<inorder.size();i++){
            inmpp[inorder[i]] = i;
        }

        TreeNode* root = tree(inmpp,inorder,0,inorder.size()-1,preorder,0,preorder.size()-1);

        return root;
    }
};