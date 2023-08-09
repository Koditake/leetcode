/*
    Same idea as two loops but one loops and two pointers
*/

#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        std::vector<int> result;
        std::unordered_map<int, int> record;

        for (auto i = 0; i < nums.size(); ++i) {
            auto item = record.find(target - nums[i]);
            if (item != record.end()) {
                return {item->second, i};
            }
            record[nums[i]] = i;
        }
        return result;
    }
};
