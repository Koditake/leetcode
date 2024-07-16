class Solution {
public:
    int findMin(vector<int>& nums) {
        if (!nums.size()) return -1;
        
        return *min_element(nums.begin(), nums.end());
    }
};