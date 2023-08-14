#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //priority queue;

        int n = nums.size();
        
        priority_queue<int> queue;

        for (int i:nums) {
            queue.push(i);
        }

        while (k > 1) {
            queue.pop();
            k--;
        }

        return queue.top();
    }
};