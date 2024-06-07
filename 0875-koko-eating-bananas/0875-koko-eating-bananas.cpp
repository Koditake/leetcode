class Solution {
public:
    auto kokoEatBanan(std::vector<int> &piles, int speed) -> long {
        long res = 0;
        for (auto &pile:piles) {
            res += ceil((double)pile/speed);
        }
        
        return res;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        
        int l = 1,
            r = *std::max_element(piles.begin(),piles.end());
        int res = r;
        while (l <= r) {
            int m = l + (r - l)/2; //banan per hour
            long v = kokoEatBanan(piles, m); //time to eat wrt to speed
            
                if (h >= v) {
                    res = std::min(res,m);
                    r = m - 1;
                } else {
                    l = m + 1;
                }  
        }
        
        return res;
    }
};