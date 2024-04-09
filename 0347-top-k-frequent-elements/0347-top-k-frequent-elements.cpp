class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        //heap of pair <freq,element>

        unordered_map<int,int> map;

        for (int& i:nums) {
            map[i]++;
        }

        priority_queue<pair<int,int>> heap;
        vector<int> result;

        for (auto& [elem,freq]:map) {
            heap.push(make_pair(freq, elem));
            if (heap.size() > (int)map.size() - k){
                result.push_back(heap.top().second);
                heap.pop();
            }
        }

        return result;
    }
};