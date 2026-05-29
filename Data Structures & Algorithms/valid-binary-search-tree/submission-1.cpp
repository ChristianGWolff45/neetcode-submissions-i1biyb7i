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
    bool valid;
    bool isValidBST(TreeNode* root) {
        valid = true;
        if(root->left != nullptr){
            dfs(root->left, INT_MIN, root->val);
        }
        if(root->right != nullptr){
            dfs(root->right, root->val, INT_MAX);
        }

        return valid;
    }
    void dfs(TreeNode* node, int min, int max){
        if(node->val <= min || node->val >= max){
            valid = false;
        }
        if(!valid){
            return;
        }
        if(node->left != nullptr){
            dfs(node->left, min, node->val);
        }
        if(node->right != nullptr){
            dfs(node->right, node->val, max);
        }
    }

};
