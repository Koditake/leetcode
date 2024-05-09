class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0,
            r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l)/2,
                val = nums[mid];
            
            if (val == target) {
                return mid;
            } else if (val > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return -1;
    }
};