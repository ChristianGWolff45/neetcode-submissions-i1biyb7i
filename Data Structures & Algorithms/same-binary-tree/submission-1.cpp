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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        std::queue<TreeNode*> qp, qq;
        if(p != nullptr && q != nullptr){
            qp.push(p);
            qq.push(q);
        }else if(p != nullptr || q != nullptr){
            return false;
        }else{
            return true;
        }
        while(!qp.empty() && !qq.empty()){
            TreeNode* pcurr = qp.front(); qp.pop();
            TreeNode* qcurr = qq.front(); qq.pop();
            if(qcurr->val != pcurr->val){
                return false;
            }
            if(pcurr->left != nullptr && qcurr->left != nullptr){
                qp.push (pcurr->left);
                qq.push (qcurr->left);
            }else if(pcurr->left != nullptr || qcurr->left != nullptr){
                return false;
            }
            if(pcurr->right != nullptr && qcurr->right != nullptr){
                qp.push (pcurr->right);
                qq.push (qcurr->right);
            }else if(pcurr->right != nullptr || qcurr->right != nullptr){
                return false;
            }
        }
        if(!qp.empty() || !qq.empty()){
            return false;
        }
        return true;
    }
};
