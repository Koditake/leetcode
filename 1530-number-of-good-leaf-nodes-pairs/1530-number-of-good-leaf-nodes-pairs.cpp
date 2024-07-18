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
    int cnt = 0;
    vector<int> calcPairs(TreeNode* root, int dist)
    {
        //since this is a leaf node, return empty vector list
        if((root->left == NULL) && (root->right == NULL))
        {
            vector<int> v1;
            return v1;
        }
        
        //Left and Right to find the pairs and then to merge and send them
        vector<int> left;
        vector<int> right;
        
        //if the left node is not empty
        if(root->left)
        {
            //get the vector from the left
            left = calcPairs(root->left, dist);
            
            //if the vector from left is of size 0 then, it means we are just above a leaf node
            if(left.size()==0)
                left.push_back(1);
        }
        
        //if the right node is not empty
        if(root->right)
        {
            //get the vector from right
            right = calcPairs(root->right, dist);
            
            //if the right vectors is 0 then, it means we are just above a leaf node
            if(right.size()==0)
                    right.push_back(1);
        }
        
        //count the pairs less than or equal to the distance.
        for(int i=0; i<left.size(); i++)
        {
            for(int j=0; j<right.size(); j++)
            {
                if(left[i]+right[j]<=dist)
                    cnt++;
            }
        }
        
        //merging the vectors and increasing their height from the upcoming node.
        int i = 0;
        for(int i=0; i<left.size(); i++)
            ++left[i];
        while(i<right.size())
        {
            left.push_back(right[i]+1);
            i++;
        }
        return left;       
    }
    int countPairs(TreeNode* root, int distance) {
        vector<int> v = calcPairs(root, distance);
        return cnt;
    }
};
