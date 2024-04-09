class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        std::vector<int> res (n,1), 
                        pre (n,1), post (n,1);

        //pre
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] * nums[i - 1];
        }

        //post
        for (int i = n - 2; i >= 0; i--) {
            post[i] = post[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < n; i++) {
            res[i] = post[i] * pre[i];
        }

        return res;
    }
};