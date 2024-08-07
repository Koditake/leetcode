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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        std::unordered_map<TreeNode*, TreeNode*> parentMap; // map from child node pointer to parent node pointer
        std::unordered_map<int, TreeNode*> m; // map from node value to node pointer
        for (auto &des : descriptions) {
            int p = des[0], 
                c = des[1], 
                isLeft = des[2];
            
            auto parent = m.count(p) ? m[p] : (m[p] = new TreeNode(p));
            auto child = m.count(c) ? m[c] : (m[c] = new TreeNode(c));
            if (isLeft) parent->left = child;
            else parent->right = child;
            parentMap[child] = parent;
        }
        auto root = m.begin()->second; // Pick a random node pointer and keep traversing up until the node doesn't have any parents
        while (parentMap.count(root)) 
            root = parentMap[root];
        return root;
    }
};