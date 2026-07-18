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
    unordered_map<TreeNode*,TreeNode*>parent;
    void parent_track(TreeNode* root){
        if(root ==NULL)return ;

        if(root->left!=NULL){parent[root->left]=root;}
        parent_track(root->left);

        if(root->right !=NULL){parent[root->right]=root;}
        parent_track(root->right);
    }

    TreeNode* findnode(TreeNode* root, int target){
        if(root ==NULL)return nullptr;
        if(root->val == target) return root;

        TreeNode* left = findnode(root->left,target);
        TreeNode* right = findnode(root->right,target);
        if(left) return left;
        if(right) return right;
        return nullptr;
    }
    int amountOfTime(TreeNode* root, int start) {
        // find at which node the value is equal start
        TreeNode* target = findnode(root,start); 

        parent_track(root);

        queue<TreeNode*>q;
        unordered_set<TreeNode*>visited;
        q.push(target);
        visited.insert(target);
        int cnt=0;

        while(!q.empty()){
            int n = q.size();
            for(int i =0;i<n;i++){
                TreeNode* currnode = q.front();
                q.pop();

                if(currnode->left !=NULL && (visited.find(currnode->left)==visited.end())){
                    q.push(currnode->left);
                    visited.insert(currnode->left);
                }
                if(currnode->right !=NULL && (visited.find(currnode->right)==visited.end())){
                    q.push(currnode->right);
                    visited.insert(currnode->right);
                }
                if(parent.count(currnode) && (visited.find(parent[currnode])==visited.end())){
                    q.push(parent[currnode]);
                    visited.insert(parent[currnode]);
                }
            }
            if(!q.empty()) cnt++;
        }
        return cnt;
    }
};