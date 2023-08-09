/*
    Make a histogram of the array, check if frequency of any number is greater than 1

    Time: O(n)
    Space: O(n)
*/

#include <unordered_map>
#include <vector>

class Solution {
public:
    bool containsDuplicate(std::vector<int> &nums)
    {
        if (nums.empty())
        {
            return false;
        }
        std::unordered_map<int, int> mp;
        for (int i : nums)
        {
            if (++mp[i] > 1)
            {
                return true;
            }
        }
        return false;
    }
};