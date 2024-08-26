/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    auto helper(Node* root, vector<int> &res) -> void {
        if (!root) return;
        for (auto const &n:root->children)
            helper(n,res);
        res.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }
};