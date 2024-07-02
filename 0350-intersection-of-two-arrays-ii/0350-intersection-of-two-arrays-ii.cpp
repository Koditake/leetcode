class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // If the size of nums1 is greater than nums2, swap them...
        if(nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }
        
        unordered_map<int,int> map;
        
        for(auto val: nums1) {
            map[val]++;
        }
        
        int idx = 0;
        for(auto val: nums2) {
            if(map[val] > 0) {
                nums1[idx++] = val;
                --map[val];
            }
        }
        return vector<int>(nums1.begin(), nums1.begin()+idx);
    }
};