class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0,
            r = numbers.size() - 1;
        
        while (l < r) {
            int m = numbers[l] + numbers[r];
            
            if (m > target) {
                --r;
            } else if (m < target) {
                ++l;
            } else {
                return {l + 1,r + 1};
            }
        }
        
        return {-1,-1};
    }
};