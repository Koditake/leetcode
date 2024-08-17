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
        /** Idea:
        * Let   L1 = start of cycle in LL
        *       l1 = dist head -> L1
        *       L2 = meeting of slow&fast ptrs in Floyd's algorithm
        *       l2 = dist L1 -> L2
        *       XP = the dist from L2 to L1 in cycle
        * When slow meets fast,
        *       dist of slow: l1 + l2
        *       dist of fast: l1 + l2 + XP + l2;
        * Since 2Vs = Vf, w.r.t same travel time:
        *       ==> 2(l1 + l2) = l1 + l2 + XP + l2;
        *       <=> 2*l1 + 2*l2 = l1 + 2*l2 +  XP
        *       <=> l1 = XP;
        * This mean H -> L1 = L2 -> L1;
        * Plan:
        * Find if LL is cycle. If yes, mark the meeting ptr of Floyd's
        * Make new cur ptr from H. Run cur and slow and same speed.
        * If cur meets slow -> that's where cycle head is.
        */
        
        auto cyl = isCycle(head);
        if (!head || !cyl) return nullptr;
        
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