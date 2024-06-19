class Solution {
public:
    auto canHarvest(vector<int>& bDay, int harvestDay, int m, int k) -> bool {
        int adjacent = 0;
        for (auto &bloomDay:bDay) {
            adjacent = (bloomDay <= harvestDay) ? adjacent + 1 : 0;
            if (adjacent == k) {
                adjacent = 0;
                --m;
            }
        }
        return m <= 0;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        //if m bouquets each needed k flowers is more than bloom map -> error 
        if ((long long)m * k > bloomDay.size())
            return -1;
        
        
        auto lo = 1, 
            hi = 1000000000;
        while (lo < hi) {
            auto mid = (hi + lo) / 2;
            if (canHarvest(bloomDay, mid, m, k))
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};