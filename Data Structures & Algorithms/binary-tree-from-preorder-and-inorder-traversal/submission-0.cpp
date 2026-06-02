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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int i = 0;
        if (preorder.empty() || inorder.empty()) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        if(preorder.size() == 1){
            return root;

        }
        while(i < inorder.size()){
            if(inorder[i] == preorder[0]){
                std::vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + i + 1);
                std::vector<int> leftInorder(inorder.begin(), inorder.begin() + i);
                root->left = buildTree(leftPreorder, 
                                       leftInorder);
                std::vector<int> rightPreorder(preorder.begin() + i + 1, preorder.end());
                std::vector<int> rightInorder(inorder.begin() + i + 1, inorder.end());
                root->right = buildTree(rightPreorder,
                                        rightInorder);
                break;
            }
            i++;
        }
        return root;
    
    }
 
};
