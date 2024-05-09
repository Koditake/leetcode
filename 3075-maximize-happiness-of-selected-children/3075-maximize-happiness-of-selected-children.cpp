class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());
        
        long long sum = 0LL;
        for (int i = 0, unhappy = 0; i < k; i++, unhappy++) {
            sum += max(0, happiness[i] - unhappy);
        }
        return sum;
    }
};