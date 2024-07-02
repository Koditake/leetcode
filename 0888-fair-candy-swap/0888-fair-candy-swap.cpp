class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int diff = (std::accumulate(aliceSizes.begin(), aliceSizes.end(), 0) - std::accumulate(bobSizes.begin(), bobSizes.end(), 0))/2;
                            
        for (auto i : aliceSizes) 
            if(std::find(bobSizes.begin(), bobSizes.end(), i - diff) != bobSizes.end())
                return {i,  i - diff};
        return {};
    }
};