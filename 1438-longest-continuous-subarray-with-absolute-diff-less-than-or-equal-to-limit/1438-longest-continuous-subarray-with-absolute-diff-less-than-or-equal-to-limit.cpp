class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        std::multiset<int> count;
        int j = 0, 
            res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            count.insert(nums[i]);
            while (*count.rbegin() - *count.begin() > limit)
                count.erase(count.find(nums[j++]));
            res = max(res, i - j + 1);
        }
        return res;
    }
};