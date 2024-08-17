/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    auto isCycle(ListNode *head) -> ListNode* {
        if (!head) return nullptr;
        auto slow = head, fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return slow;
        }
        
        return nullptr;
    }
    
    ListNode *detectCycle(ListNode *head) {
        auto cyl = isCycle(head);
        if (!head || !cyl) return nullptr;
        /** Idea:
        *   Run a third ptr fron head
        *   For every node of third ptr, run the cycle at normal speed.
        *   If a full cycle does not meet the third ptr, move to the next node.
        *   Repeat ad naseaum
        */
        auto cur = head;
        while (cur) {
            auto pre = cyl;
            do {
                cyl = cyl->next;
                if (cur == cyl) return cur;
            } while (pre != cyl);
            cur = cur->next;
        }
        
        return cur;
    }
};