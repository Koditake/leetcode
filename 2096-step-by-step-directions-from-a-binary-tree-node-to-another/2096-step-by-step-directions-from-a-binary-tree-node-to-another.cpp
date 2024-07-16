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
    auto lca(TreeNode *root, int startValue, int destValue) -> TreeNode* {
        if (!root) return NULL;
        if (root->val == startValue) return root;
        if (root->val == destValue) return root;
        auto l = lca(root->left, startValue, destValue);
        auto r = lca(root->right, startValue, destValue);
        if (l && r) return root;
        return l ? l : r;
    }
    auto getPath(TreeNode *root, int value, string &path) -> bool {
        if (!root) return false;
        if (root->val == value) return true;
        path += 'L';
        auto res = getPath(root->left, value, path);
        if (res) return true;
        path.pop_back();
        path += 'R';
        res = getPath(root->right, value, path);
        if (res) return true;
        path.pop_back();
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        root = lca(root, startValue, destValue);
        string p1, p2;
        getPath(root, startValue, p1);
        getPath(root, destValue, p2);
        for (auto &c : p1) c = 'U';
        return p1 + p2;
    }
};