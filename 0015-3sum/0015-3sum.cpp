class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        
        std::sort(nums.begin(), nums.end()); ///O(Nlog(N))
        std::vector<std::vector<int>> res;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                ///the chance of finding a triplet of elements that summed up to 0 is impossible at this point
                break;
            }
            
            int l = i + 1,
                r = n - 1;
            
            while (l < r) {
                if (nums[i] + nums[l] + nums[r] == 0) {
                    std::vector<int> temp = {nums[i],nums[l],nums[r]};
                    res.push_back(temp);
                    
                    /// skip all r duplicates
                    while (l <= r && nums[r] == temp[2]) {
                        --r;
                    }
                    
                    /// skip all l duplicates
                    while (l <= r && nums[l] == temp[1]) {
                        ++l;
                    }
                } else if (nums[i] + nums[l] + nums[r] > 0) {
                    --r;
                } else {
                    ++l;
                }
            }
            while(i+1 < nums.size() && nums[i]==nums[i+1]) i++;
        }
        
        return res;
    }
};