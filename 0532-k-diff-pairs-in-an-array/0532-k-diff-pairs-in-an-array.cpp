class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (nums.size() == 0 || k < 0)
            return 0;

        std::unordered_map<int, int> map;
        
        for (int i:nums) {
            map[i]++;
        }

        int count = 0;
        for (const auto& entry:map) {
            if (k == 0) {
                // count how many elements in the array that appear more than twice
                if (entry.second >= 2) {
                    count++;
                }
            } else {
                if (map.find(entry.first + k) != map.end()) {
                    count++;
                }
            }
        }

        return count;
    }
};