class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int res = 0;
        std::queue<int> flips;
        for (auto i = 0; i < nums.size(); ++i) {
            if (nums[i] != (flips.size() % 2 ? 0 : 1)) {
                ++res;
                flips.push(i + k - 1);
            }
            if (!flips.empty() && flips.front() <= i) 
                flips.pop();
        }
        return flips.empty() ? res : -1;
    }
};