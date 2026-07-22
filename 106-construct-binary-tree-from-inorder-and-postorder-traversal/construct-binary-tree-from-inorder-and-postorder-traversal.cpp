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

    TreeNode* solve(unordered_map<int,int>& Inmpp, vector<int>&inorder, int inStart,int inEnd,vector<int>& postorder, int pStart,int pEnd){
        if(inStart>inEnd || pStart>pEnd) {
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[pEnd]);
        int indx = Inmpp[postorder[pEnd]];
        int numleft = indx - inStart;

        root->left  = solve(Inmpp,inorder,inStart,indx-1, postorder,pStart,pStart+numleft-1);
        root->right = solve(Inmpp,inorder,indx+1,inEnd,postorder,pStart+numleft,pEnd-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
       unordered_map<int,int>Inmpp;

       for(int i=0;i<inorder.size();i++){
        Inmpp[inorder[i]]=i;
       } 

       TreeNode* root = solve(Inmpp,inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);

       return root ;

    }
};