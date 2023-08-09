/*
    Sort the array and check if two consecutive numbers are different or not. If same, the second one is the one we are looking for.

    Time: O(n)
    Space: O(1)
*/
#include <math.h>
#include <vector>

class Solution{
public:
    bool containsDuplicate(std::vector<int> &nums)
    {
        bool result = false;
        std::sort(nums.begin(), nums.end());
        for (unsigned int i = 0; i < (nums.size() - 1); i++)
        {
            if (nums[i] == nums[i + 1])
            {
                result = true;
            }
        }
        return result;
    }
};