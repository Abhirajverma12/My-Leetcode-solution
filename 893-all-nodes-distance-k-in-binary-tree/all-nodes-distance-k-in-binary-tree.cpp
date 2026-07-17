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
    unordered_map<TreeNode*,TreeNode*>parentrec;
    
    void track_parent(TreeNode* root){
        if(root==NULL)return ;
        
        if(root->left!=NULL) parentrec[root->left] = root;
        track_parent(root->left);

        if(root->right != NULL) parentrec[root->right] = root;
        track_parent(root->right);

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>result;

        track_parent(root);

        queue<TreeNode*>q;
        q.push(target);
        unordered_set<int>visited;
        visited.insert(target->val);

        while(!q.empty()){
            
            if(k==0) break;

            int n =q.size();
            for(int i=0;i<n;i++){
                TreeNode* currnode = q.front();
                q.pop();
                if(currnode->left!=NULL && !visited.count(currnode->left->val)){
                    q.push(currnode->left);
                    visited.insert(currnode->left->val);
                }

                if(currnode->right!=NULL && !visited.count(currnode->right->val)){
                    q.push(currnode->right);
                    visited.insert(currnode->right->val);
                }
                if(parentrec.count(currnode) && (visited.find(parentrec[currnode]->val) ==visited.end())){
                    q.push(parentrec[currnode]);
                    visited.insert(parentrec[currnode]->val);
                }
            }k--;
        }
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            result.push_back(temp->val);
        }
        return result;
    }
};