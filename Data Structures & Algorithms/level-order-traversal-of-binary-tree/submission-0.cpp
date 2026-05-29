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
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::queue<TreeNode*> q;
        std::vector<std::vector<int>> v;
        if(root==nullptr) return {};
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            std::vector<int> level;
            for(int i = 0; i < size; i++){
                TreeNode* cur =  q.front(); q.pop();
                level.push_back(cur->val);
                if(cur->left != nullptr){
                    q.push(cur->left);
                }
                if(cur->right != nullptr){
                    q.push(cur->right);
                }
            }
            v.push_back(level);
        }
        return v;
    }
};
