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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        std::queue<TreeNode*> q;
        if(root == nullptr){
            return subRoot == nullptr;
        }
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front(); q.pop();
            if(curr->val == subRoot->val){
                if(isEqual(curr, subRoot)) return true;
            }
            if(curr->left != nullptr){
                q.push(curr->left);
            }
            if(curr->right != nullptr){
                q.push(curr->right);
            }
        }
        return false;
    }
    bool isEqual(TreeNode* root, TreeNode* subRoot){
        if(!root && !subRoot) return true;
        else if(!root || !subRoot) return false;
        else if(root->val != subRoot->val) return false;
        else return isEqual(root->left, subRoot->left) && isEqual(root->right, subRoot->right);
    }
};
