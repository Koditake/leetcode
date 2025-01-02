class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = INT_MAX,
            l = 0,
            r = 0,
            t = 0,
            n = nums.size();

        for (r; r < n; ++r) {
            t += nums[r];
            while (t >= target) {
                res = min(res, r - l + 1);
                t -= nums[l];
                ++l;
            } 
        }

        // summation of entire array was smaller than target
        if (res == INT_MAX) return 0;
        return res;
    }
};