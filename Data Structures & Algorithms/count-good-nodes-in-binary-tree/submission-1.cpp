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
    int good;
    int goodNodes(TreeNode* root) {
        good = 0;
        if(root == nullptr) return 0;
        isGood(root, root->val);
        return good;
    }
    void isGood(TreeNode* node, int max){
        if(node->val >= max){
            good+=1;
            max = node->val;
        }
        if(node->right != nullptr){
            isGood(node->right, max);
        }
        if(node->left != nullptr){
            isGood(node->left, max);
        }
        
    }
};
