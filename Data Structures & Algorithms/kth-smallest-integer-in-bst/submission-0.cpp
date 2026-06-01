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
    int k = 0;
    int val = -1;
    int kthSmallest(TreeNode* root, int k) {
        int i = 0;
        this->k = k;
        dfs(root, i);
        return val;
    }
    void dfs(TreeNode* root, int& index){
        
        if(root->left) dfs(root->left, index);
        index++;
        if(index == k) {
            std::cout << val << ": " << root->val << std::endl;
            val = root->val;
            return;
        }
        if(root->right) dfs(root->right, index);
    }

};
