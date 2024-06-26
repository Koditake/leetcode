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
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return  0;
        int sum=0;
        vector<pair<TreeNode*, bool>> stack={{root, 0}};// as stack
        while(!stack.empty()){
            auto [Node, isLeft]=stack.back();
            stack.pop_back();
            if (!Node->left && !Node->right && isLeft) sum+=Node->val;
            else{
            //since stack, the following order:right sbtree, then left subtree
                if (Node->right)stack.emplace_back(Node->right, 0);
                if (Node->left) stack.emplace_back(Node->left, 1);
            }
        }
        return sum;
    }
};