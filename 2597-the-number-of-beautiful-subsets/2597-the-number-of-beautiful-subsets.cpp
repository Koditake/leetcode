class Solution {
public:
    void dfs(std::vector<int> &nums, int idx, int k, std::unordered_map<int, int> &mp, int &ans) {
        // If we have reached the end of the list, count this unique subset
        if(idx == nums.size()) ans++;
        
        else {
            // recurse, if possible recurse taking this element for the subset
            if(!mp[nums[idx] - k] && !mp[nums[idx] + k]) {
                mp[nums[idx]]++;
                dfs(nums, idx + 1, k, mp, ans);
                mp[nums[idx]]--;
            }
            // Recurse without taking this element in the subset
            dfs(nums, idx + 1, k, mp, ans);
        }
    }
    
    
    int beautifulSubsets(vector<int>& nums, int k) {
        int ans = 0;
        std::unordered_map<int, int> mp;
        // DFS through the numbers array from index 0
        dfs(nums, 0, k, mp, ans);
        // Return all of the counted sets - 1 for the empty set
        return ans - 1;
    }
};