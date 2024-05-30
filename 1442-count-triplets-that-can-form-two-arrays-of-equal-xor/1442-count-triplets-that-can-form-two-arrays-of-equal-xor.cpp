class Solution {
public:
    int countTriplets(vector<int>& arr) {
        std::unordered_map<int, vector<int>> xorMap;
        xorMap[0].push_back(-1);
        
        int x = 0;
        int res = 0;
        for (int i = 0; i < arr.size(); i++) {
            x ^= arr[i];
            for (auto j: xorMap[x]) {
                int start = j + 1, end = i;
                res += end - start;
            }
            xorMap[x].push_back(i);
        }
        
        return res;
    }
};