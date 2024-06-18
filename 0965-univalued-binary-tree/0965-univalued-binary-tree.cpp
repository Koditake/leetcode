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
    auto isFinder(TreeNode* root, int val) -> bool {
        if (root == nullptr) {
            return true;
        }
        
        if (val != root->val) {
            return false;
        }
        
        return isFinder(root->left, root->val) && isFinder(root->right, root->val);
    }
    
    bool isUnivalTree(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        
        return isFinder(root->left, root->val) && isFinder(root->right, root->val);
    }
};