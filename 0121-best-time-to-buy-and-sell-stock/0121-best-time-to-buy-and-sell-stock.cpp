class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = INT_MIN,
            minprice = INT_MAX;
        
        for (auto &p:prices) {
            
            minprice = min(p,minprice);maxprofit = max(maxprofit, p - minprice);
        }
        
        return maxprofit;
    }
};