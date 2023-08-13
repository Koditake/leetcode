#include <vector>

using namespace std;

class Solution {
public:
    bool validPartition(vector<int> &nums)
    {
        // We are setting all of them to be true because if we take any number of steps from last index, the answer is true
        int dp_1 = 1, dp_2 = 1, dp_3 = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            int cur = 0;
            if (i + 1 < nums.size() and nums[i] == nums[i + 1])
                cur = max(cur, dp_2);
            if (i + 2 < nums.size())
            {
                if (nums[i] == nums[i + 1] and nums[i + 1] == nums[i + 2])
                    cur = max(cur, dp_3);
                else if (nums[i + 1] - nums[i] == 1 && nums[i + 2] - nums[i + 1] == 1)
                    cur = max(cur, dp_3);
            }
            dp_3 = dp_2;
            dp_2 = dp_1;
            dp_1 = cur;
        }
        return dp_1;
    }
};