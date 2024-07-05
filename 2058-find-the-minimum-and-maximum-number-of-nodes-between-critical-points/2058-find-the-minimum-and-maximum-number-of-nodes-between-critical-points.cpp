/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = INT_MAX, 
            last = 0, 
            prev_val = head->val, 
            min_d = INT_MAX;
        
        for (int i = 0; head->next != nullptr; ++i) {
            if ((max(prev_val, head->next->val) < head->val) || 
                (min(prev_val, head->next->val) > head->val)) {
                if (last != 0)
                    min_d = min(min_d, i - last);
                first = min(first, i);
                last = i;
            }
            prev_val = head->val;
            head = head->next;
        }
        
        if (min_d == INT_MAX)
            return {-1, -1};
        
        return {min_d, last - first};
    }
};