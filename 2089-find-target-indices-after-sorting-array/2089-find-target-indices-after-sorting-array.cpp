class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        ///bucket sort using map
        sort(nums.begin(), nums.end());
        std::vector<int> res;
        std::unordered_map<int, std::vector<int>> map;
        
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]].push_back(i);
        }
        
        if (map.contains(target)) {
            for (auto &n:map[target]) {
                res.push_back(n);
            }
        }
        
        return res;
    }
};