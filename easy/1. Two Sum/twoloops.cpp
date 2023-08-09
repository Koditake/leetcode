/*
    Give two loops, one run from begin to end, one run from the one loop above to end. If we detect a pair that fit, exit.

    Time: O(n^2)
    Space: O(n^2)
*/

#include <vector>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        // naive
        std::vector<int> result;

        bool flag = false;

        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = 1; j < nums.size(); j++)
            {
                if ((nums[i] + nums[j] == target) && (i != j))
                {
                    result.push_back(i);
                    result.push_back(j);
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
        }
        return result;
    }
};
