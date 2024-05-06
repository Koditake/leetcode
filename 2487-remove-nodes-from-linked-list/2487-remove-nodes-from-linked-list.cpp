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
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = head, *prev = nullptr;
        while (cur != nullptr) {
            swap(cur->next, prev);
            swap(prev, cur);
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        head = reverseList(head);
        for (auto p = head; p != nullptr && p->next != nullptr; ) {
            if (p->val > p->next->val)
                p->next = p->next->next;
            else
                p = p->next;
        }
        return reverseList(head);
    }
};