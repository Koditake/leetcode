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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || !head->next)
            return nullptr;
        
        auto slow = head, fast = head, slow_prev = slow;
        
        while (n > 0) {
            fast = fast->next;
            --n;
        }
        
        if (!fast)
            return head->next;
        
        while (fast) {
            slow_prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        
        slow_prev->next = slow->next;
        slow = nullptr;
        return head;
    }
};