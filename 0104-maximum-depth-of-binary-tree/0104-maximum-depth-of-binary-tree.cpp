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
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        int res = 0;
        std::queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()) {
            ++res;
            int n = q.size();
            
            for (n; n > 0; --n) {
                TreeNode *t = q.front();
                q.pop();
                if (t->left) {
                    q.push(t->left);
                }

                if (t->right) {
                    q.push(t->right);
                }
            }
        }
        
        root->left = root->right = nullptr;
        return res;
    }
};