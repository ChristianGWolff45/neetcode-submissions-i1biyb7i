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
    bool balanced=true;
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return balanced;
        
    }
    int dfs(TreeNode* node){
        if(node == nullptr || !balanced){
            return 0;
        }
        int left = dfs(node->left);
        int right = dfs(node->right);
        if(left >= (right +2) || right >= (left+2)){
            balanced = false;
        }
        return 1 + max(left,right);

    }
};
