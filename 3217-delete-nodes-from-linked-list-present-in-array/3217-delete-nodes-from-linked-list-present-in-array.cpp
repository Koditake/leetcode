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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if (!head) return nullptr;
        
        unordered_set<int> iset(nums.begin(),nums.end());
        
        while (head && iset.contains(head->val)) {
            auto tmp = head;
            head = head->next;
            delete tmp;
        }
        
        if (!head) return nullptr;
        
        auto cur = head;
        
        while (cur->next) {
            if (iset.contains(cur->next->val)) {
                auto tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }
        
        return head;
    }
};