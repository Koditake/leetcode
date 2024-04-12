class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        if (n < 2) [[unlikely]]
            return 0;

        int l = 0, r = n - 1, res = 0;
        while (l <= r) {
            int temp = std::min(height[l],height[r]) * (r - l);
            res = std::max(res,temp);
            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }

        return res;
    }
};