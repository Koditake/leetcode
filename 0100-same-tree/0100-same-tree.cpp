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
    auto treeCheck(TreeNode *p, TreeNode *q) -> bool {
        if (p == q) {
            return true;
        }

        if (!p || !q) {
            return false;
        }

        if (p->val != q->val) {
            return false;
        }
        
        return treeCheck(p->left, q->left) && treeCheck(p->right, q->right);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        auto res = treeCheck(p, q);
        
        p = q = nullptr;
        
        return res;
    }
};