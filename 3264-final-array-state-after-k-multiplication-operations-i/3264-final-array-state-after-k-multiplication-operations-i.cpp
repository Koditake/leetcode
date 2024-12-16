class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while (k > 0) {
            auto n = *min_element(nums.begin(),nums.end()), i = 0;
            for (i; i < nums.size(); ++i) if (nums[i] == n) break;
            nums[i] *= multiplier;
            --k;
        }
        
        return nums;
    }
};