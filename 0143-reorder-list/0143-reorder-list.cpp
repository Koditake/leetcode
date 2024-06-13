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
    auto reverseList(ListNode *head) ->ListNode* {
        if (!head) {
            return nullptr;
        }
        
        ListNode *pre = nullptr,
                *cur = head,
                *temp;
        
        while (cur) {
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        
        return pre;
    }
    
    void reorderList(ListNode* head) {
        // Check for edge cases
        if(head->next == NULL || head->next->next == NULL)
            return;

        // Step 1 - Find middle of the LL with slow-fast pointer approach
        ListNode *slow = head, 
                *fast = head, 
                *slow_prev = nullptr;
        while(fast != nullptr && fast->next != nullptr){
            slow_prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2 - Split the LL into 2 parts from the middle 
        // and reverse the second part
        ListNode *h1 = head, 
                *h2;
        if(fast == nullptr){
            h2 = reverseList(slow);
            slow_prev->next = nullptr;
        }
        else{
            h2 = reverseList(slow->next);
            slow->next = nullptr;
        }
        
        // Traverse both the LL while linking heads of both LL
        ListNode *next1 = h1->next, 
                *next2 = h2->next;
        while(h1 != nullptr && h2 != nullptr){
            next1 = h1->next;
            next2 = h2->next;

            h1->next = h2;
            h2->next = next1;

            h1 = next1;
            h2 = next2;
        }
    }
};