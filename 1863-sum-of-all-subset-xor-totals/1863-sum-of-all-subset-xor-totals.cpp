class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        int n = nums.size(),
            numOfSubsets = pow(2, n),
            result = 0;
        
        // binary representation of subsets help us identify whether to take an element of num or not
        for (int subset = 1; subset < numOfSubsets; ++subset)
        {
            int runningXor = 0;
            for (int i = 0, bits = subset; i < nums.size(); ++i, bits >>= 1)
                if (bits & 1)   // whether to include current element in subset
                    runningXor ^= nums[i];
            
            result += runningXor;
        }
        
        return result;
    }
};