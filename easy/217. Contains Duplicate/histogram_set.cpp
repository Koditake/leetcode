/*
    Make a hashmap using a set. If the size of the array is larger than the size of set (which contains only unique elements), determine if any element is repeated.
*/

#include <vector>
#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(std::vector<int> &nums)
    {
        bool result = false;

        std::unordered_set<int> map;

        for (int i : nums)
        {
            if (map.find(i) != map.end())
                result = true;
            else
                map.insert(i);
        }

        return result;
    }
};