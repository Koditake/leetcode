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
        /***
        *   We have two edges case:
        *   1. !head: LL did not existed -> simply return null
        *   2. !head->next: LL have only one node (head) 
        *       and since n >= 1 (LL starting from 1) remove it would return null
        */
        if (!head || !head->next) return nullptr;
        
        auto slptr = head, fsptr = head, slprv = head;

        while (n > 0) {
            fsptr = fsptr->next;
            --n;
        }
        
        /***
        *   if n = length of LL, fast would be at the end (...->next == <null> <- the end)
        *   "to delete node n from behind" -> delete head of LL
        *   -> just return next node from ptr;
        */
        if (!fsptr) return head->next;
        
        while (fsptr) {
            slprv = slptr;
            slptr = slptr->next;
            fsptr = fsptr->next;
        }
        
        slprv->next = slptr->next;
        slptr = nullptr;
        return head;
    }
};