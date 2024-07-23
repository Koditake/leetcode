class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        std::unordered_map<int, int> map;
        for (int &n:nums)
            map[n]++;
        sort(begin(nums), end(nums), [&](int a, int b) {
            return map[a] == map[b] ? a > b : map[a] < map[b];
        });
        return nums;
    }
};