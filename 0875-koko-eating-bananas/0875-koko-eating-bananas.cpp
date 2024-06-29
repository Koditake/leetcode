class Solution {
public:
    auto bananEatTime(int speed, vector<int> &piles) -> long long {
        long long res = 0;
        for (auto &pile:piles) {
            res += ceil((double)pile/speed);
        }
        
        return res;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        long long l = 1,
            r = *std::max_element(piles.begin(),piles.end());
        long long res = r;
        while (l <= r) {
            long long m = l + (r - l)/2,
                t = bananEatTime(m, piles);
            
            if (t > h) {
                l = m + 1;
            } else /*if (t <= h)*/ {
                r = m - 1;
                res = std::min(res,m);
            }
        }
        
        return (int)res;
    }
};